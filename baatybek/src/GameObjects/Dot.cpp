#include "Dot.h"

/**
 * Construtor
 * @param[in] x is a horizontal coordinate vale on ncurses window
 * @param[in] y is a vertical coordinate vale on ncurses window
 * @param[in] type is enum TypeDot::Dot for identification of the class
 **/
Dot::Dot ( int x, int y ) : PacDot ( x, y, CDot ) {
}

/**
 * Method prints game object on a ncurses window
 * @param[in] win1dow ncurses object displays the game flow on a terminal
 */
void Dot::draw ( WINDOW * window ) {
    wattron(window, A_BOLD);
    eaten ? mvwprintw(window, y, x, " ") : mvwprintw(window, y, x, ".");
    wattroff(window, A_BOLD);
}
/**
 * Method return number of points, which corresponds for a specific pac-dot
 */
int Dot::givePoints () const {
    return eaten ? 0 : 10;
} 
/**
 * Copy constuctor
 */
Dot * Dot::clone() && {
    return new Dot ( move ( * this ) );
}