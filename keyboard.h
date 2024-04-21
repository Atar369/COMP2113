#pragma once

#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>

#define KEY_UP 650
#define KEY_DOWN 660
#define KEY_LEFT 680
#define KEY_RIGHT 670
#define KEY_ENTER 10 // '\n' key
#define KEY_ESC 27  
#define KEY_SPACE 32
#define KEY_ACTION 69
#define KEY_EXIT 81

class Keyboard {
    public:
    int key;

    public:
    bool key_pressed(int key);
    bool waiting(int key);
    void get_userInput();
    //void stop();
};

