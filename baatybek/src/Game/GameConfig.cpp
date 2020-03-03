#include "GameConfig.h"

/**
 * Constructor with a default map
 */
GameConfig::GameConfig (){
}
/**
 * Destructor
 */
GameConfig::~GameConfig () {
}

/**
 * Method to load maze from a  file
 */
bool GameConfig::loadMap ( string fileName ) {
    /**
     * set up input stream
     */
    ifstream inFile;
    inFile.open(fileName, ios::binary | ios::in);
    /**
     * check for issues
     */
    if(!inFile) {
        return false;
    }
    /**
     * read the file line by line
     * and push back to a vector, maze_objects
     */
    string line;
    while(getline(inFile, line))
    {
        maze_objects.emplace_back(line);
        if(!inFile) {
            return false;
        }
    }
    /**
     * sucess !!!
     */
    return true;
}
/**
 * Method to load diffuclty of the game configured by the player from a file
 */
bool GameConfig::loadDifficulty(string fileName) {
    /**
     * set up input stream
     */
    ifstream inFile;
    inFile.open(fileName, ios::binary | ios::in);
    /**
     * check for issues
     */
    if(!inFile) return false;
    /**
     * read the file
     */
    inFile >> diffuclty;
    /**
     * check for issues
     */
    if(!inFile) return false;
    /**
     * sucess !!!
     */
    return true;
}
/**
 * method returns vector of static and dynamic objects in a maze
 */
vector<string> GameConfig::getMazeObjects () const {
    return maze_objects;
}
/**
 * method returns diffuclty of the game configured by the player
 */
string GameConfig::getGameDiff() const {
    return diffuclty;
}
