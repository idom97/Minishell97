/***************************************************************************
# Nom ......... : monsleep.c
# Rôle ........ : Fonction sleep() avec un nombre variable d'arguments
# Auteur ...... : Dominique, ERIN
# Version ..... : V0.1 du 27/07/2024
# Licence ..... : Réalisé dans le cadre du Cours SE (2023/2024)
# Compilation : make all
# Usage : Pour exécuter : monsleep <args1> <args2> <argsN>
#***************************************************************************/
#include "monsleep.h"


void invalid(char *prog, char *s) {
    fprintf(stderr, "%s: Intervalle de temps invalide %s\n", prog, s);
    exit(1);
}

void dring(int n) {
}

unsigned int sleep(unsigned int nsec) {
    int avant, apres;
    avant = time(0);
    signal(SIGALRM, dring);
    alarm(nsec);
    pause();
    apres = time(0);
    printf("Temps écoulé: %d secondes\n", apres - avant);
}


void monsleep(int ac, char *av[]) {
    int i, j;
    int nsec = 0;

    if (ac < 2){// Message d'erreur si moins de deux arguments sur la ldc
        fprintf (stderr, "usage: %s <args1>\n", av[0]);
	    fprintf (stderr, "usage: %s <args1> <args2> <argsN> \n", av[0]);
	    fprintf (stderr, "usage: %s <argsN><d, h, m, ou s>\n", av[0]);
        return;
    }

    for(j=1; j < ac; j++){// On débute à partir du 2nd argument
        for(i = 0; isdigit(av[j][i]); i++);// Vérifie si l'argument est un nombre

        if (!isdigit(av[j][0]))// Si ce n'est pas un nombre
            invalid(av[0], av[j]);// On affiche un message d'erreur

        //C'est un nombre, conversion de la chaîne en entier
        int nsec_tampon = atoi(av[j]);

        switch(av[j][i]) {
            default:
            invalid(av[0], av[j]);
            case 'd':
            nsec_tampon *= 86400;// Nbre de secondes dans une journée
            case 'h':
            nsec_tampon *= 3600;// Nbre de secondes dans une heure
            case 'm':
            nsec_tampon *= 60;// Nbre de secondes dans une minute
            case 's' :
            case 0:;
        }
        // On additionne les décimaux passés sur ldc
        nsec += nsec_tampon;
               
    }
    // Appel de la fonction sleep avec le nombre total de secondes
    sleep(nsec);
}
