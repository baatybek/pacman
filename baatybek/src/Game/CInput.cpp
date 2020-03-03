#include "CInput.h"

/**
 * Construtor
 */
CInput::CInput () : input ( C_LEFT ) {
}
/**
 * Destructor
 */
CInput::~CInput () {
}
/**
 * Method checks if key has been hit or not
 * function was inspired from a snake application done by ranzuh on github
 * Reference: https://github.com/ranzuh/snake/blob/master/snake_v1.c
 */
int CInput::kbhit (void) {
    struct timeval tv;
    fd_set read_fd;

    tv.tv_sec=0;
    tv.tv_usec=0;
    FD_ZERO(&read_fd);
    FD_SET(0,&read_fd);

    if(select(1, &read_fd, NULL, NULL, &tv) == -1)
        return 0;

    if(FD_ISSET(0,&read_fd))
        return 1;

    return 0;
}

/**
 * Method returns current key entered by user
 */
CInputEnum CInput::getInput () {
    char temp = 0;
    if (kbhit())
        temp = getch();
    lastinput = input;
    switch (temp) {
        case 'w':
            input = C_UP;
            break;
        case 's':
            input = C_DOWN;
            break;
        case 'd':
            input = C_RIGHT;
            break;
        case 'a':
            input = C_LEFT;
            break;
        case 27:
            input = C_ESC;
        default:
            break;
    }
    return input;
}

/**
 * Method sets input value
 */
void CInput::setInput (CInputEnum key) {
    input = key;
}
/**
 * Method returns last key entered by user
 */
CInputEnum CInput::getLastInput () {
    return lastinput;
}
