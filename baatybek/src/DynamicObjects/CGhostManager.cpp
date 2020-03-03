#include "CGhostManager.h"
/**
 * Construtor
 */
CGhostManager::CGhostManager () : timer ( 0 ) {
}
/**
 * Destructor
 */
CGhostManager::~CGhostManager () {
}
/**
 * Method setInitXY sets initial coordinates for a vector
 * @param[in] x is a value of x coordinate
 * @param[in] y is a value of y coordinate
 */
void CGhostManager::setInitXY ( int x, int y) {
    init_coords = make_pair(x, y);
}
/**
 * Method setDifficulty sets difficulty of ghosts
 * @param[in] difficulty is a value of to be set on CGhostManager::difficulty { Easy, Hard, Medium }
 */
void CGhostManager::setDifficulty ( string difficulty ) {
    CGhostManager::difficulty = difficulty;
}
/**
 * Method initilizes ghosts for a game
 */
void CGhostManager::setUp () {
    ghosts.erase(ghosts.begin(), ghosts.end());

    if(difficulty == "Easy") {
        for( int i = 0; i < 3; i ++)
        {
            addNewGhost( CGhostEasy ( init_coords.first , init_coords.second ) );
        }
        addNewGhost( CGhostHard ( init_coords.first , init_coords.second ) );
    }

    if(difficulty == "Medium") {
        for( int i = 0; i < 2; i ++)
        {
            addNewGhost( CGhostEasy ( init_coords.first , init_coords.second ) );
        }
        for( int i = 0; i < 2; i ++)
        {
            addNewGhost( CGhostHard ( init_coords.first , init_coords.second ) );
        }
    }

    if(difficulty == "Hard") {
        for( int i = 0; i < 3; i ++)
        {
            addNewGhost( CGhostHard ( init_coords.first , init_coords.second ) );
        }
        addNewGhost( CGhostEasy ( init_coords.first , init_coords.second ) );
    }

    for(auto i : ghosts ) {
        i->setInitCoords(init_coords);
    }

    frightenedOff ();
}
/**
 * Method adds a ghost to a vector of ghosts
 * @param[in] ghost, value ghost to be added to the vector
 */
void CGhostManager::addNewGhost ( CGhost && ghost ) {
    ghosts.emplace_back( shared_ptr <CGhost> ( move (ghost).clone() ));
}
/**
 * Method simulates behaviour of ghosts
 * @param[in] gameObject, map of game objects  for interaction with ghosts
 * @param[in] pacman, pointer to a pacman for interaction with ghosts
 * @param[in] window, ncurses window to print on a window
 */
void CGhostManager::simulate ( const map< pair<int, int>, shared_ptr<GameObject> > & gameObject , CPacman * pacman, WINDOW * window ) {
    if(timer >= 20 )
        if( ghosts[0]->simulate( gameObject, pacman, window ))
            return;
    if(timer >= 40 )
        if( ghosts[1]->simulate( gameObject, pacman, window ))
            return;
    if(timer >= 60 )
        if( ghosts[2]->simulate( gameObject, pacman, window ))
            return;
    if(timer >= 80 )
        if( ghosts[3]->simulate( gameObject, pacman, window ))
            return;
    if(timer == 100000)
        timer = 20;

    for ( auto i : ghosts )
    {
        if(i->getXY() == pacman->getXY())
        {
            pacman->kill(window);
            return;
        }
    }

    if(pacman->getXY().second < ghosts[0]->getXY().second )
        ghosts[0]->moveDir(UP);

    if(pacman->getXY().second > ghosts[1]->getXY().second )
        ghosts[1]->moveDir(UP);

    if(pacman->getXY().first < ghosts[2]->getXY().first )
        ghosts[2]->moveDir(LEFT);

    if(pacman->getXY().first > ghosts[3]->getXY().first )
        ghosts[3]->moveDir(RIGHT);

    frightenedOff ();
    timer ++;
}
/**
 * Method sets frightened to true for all ghosts
 */
void CGhostManager::frightenedOn () {
    for(auto i : ghosts )
    {
        i->frightenedModeOn();
    }
}
/**
 * Method sets frightened to false for all ghosts if timer passed or something else
 */
void CGhostManager::frightenedOff () {
    for(auto i : ghosts )
    {
        i->frightenedModeOff();
    }
}

/**
 * Method  kills all the ghosts
 */
void CGhostManager::kill(  WINDOW * mazeWin  ) {
    for(auto i : ghosts )
    {
        i->kill(mazeWin);
    }
}

