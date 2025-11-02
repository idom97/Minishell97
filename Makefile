#***************************************************************************
# Nom ......... : Makefile
# Rôle ........ : Le fichier Makefile permet de compiler le programme monshell
# Auteur ...... : Dominique, ERIN
# Version ..... : V0.1 du 31/07/2024
# Licence ..... : Réalisé dans le cadre du Cours SE (2023/2024)
# Compilation : make
# Manuel........: sudo make install
#***************************************************************************
# Options de compilation
CC = gcc
EXEC = monshell
SRC_DIR = src
CFLAGS = -g -I$(SRC_DIR)

# Fichiers objets
OBJECT_FILES = main.o commandes.o monsleep.o redirections.o utils.o

# Cible par défaut
all: $(EXEC) monshell.1.gz

# Règle pour créer l'exécutable
$(EXEC): $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) -o $(EXEC) 

# Règles pour compiler les fichiers sources en objets
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règles spécifiques
main.o: $(SRC_DIR)/main.c $(SRC_DIR)/sys.h
commandes.o: $(SRC_DIR)/commandes.c $(SRC_DIR)/sys.h
monsleep.o: $(SRC_DIR)/monsleep.c $(SRC_DIR)/sys.h
redirections.o: $(SRC_DIR)/redirections.c $(SRC_DIR)/sys.h
utils.o: $(SRC_DIR)/utils.c $(SRC_DIR)/sys.h

# Règle pour générer le manuel compressé
monshell.1.gz: man_pages/monshell.1
	gzip -c $< > $@

# Règle pour nettoyer les fichiers objets, l'exécutable et le manuel compressé
clean:
	rm -f *.o $(EXEC) monshell.1.gz

# Installation de l'exécutable et du manuel
install: $(EXEC) monshell.1.gz
	install -m 755 $(EXEC) /usr/local/bin/
	install -m 644 monshell.1.gz /usr/local/share/man/man1/

