#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H

#include "GameObject.h"
#include <ncurses.h>

using namespace std;

/**
 * @brief Wall class represent static object on the maze which doesnt let pacman or ghosts to pass through them
 */
class Wall : public GameObject {
    bool visible;
public:
    /**
     * Constructor
     * @param[in] x is a horizontal coordinate vale on ncurses window
     * @param[in] y is a vertical coordinate vale on ncurses window
     * @param[in] isVisible is a boolean flag to print walls as visible or invisible
     */
    Wall ( int x, int y,  bool isVisible );
    /**
     * Method prints game object on a ncurses window
     * @param[in] win1dow ncurses object displays the game flow on a terminal
     */
    virtual void draw ( WINDOW * window ) override;
    /**
     * Copy construtor
     */
    virtual Wall * clone ( ) && override;
     /**
     * Method hides pac-dots from ncurses window
     * @param[in] window is an ncurses window to show the progress
     */
    virtual int eat ( WINDOW * window ) override;
};


#endif //PACMAN_WALL_H