#ifndef PACMAN_PACDOTS_H
#define PACMAN_PACDOTS_H

#include "GameObject.h"
#include <ncurses.h>

class PacDot : public GameObject {
public:
    /**
     * Constructor
     * @param[in] x is a horizontal coordinate vale on ncurses window
     * @param[in] y is a vertical coordinate vale on ncurses window
     * @param[in] type is enum GameObjectType instance: CDot, CBoost, CFruit
     */
    PacDot ( int x, int y, GameObjectType type);

    /**
     * Method return number of points, which corresponds for a specific pac-dot
     */
    virtual int givePoints () const  = 0;
    /**
     * Method hides pac-dots from ncurses window
     * @param[in] window is an ncurses window to show the progress
     */
    virtual int eat ( WINDOW * window ) override;
};


#endif //PACMAN_PACDOTS_H