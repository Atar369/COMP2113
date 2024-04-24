#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
#include "keyboard.h"
#include "constant.h"


using namespace std;

class Player {

    public:
    int hrz, vtrl;
    int x, y;
    int direction;
    string symbol;
    string color;
    
    
    // Player's inventory & states
    bool have_key;
    bool open_treasure;
    bool turn_light_switch;
    bool have_sword;
    bool investigate;
    bool chat_npc;


    public:

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void stopMovement();

    void player_move(int key, vector<vector<short> > &current_map);

    void player_collision(vector<vector<short> > &current_map);
};

extern Player player; // temp

/*
struct objects {
    int key = 0;
    //int sword;
    int treasure = 0;
    int light_switch;
    //int closet;
    //int wall;
    int npc = 0;
    int monster = 0;
}; */




//void updatePlayercorr(short current_map[ROWS][COLS]);

//void displayMap(short current_map[ROWS][COLS]);


