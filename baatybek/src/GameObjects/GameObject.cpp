#include "GameObject.h"

/**
 * Constructor
 * @param[in] x is a horizontal coordinate vale on ncurses window
 * @param[in] y is a vertical coordinate vale on ncurses window
 * @param[in] type is enum GameObjectType instance: CWall, CDot, CBoost, CFruit
 */
GameObject::GameObject ( int x, int y, GameObjectType type ) : x (x), y (y), type (type), eaten(false) {
}
/**
 * Method returns GameObjectType::type value, which is set in the constructor
 */
GameObjectType GameObject:: getGameObjectType () const {
    return type;
}

