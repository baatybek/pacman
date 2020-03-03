#ifndef PACMAN_CGHOSTMANAGER_H
#define PACMAN_CGHOSTMANAGER_H

#include "CPacman.h"
#include "DynamicObject.h"
#include "CGhost.h"
#include "CGhostEasy.h"
#include "CGhostHard.h"
#include "../GameObjects/GameObject.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <ncurses.h>
using namespace std;

/**
 * @brief CGhostManager manipulates with a vector of Ghosts
 **/
class CGhostManager {
    long long int timer;
    pair<int , int> init_coords;
    vector<shared_ptr<CGhost>> ghosts;
    string difficulty;
public:
    /**
     * Construtor
     */
    CGhostManager ();
    /**
     * Destructor
     */
    ~CGhostManager ();
    /**
     * Method setInitXY sets initial coordinates for a vector
     * @param[in] x is a value of x coordinate
     * @param[in] y is a value of y coordinate
     */
    void setInitXY ( int x, int y);
    /**
     * Method setDifficulty sets difficulty of ghosts
     * @param[in] difficulty is a value of to be set on CGhostManager::difficulty { Easy, Hard, Medium }
     */
    void setDifficulty ( string difficulty );
    /**
     * Method initilizes ghosts for a game
     */
    void setUp ();
    /**
     * Method adds a ghost to a vector of ghosts
     * @param[in] ghost, value ghost to be added to the vector
     */
    void addNewGhost ( CGhost && ghost );
    /**
     * Method simulates behaviour of ghosts
     * @param[in] gameObject, map of game objects  for interaction with ghosts
     * @param[in] pacman, pointer to a pacman for interaction with ghosts
     * @param[in] window, ncurses window to print on a window
     */
    void simulate ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject , CPacman * pacman, WINDOW * window );
    /**
     * Method sets frightened to true for all ghosts
     */
    void frightenedOn ();
    /**
     * Method sets frightened to false for all ghosts if timer passed or something else
     */
    void frightenedOff ();
    /**
     * Method  kills all the ghosts
     */
    void kill( WINDOW * mazeWin );
};


#endif //PACMAN_CGHOSTMANAGER_H
