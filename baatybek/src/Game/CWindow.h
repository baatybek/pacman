#ifndef PACMAN_CWINDOW_H
#define PACMAN_CWINDOW_H

#include <ncurses.h>

/** @brief CWindow class handles ncurses window
 */
class CWindow {
    int screenX;
    int screenY;
    WINDOW * mazeWin;
    WINDOW * info;
public:
    /**
     * Constructor
     */
    CWindow ();
    /**
     * Destructor
     */
    ~CWindow ();
    /**
     * Method starts ncurses
     */
    void start();
    /**
     * Method stops ncurses
     */
    void end();
    /**
     * Method returns screensize width
     */
    int screenWidth () const;
    /**
     * Method returns screensize height
     */
    int screenHeight () const;
    /**
     * Method ncurses window "mazeWin"
     */
    WINDOW * getMazeWindow () const ;
    /**
     * Method ncurses window "info"
     */
    WINDOW * infoWindow () const ;
    /**
     * Method sets up ncurses windows "mazeWin" and "info"
     * @param[in] mapWidth width of ncurses window "mazeWin"
     * @param[in] mapHeight height ncurses window "mazeWin"
     */
    void initWindows (int mapWidth, int mapHeight);
    /**
     * Method prints information about pacman on the info screen
     * @param[in] lives pacman's lives
     * @param[in] score pacman's score
     */
    void updateInfoScreen ( int lives, int score);
    /**
     * Method prints last updated on ncurses windows "mazeWin" and "info"
     */
    void refresh();
};



#endif //PACMAN_CWINDOW_H
