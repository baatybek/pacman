#ifndef PACMAN_POWERPELLET_H
#define PACMAN_POWERPELLET_H

#include "PacDot.h"

class PowerPellet : public PacDot {
public:
    /**
     * Construtor
     * @param[in] x is a horizontal coordinate vale on ncurses window
     * @param[in] y is a vertical coordinate vale on ncurses window
     * @param[in] type is enum TypePowerPellet::PowerPellet for identification of the class
     **/
    PowerPellet ( int x, int y );
    /**
     * Method prints game object on a ncurses window
     * @param[in] win1dow ncurses object displays the game flow on a terminal
     */
    virtual void draw ( WINDOW * window ) override;
    /**
     * Method return number of points, which corresponds for a specific pac-dot
     */
    virtual int givePoints () const override;
    /**
     * Copy construtor
     */
    virtual PowerPellet * clone ( ) && override {
        return new PowerPellet ( move ( * this ) );
    }
};


#endif //PACMAN_POWERPELLET_H
