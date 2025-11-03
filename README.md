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

Notre shell supporte plusieurs commandes parmi lesquelles:

<dl>
  <dt>monhelp</dt>
  <dd>Affiche le message d'aide du shell et indique les étapes pour accéder au manuel du programme.</dd> 
</dl>

```bash
$ monhelp
```
![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE3.png "monhelp")

<dl>
  <dt>moncd</dt>
  <dd>Change le répertoire courant de l'utilisateur.</dd> 
</dl>

On affiche le répertoire actuel avec la commande suivante:

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

 <dl>
  <dt>monexit</dt>
  <dd>Quitte le shell proprement, en terminant tous les processus en arrière-plan.</dd> 
</dl>

```bash
$ monexit
```
![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE9.png "monexit")


<dl>
  <dt>monsleep</dt>
  <dd>Met le shell en pause pendant le nombre de secondes spécifié. Cette commande est robuste et gère les erreurs de saisie.</dd> 
</dl>

```bash
$ monsleep 1 1 1
```

![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE10.png "monsleep")

```bash
$ monsleep 1m 10s 5s
``` 

![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE11.png "monsleep2")

