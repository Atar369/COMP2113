#include "keyboard.h"

bool Keyboard::key_pressed(int key) {
    if (key != 0 && (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT || key == KEY_ENTER || key == KEY_ESC || key == KEY_SPACE || key == KEY_ACTION || key == KEY_EXIT) ) {
        return 0;
    }
    return 1;
}

bool Keyboard::waiting(int key) {
    if (key == KEY_ENTER) {
        return 0;
    }
    return 1;
}

void Keyboard::get_userInput() {
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
    newSettings.c_cc[VTIME] = 0;
    newSettings.c_cc[VMIN] = 1;
    char userInput = getchar();

    switch (userInput) {
        case 'W': case 'w': case KEY_UP:
            key = KEY_UP;
            break;
        case 'A': case 'a': case KEY_LEFT:
            key = KEY_LEFT;
            break;
        case 'S': case 's': case KEY_DOWN:
            key = KEY_DOWN;
            break;
        case 'D': case 'd': case KEY_RIGHT:
            key = KEY_RIGHT;
            break;
        case KEY_ENTER:
            key = KEY_ENTER;
            break;
        case KEY_ESC:
            key = KEY_ESC;
            break;
        case KEY_SPACE:
            key = KEY_SPACE;
            break;
        case 'E': case 'e': 
            key = KEY_ACTION;
            break;
        case 'Q': case 'q':
            key = KEY_EXIT;
            break;
        //default:
            // Ignore invalid keys
            //break;
    }

}

