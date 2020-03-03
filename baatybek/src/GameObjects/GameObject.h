#ifndef PACMAN_GAMEOBJECT_H
#define PACMAN_GAMEOBJECT_H

#include <iostream>
#include <ncurses.h>


using namespace std;

enum GameObjectType { CWall, CDot, CPowerPellet, CFruit , CDefault };
/**
 * @brief GameObject is an abstarct class for classes Wall, Dot, Boost, Fruit
 */
class GameObject {
protected:
    int x, y;
    GameObjectType type;
    bool eaten;
public:
    /**
     * Constructor
     * @param[in] x is a horizontal coordinate vale on ncurses window
     * @param[in] y is a vertical coordinate vale on ncurses window
     * @param[in] type is enum GameObjectType instance: CWall, CDot, CBoost, CFruit
     */
    GameObject ( int x, int y, GameObjectType type );
    /**
     * Destructor
     */
    virtual ~GameObject () = default;
    /**
     * Copy construtor
     */
    virtual GameObject * clone ( ) && = 0;
    /**
     * Method returns GameObjectType::type value, which is set in the constructor
     */
    GameObjectType  getGameObjectType () const;
    /**
     * Method prints game object on a ncurses window
     * @param[in] window ncurses object displays the game flow on a terminal
     */
    virtual void draw ( WINDOW * window ) = 0;
    /**
     * Method hides pac-dots from ncurses window
     * @param[in] window is an ncurses window to show the progress
     */
    virtual int eat ( WINDOW * window ) = 0;
};


#endif //PACMAN_GAMEOBJECT_H