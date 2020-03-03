#ifndef PACMAN_CGHOSTEASY_H
#define PACMAN_CGHOSTEASY_H

#include "CGhost.h"
#include "CPacman.h"
#include "../GameObjects/GameObject.h"
#include <iostream>
#include <map>
#include <memory>

using namespace std;
/**
 * @brief  CGhostEasy represents easy ghost
 */
class CGhostEasy : public CGhost {
public:
    /**
     * Construtor
     */
    CGhostEasy ();
    /**
     * Destrutor
     */
    ~CGhostEasy () = default;
    /**
     * Construtor
     * @param[in] x, x coordinate value
     * @param[in] y, y coordinate value
     */
    CGhostEasy ( int x, int y );
    /**
     * Virtual method for a simulation of a ghost movement around the maze
     * @param[in] gameObject, gameObjects on the map: Wall, PacDots
     * @param[in] window, ncurses window
     * @param[in] pacman, pointer to the pacman for an intercation with a ghosts
     */
    virtual bool simulate ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject , CPacman * pacman, WINDOW * window ) override ;
    /**
     * Copy construtor
     */
    virtual CGhostEasy * clone () const & override  {
        return new CGhostEasy ( * this );
    }
    /**
     * Copy construtor
     */
    virtual CGhostEasy * clone () && override {
        return new CGhostEasy ( std::move ( * this ) );
    }
};


#endif //PACMAN_CGHOSTEASY_H
