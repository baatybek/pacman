#include "SetupMenu.h"


/**
 * Method implements a start up menu of the program
 */
SetUpMenuChoice SetUpMenu::runMenu () {
     /**
     * init ncruses
     */
    window.start();

    /**
     * create a ncurses window for input
     */
    int menuWinWidth =  window.screenWidth() / 2;
    int menuWinHeight =  window.screenHeight() / 2;
    int startX = window.screenWidth() - window.screenWidth() * 3/4;
    int startY = window.screenHeight() - window.screenHeight()*3/4;
    WINDOW * menuWin = newwin(menuWinHeight, menuWinWidth, startY, startX);
    box(menuWin, 0, 0);
    refresh();
    wrefresh(menuWin);

    /**
     * enable arrow keys
     */
    keypad(menuWin, true);

    /**
     * initial menu contets
     */
    string menuOptions [4] = {"Play", "Info", "Set Difficulty", "Exit"};

    /**
     * variables for interaction with user and menu
     */
    int choice = 0, highlight = 0, enter = 10;
    /**
     * loop through, while user won't choose one of the options
     */
    while(1)
    {
        /**
         * currently selected option is highlighted
         */
        for(int i = 0; i < 4; ++i)
        {
            /** A_REVERSE - ncurses attribute to highlight characters */
            if(i == highlight)
                wattron(menuWin, A_REVERSE);
            /** print to the ncurses window,menuWin, at certain poisition the text options */
            mvwprintw(menuWin, menuWinHeight*3/8+i+1, menuWinWidth/2, menuOptions[i].c_str());
            /** turn off highlighting some window element */
            wattroff(menuWin, A_REVERSE);

        }
        /** ask for user input */
        choice = wgetch(menuWin);
        int temp = highlight;
        switch(choice)
        {
            case KEY_UP:
                highlight == 0 ? highlight = temp : highlight --;
                break;
            case KEY_DOWN:
                highlight == 3 ? highlight = temp : highlight ++;
                break;
            case KEY_UP2:
                highlight == 0 ? highlight = temp : highlight --;
                break;
            case KEY_DOWN2:
                highlight == 3 ? highlight = temp : highlight ++;
                break;
            default:
                break;
        }

        /** if user clicked enter proceed*/
        if(choice == enter)
            break;
    }

    SetUpMenuChoice userchoice = Exit;
    /**
     * proceed according to user's choice
     */
    switch (highlight) {
        case 0:
            window.end();
            userchoice = SetUpMenuChoice::Play;
            break;
        case 1:
            window.end();
            showInfo();
            userchoice = SetUpMenuChoice::Info;
            break;
        case 2:
            window.end();
            setDificulty();
            userchoice = SetUpMenuChoice::Difficulty;
            break;
        case 3:
            window.end();
            userchoice = SetUpMenuChoice::Exit;
            break;
    }

    return userchoice;
}

/**
 * Method shows info about the game
 */
void SetUpMenu::showInfo() {
    /**
     * init ncruses
     */
    window.start();

    /**
     * create and init ncurses window
     */
    int infoWinWidth =  window.screenWidth()*4/5;
    int infoWiHeight =  window.screenHeight()*4/5;
    int startX = 0;
    int startY = 0;

    WINDOW * infoWin = newwin(infoWiHeight, infoWinWidth, startY, startX);
    box(infoWin, 0, 0);
    refresh();
    wrefresh(infoWin);
    keypad(infoWin, true);

    /**
     * load information about the game from a text file
     */
    vector<string> text = readFromFile ();

    for(unsigned i = 0; i < text.size(); ++i)
    {
        mvwprintw(infoWin, i+1, 1, text[i].c_str());
    }
    /**
     * update ncurses windowhard
     */
    wrefresh(infoWin);
    /**
     * wait for some input
     */
    wgetch(infoWin);
    window.end();
}


/**
 * Method loads text from a file, which is information about the game
 */
vector<string> SetUpMenu::readFromFile ()
{
    /**
     * set up for reading from a file
     */
    vector<string> myvector;
    string line;
    ifstream inFile;
    inFile.open("./examples/game-descp.txt", ios::binary | ios::in);
    /**
     * read from a file line by line
     */
    while (getline(inFile, line))
    {
        myvector.push_back(line);
    }
    /**
     * return retrieved data from a file
     */
    return myvector;
}

void SetUpMenu::setDificulty() {
    /**
     * init ncruses
     */
    window.start();

    string level;
    ifstream inFile;
    inFile.open("./examples/difficulty.txt", ios::binary | ios::in );
    inFile >> level;

    /**
     * create a ncurses window for input
     */
    int diffWidth =  window.screenWidth() / 2;
    int diffHeight =  window.screenHeight() / 2;
    int startX = window.screenWidth() - window.screenWidth() * 3/4;
    int startY = window.screenHeight() - window.screenHeight()*3/4;
    WINDOW * menuWin = newwin(diffHeight, diffWidth, startY, startX);
    box(menuWin, 0, 0);
    refresh();
    wrefresh(menuWin);

    /**
     * enable arrow keys
     */
    keypad(menuWin, true);

    /**
     * initial menu contets
     */
    string menuOptions [4] = {"Easy", "Medium", "Hard", "Back"};

    /**
     * variables for interaction with user and menu
     */
    int choice = 0, highlight = 0, enter = 10;
    /**
     * loop through, while user won't choose one of the options
     */
    while(1)
    {
        /**
         * currently selected option is highlighted
         */
        for(int i = 0; i < 4; ++i)
        {
            /** A_REVERSE - ncurses attribute to highlight characters */
            if(i == highlight)
                wattron(menuWin, A_REVERSE);
            /** print to the ncurses window,menuWin, at certain poisition the text options */
            if(level == "Easy" && i == 0)
                wattron(menuWin, A_BOLD);
            if(level == "Medium" && i == 1)
                wattron(menuWin, A_BOLD);
            if(level == "Hard" && i == 2)
                wattron(menuWin, A_BOLD);
            mvwprintw(menuWin, diffHeight*3/8+i+1, diffWidth/2, menuOptions[i].c_str());
            wattroff(menuWin, A_BOLD);
            /** turn off highlighting some window element */
            wattroff(menuWin, A_REVERSE);

        }
        /** ask for user input */
        choice = wgetch(menuWin);
        int temp = highlight;
        switch(choice)
        {
            case KEY_UP:
                highlight == 0 ? highlight = temp : highlight --;
                break;
            case KEY_DOWN:
                highlight == 3 ? highlight = temp : highlight ++;
                break;
            case KEY_UP2:
                highlight == 3 ? highlight = temp : highlight --;
                break;
            case KEY_DOWN2:
                highlight == 3 ? highlight = temp : highlight ++;
                break;
            default:
                break;
        }

        /** if user clicked enter proceed*/
        if(choice == enter)
        {
            switch (highlight) {
                case 0:
                    level = "Easy";
                    writeToFile(level, "./examples/difficulty.txt");
                    break;
                case 1:
                    level = "Medium";
                    writeToFile(level, "./examples/difficulty.txt");
                    break;
                case 2:
                    level = "Hard";
                    writeToFile(level, "./examples/difficulty.txt");
                    break;
                case 3:
                    window.end();
                    return;
                default:
                    break;
            }
        }
    }
}

void SetUpMenu::writeToFile ( string text, string filename ) {
    ofstream outFile;
    outFile.open(filename.c_str(), ios::binary | ios::out );
    outFile << text;
    outFile.close();
}
