#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
#include <vector>
#include "constant.h"
#include "object.h"

using namespace std;



void moveUp() {
    player.vtrl = -1;
}

void moveDown() {
    player.vtrl = 1;
}

void moveLeft() {
    player.hrz = -1;
}

void moveRight() {
    player.hrz = 1;
}

void stopMovement() {
    player.hrz = 0;
    player.vtrl = 0;
}

int dir_x;
int dir_y;

int player_move(const string key, short current_map[ROWS][COLS]) {
    // Key check
    int key_left  = ( key == "LEFT" ) ? 1 : 0;
    int key_right = ( key == "RIGHT" ) ? 1 : 0;
    int key_down  = ( key == "DOWN" ) ? 1 : 0;
    int key_up    = ( key == "UP" ) ? 1 : 0;

    // Reset player's movement
    stopMovement();

    // key dir
    dir_x = key_right - key_left;
    dir_y = key_down  - key_up;

    // Animation and direction shoot
    int dir_shoot = 0;

    if (dir_x == 0 && dir_y == 0) {
        player.symbol = "|0|";
    } 
    else {
        if (dir_x == 1) { 
            //dir_shoot = 1; 
            player.symbol = "|0>";
        }
        if (dir_x == -1) { 
            //dir_shoot = -1; 
            player.symbol = "<0|"; 
        }
        if (dir_y == -1) { 
            //dir_shoot = -2; 
            player.symbol = "/0\\"; 
        }
        if (dir_y == 1) { 
            //dir_shoot = 2; 
            player.symbol = "\\0/"; 
        }
    }

    player.hrz = 1 * dir_x;
    player.vtrl = 1 * dir_y;  

    player.x += player.hrz;
    player.y += player.vtrl;
}

/* testing
void displayBoard(const vector<vector<string> >& board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == player.y && j == player.x) {
                cout << player.symbol << " ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    while (true) {
        displayBoard(board);
        usleep(100000);
        system("clear");
    }
}
*/
