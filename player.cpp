#include "player.h"

//objects obj;

void Player::moveUp() {
    this->vtrl = -1;
}

void Player::moveDown() {
    this->vtrl = 1;
}

void Player::moveLeft() {
    this->hrz = -1;
}

void Player::moveRight() {
    this->hrz = 1;
}

void Player::stopMovement() {
    this->hrz = 0;
    this->vtrl = 0;
}

/*
void updatePlayercorr(vector<vector<short> > current_map) {
    for (int i = 0; i < current_map.size(); i++) {
        for (int j = 0; j < current_map[0].size(); j++) {
            if (current_map[i][j] == i_player) {
                player.x = j;
                player.y = i;
            }
        }
    }
}   */ 


void Player::player_move(int key, vector<vector<short> > &current_map) {
    // Key check
    bool left  = ( key == KEY_LEFT ) ? 1 : 0;
    bool right = ( key == KEY_RIGHT ) ? 1 : 0;
    bool down  = ( key == KEY_DOWN ) ? 1 : 0;
    bool up    = ( key == KEY_UP ) ? 1 : 0;

    // Reset player movement
    this->stopMovement();

    // Animation and direction shoot
    //int dir_shoot = 0;

    if (!left && !right && !down && !up) {
        this->symbol = "|0|";
    } 
    else {
        if (right) { 
            //dir_shoot = 1; 
            this->symbol = "|0>";
        }
        if (left) { 
            //dir_shoot = -1; 
            this->symbol = "<0|"; 
        }
        if (up) { 
            //dir_shoot = -2; 
            this->symbol = "/0\\"; 
        }
        if (down) { 
            //dir_shoot = 2; 
            this->symbol = "\\0/"; 
        }
    }

    // Move player
    this->hrz = int(right) - int(left);
    this->vtrl = int(down) - int(up);

    // Check
    if (this->hrz != 0) {
        this->vtrl = 0;
    } 
    else if (this->vtrl != 0) {
        this->hrz = 0;
    }

    this->x += this->hrz;
    this->y += this->vtrl;
}


// Collsiion
void Player::player_collision(vector<vector<short> > &current_map) {
    switch(current_map[this->y][this->x]) {
        
        // Collision
        case i_wall:    // wall
        case i_lightoff:  // lightoff
        case i_lighton:   // lighton
        case i_monster:   // monster
        case i_closet:    // closet
        case i_chair:     // chair
        case i_table:     // table
            this->x -= this->hrz;
            this->y -= this->vtrl;
            break;

        // Treasure collision
        case i_treasure:
            current_map[this->y][this->x] = 0;
            //this->obj.treasure = 1;
        break;

        // key collision
        case i_key:
            current_map[this->y][this->x] = 0;
            //this->obj.key = 1;
        break;

        case i_npc:     // npc
            this->x -= this->hrz;
            this->y -= this->vtrl;
            //this->obj.npc = 1;
            break;
    }
}

/* testing
void displayMap(vector<vector<short> > current_map[ROWS][COLS]) {
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

