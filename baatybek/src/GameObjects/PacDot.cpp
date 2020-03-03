#include "PacDot.h"

/**
 * Constructor
 * @param[in] x is a horizontal coordinate vale on ncurses window
 * @param[in] y is a vertical coordinate vale on ncurses window
 * @param[in] type is enum GameObjectType instance: CDot, CBoost, CFruit
 */
PacDot::PacDot ( int x, int y, GameObjectType type) : GameObject ( x, y, type ) {
}

/**
 * Method hides pac-dots from ncurses window
 * @param[in] window is an ncurses window to show the progress
 */
int PacDot::eat ( WINDOW * window ) {
    int points = givePoints();
    if( ! eaten )
    {
        mvwprintw(window, y, x, " ");
        eaten = true;
    }
    return points;
}
