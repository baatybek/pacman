#include "Fruit.h"

/**
 * Construtor
 * @param[in] x is a horizontal coordinate vale on ncurses window
 * @param[in] y is a vertical coordinate vale on ncurses window
 * @param[in] type is enum TypeFruit::Fruit for identification of the class
 **/
Fruit::Fruit ( int x, int y ) : PacDot ( x, y, CFruit ), on ( false ), timer ( 0 ) {
}
/**
 * Method prints game object on a ncurses window
 * @param[in] win1dow ncurses object displays the game flow on a terminal
 */
void Fruit::draw ( WINDOW * window ) {
    timer ++;
    if(timer == 100)
        on = true;
    if(timer == 200)
        on = false;
    if(timer == 300)
        on = false;

    if ( on )
    {
        wattron(window, A_BLINK);
        eaten ?  mvwprintw(window, y, x, " ") : mvwprintw(window, y, x, "F") ;
        wattroff(window, A_BLINK);
    }
}
/**
 * Method removes gameobject from the window
 * @param[in] win1dow ncurses object displays the game flow on a terminal
 */
void Fruit::unDraw ( WINDOW * window ) {
    mvwprintw(window, y, x, " ");
}
/**
 * Method return number of points, which corresponds for a specific pac-dot
 */
int Fruit::givePoints () const {
    return 200;
}