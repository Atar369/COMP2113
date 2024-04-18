#ifndef KEYBOARD_H // include guard
#define KEYBOARD_H

#include <string>
#include <vector>
using namespace std;

struct Player {
    int x;
    int y;
    int hrz;
    int vtcl;
    char symbol;
};

Player player;

void moveUp();

void moveDown();

void moveLeft();

void moveRight();

void stopMovement();

void player_move(string key);

void displayBoard(const vector<vector<string> >& board);

#endif // KEYBOARD_H
