/**
 * \file launchLevel.c
 * \author BAUER Erwan
 * \author SYMKO Tristan
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> 

#include "launchLevel.h"
#include "level.h"
#include "game_logic.h"

#define MAX_NIV 20 // Nombre de niveaux max dans la tab de niveaux
#define MAX_INPUT_LENGTH 100 // Nb max de char que l'utilisateur peut rentrer

void affichage_niv(char ** temp, int nb_niveaux) {
    printf("\033[1;37mNiveaux disponibles:\n\n");
    int i;
    for (i = 0; i < nb_niveaux+1; i++) {
        if (i==nb_niveaux) {
            if (i < 9) {
                printf("\n\033[1;37m %d: \033[1;31m%s\033[1;37m\n", i+1, "Quitter le jeu");
            } else {
                printf("\n\033[1;37m%d: \033[1;31m%s\033[1;37m\n", i+1, "Quitter le jeu");
            }
            break;
        }
        if (i < 9) {
            printf("\033[1;37m %d: \033[1;34m%s\033[0m\n", i+1, temp[i]);
        } else {
            printf("\033[1;37m%d: \033[1;34m%s\033[0m\n", i+1, temp[i]);
        }
        
    }
    printf("\033[1;37m\n");
}

char * FindLvl() {
    rechercher : ;
    // Prologue
    char **niveaux = malloc(MAX_NIV * sizeof(char *));  
    int i = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir("./lvl/");

    // Chercher les fichiers de niveau
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (i != MAX_NIV-1 && dir->d_type == DT_REG) {
                char *file_name = dir->d_name;
                char *extension = strrchr(file_name, '.'); // Trouver l'extension du fichier

                if (extension != NULL && strcmp(extension, ".xsb") == 0) {
                    niveaux[i] = strdup(file_name);
                    i++;
                }
            }
        }
        closedir(d);
    }
    affichage_niv(niveaux, i);
    int res;
    char input[MAX_INPUT_LENGTH];
    printf("\033[1;33mVeuillez choisir un numero de niveau parmis ceux ci-dessus\n\n\033[1;37m");
    printf("Reponse: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    // Utiliser sscanf pour extraire un entier de l'entrée
    if (sscanf(input, "%d", &res) == 1) {
        if (res > i+1) {
            goto refind;
        } else if(res == i+1) {
            return "o";
        }
        // Le scanf a réussi à extraire un entier
        printf("\nVous avez choisi le niveau: %s\n\n", niveaux[res-1]);
        // Faites ce que vous voulez avec "res" ici
    } else {
        refind : ;
        if (OS_TYPE== 0) {
            system("cls"); // windows version
        } else {
            system("clear"); // Linux macos version
        }
        // L'utilisateur n'a pas entré un entier valide
        printf("\033[1;31mErreur : Veuillez entrer un nombre valide.\n\n\033[1;37m");
        goto rechercher;
        // Gérer l'erreur ou demander à l'utilisateur de réessayer, etc.
    }
    return niveaux[res-1];
}

void launch(int sys) {
    launch :
    if (OS_TYPE== 0) {
        system("cls"); // windows version
    } else {
        system("clear"); // Linux macos version
    }
    char niv[100];
    strcpy(niv, FindLvl());
    char * test = "o";
    if (*niv == *test) goto fin;
    char before[] = "./lvl/";
    char path[256];
    snprintf(path, sizeof(path), "%s%s", before, niv);
    char c;
    printf("%s",path);
    recommencer : ;
    Level lvl = load_level(path);
    if (lvl.col == 0 && lvl.li == 0) {
        printf("Un probleme est survenu");
        return;
    }
    if (OS_TYPE== 0) {
        system("cls"); // windows version
    } else {
        system("clear"); // Linux macos version
    }
    int z;
    do {
        printf("\033[1;37mNiveau selectionne : \033[1;30m\"%s\"\n", niv); 
        affichage(lvl);
        printf("\033[1;33mz\033[1;37m: haut    \033[1;33ms\033[1;37m: bas\n\033[1;33mq\033[1;37m: gauche  \033[1;33md\033[1;37m: droite\n\n\033[1;32mr\033[1;37m: recommencer\n\033[1;32mc\033[1;37m: changer de niveau\n\n\033[1;31mo\033[1;37m: quitter le jeu\n\n");
        printf("\033[0;33mEntrez un caractere\033[1;37m: ");
        c = getchar();
        while ((z = getchar()) != '\n' && c != EOF); // fixe du getchar();
        if (c=='o') {
            fin : ;
            if (OS_TYPE== 0) {
                system("cls"); // windows version
            } else {
                system("clear"); // Linux macos version
            }
            printf("\nLe jeu a correctement ete arrete !\n");
            printf("\nMerci d'avoir joue a notre jeu, a bientot !\n\n\033[0m");
            return;
        } else if (c=='r') {
            goto recommencer;
            return;
        } else if (c=='c') {
            goto launch;
        }
        lvl = keyControl(lvl, c);
        if (OS_TYPE== 0) {
            system("cls"); // windows version
        } else {
            system("clear"); // Linux macos version
        }
    }
    while (lvl.cibles != 0);
    printf("\033[1;32mFelicitations vous avez reussi le niveau \"%s\"!\n\n\033[0m", niv);
    reask : ;
    printf("\033[1;37mVoulez en faire un autre ? [N] Non, [Y] Oui : ");
    char resp;
    scanf("%c", &resp);
    if (resp=='Y') {goto launch;} 
    else if (resp=='N') {
        printf("\nMerci d'avoir joue a notre jeu, a bientot !\n\n\033[0m");
    } else {
        if (OS_TYPE== 0) {
            system("cls"); // windows version
        } else {
            system("clear"); // Linux macos version
        }
        printf("\033[1;31mErreur : Veuillez entrer un caractère valide.\n\n\033[1;37m");
        goto reask;
    }
}