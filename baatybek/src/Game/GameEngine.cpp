#include "GameEngine.h"
/**
 * Constructor
 */
GameEngine::GameEngine() {
}
/**
 * Destructor
 */
GameEngine::~GameEngine() {
    window.end();
}
/**
 * All the manipulation on Game States
 */
void GameEngine::play() {
    SetUpMenu startupmenu;
    cout << "[INFO]: Started Main Menu" << endl;
    while (1) {
        SetUpMenuChoice usermenuchoice = startupmenu.runMenu();
        refresh();
        if(usermenuchoice == Play) {
            while (1) {
                GameMenuOptions gamemenoptions = game ();
                if(gamemenoptions == CRestart)
                    continue;
                else if(gamemenoptions == CMainMenu )
                    break;
                else if(gamemenoptions == CExit )
                    return;
            }
        } else if( usermenuchoice == Info ) {
            continue;
        } else if( usermenuchoice == Difficulty ) {
            continue;
        } else if( usermenuchoice == Exit ) {
            break;
        }
    }
}
/**
 * Method implements game
 */
GameMenuOptions GameEngine::game () {
    if ( !setUp() ) {
        cout << "[ERROR]: Could not set up the game!" << endl;
        return CExit;
    }
    CInput input;
    GameMenu menu;
    while ( cpacman.getLives() != 0 && cpacman.getCandyScore() != 0)
    {
        drawMap();
        cpacman.setUp();
        ghosts.setUp();
        window.refresh();
        sleep(2);
        while ( cpacman.is_alive() ) {
            /**
             * User input to control pacman
             */
            switch (input.getInput()) {
                case C_UP:
                    cpacman.moveDir(UP);
                    cpacman.move(gameObjects);
                    break;
                case C_DOWN:
                    cpacman.moveDir(DOWN);
                    cpacman.move(gameObjects);
                    break;
                case C_LEFT:
                    cpacman.moveDir(LEFT);
                    cpacman.move(gameObjects);
                    break;
                case C_RIGHT:
                    cpacman.moveDir(RIGHT);
                    cpacman.move(gameObjects);
                    break;
                case C_ESC:
                    GameMenuOptions opt = menu.run(false, (int)mapWidth/2, mapHeight/4 + 2, window.screenWidth()*0.25 -3 , window.screenHeight()*0.30 + 4);
                    if(opt != CResume)
                        return opt;
                    input.setInput(input.getLastInput());
            }

            switch (cpacman.eat(gameObjects, window.getMazeWindow())) {
                case CPowerPellet:
                    ghosts.frightenedOn();
                    break;
                default:
                    break;
            }

            drawMap ();
            cpacman.update(window.getMazeWindow());
            ghosts.simulate(gameObjects, &cpacman, window.getMazeWindow() );
            window.updateInfoScreen(cpacman.getLives(), cpacman.getScore() );
            window.refresh();
            usleep(gameSpeed);
        }

        ghosts.kill(window.getMazeWindow());
        window.refresh();
    }

    stringstream ss;
    ss << cpacman.getScore();
    if(cpacman.getCandyScore() > 0)
        menu.setString("Game Over! Score = " + ss.str());
    else
        menu.setString("Winner! Score = " + ss.str());
    return menu.run(true, (int)mapWidth/2, mapHeight/4 + 2, window.screenWidth()*0.25 -3 , window.screenHeight()*0.30 + 4);
}
/**
 * Method sets up everyything for the game
 */
bool GameEngine::setUp() {
    GameConfig newGame;
    if( !newGame.loadMap("./examples/map.txt") ) {
        cout << "[ERROR]: Could not load the map at ./examples/map.txt" << endl;
        return false;
    }

    string difficulty;
    if( !newGame.loadDifficulty("./examples/difficulty.txt")) {
        cout << "[INFO]: Could not load the difficulty at ./examples/difficulty.txt" << endl;
        difficulty = "Medium";
    }else {
        difficulty = newGame.getGameDiff();
    }

    if(difficulty == "Easy") {
        gameSpeed = 150000;
    }else if ( difficulty == "Medium") {
        gameSpeed = 100000;
    }else if ( difficulty == "Hard"){
        gameSpeed = 80000;
    } else {
        gameSpeed = 100000;
    }
    cpacman.reset();
    ghosts.setDifficulty(difficulty);
    window.start();
    gameObjects.erase(gameObjects.begin(), gameObjects.end());
    loadGameObjects(newGame.getMazeObjects());
    window.initWindows(mapWidth, mapHeight);
    window.refresh();
    return true;
}
/**
 * Method loads game objects
 */
void GameEngine::loadGameObjects ( vector <string> gameMap) {
    mapHeight = (int) gameMap.size();
    mapWidth = 0;
    candies = 0;
    for( int i = 0; i < (int) gameMap.size(); ++ i )
    {
        for ( int j = 0; j < (int) gameMap[i].size(); ++ j)
        {
            mapWidth = max(mapWidth , (int) gameMap[i].size());
            switch (gameMap[i][j]) {
                case '#':
                    addGameObject(make_pair(j, i), Wall(j, i, true));
                    break;
                case '|':
                    addGameObject(make_pair(j, i), Wall(j, i, false));
                    break;
                case '.':
                    addGameObject(make_pair(j, i), Dot(j, i));
                    candies++;
                    break;
                case '*':
                    addGameObject(make_pair(j, i), PowerPellet(j, i));
                    candies++;
                     break;
                case 'P':
                    cpacman.setInitCoords(make_pair(j, i));
                    break;
                case 'G':
                    ghosts.setInitXY(j, i);
                    break;
                default:
                    break;
            }
        }
    }
    cpacman.setCandies(candies);
}

/**
 * Method adds a gameobject to map of gameobjects
 * @param[in] xy x, y coordinate values on the ncurses window
 * @param[in] gameObject is current object to be added into map of gameobjects
 */
void GameEngine::addGameObject ( pair< int, int> xy, GameObject && gameObject ) {
    gameObjects.emplace(xy, shared_ptr <GameObject> ( move (gameObject).clone() ));
}

/**
 * Method prints game objects on ncurses window
 */
void GameEngine::drawMap () const {
    for(auto i : gameObjects )
    {
        i.second->draw(window.getMazeWindow());
    }
}