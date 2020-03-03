#ifndef PACMAN_CINPUT_H
#define PACMAN_CINPUT_H

#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum CInputEnum { C_UP, C_DOWN, C_LEFT, C_RIGHT, C_ESC };

/** @brief CInput class handles inputs to interact with a pacman
 */
class CInput {
public:
    /**
     * current input, entered by user
     */
    CInputEnum input;
    /**
     * last input, entered by user
     */
    CInputEnum lastinput;
    /**
     * Construtor
     */
    CInput ();
    /**
     * Destructor
     */
    ~CInput ();
    /**
     * Method checks if key has been hit or not
     */
    int kbhit (void);
    /**
     * Method sets input value
     */
    void setInput (CInputEnum key);
    /**
     * Method returns current key entered by user
     */
    CInputEnum getInput () ;
    /**
     * Method returns last key entered by user
     */
    CInputEnum getLastInput () ;
};

#endif //PACMAN_CINPUT_H
