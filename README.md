# Minishell - Projet Systèmes d'exploitation

Minishell développé en langage C dans le cadre du projet final du cours "Systèmes d’exploitation" de la seconde année de licence informatique à distance de l’Université Paris 8, sous la direction du professeur P.KISLIN.

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

Puis on change de répertoire avec notre commande interne, moncd, et on vérifie ensuite que le chemin a changé grâce à la commande externe pwd:

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


## 🔄 GESTION DES FLUX (PIPES et REDIRECTIONS)
<dl>
  <dt>Notre shell gère le chaînage de processus et la manipulation des flux d'entrée/sortie standard.</dt>
</dl>
    
### PIPE (<code>|</code>)
<dl>
  <dt>Permet de chaîner des commandes. La sortie standard (STDOUT) de la première commande devient l'entrée standard (STDIN) de la seconde.</dt>
</dl>    


```bash
$ ls | grep a
```

![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE6.png "pipe")

### REDIRECTIONS
    
<dl>
  <dt>Redirection de l’erreur standard (STDERR) vers un fichier en écrasant ses données:</dt>
</dl>


```bash
$ copier -coller 2> erreurs.txt
```

(Ici, `copier -coller` est supposé être une commande qui génère une erreur, enregistrée dans `erreurs.txt`)

<dl>
  <dt>Redirection de l’entrée standard (STDIN) depuis un fichier:</dt>
</dl>



```bash
$ cat < erreurs.txt
```

![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE7.png "redirection1")

<dl>
  <dt>Redirection de l’erreur standard vers la fin du fichier:</dt>
</dl>


```bash
$ ajouter -RAM 2>> erreurs.txt
$
$ cat < erreurs.txt
```
       
![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE8.png "redirection2")

## 🏃 COMMANDES D'ARRIÈRE-PLAN

<dl>
  <dt>Le shell permet de lancer des processus en arrière-plan en utilisant l'opérateur &:</dt>
</dl>

```bash
$ gedit &
```
<dl>
  <dt>Test de téléchargement en arrière-plan avec double redirection</dt>
  <dd>On lance une commande externe wget en arrière-plan, tout en redirigeant sa sortie standard et ses erreurs standard vers des fichiers séparés.</dd> 
</dl>

```bash
$ wget -O nginx.tar.gz https://nginx.org/download/nginx-1.18.0.tar.gz >> sortie.txt 2> erreurs.txt &
```

![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE12.png "wget")

![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE13.png "preuve")


## 🐞 COMPORTEMENT OBSERVÉ
<dl> 
  <dt>Le fichier <code>sortie.txt</code> reste vide, tandis que les messages d’état et de progression apparaissent dans <code>erreurs.txt</code>.</dt> 
  <dd>Ce comportement est normal, car selon la <a href="https://www.gnu.org/software/wget/manual/wget.html?utm_source=chatgpt.com">documentation officielle</a>, les barres de progression et messages d’état sont imprimés sur <code>stderr</code> afin de séparer les informations d’exécution des données téléchargées. </dd> </dl>

</dl>

![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE14.png "preuve")

![alt text](https://github.com/idom97/Minishell97/blob/main/CE/CE15.png "preuve")



