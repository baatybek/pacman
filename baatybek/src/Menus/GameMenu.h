#ifndef PACMAN_GAMEMENU_H
#define PACMAN_GAMEMENU_H


#include "../Game/CWindow.h"
#include <ncurses.h>
#include <string>
using namespace std;
/**
 * Game menu options
 */
enum GameMenuOptions { CResume, CRestart, CMainMenu, CExit };

/** @brief GameMenu class represents menu when the game has already started.
 *         it's called, when user clicked ESC, lost the game or won the game
 */
class GameMenu {
    string text;
public:
    /**
     * CWindow object to handle ncurses
     */
    CWindow window;
    /**
     * Constructor
     */
    GameMenu () {

    }

    /**
     * Destructor
     */
    ~GameMenu () {
    }
    /**
     * Method sets string values to a text
     * @param[in] str a string value to be set to a text
     */
    void setString ( string str );
    /**
     * Method implements menu
     */
    GameMenuOptions run ( bool end, int x, int y, int startx, int starty );

};


#endif //PACMAN_GAMEMENU_H
