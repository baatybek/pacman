#ifndef PACMAN_DYNAMICOBJECT_H
#define PACMAN_DYNAMICOBJECT_H

#include "../GameObjects/Wall.h"
#include <iostream>
#include <memory>
#include <map>
#include <ncurses.h>
#include <vector>

using namespace std;

/**
 * directions to move for a player or a ghosts
 */
enum Direction { UP, DOWN, LEFT, RIGHT };

/** @brief Controls class is an abstact class for moving objects
 */


class DynamicObject {
protected:
    /**
     * init_coords: initial coordinate values x and y on ncurses window of a player or a ghost
     */
    pair < int, int > init_coords;
    /**
     * prev_coords: previous coordinate values x and y on ncurses window of a player or a ghost
     */
    pair < int, int > prev_coords;
    /**
     * coords: current coordinate values x and y on ncurses window of a player or a ghost
     */
    pair < int, int > coords;
    /**
     * next_coords: next coordinate values x and y on ncurses window of a player or a ghost
     */
    pair < int, int > next_coords;
    /**
     * Direction where DynamicObject is going.
     */
    Direction cur_dir;
    /**
     * Direction where DynamicObject is going.
     */
    Direction next_dir;
public:
    /**
     * Constructor
     */
    DynamicObject ();
    /**
     * Constructor with specified initial coordinates for a player or a ghost
     */
    DynamicObject ( int x, int y);
    /**
     * Destructor
     */
    virtual ~DynamicObject () = default;
    /**
     * Assignment operator
     */
    DynamicObject & operator = ( const DynamicObject & other );
    /**
     * Method  initializes coordinates of a dynamic object
     * @param[in] xy, pair of values x and y on a coordinate
     */
    void setInitCoords ( pair < int, int > xy );
    /**
     * Method returns value of xy coordinates
     */
    pair < int, int > getXY () const;
    /**
     * Method moves DynamicObject one tile to direction where it heads.
     * @param[in] dir, direction for a DynamicObject to head: LEFT, DOWN, UP, RIGHT
     */
    void moveDir ( Direction dir);
    /**
     * Abstract method for killing a DynamicObject
     */
    virtual void kill ( WINDOW * mazeWin ) = 0;
    /**
     * Method moves DynamicObject one tile to direction where it heads.
     * @param[in] dir, direction for a DynamicObject to head: LEFT, DOWN, UP, RIGHT
     */
    bool move ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject );
    /**
     * Virtual method for printing each move to the ncurses window
     * @param[in] window ncurses window where the gameflow is
     */
    virtual void update ( WINDOW * window ) const = 0;

};


#endif //PACMAN_DYNAMICOBJECT_H
