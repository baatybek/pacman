#include "GameMenu.h"


GameMenuOptions GameMenu::run( bool end, int x, int y, int startx, int starty ) {
    /**
     * create a ncurses window for input
     */

    WINDOW * menuWin = newwin(y, x, starty, startx);
    box(menuWin, 0, 0);
    refresh();
    wrefresh(menuWin);

    if( end )
    {
        WINDOW * textWin = newwin(5, x, starty-5, startx);
        refresh();
        mvwprintw(textWin, 1, 1, "%s", text.c_str());
        wrefresh(textWin);
    }


    /**
     * enable arrow keys
     */
    keypad(menuWin, true);
    /**
     * initial menu contets
     */
    string menuOptions [4] = {"Resume", "Restart", "MainMenu", "Exit"};
    /**
     * variables for interaction with user and menu
     */
    int choice = 0, highlight = 0, enter = 10;
    int lower  = ( ! end ? 0 : 1);
    /**
     * loop through, while user won't choose one of the options
     */
    while (1) {
        /**
         * currently selected option is highlighted
         */
        for(int i = lower; i < 4; ++i)
        {
            /** A_REVERSE - ncurses attribute to highlight characters */
            if(i == highlight)
                wattron(menuWin, A_REVERSE);
            /** print to the ncurses window,menuWin, at certain poisition the text options */
            mvwprintw(menuWin, i + 2, startx*0.3 , menuOptions[i].c_str());
            /** turn off highlighting some window element */
            wattroff(menuWin, A_REVERSE);
            wattroff(menuWin, A_INVIS);
        }

        /** ask for user input */
        choice = wgetch(menuWin);
        int temp = highlight;
        switch(choice)
        {
            case KEY_UP:
                highlight == lower ? highlight = temp : highlight --;
                break;
            case KEY_DOWN:
                highlight == 3 ? highlight = temp : highlight ++;
                break;
            default:
                break;
        }

        if(choice == enter && highlight == 3)
            break;

        /** if user clicked enter proceed*/
        if(choice == enter)
        {
            /**
             * proceed according to user's choice
             */
            switch (highlight) {
                case 0:
                    werase(menuWin);
                    wrefresh(menuWin);
                    return CResume;
                case 1:
                    window.end();
                    return CRestart;
                case 2:
                    window.end();
                    return CMainMenu;
                case 3:
                    window.end();
                    return CExit;
                default:
                    break;
            }
        }
    }

    return CExit;
}

/**
 * Method sets string values to a text
 * @param[in] str a string value to be set to a text
 */
void GameMenu::setString ( string str ) {
    text = str;
}