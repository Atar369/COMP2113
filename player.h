#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
#include "keyboard.h"
#include "constant.h"
#include "format.h"


using namespace std;

// Player class for player movement and collision
class Player {
    
    public:
    int hrz, vtrl; // horizontal, vertical, -1, 0, 1
    int x, y;
    string symbol;
    string color;

    // player status
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
    bool touch_key = false;
    bool open_treasure = false;
    

    public:

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void stopMovement();

    void player_move(int key, vector<vector<short> > &current_map);

    void player_collision(vector<vector<short> > &current_map);

    void reset_player();
};

extern Player player; 


