#include "sys.h"
#include "commandes.h"
#include "redirections.h"
#include "utils.h"
#include "monsleep.h"

int detecte_pipe(char **mot) {
    int i;

    for (i = 0; mot[i] != NULL; i++) {
        if (strcmp(mot[i], "|") == 0) {
            mot[i] = NULL;
            return i;
        }
    }
    return 0;
}
void detecte_redirections(struct commande *cmd) {
    int i;

    for (i = 0; cmd->argv[i] != NULL; i++) {
        if (strcmp(cmd->argv[i], "<") == 0) {
            if (cmd->argv[i + 1] != NULL) {
                cmd->input = cmd->argv[i + 1];
                cmd->argv[i] = NULL;
            }
        } else if (strcmp(cmd->argv[i], ">") == 0) {
            if (cmd->argv[i + 1] != NULL) {
                cmd->output = cmd->argv[i + 1];
                cmd->argv[i] = NULL;
            }
        } else if (strcmp(cmd->argv[i], ">>") == 0) {
            if (cmd->argv[i + 1] != NULL) {
                cmd->output = cmd->argv[i + 1];
                cmd->append = 1;
                cmd->argv[i] = NULL;
            }
        } else if (strcmp(cmd->argv[i], "2>") == 0) {
            if (cmd->argv[i + 1] != NULL) {
                cmd->err = cmd->argv[i + 1];
                cmd->argv[i] = NULL;
            }
        } else if (strcmp(cmd->argv[i], "2>>") == 0) {
            if (cmd->argv[i + 1] != NULL) {
                cmd->err = cmd->argv[i + 1];
                cmd->append = 1;
                cmd->argv[i] = NULL;
            }
        } else if (strcmp(cmd->argv[i], "2>&1") == 0) {
            cmd->error_output = 1;
            cmd->err = "2>&1";
            cmd->argv[i] = NULL;
        } else if (strcmp(cmd->argv[i], "&") == 0) {
            cmd->background = 1;
            cmd->argv[i] = NULL;
            break;
        }
    }
}


void detecteur(char **mot) {
    int i = 0;
    int pipe_position;
    pipe_position = detecte_pipe(mot);

    if(pipe_position) {
        cmd1.argv = mot;
        cmd1.pipe = 1;
        detecte_redirections(&cmd1);

        cmd2.argv = mot + pipe_position + 1;
        detecte_redirections(&cmd2);

        config_pipe(&cmd1, &cmd2);
    } else {
        cmd1.argv = mot;
        detecte_redirections(&cmd1);
        cmd1.argc = i;
        while (mot[cmd1.argc] != NULL) {
            cmd1.argc++;
        }

         // Setting argc for the number of arguments
        if (strcmp(cmd1.argv[0], "monsleep") == 0) {
            monsleep(cmd1.argc, cmd1.argv);
        } else if (strcmp(cmd1.argv[0], "moncd") == 0) {
            moncd(&cmd1);
        } else if (strcmp(cmd1.argv[0], "monexit") == 0) {
            monexit(&cmd1);
        } else if (strcmp(cmd1.argv[0], "monhelp") == 0) {
            monhelp(&cmd1);
        } else {
            run(&cmd1);
        }
    }
}

void run(struct commande *cmd) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return;
    } else if (pid == 0) {
        config_redirections(cmd);
        execvp(cmd->argv[0], cmd->argv);
        perror("execvp");
        exit(1);
    } else {
        if (!cmd->background) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            printf("[%d]\n", pid);
            waitpid(pid, NULL, WNOHANG);
        }
    }
}

void moncd(struct commande *cmd) {
    if (cmd->argv[1] == NULL) {
        fprintf(stderr, "Usage: moncd <args>\n");
        return;
    }
    if (chdir(cmd->argv[1]) == -1) {
        perror("moncd");
    }
}

void monexit(struct commande *cmd) {
    if (cmd->argv[1] != NULL) {
        usage("Usage: monexit ne prend pas d'arguments");
        return;
    }
    printf("An lot soley!\n");
    exit(0);
}

void monhelp(struct commande *cmd) {
    if (cmd->argv[1] != NULL) {
        usage("Usage: monhelp ne prend pas d'arguments");
        return;
    }
    // --- EN-TÊTE et BIENVENUE ---
    printf("\n");    
    printf("==============================================================\n");
    printf("        BIENVENUE dans le Minishell - Réalisé par D. ERIN\n");
    printf("==============================================================\n");
    printf("\n");
    
    // --- COMMANDES INTERNES ---
    printf(" COMMANDES INTERNES DISPONIBLES :\n");
    printf("----------------------------------\n");
    printf("  - monhelp              : Affiche ce message d'aide.\n");
    printf("  - moncd <chemin>       : Change le répertoire courant.\n");
    printf("  - monexit              : Quitte le shell proprement.\n");
    printf("  - monsleep <secondes>  : Attend un certain nombre de secondes.\n");
    printf("\n");

    // --- GESTION DES FLUX (PIPES et REDIRECTIONS) ---
    printf(" GESTION DES FLUX ET COMMANDES EXTERNES :\n");
    printf("------------------------------------------\n");
    printf("Minishell supporte les commandes externes (ex: ls, grep, find, etc.).\n");
    printf("\n");
    printf("  * PIPE (|) :\n");
    printf("    Permet de chaîner des commandes. La sortie de la première\n");
    printf("    commande devient l'entrée de la seconde.\n");
    printf("    Exemple : commande_A | commande_B\n");
    printf("\n");
    printf("  * REDIRECTIONS (>, <, >>) :\n");
    printf("    - > Fichier : Redirige la sortie vers un fichier (écrase).\n");
    printf("    - < Fichier : Utilise le contenu d'un fichier comme entrée.\n");
    printf("    - >> Fichier: Ajoute la sortie à la fin d'un fichier.\n");
    printf("\n");
    
    // --- MANUEL SYSTÈME ---
    printf(" MANUEL SYSTÈME (man) :\n");
    printf("--------------------------\n");
    printf("Pour générer le manuel, il faudra:\n");
    printf("1. Quittez le minishell: monexit\n");
    printf("2. Compiler le manuel: sudo make install\n");
    printf("3. Revenir dans le minishell: ./monshell\n");
    printf("4. Consulter le manuel: man monshell\n");
}

