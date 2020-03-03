#include "CWindow.h"

/**
 * Constructor
 */
CWindow::CWindow () {
}
/**
 * Destructor
 */
CWindow::~CWindow (){
}
/**
 * Method starts ncurses
 */
void CWindow::start(){
    /** ncurses start*/
    initscr();
    /** Line buffering disabled */
    raw();
    /** We get F1, F2 etc.. */
    keypad(stdscr, TRUE);
    /** Don't echo() while we do getch */
    noecho();
    cbreak();
    /** hide cursor on window */
    curs_set(0);
    /** get screen size */
    getmaxyx(stdscr, screenY, screenX);
}
/**
 * Method stops ncurses
 */
void CWindow::end(){
    /** show cursor on window */
    curs_set(1);
    /** clear the screen */
    clear();
    /** End curses mode */
    endwin();
}

/**
 * Method returns screensize width
 */
int CWindow::screenWidth () const {
    return screenX;
}
/**
 * Method returns screensize height
 */
int CWindow::screenHeight () const {
    return screenY;
}
/**
 * Method sets up ncurses windows "mazeWin" and "info"
 * @param[in] mapWidth width of ncurses window "mazeWin"
 * @param[in] mapHeight height ncurses window "mazeWin"
 */
void CWindow::initWindows ( int mapWidth, int mapHeight) {
    int start_x = (int) (screenX*0.15);
    int start_y = (int) (screenY*0.25);
    mazeWin = newwin ((int)mapHeight, (int)mapWidth, start_y, start_x);
    keypad(mazeWin, true);
    refresh();
    wrefresh(mazeWin);

    start_y = start_y + mapHeight + 1;
    info  = newwin(5, mapWidth, start_y, start_x);
    box(info, 0, 0);
    refresh();
    wrefresh(info);
}

/**
 * Method ncurses window "mazeWin"
 */
WINDOW * CWindow::getMazeWindow () const {
    return mazeWin;
}

/**
 * Method ncurses window "info"
 */
WINDOW * CWindow::infoWindow () const {
    return info;
}
/**
 * Method prints last updated on ncurses windows "mazeWin" and "info"
 */
void CWindow::refresh() {
    wrefresh(mazeWin);
    wrefresh(info);
}
/**
 * Method prints information about pacman on the info screen
 * @param[in] lives pacman's lives
 * @param[in] score pacman's score
 * @param[in] candies number of candies left on the maze
 */
void CWindow::updateInfoScreen ( int lives, int score) {
    mvwprintw(info, 1, 1, "Lives = %d", lives);
    mvwprintw(info, 2, 1, "Score = %d", score);
}