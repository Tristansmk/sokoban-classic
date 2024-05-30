
# Sokoban classique en C 

![https://i.ibb.co/sHVpWJX/Sans-titre.png](https://i.ibb.co/sHVpWJX/Sans-titre.png)

###  Auteurs 

- SYMKO Tristan
- BAUER Erwan 

### Prérequis

- Avoir le compilateur gcc
- Avoir Make
- Avoir Git
- Avoir Doxygen (uniquement nécessaire pour la documentation)

# Introduction

Bienvenue dans notre projet de jeu Sokoban ! Ce jeu a été développé en utilisant le langage de programmation C et est conçu pour mettre en pratique les concepts abordés dans le cours de Techniques de développement. Le Sokoban est un jeu de puzzle classique où le joueur doit pousser des boîtes vers des emplacements de stockage désignés. Les règles du jeu et les fonctionnalités sont basées sur les spécifications ci-dessous.

## Mécanismes de Jeu

Le jeu est basé sur les règles classiques du Sokoban. Le Sokoban est un jeu de puzzle classique où le joueur contrôle un personnage qui doit pousser des boîtes vers des emplacements de stockage désignés. Le jeu se joue sur une carte basée sur une grille où le personnage peut se déplacer dans quatre directions (z: haut, b: bas, q: gauche, d: droite). Le personnage ne peut pousser qu’une seule boîte à la fois et il ne peut pas tirer les boîtes ou passer à travers les murs.

## Présentation

Voici un aperçu des fonctionnalités implémentées dans notre projet :

- Affichage basé sur la console de la carte du jeu.
- Capacité à charger et à jouer des niveaux de jeu à partir d'un fichier.
- Gestion appropriée des mouvements du joueur et de la poussée des boîtes.
- Détection et gestion de la condition de victoire (toutes les boîtes sont dans les emplacements de stockage).

Les touches du jeu sont :

- z: avancer vers le haut
- s: aller vers le bas
- q: aller vers la gauche
- d: aller vers la droite
- r: recommencer le niveau actuel
- c: changer de niveau
- o: out (quitter le jeu)

Les caractères du jeu sont :

- '#': un mur
- '.': case de destination (pour caisses)
- '$': une caisse
- '*': caisse sur déstination
- '@': le joueur
- '+': joueur sur déstination

# Compilation et lancement

Une fois les règles et le jeu compris il ne vous reste plus qu'à suivre les étapes ci-dessous pour jouer !

## Compilation


1. Clonez le dépôt Git
```bash
git  clone  git@git.unistra.fr:symko/projet-techdev.git
```
2. Allez dans le répertoire du projet
```bash
cd  projet-techdev
```
3. Compilez le projet en utilisant le Makefile
```bash
make
```
## Lancement du jeu

Retourner dans l'invite de commande et suivez la procédure suivante

4. **Lancer** le jeu avec la commande suivante
```bash
./sokoban.exe
```  
**BON JEU !**

# Paramétrage du jeu
  
## Ajout d'un niveau

Avant tout choses il est nécessaire que le **niveau** à ajouter soit dans le format de fichiers **.xsb**, c'est à dire un fichier avec le niveau en brut comme ci-dessous.

**Fichier Niveau 1.xsb** :

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

**ATTENTION**, le programme ne gère que 20 niveaux au maximum !

- Se rendre dans le dossier "lvl" et simplement ajouter votre nouveau niveau dedans.
- Il ne reste plus qu'à resuivre les **étapes 3 et 4** de la section [Compilation et lancement](#compilation-et-lancement)

## Les commandes optionnelles make

- Pour générer la documentation en html

```
make doc
```

- Pour nettoyer le répertoire du projet

```
make clean
```

NB : supprime l'éxecutable, le dossier contenant la documentation et les ficiers .tar.gz.

- Pour générer une archive

```
make archive
```

NB : Une archive contenant les fichiers c, h, le Makefile, le README et le Doxyfile sera créée.

# Questions / Feedbacks

N'hésitez pas à nous contacter si vous avez des questions ou des commentaires sur notre projet.

Merci de nous avoir donné l'opportunité de travailler sur ce projet Sokoban !