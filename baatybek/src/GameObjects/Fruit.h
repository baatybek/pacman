#ifndef PACMAN_FRUIT_H
#define PACMAN_FRUIT_H

#include "PacDot.h"

class Fruit : PacDot {
    bool on;
    int timer;
public:
    /**
     * Construtor
     * @param[in] x is a horizontal coordinate vale on ncurses window
     * @param[in] y is a vertical coordinate vale on ncurses window
     * @param[in] type is enum TypeFruit::Fruit for identification of the class
     **/
    Fruit ( int x, int y );
    /**
     * Method prints game object on a ncurses window
     * @param[in] win1dow ncurses object displays the game flow on a terminal
     */
    virtual void draw ( WINDOW * window ) override;
    /**
     * Method removes gameobject from the window
     * @param[in] win1dow ncurses object displays the game flow on a terminal
     */
    void unDraw ( WINDOW * window );

    /**
     * Method return number of points, which corresponds for a specific pac-dot
     */
    virtual int givePoints () const override;
    /**
     * Copy construtor
     */
    virtual Fruit * clone ( ) && override {
        return new Fruit ( move ( * this ) );
    }
};


#endif //PACMAN_FRUIT_H
