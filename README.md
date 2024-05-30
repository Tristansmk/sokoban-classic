# Classic Sokoban in C

![https://i.ibb.co/sHVpWJX/Sans-titre.png](https://i.ibb.co/sHVpWJX/Sans-titre.png)

### Authors

- Tristan Symko
- Erwan Bauer

### Prerequisites

- GCC compiler
- Make
- Git
- Doxygen (only needed for documentation)

# Introduction

Welcome to our Sokoban game project! This game was developed using the C programming language and is designed to practice the concepts covered in the Development Techniques course. Sokoban is a classic puzzle game where the player must push boxes to designated storage locations. The game's rules and features are based on the specifications below.

## Game Mechanics

The game is based on the classic rules of Sokoban. In Sokoban, the player controls a character who must push boxes to designated storage locations. The game is played on a grid-based map where the character can move in four directions (z: up, s: down, q: left, d: right). The character can only push one box at a time and cannot pull boxes or pass through walls.

## Features

Here is an overview of the features implemented in our project:

- Console-based display of the game map.
- Ability to load and play game levels from a file.
- Proper management of player movements and box pushing.
- Detection and management of the win condition (all boxes are in storage locations).

The game controls are:

- z: move up
- s: move down
- q: move left
- d: move right
- r: restart the current level
- c: change level
- o: quit the game

The game characters are:

- '#': a wall
- '.': destination tile (for boxes)
- '$': a box
- '*': box on destination
- '@': the player
- '+': player on destination

# Compilation and Launch

Once you understand the rules and the game, just follow the steps below to play!

## Compilation

1. Clone the Git repository
```bash
git clone git@git.unistra.fr:symko/projet-techdev.git
```
2. Go to the project directory
```bash
cd  projet-techdev
```
3. Compile the project using the Makefile
```bash
make
```
## Launching the Game

Go back to the command prompt and follow this procedure

4. **Launch** the game with the following command
```bash
./sokoban.exe
```  
**ENJOY THE GAME!**

# Game Configuration
  
## Adding a Level

First of all, the **level** to be added must be in **.xsb** file format, which means a raw level file like the one below.

**Level 1.xsb File:**

```
1       #####
2      ### ###
3      # ... #
4      # # # #
5     ## #$# ##
6     # $ @ $ #
7       # # #
8      #######
```

**NOTE**, the program only handles up to 20 levels!

- Go to the "lvl" folder and simply add your new level there.
- Then just follow **steps 3 and 4** in the [Compilation and Launch](#compilation-and-lancement) section again.

## Optional make Commands

- To generate the documentation in HTML

```
make doc
```

- To clean the project directory

```
make clean
```

NB: This removes the executable, the documentation folder, and the .tar.gz files.

- To generate an archive

```
make archive
```

NB: An archive containing the .c, .h files, the Makefile, the README, and the Doxyfile will be created.

# Questions / Feedback

Feel free to contact us if you have any questions or comments about our project.

Thank you for giving us the opportunity to work on this Sokoban project!
