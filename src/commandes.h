#ifndef COMMANDES_H
#define COMMANDES_H

int detecte_pipe(char **mot);
void detecte_redirections(struct commande *cmd);
void detecteur(char **mot);
void run(struct commande *cmd);
void moncd(struct commande *cmd);
void monexit(struct commande *cmd);
void monhelp(struct commande *cmd);
#endif // COMMAND_H
