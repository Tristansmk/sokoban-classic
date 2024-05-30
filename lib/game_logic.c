/**
 * \file game_logic.c
 * \author BAUER Erwan
 * \author SYMKO Tristan
*/

#include <stdio.h>
#include "level.h"
#include "game_logic.h"

Level keyControl(Level lvl, char touche) {
    Position suivante;
    Position suivanteCaisse;
    switch (touche) {
        // Vers le haut (y -1)
        case 'z': ;
            suivante = (struct Position) {lvl.joueur.x, (lvl.joueur.y)-1};
            suivanteCaisse = (struct Position) {lvl.joueur.x, (lvl.joueur.y)-2};
            lvl = avancerJoueur(lvl, lvl.joueur, suivante, suivanteCaisse);
            break;
        // Vers la gauche (x -1)
        case 'q': ;
            suivante = (struct Position) {(lvl.joueur.x)-1, lvl.joueur.y};
            suivanteCaisse = (struct Position) {(lvl.joueur.x)-2, lvl.joueur.y};
            lvl = avancerJoueur(lvl, lvl.joueur, suivante, suivanteCaisse);
            break;
        // Vers le bas (y +1)
        case 's': ;
            suivante = (struct Position) {lvl.joueur.x, (lvl.joueur.y)+1};
            suivanteCaisse = (struct Position) {lvl.joueur.x, (lvl.joueur.y)+2};
            lvl = avancerJoueur(lvl, lvl.joueur, suivante, suivanteCaisse);
            break;
        // Vers la droite (x +1)
        case 'd': ;
            suivante = (struct Position) {(lvl.joueur.x)+1, lvl.joueur.y};
            suivanteCaisse = (struct Position) {(lvl.joueur.x)+2, lvl.joueur.y};
            lvl = avancerJoueur(lvl, lvl.joueur, suivante, suivanteCaisse);
            break;
        default: ;
            break;
    }
    return lvl;
}


// Faire actualiser la pose du joueur à chaque fois
Level avancerJoueur(Level lvl, Position joueur, Position suivante, Position suivcaisse) {
    switch (lvl.tab[suivante.y][suivante.x]) {
        case ' ': // Vide
            if (lvl.tab[joueur.y][joueur.x] == '@') {
                lvl.tab[joueur.y][joueur.x] = ' ';
            } else {
                lvl.tab[joueur.y][joueur.x] = '.'; 
            }  lvl.tab[suivante.y][suivante.x] = '@';
            break;

        case '.': // Case déstination
            if (lvl.tab[joueur.y][joueur.x] == '@') {
                lvl.tab[joueur.y][joueur.x] = ' ';
            } else {
                lvl.tab[joueur.y][joueur.x] = '.';
            }
            lvl.tab[suivante.y][suivante.x] = '+';
            break;

        case '$': // Une boite
            if (lvl.tab[suivcaisse.y][suivcaisse.x] != '#' && lvl.tab[suivcaisse.y][suivcaisse.x] != '$' && lvl.tab[suivcaisse.y][suivcaisse.x] != '*') {            
                lvl.tab[suivante.y][suivante.x] = ' ';
                switch (lvl.tab[suivcaisse.y][suivcaisse.x]) {
                    case ' ':
                        lvl.tab[suivcaisse.y][suivcaisse.x] = '$';
                        break;
                    case '.':
                        lvl.tab[suivcaisse.y][suivcaisse.x] = '*';
                        lvl.cibles--;
                        break;
                    default:
                        break;
                }
                lvl = avancerJoueur(lvl, joueur, suivante, suivcaisse);
                lvl.joueur = getPlayerPosition(lvl);
                return lvl;
            }
            break;
        
        case '*': // Une boite
            if (lvl.tab[suivcaisse.y][suivcaisse.x] != '#' && lvl.tab[suivcaisse.y][suivcaisse.x] != '$' && lvl.tab[suivcaisse.y][suivcaisse.x] != '*') {  
                lvl.tab[suivante.y][suivante.x] = '.';
                lvl.cibles++;
                switch (lvl.tab[suivcaisse.y][suivcaisse.x]) {
                    case ' ':
                        lvl.tab[suivcaisse.y][suivcaisse.x] = '$';
                        break;
                    case '.':
                        lvl.tab[suivcaisse.y][suivcaisse.x] = '*';
                        lvl.cibles--;
                        break;
                    default:
                        break;
                }
                lvl = avancerJoueur(lvl, joueur, suivante, suivcaisse);
                lvl.joueur = getPlayerPosition(lvl);
                return lvl;
            }
            break;

        default: // Choix par defaut
            return lvl;
            break;
    }

    lvl.joueur = getPlayerPosition(lvl);
    return lvl;
}