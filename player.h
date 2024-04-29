#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
#include "keyboard.h"
#include "constant.h"
#include "format.h"


using namespace std;

class Player {
    
    public:
    int hrz, vtrl; // horizontal, vertical, -1, 0, 1
    int x, y;
    string symbol;
    string color;
    bool chat_npc = false;
    bool reach_ending = false;
    bool touch_monster = false;
    bool touch_oldman = false;
    bool touch_librarian = false;
    bool touch_penny = false;
    bool touch_cooper = false;
    bool touch_robert = false;
    bool touch_dragon = false;
    bool touch_dragonnpc = false;
    
    
    // Player's inventory & states
    bool touch_key = false;
    bool open_treasure = false;
    bool turn_light_switch = false;
    bool investigate = false;
    


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


