# Définition des variables
CC = gcc
CFLAGS = -Wall -Werror
SRC_FILES = $(wildcard ./lib/*.c)
EXECUTABLE = sokoban

# Règle par défaut pour la compilation de tous les fichiers source
all: $(EXECUTABLE)

# Règle pour créer l'exécutable
$(EXECUTABLE): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -rf $(EXECUTABLE) Documentation *.o *.tar.gz

# Règle pour créer une archive compressée du projet
archive:
	tar czf project_archive.tar.gz $(filter-out $(EXECUTABLE).exe ./Documentation, $(wildcard *))

# Règle pour générer la documentation avec Doxygen
doc:
	doxygen Doxyfile

# Indique à Make que "clean" et "archive" ne créent pas de fichiers
.PHONY: clean archive 