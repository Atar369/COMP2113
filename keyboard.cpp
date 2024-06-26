#include "keyboard.h"

Keyboard keyboard;

// check if the key is pressed
bool Keyboard::key_pressed() {
    this->get_userInput();
    if (this->key != 0 && (this->key != KEY_EXIT || this->key != KEY_ENTER || this->key != KEY_ESC || this->key != KEY_SPACE || this->key != KEY_ACTION || this->key != KEY_UP || this->key != KEY_DOWN || this->key != KEY_LEFT || this->key != KEY_RIGHT) ) {
        return 0;
    }
    return 1;
}

// get the user input
void Keyboard::get_userInput() {
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
    newSettings.c_cc[VTIME] = 0;
    newSettings.c_cc[VMIN] = 1;

    char userInput = getchar(); // get one character from the user

    // map the user input to the key
    switch (userInput) {
        case 'W': case 'w':
            this->key = KEY_UP;
            break;
        case 'A': case 'a': 
            this->key = KEY_LEFT;
            break;
        case 'S': case 's':
            this->key = KEY_DOWN;
            break;
        case 'D': case 'd':
            this->key = KEY_RIGHT;
            break;
        case KEY_ENTER:
            this->key = KEY_ENTER;
            break;
        case KEY_ESC:
            this->key = KEY_ESC;
            break;
        case KEY_SPACE:
            this->key = KEY_SPACE;
            break;
        case 'E': case 'e': 
            this->key = KEY_ACTION;
            break;
        case 'Q': case 'q':
            this->key = KEY_EXIT;
            break;
        case 'P': case 'p':
            this->key = KEY_P;
            break;
        case 'G': case 'g':
            this->key = KEY_G;
            break;
        case 'F': case 'f':
            this->key = KEY_F;
            break;
        case 'K': case 'k':
            this->key = KEY_K;
            break;
        case 'C': case 'c':
            this->key = KEY_C;
            break;
        case 'J': case 'j':
            this->key = KEY_J;    
            break;                    
    }
    oldSettings.c_lflag |= ECHO;
    tcsetattr(0, TCSANOW, &oldSettings);
}

