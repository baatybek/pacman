#ifndef PACMAN_SETUPMENU_H
#define PACMAN_SETUPMENU_H


#include "../Game/CWindow.h"
#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>

using namespace std;

/**
 * Setup menu options
 */
enum SetUpMenuChoice { Play, Info, Difficulty, Exit};

/**
 * KEY_UP2 equivalent ASCII value for 'w'
 * KEY_DOWN2 equivalent ASCII value for 's'
 */
const int KEY_UP2 = 119;
const int KEY_DOWN2 = 115;

/** @brief SetUpMenu class is class that responsible for very first interaction with user
 *         it runs initial menu, modifies game difficulty, game speed, provided by user
 */
class SetUpMenu {
public:
    /**
     * CWindow object to handle ncurses
     */
    CWindow window;
    /**
     * Constructor
     */
    SetUpMenu () {
    }

    /**
     * Destructor
     */
    ~SetUpMenu () {
    }

    /**
     * Method implements a start up menu of the program
     */
    SetUpMenuChoice runMenu ();

    /**
     * Method shows info about the game
     */
    void showInfo ();
    /**
     * Method sets up diffuclty of the game about tMainMenu::he game
     */
    void setDificulty ();
    /**
     * Method sets up diffuclty of the game about the game
     */
    void setSpeed ();
    /**
     * Method loads text from a file, which is information about the game
     */
    vector<string>  readFromFile ();
    /**
     * Method writes difficulty level to a file
     */
    void writeToFile ( string text, string filename  );
};



#endif //PACMAN_SETUPMENU_H
