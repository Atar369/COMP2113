#pragma once

#include <string>

using namespace std;

void moveUp();

void moveDown();

void moveLeft();

void moveRight();

void stopMovement();

void player_move(string key, short current_map[ROWS][COLS]);


