# Minishell - Projet Systèmes d'exploitation

Notre Minishell est un shell que nous avons développé en langage C dans le cadre du projet final du cours "Systèmes d’exploitation" de la seconde année de licence informatique à distance de l’Université Paris 8, sous la direction du professeur P.KISLIN.

## ⚙️ COMPILATION DU SHELL
Pour compiler le minishell, utilisez la commande suivante:
```bash
$ make
```
![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE1.png "Compilation")

## 🚀 LANCEMENT DU SHELL

Pour exécuter le minishell:
```bash
$ ./monshell
```
![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE2.png "Lancement")


## 🛠️ COMMANDES INTERNES (Built-in)

Notre shell supporte plusieurs commandes intégrées (built-in) essentielles pour la gestion des processus et de l'environnement.

<dl>
  <dt>monhelp</dt>
  <dd>Affiche le message d'aide du shell et indique les étapes pour accéder au manuel du programme.</dd>
<d/l> 
```bash
$ monhelp
```
![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE3.png "monhelp")


### 2. moncd 
    Change le répertoire courant de l'utilisateur. On afficher le répertoire actuel
 avec la commande suivante:
```bash
$ pwd
```
![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE4.png "pwd")

Puis on change de répertoire avec notre commande interne, 'moncd ..', puis on vérifie nouveau répertoire
avec la commande externe pwd:

```bash
$ moncd ..
$ pwd
```
![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE5.png "moncd_pwd") 


