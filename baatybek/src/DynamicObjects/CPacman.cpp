#include "CPacman.h"

/**
 * Construtor
 */
CPacman::CPacman () :  alive(true), lives (3), score (0) {
}
/**
 * Assignment operator
 */
CPacman & CPacman::operator = ( const CPacman & other ) {
    lives = other.lives;
    alive = other.alive;
    score = other.score;
    return * this;
}
/**
 * Method resets pacman and subtructs from pacman's lives
 */
void CPacman::kill ( WINDOW * mazeWin  ) {
    lives --;
    alive = false;
    prev_coords = coords;
    setInitCoords(init_coords);
    update(mazeWin);
}
/**
 * Method tells if pacman is alive.
 *
 */
bool CPacman::is_alive () const {
    return alive;
}
/**
 * Method returns lives value
 */
int CPacman::getLives () const  {
    return lives;
}
/**
 * Method prints each move to the ncurses window
 * @param[in] window ncurses window where the gameflow is
 */
void CPacman::update ( WINDOW * window ) const {

    mvwprintw(window, prev_coords.second, prev_coords.first, " ");

    switch ( cur_dir )
    {
        case LEFT:
            mvwprintw(window, coords.second, coords.first, ">");
            break;
        case RIGHT:
            mvwprintw(window, coords.second, coords.first, "<");
            break;
        case UP:
            mvwprintw(window, coords.second, coords.first, "v");
            break;
        case DOWN:
            mvwprintw(window, coords.second, coords.first, "^");
            break;
    }
}

/**
 * Method sets up a pacman for a game
 */
void CPacman::setUp () {
    coords = init_coords;
    alive = true;
}

/**
 * Method implements eat an object by a pacman
 * @param[in] gameObject, gameObjects on the map: Wall, PacDots
 * @param[in] window, ncurses window
 */
GameObjectType CPacman::eat (  const map< pair<int, int>, shared_ptr<GameObject> > & gameObject, WINDOW * window  ) {

    GameObjectType type = CDefault;
    auto objectType = gameObject.find( coords );

    if( objectType == gameObject.end() )
        return type;

    type = objectType->second->getGameObjectType();
    int eaten_score = objectType->second->eat(window);
    score = score + eaten_score;
    if(eaten_score == 10 || eaten_score == 50)
        candies --;
    return type;
}
/**
 * Method returns score value
 */
int CPacman::getScore () const {
    return score;
}
/**
 * Method increases score value value by inscrease
 * @param[in] inscrease, a value by which score should be increased
 */
void CPacman::increaseScore ( int inscrease ) {
    score += inscrease;
}

void CPacman::reset () {
    lives = 3;
    score = 0;
}
/**
 * Method set candies value
 */
void CPacman::setCandies ( int aCandy ) {
    candies = aCandy;
}


/**
 * Method returns value of candies
 */
int CPacman::getCandyScore () const  {
    return candies;
}