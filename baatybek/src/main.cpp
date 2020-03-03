#include <fstream>
#include "Game/GameEngine.h"

using namespace std;

int main() {

    GameEngine newGame;

    ofstream outFile;
    outFile.open("./src/Files/log.txt", ios::binary | ios::out );
    if(!outFile) cout << "Cannot open log.txt file" << endl;
    outFile << "[MAIN]: New object GameEngine created" << endl;

    newGame.play();
    return 0;
}