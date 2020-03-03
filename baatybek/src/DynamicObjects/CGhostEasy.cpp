#include "CGhostEasy.h"

/**
 * Construtor
 */
CGhostEasy::CGhostEasy () {
}
/**
 * Construtor
 * @param[in] x, x coordinate value
 * @param[in] y, y coordinate value
 */
CGhostEasy::CGhostEasy ( int x, int y ) : CGhost ( x, y){
}
/**
 * Virtual method for a simulation of a ghost movement around the maze
 * @param[in] gameObject, gameObjects on the map: Wall, PacDots
 * @param[in] window, ncurses window
 * @param[in] pacman, pointer to the pacman for an intercation with a ghosts
 */
bool CGhostEasy::simulate ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject , CPacman * pacman, WINDOW * window ) {
    switch (cur_dir) {
        case UP:
            moveComboUp(gameObject);
            break;
        case DOWN:
            moveComboDown(gameObject);
            break;
        case LEFT:
            moveComboLeft(gameObject);
            break;
        case RIGHT:
            moveComboRight(gameObject);
            break;
        default:
            break;
    }
    update(window);

    if( ! isFrightened() && pacman->getXY() == coords ) {
        pacman->kill( window );
        return true;
    }

    if( isFrightened() && pacman->getXY() == coords ) {
        kill(window);
        pacman->increaseScore(200);
    }
    return false;
}
