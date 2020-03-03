#ifndef PACMAN_CPACMAN_H
#define PACMAN_CPACMAN_H

#include <iostream>
#include <map>
#include "../GameObjects/GameObject.h"
#include "DynamicObject.h"

using namespace std;

/**
 * @brief CPacman represents pacman
 */
class CPacman : public DynamicObject {
    bool alive;
    int lives;
    int score;
    int candies;
public:
    /**
     * Construtor
     */
    CPacman ();
    /**
     * Assignment operator
     */
    CPacman & operator = ( const CPacman & other );
    /**
     * Method resets pacman and subtructs from pacman's lives
     */
    virtual void kill (  WINDOW * mazeWin  ) override;
    /**
     * Method tells if pacman is alive.
     */
    bool is_alive () const;
    /**
     * Method implements eat an object by a pacman
     * @param[in] gameObject, gameObjects on the map: Wall, PacDots
     * @param[in] window, ncurses window
     */
    GameObjectType eat (  const map< pair<int, int>, shared_ptr<GameObject> > & gameObject, WINDOW * window  );
    /**
     * Method prints each move to the ncurses window
     * @param[in] window ncurses window where the gameflow is
     */
    virtual void update ( WINDOW * window ) const override;
    /**
     * Method returns lives value
     */
    int getLives () const ;
    /**
     * Method sets up a pacman for a game
     */
    void setUp ();
    /**
     * Method returns score value
     */
    int getScore () const;
    /**
     * Method increases score value value by inscrease
     * @param[in] inscrease, a value by which score should be increased
     */
    void increaseScore ( int inscrease );
    /**
     * Method resets lives and score values
     */
    void reset ();
    /**
     * Method set candies value
     * @param[in] aCandy, value to set candies
     */
    void setCandies ( int aCandy );

    /**
     * Method returns value of candies
     */
     int getCandyScore () const ;
};


#endif //PACMAN_CPACMAN_H
