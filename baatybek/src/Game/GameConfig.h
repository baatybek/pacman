#ifndef PACMAN_GAMECONFIG_H
#define PACMAN_GAMECONFIG_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

/** @brief GameConfig class helps to get data from a file, to configure map, speed of the game and diffuclty of the game
 */
class GameConfig {
    /**
     * diffuclty stores, ghost diffuclty specified by the user
     */
    string diffuclty;
    /**
     * vector of string to store static and dynamic objects in the maze
     */
    vector<string> maze_objects;
public:
    /**
     * Constructor with a default map
     */
    GameConfig ();
    /**
     * Destructor
     */
    ~GameConfig ();

    /**
     * Method to load maze from a file
     */
    bool loadMap (string fileName);
    /**
     * Method to load difficulty of the game from a file
     */
    bool loadDifficulty(string fileName);
    /**
     * method returns vector of strings, each character correspond to object on ncurses window
     */
    vector<string> getMazeObjects () const;
    /**
     * method returns vector of static and dynamic objects in a maze
     */
    string getGameDiff () const;
};


#endif //PACMAN_GAMECONFIG_H
