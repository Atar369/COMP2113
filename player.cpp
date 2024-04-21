#include "player.h"

object player;

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

/*
void updatePlayercorr(short current_map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (current_map[i][j] == i_player) {
                player.x = j;
                player.y = i;
            }
        }
    }
}   */ 

void player_move(int key, short current_map[ROWS][COLS]) {
    // Key check
    bool left  = ( key == KEY_LEFT ) ? 1 : 0;
    bool right = ( key == KEY_RIGHT ) ? 1 : 0;
    bool down  = ( key == KEY_DOWN ) ? 1 : 0;
    bool up    = ( key == KEY_UP ) ? 1 : 0;

    // Reset player movement
    stopMovement();

    // Animation and direction shoot
    //int dir_shoot = 0;

    if (!left && !right && !down && !up) {
        player.symbol = "|0|";
    } 
    else {
        if (right) { 
            //dir_shoot = 1; 
            player.symbol = "|0>";
        }
        if (left) { 
            //dir_shoot = -1; 
            player.symbol = "<0|"; 
        }
        if (up) { 
            //dir_shoot = -2; 
            player.symbol = "/0\\"; 
        }
        if (down) { 
            //dir_shoot = 2; 
            player.symbol = "\\0/"; 
        }
    }

    // Move player
    player.hrz = int(right) - int(left);
    player.vtrl = int(down) - int(up);

    // Check
    if (player.hrz != 0) {
        player.vtrl = 0;
    } 
    else if (player.vtrl != 0) {
        player.hrz = 0;
    }

    player.x += player.hrz;
    player.y += player.vtrl;
}


// Collsiion
void player_collision(short current_map[][COLS]) {
    switch(current_map[player.y][player.x]) {
        
        // Collision
        case i_wall:    // wall
        case i_npc:     // box
        case i_lightoff:  // lightoff
        case i_lighton:   // lighton
        case i_monster:   // monster
        case i_closet:    // closet
        case i_chair:     // chair
            player.x -= player.hrz;
            player.y -= player.vtrl;
            break;

        // Treasure collision
        case i_treasure:
            current_map[player.y][player.x] = 0;
        break;

        // key collision
        case i_key:
            current_map[player.y][player.x] = 0;
        break;
    }
}

/* testing
void displayMap(short current_map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == player.y && j == player.x) {
                cout << player.symbol << "";
            } else {
                cout << current_map[i][j] << "";
            }
        }
        cout << endl;
    }
}  */

