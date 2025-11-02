/***************************************************************************
# Nom ......... : main.c
# Rôle ........ : Tour de contrôle du shell
# Auteur ...... : Dominique, ERIN
# Version ..... : V0.1 du 31/07/2024
# Licence ..... : Réalisé dans le cadre du Cours SE (2023/2024)
#***************************************************************************/
#include "sys.h"
#include "commandes.h"
#include "utils.h"
#include "redirections.h"
// Définitions des variables globales
char ligne[MaxLigne];
char pathname[MaxPathLength];
str mot[MaxMot];
str dirs[MaxDirs];

struct commande cmd, cmd1, cmd2;
int main(int ac, str av[]) {
    // Afficher un message de bienvenue
    init_Bienvenue();

    // Découper UNE COPIE de PATH en répertoires
    char *path_copy = strdup(getenv("PATH"));
    decouper(path_copy, ":", dirs, MaxDirs);
    free(path_copy);

    /* Lire et traiter chaque ligne de commande */
    for (printf(PROMPT); fgets(ligne, sizeof ligne, stdin) != 0; printf(PROMPT)) {
        decouper(ligne, " \t\n", mot, MaxMot);
        if (mot[0] == NULL) {
            continue;
        }

        // Initialiser les structures de commande
        cmd1.argv = mot;
        cmd1.input = NULL;
        cmd1.output = NULL;
        cmd1.err = NULL;
        cmd1.background = 0;
        cmd1.append = 0;
        cmd1.error_output = 0;
        cmd1.pipe = 0;
        cmd1.argc = 0;

        cmd2.argv = NULL;
        cmd2.input = NULL;
        cmd2.output = NULL;
        cmd2.err = NULL;
        cmd2.background = 0;
        cmd2.append = 0;
        cmd2.error_output = 0;

        detecteur(mot);
    }
    return 0;
}
