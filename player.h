#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
#include "keyboard.h"
#include "constant.h"


using namespace std;

struct object {
    int hrz, vtrl;
    int x, y;
    int direction;
    string symbol;
};

extern object player;

void moveUp();

void moveDown();

void moveLeft();

void moveRight();

void stopMovement();

void player_move(int key, short current_map[ROWS][COLS]);

void player_collision(short current_lvl[][COLS]);
