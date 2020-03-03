#ifndef PACMAN_CGHOST_H
#define PACMAN_CGHOST_H

#include <iostream>
#include <map>
#include <memory>
#include "DynamicObject.h"
#include "CPacman.h"
#include "../GameObjects/GameObject.h"

using namespace  std;

class CGhost : public DynamicObject {
    bool frightened;
    int  frightenedTimer;
public:
    /**
     * Construtor
     */
    CGhost ();
    /**
     * Constructor with specified initial coordinates for a ghost
     * @param[in] x, x coordinate on ncurses window
     * @param[in] y, y coordinate on ncurses window
     */
    CGhost ( int x, int y );

    /**
     * Copy construtor
     */
    virtual CGhost * clone ( ) const & = 0;
    /**
     * Copy construtor
     */
    virtual CGhost * clone ( ) && = 0;
    /**
     * Method returns value of frightened
     */
    bool isFrightened () const;
    /**
     * Method sets frightened to true
     */
    void frightenedModeOn ();
    /**
     * Method sets frightened to false
     */
    void frightenedModeOff ();
    /**
     * Method prints each move to the ncurses window
     * @param[in] window ncurses window where the gameflow is
     */
    virtual void update ( WINDOW * window ) const override;
    /**
     * Method kills the ghost
     */
    virtual void kill ( WINDOW * mazeWin ) override;
    /**
     * Method moves a ghost in combination 1
     * @param[in] gameObject, gameObjects on the map: Wall, PacDots
     */
    void moveComboUp ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject );
    /**
     * Method moves a ghost in combination 2
     * @param[in] gameObject, gameObjects on the map: Wall, PacDots
     */
    void moveComboDown ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject );
    /**
     * Method moves a ghost in combination 3
     * @param[in] gameObject, gameObjects on the map: Wall, PacDots
     */
    void moveComboRight ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject );
    /**
     * Method moves a ghost in combination 4
     * @param[in] gameObject, gameObjects on the map: Wall, PacDots
     */
    void moveComboLeft ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject );
    /**
     * Virtual method for a simulation of a ghost movement around the maze
     * @param[in] gameObject, gameObjects on the map: Wall, PacDots
     * @param[in] window, ncurses window
     * @param[in] pacman, pointer to the pacman for an intercation with a ghosts
     */
    virtual bool simulate ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject , CPacman * pacman, WINDOW * window ) = 0;
};


#endif //PACMAN_CGHOST_H
