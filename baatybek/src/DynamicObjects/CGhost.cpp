#include "CGhost.h"

/**
 * Construtor
 */
CGhost::CGhost () {
}
/**
 * Constructor with specified initial coordinates for a ghost
 * @param[in] x, x coordinate on ncurses window
 * @param[in] y, y coordinate on ncurses window
 */
CGhost::CGhost ( int x, int y ) : DynamicObject ( x, y), frightened ( false ), frightenedTimer ( 0 ) {
}
/**
 * Method returns value of frightened
 */
bool CGhost::isFrightened () const {
    return frightened;
}
/**
 * Method prints each move to the ncurses window
 * @param[in] window ncurses window where the gameflow is
 */
void CGhost::update ( WINDOW * window ) const {
    mvwprintw(window, prev_coords.second, prev_coords.first, " ");
    if( frightened )
        wattron ( window, A_REVERSE);
    mvwprintw(window, coords.second, coords.first, "M");
    wattroff(window, A_REVERSE);
}
/**
 * Method kills the ghost
 */
void CGhost::kill (  WINDOW * mazeWin  ) {
    prev_coords = coords;
    coords = init_coords;
    frightenedTimer = 100;
    frightenedModeOff ();
    update(mazeWin);
}
/**
 * Method sets frightened to true
 */
void CGhost::frightenedModeOn () {
    frightenedTimer = 0;
    frightened = true;
}
/**
 * Method sets frightened to false
 */
void CGhost::frightenedModeOff () {
    if(frightened)
    {
        frightenedTimer++;
        if(frightenedTimer == 100) {
            frightened = false;
            frightenedTimer = 0;
        }
    }
}
/**
 * Method moves a ghost in combination 1
 * @param[in] gameObject, gameObjects on the map: Wall, PacDots
 */
void CGhost::moveComboUp ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject ) {
    moveDir(UP);
    if( move ( gameObject ))
        return;
    moveDir(LEFT);
    if( move ( gameObject ))
        return;
    moveDir(RIGHT);
    if( move ( gameObject ))
        return;
    moveDir(DOWN);
    if( move ( gameObject ))
        return;

}
/**
 * Method moves a ghost in combination 2
 * @param[in] gameObject, gameObjects on the map: Wall, PacDots
 */
void CGhost::moveComboDown ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject ) {
    moveDir(DOWN);
    if( move ( gameObject ))
        return;
    moveDir(RIGHT);
    if( move ( gameObject ))
        return;
    moveDir(LEFT);
    if( move ( gameObject ))
        return;
    moveDir(UP);
    if( move ( gameObject ))
        return;
}
/**
 * Method moves a ghost in combination 3
 * @param[in] gameObject, gameObjects on the map: Wall, PacDots
 */
void CGhost::moveComboRight ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject ) {
    moveDir(RIGHT);
    if( move ( gameObject ))
        return;
    moveDir(UP);
    if( move ( gameObject ))
        return;
    moveDir(DOWN);
    if( move ( gameObject ))
        return;
    moveDir(LEFT);
    if( move ( gameObject ))
        return;
}
/**
 * Method moves a ghost in combination 4
 * @param[in] gameObject, gameObjects on the map: Wall, PacDots
 */
void CGhost::moveComboLeft ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject ) {
    moveDir(LEFT);
    if( move ( gameObject ))
        return;
    moveDir(DOWN);
    if( move ( gameObject ))
        return;
    moveDir(UP);
    if( move ( gameObject ))
        return;
    moveDir(RIGHT);
    if( move ( gameObject ))
        return;
}
