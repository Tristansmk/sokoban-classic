/**
 * \file launchLevel.h
 * \author BAUER Erwan
 * \author SYMKO Tristan
*/
#ifndef launchLevel
#define launchLevel

/**
 * \fn void affichage_niv()
 * \brief Affiche les niveaux disponibles dans le répertoire "./lvl/".
 */
void affichage_niv();

/**
 * \fn char ** FindLvl()
 * \brief Cherche tout les niveaux disponnibles dans le répertoire "./lvl/" et renvoie le niveaux choisi par l'utilisateur.
 */
char * FindLvl();

/**
 * \fn void launch(int sys)
 * \brief Lance un niveau du jeu Sokoban séléctionné par l'utilisateur.
 * \param sys OS utilisé (0: Windows 1: autres).
 */
void launch();

#endif