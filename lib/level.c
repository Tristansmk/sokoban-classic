/**
 * @file level.c
 * \author Erwan
 * \author Tristan
*/
#include <stdio.h>
#include "level.h"
#define MAX 256

Level load_level(char nom_fichier[]) {
    // Creation du lvl
    Level lvl;
    lvl.col = 0;
    lvl.li = 0;
    lvl.cibles = 0;
    // Ouverture du fichier
    FILE *fichier;
    fichier = fopen(nom_fichier, "r");
    int colonnesDansLigneActuelle;
    char ligne[256];
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return lvl;
    } else {
        while (fgets(ligne, sizeof(ligne), fichier)) {
            // Parcourir la ligne caractère par caractère
            for (int i = 0; ligne[i] != '\0'; i++) {
                lvl.tab[lvl.li][i] = ligne[i];
                colonnesDansLigneActuelle=i;
            }
            if (colonnesDansLigneActuelle > lvl.col) {
                lvl.col = colonnesDansLigneActuelle;
            }
            lvl.li++;
        }
    }
    lvl.cibles = getLevelDestination(lvl);
    lvl.joueur = getPlayerPosition(lvl);
    return lvl;
}

Position getPlayerPosition(Level lvl) {
    Position temp;
    for (int x = 0; x < lvl.li; x++) {
        for (int y = 0; y < lvl.col; y++) {
            if (lvl.tab[x][y] == '@') {
                temp.x = y;
                temp.y = x;
            }
            if (lvl.tab[x][y] == '+') {
                temp.x = y;
                temp.y = x;
            } 
        }   
    }
    return temp;
}

int getLevelDestination(Level lvl) {
    int temp = 0;
    for (int x = 0; x < lvl.li; x++) {
        for (int y = 0; y < lvl.col; y++) {
            if (lvl.tab[x][y] == '.' || lvl.tab[x][y] == '+') {
                temp++;
            }
        }
    }
    return temp;
}

void affichage(Level lvl) {
    printf("\n\n");
    for (int i = 0; i < lvl.li; i++) {
        printf("    ");
        for (int z = 0; z < lvl.col; z++) {
            switch (lvl.tab[i][z]) {
                case '#':
                    printf("\033[1;34m"); // bleu
                    printf("%c", lvl.tab[i][z]);
                    printf("\033[0m");
                    break;
                case '$':
                    printf("\033[1;35m"); // magenta
                    printf("%c", lvl.tab[i][z]);
                    printf("\033[0m");
                    break;
                case '*':
                    printf("\033[1;32m"); // vert
                    printf("%c", lvl.tab[i][z]);
                    printf("\033[0m");
                    break;
                case '+':
                    printf("\033[1;33m"); // jaune
                    printf("%c", lvl.tab[i][z]);
                    printf("\033[0m");
                    break;
                case '@':
                    printf("\033[1;33m"); // jaune
                    printf("%c", lvl.tab[i][z]);
                    printf("\033[0m");
                    break;
                case '.':
                    printf("\033[1;37m"); // blanc
                    printf("%c", lvl.tab[i][z]);
                    printf("\033[0m");
                    break;
                default:
                    printf("\033[0m"); // Couleur par défaut
                    printf(" ");
                    printf("\033[0m");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n\n");
}