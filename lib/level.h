/**
 * \file level.h
 * \author Erwan
 * \author Tristan
*/
#ifndef level
#define level
/**
 * \def MAX
 * \brief MAX est défini à 256
 */
#define MAX 256

/**
 * \struct Position
 * \brief Structure de données pour représenter une position (x, y).
 */ 
typedef struct Position {
    int x; /**< Coordonnée X. */
    int y; /**< Coordonnée Y. */
} Position;

/**
 * \struct Level
 * \brief Structure de données pour représenter un niveau du jeu Sokoban.
 */
typedef struct Level {
    char tab[MAX][MAX]; /**< Tableau représentant le niveau. */
    int col;            /**< Nombre de colonnes dans le tableau. */
    int li;             /**< Nombre de lignes dans le tableau. */
    int cibles;         /**< Nombre de cibles restantes. */
    Position joueur;    /**< Position du joueur. */
} Level;

/**
 * \fn Level load_level(char nom_fichier[])
 * \brief Charge un niveau à partir d'un fichier.
 * \param nom_fichier Nom du fichier de niveau.
 * \return Le niveau chargé.
 */
Level load_level();

/**
 * \fn Position getPlayerPosition(Level lvl)
 * \brief Obtient la position du joueur dans un niveau.
 * \param lvl Le niveau dans lequel le joueur évolue.
 * \return La position du joueur.
 */
Position getPlayerPosition();

/**
 * \fn int getLevelDestination(Level lvl)
 * \brief Obtient le nombre de cibles dans un niveau.
 * \param lvl Le niveau dans lequel le joueur évolue.
 * \return Le nombre de cibles.
 */
int getLevelDestination();

/**
 * \fn void affichage(Level lvl)
 * \brief Affiche le niveau dans la console.
 * \param lvl Le niveau à afficher.
 */
void affichage();

#ifdef _WIN32
    #define OS_TYPE 0
#else
    #define OS_TYPE 1
#endif

#endif