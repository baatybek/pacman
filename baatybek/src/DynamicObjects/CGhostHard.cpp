#include "CGhostHard.h"
/**
 * Construtor
 */
CGhostHard::CGhostHard () {
}
/**
 * Construtor
 * @param[in] x, x coordinate value
 * @param[in] y, y coordinate value
 */
CGhostHard::CGhostHard ( int x, int y ) : CGhost (x, y){
}
/**
 * Virtual method for a simulation of a ghost movement around the maze
 * @param[in] gameObject, gameObjects on the map: Wall, PacDots
 * @param[in] window, ncurses window
 * @param[in] pacman, pointer to the pacman for an intercation with a ghosts
 */
bool CGhostHard::simulate ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject , CPacman * pacman, WINDOW * window ) {
    if( ! isFrightened() && chase( pacman ) &&  move(gameObject)) {
        update(window);
        if( pacman->getXY() == coords ) {
            pacman->kill(window);
            return true;
        }
        return false;
    }

    if( isFrightened() && escape ( pacman ) &&  move(gameObject)) {
        update(window);
        if( pacman->getXY() == coords ) {
            kill(window);
            pacman->increaseScore(200);
        }
        return false;
    }

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

    if( pacman->getXY() == coords ) {
        pacman->kill(window);
        return true;
    }
    return false;
}
/**
 * Method simulates chasing a pacman by a ghost
 */
bool CGhostHard::chase  ( CPacman * pacman ) {
    if( pacman->getXY().first == coords.first ) {
        if(coords.second <= pacman->getXY().second )
            moveDir(DOWN);
        else
            moveDir(UP);

        return true;
    }

    if( pacman->getXY().second == coords.second ) {
        if(coords.first <= pacman->getXY().first )
            moveDir(RIGHT);
        else
            moveDir(LEFT);

        return true;
    }
    return false;
}
/**
 * Method simulates a ghost escaping from a pacman
 */
bool CGhostHard::escape ( CPacman * pacman ) {
    if( pacman->getXY().first == coords.first ) {
        if(coords.second <= pacman->getXY().second )
            moveDir(UP);
        else
            moveDir(DOWN);

        return true;
    }

    if( pacman->getXY().second == coords.second ) {
        if(coords.first <= pacman->getXY().first )
            moveDir(LEFT);
        else
            moveDir(RIGHT);

        return true;
    }
    return false;
}
