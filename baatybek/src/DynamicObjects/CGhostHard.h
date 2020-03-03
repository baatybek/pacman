#ifndef PACMAN_CGHOSTHARD_H
#define PACMAN_CGHOSTHARD_H

#include "CGhost.h"
#include "CPacman.h"
#include "../GameObjects/GameObject.h"

class CGhostHard : public CGhost  {
public:
    /**
     * Construtor
     */
    CGhostHard ();
    /**
     * Construtor
     * @param[in] x, x coordinate value
     * @param[in] y, y coordinate value
     */
    CGhostHard ( int x, int y );
    /**
     * Destrutor
     */
    ~CGhostHard () = default;
    /**
     * Virtual method for a simulation of a ghost movement around the maze
     * @param[in] gameObject, gameObjects on the map: Wall, PacDots
     * @param[in] window, ncurses window
     * @param[in] pacman, pointer to the pacman for an intercation with a ghosts
     */
    virtual bool simulate ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject , CPacman * pacman, WINDOW * window ) override ;
    /**
     * Method simulates chasing a pacman by a ghost
     */
    bool chase  ( CPacman * pacman );
    /**
     * Method simulates a ghost escaping from a pacman
     */
    bool escape ( CPacman * pacman );
    /**
     * Copy constructor
     */
    virtual CGhostHard * clone ( ) const & override  {
        return new CGhostHard ( * this );
    }
    /**
     * Copy constructor
     */
    virtual CGhostHard * clone ( ) && override {
        return new CGhostHard ( std::move ( * this ) );
    }

};


#endif //PACMAN_CGHOSTHARD_H
