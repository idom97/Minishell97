#include "sys.h"
#include "utils.h"

void init_Bienvenue() {
    str user = getenv("USER");
    printf("\n");
    printf("*************************************************************************\n");
    printf("*                                                                       *\n");
    if (user) {
        printf("*                    Bienvenue dans monshell, %s!                  *\n", user);
    } else {
        printf("*                    Bienvenue dans monshell!                       *\n");
    }
    printf("*                                                                       *\n");
    printf("*  Pour obtenir de l'aide, tapez 'monhelp' ou consultez le manuel.      *\n");
    printf("*************************************************************************\n");
    printf("\n");
}

void decouper(char *ligne, char *separ, char **mot, int maxmot) {
    int i;
    mot[0] = strtok(ligne, separ);
    for (i = 1; mot[i - 1] != NULL && i < maxmot; i++) {
        mot[i] = strtok(NULL, separ);
    }
    if (i == maxmot) {
        mot[maxmot - 1] = NULL;
    }
}

void usage(str message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
