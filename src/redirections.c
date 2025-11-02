#include "sys.h"
#include "redirections.h"

void config_redirections(struct commande *cmd) {
    int fd;

    if (cmd->input != NULL) {
        fd = open(cmd->input, O_RDONLY);
        if (fd == -1) {
            perror("Erreur ouverture fichier d'entrée");
            exit(1);
        }
        if (dup2(fd, STDIN_FILENO) == -1) {
            perror("dup2 stdin");
            exit(1);
        }
        close(fd);
    }
    
    // 2. Redirection de sortie (STDOUT)
    if (cmd->output != NULL) {
        // Détermine si on écrase (O_TRUNC) ou si on ajoute (O_APPEND)
        int flags = O_CREAT | O_WRONLY | (cmd->append ? O_APPEND : O_TRUNC);
        fd = open(cmd->output, flags , 0644);
        if (fd == -1) {
            perror("Erreur ouverture fichier de sortie");
            exit(1);
        }
        if (dup2(fd, STDOUT_FILENO) == -1) {
            perror("dup2 stdout");
            exit(1);
        }
        close(fd);
    }
    // 3. Redirection d'erreur (STDERR)
    if (cmd->err != NULL) {
        int flags = O_CREAT | O_WRONLY | (cmd->append ? O_APPEND : O_TRUNC);
        fd = open(cmd->err, flags, 0644);
        if (fd == -1) {
            perror("Erreur ouverture fichier d'erreur");
            exit(1);
        }
        if (dup2(fd, STDERR_FILENO) == -1) {
            perror("dup2 stderr");
            exit(1);
        }
        close(fd);
    // 4. Redirection 2>&1
    } else if (cmd->error_output) {
        if (dup2(STDOUT_FILENO, STDERR_FILENO) == -1) {
            perror("dup2 stderr vers stdout");
            exit(1);
        }
    }
    // 5. Gestion de l'arrière-plan SANS REDIRECTION (pour éviter les affichages)
    if (cmd->background && cmd->output == NULL && cmd->err == NULL) {
        fd = open("/dev/null", O_WRONLY);
        if (fd == -1) {
            perror("ouvre /dev/null");
            exit(1);
        }
        // Redirection de STDIN
        if (dup2(fd, STDOUT_FILENO) == -1 || dup2(fd, STDERR_FILENO) == -1) {
            perror("dup2 /dev/null");
            exit(1);
        }
        close(fd);
    }
}
// Fonction pour conf. 2 commandes liées par un pipe (cmd1 | cmd2)
void config_pipe(struct commande *cmd1, struct commande *cmd2) {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(1);
    } else if (pid1 == 0) {
        // Premier processus enfant
        close(fd[0]); // Ferme l'extrémitié de lecture inutilisée du pipe

        // 1. Redirection STDOUT vers l'extrémité d'écriture du pipe
        if (dup2(fd[1], STDOUT_FILENO) == -1) {
            perror("dup2 stdout");
            exit(1);
        }

        // 2. Gestion de la redirection d'entrée (cmd1 < fichier)
        if (cmd1->input != NULL) {
            int fd_in = open(cmd1->input, O_RDONLY);
            if (fd_in == -1) {
                perror("ouvre input pour cmd1");
                exit(1);
            }
            if (dup2(fd_in, STDIN_FILENO) == -1) {
                perror("dup2 stdin pour cmd1");
                exit(1);
            }
            close(fd_in);
        }

        // 3. Gestion de STDERR pour cmd1
        if (cmd1->err != NULL) {
            int err_fd = open(cmd1->err, O_CREAT | O_WRONLY | (cmd1->append ? O_APPEND : O_TRUNC), 0644);
            if (err_fd == -1) {
                perror("ouvre err pour cmd1");
                exit(1);
            }
            if (dup2(err_fd, STDERR_FILENO) == -1) {
                perror("dup2 stderr");
                exit(1);
            }
            close(err_fd);
        } else if (cmd1->error_output) {
            // Redirige STDERR vers le même endroit que STDOUT (le pipe fd[1])
            if (dup2(STDOUT_FILENO, STDERR_FILENO) == -1) {
                perror("dup2 stderr redirigé vers stdout");
                exit(1);
            }
        }
        
        // Ferme le descripteur original du pipe APRÈS toutes les duplications
        close(fd[1]); 

        // On ne rappelle pas config_redirections(cmd1)
        execvp(cmd1->argv[0], cmd1->argv);
        perror("execvp");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(1);
    } else if (pid2 == 0) {
        // Second processus enfant
        close(fd[1]); // Ferme extrémité d'écriture inutilisée du pipe

        // 1. Redirection de STDIN depuis le pipe
        if (dup2(fd[0], STDIN_FILENO) == -1) {
            perror("dup2 stdin");
            exit(1);
        }

        // 2. Gestion de la redirection de sortie (cmd2 > fichier)
        if (cmd2->output != NULL) {
            int flags = O_CREAT | O_WRONLY | (cmd2->append ? O_APPEND : O_TRUNC);
            int fd_out = open(cmd2->output, flags, 0644);
            if (fd_out == -1) {
                perror("ouvre output pour cmd2");
                exit(1);
            }
            if (dup2(fd_out, STDOUT_FILENO) == -1) {
                perror("dup2 stdout pour cmd2");
                exit(1);
            }
            close(fd_out);
        }
        // 3. Gestion de STDERR pour cmd2 (Identique à votre code)
        if (cmd2->err != NULL) {
            int err_fd = open(cmd2->err, O_CREAT | O_WRONLY | (cmd2->append ? O_APPEND : O_TRUNC), 0644);
            if (err_fd == -1) {
                perror("ouvre err pour cmd2");
                exit(1);
            }
            if (dup2(err_fd, STDERR_FILENO) == -1) {
                perror("dup2 stderr");
                exit(1);
            }
            close(err_fd);
        } else if (cmd2->error_output) {
            // Redirection de STDERR vers STDOUT
            if (dup2(STDOUT_FILENO, STDERR_FILENO) == -1) {
                perror("dup2 stderr redirigé vers stdout");
                exit(1);
            }
        }
        

        execvp(cmd2->argv[0], cmd2->argv);// Exécute la deuxième commande
        perror("execvp");
        exit(1);
    }

    // Processus parent
    close(fd[0]); // Ferme l'extrémité de lecture inutilisée
    close(fd[1]); // Ferme l'extrémité de écriture inutilisée
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}



