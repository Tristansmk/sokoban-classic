/**
 * \file game_logic.h
 * \author BAUER Erwan
 * \author SYMKO Tristan
*/
#ifndef game_logic
#define game_logic
/**
 * \def MAX
 * \brief MAX est défini à 256
 */
#define MAX 256

/**
 * \fn Level keyControl(Level lvl, char touche)
 * \brief Gère le contrôle du joueur en fonction de la touche appuyée.
 * \param lvl Le niveau dans lequel le joueur opère.
 * \param touche La touche appuyée par le joueur (valeurs acceptées : 'h' pour haut, 'b' pour bas, 'g' pour gauche, 'd' pour droite).
 * \return Le niveau avec la nouvelle position du joueur.
 */

Level keyControl(Level lvl, char touche);

/**
 * \fn Level avancerJoueur(Level lvl, Position joueur, Position suivante, Position suivcaisse)
 * \brief Gère le déplacement du joueur dans le niveau.
 * \param lvl Le niveau dans lequel le joueur opère.
 * \param joueur Position actuelle du joueur.
 * \param suivante Position future du joueur.
 * \param suivcaisse Position de la case se trouvant 2 case après la position actuelle du joueur.
 * \return Le niveau mis à jour après le déplacement du joueur.
 */
Level avancerJoueur(Level lvl, Position joueur, Position suivante, Position suivcaisse);

#endif