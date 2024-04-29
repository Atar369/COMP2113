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
#define KEY_EXIT 81 // ascii numbers

//fighting class
#define KEY_P 80
#define KEY_G 71
#define KEY_F 70
#define KEY_K 75
#define KEY_C 67
#define KEY_J 74

class Keyboard {
    public:
    int key;

    public:
    bool key_pressed();
    void get_userInput();
};

extern Keyboard keyboard;

