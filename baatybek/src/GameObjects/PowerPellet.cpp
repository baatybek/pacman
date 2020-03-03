#include "PowerPellet.h"

/**
 * Construor
 * @param[in] x is a horizontal coordinate vale on ncurses window
 * @param[in] y is a vertical coordinate vale on ncurses window
 * @param[in] type is enum TypeDot::Dot for identification of the class
 **/
PowerPellet::PowerPellet ( int x, int y ) : PacDot ( x, y, CPowerPellet ) {
}
/**
 * Method prints game object on a ncurses window
 * @param[in] win1dow ncurses object displays the game flow on a terminal
 */
void PowerPellet::draw ( WINDOW * window ) {
    wattron( window, A_BLINK );
    eaten ? mvwprintw(window, y, x, " ") : mvwprintw(window, y, x, "*");
    wattroff( window, A_BLINK );
}
/**
 * Method return number of points, which corresponds for a specific pac-dot
 */
int PowerPellet::givePoints () const {
    return eaten ? 0 : 50;
}