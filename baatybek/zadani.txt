Author: Beksultan Baatyrbekov
Semestral project for BIE-PA2 : Pacman.

Game is insipired from Pac-Man game, more info about Pac-Man https://en.wikipedia.org/wiki/Pac-Man

Game is going to fullfil compliance with the rules of the game, collecting bonuses, points, cherries, teleports, etc.

Game is going to have different types of ghost AI.

Game will load a map from file (labyrinth *´+ position of bonuses and ghost home).

Game is goint to be a configurable game from file (speed of ghosts, speed of player, duration of game modes, ...).

Game will have scalable game difficulty (by difficulty, by different behaviour).

Ncurses is chosen as an interace.

Game is mainly about interaction of static objects and dynamic objects. 

As static objects can be considered walls for a maze and a ghost house. 

As dynamic objects can be considered a pacman, ghosts, points, boosters, fruits.

Pacman - main character of the game, it has to eat all the points and boosters without being eaten by ghosts.

Ghosts - enimies of Pacman, try to catch throught the game within the maze.

Points - sometimes called candies or dots, they are all around the maze, once Pacman eats, they disappear from the map. Each point gives 10 points

Boosters - bigger dots. There are 4 of dots accross the maze. It gives Pacman invulnerablity for Pacman, but just for a short amount  of time. Each booster gives 50 points.

Fruits - Temporary objects to be eaten, they appear suddenly in the maze and dissappear if not eaten within some time. There are 8 types of them (100-5000 points).

Static objects limit moves of Ghosts and a player. 

When a game starts, ghosts are located in the ghost house and within some time ghosts go out from the ghost house one by one.

When a game starts, Pacman is located in southern part of the maze and seperated from ghosts.



POLYMORPHISM:

1. GameObject is an abstract class as an interface for walls, ghost house, points, boosters, fruits.

It must help to work with ncurses library, as printing objects to screen and removing some of them.

2. Controls is an abstract class as an interface for a player and ghosts.

It must help to move them move around the maze, as well as booster activation of a pacman.

