#include "Wall.h"

/**
 * Constructor
 * @param[in] x is a horizontal coordinate vale on ncurses window
 * @param[in] y is a vertical coordinate vale on ncurses window
 * @param[in] isVisible is a boolean flag to print walls as visible or invisible
 */
Wall::Wall ( int x, int y, bool isVisible ) : GameObject ( x , y, GameObjectType::CWall ), visible ( isVisible ) {
}
/**
 * Method prints game object on a ncurses window
 * @param[in] win1dow ncurses object displays the game flow on a terminal
 */
void Wall::draw ( WINDOW * window ) {
    if( visible )   wattron(window, A_REVERSE );
    mvwprintw(window, y, x, " ");
    wattroff(window, A_REVERSE);
}
/**
 * Copy construtor
 */
Wall * Wall::clone ( ) && {
    return new Wall ( move ( * this ) );
}

/**
* Method hides we can eat walls
* @param[in] window is an ncurses window to show the progress
*/
int Wall::eat ( WINDOW * window ) {
draw(window);
return 0;
}