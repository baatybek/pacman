#ifndef PACMAN_GAMEENGINE_H
#define PACMAN_GAMEENGINE_H

#include "CInput.h"
#include "../Menus/SetupMenu.h"
#include "CWindow.h"
#include "GameConfig.h"
#include "../Menus/GameMenu.h"
#include "../GameObjects/Dot.h"
#include "../GameObjects/Fruit.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/PacDot.h"
#include "../GameObjects/PowerPellet.h"
#include "../GameObjects/Wall.h"
#include "../DynamicObjects/CPacman.h"
#include "../DynamicObjects/CGhostManager.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <memory>
#include <sstream>

using namespace std;

/**
 * @brief GameEngine class for core logic of the game
 */
class GameEngine {
    map< pair<int, int> , shared_ptr < GameObject > > gameObjects;
    CGhostManager ghosts;
    CPacman cpacman;
    int gameSpeed;
    int candies;
    int mapHeight , mapWidth;
    CWindow window;
public:
    /**
     * Constructor
     */
    GameEngine ();
    /**
     * Destructor
     */
    ~GameEngine ();
    /**
     * Method implements game state interaction
     */
     void play ();

     /**
      * Method sets up everyything for the game
      */
     bool setUp ();
     /**
      * Method loads game objects
      */
     void loadGameObjects ( vector <string>  gameMap);
    /**
     * Method implements game
     */
     GameMenuOptions game ();
    /**
     * Method adds a gameobject to map of gameobjects
     * @param[in] xy x, y coordinate values on the ncurses window
     * @param[in] gameObject is current object to be added into map of gameobjects
     */
    void addGameObject ( pair< int, int> xy, GameObject && gameObject );
    /**
     * Method prints game objects on ncurses window
     */
    void drawMap () const;
};


#endif //PACMAN_GAMEENGINE_H
