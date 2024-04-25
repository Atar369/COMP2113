#include "player.h"

// temp
Player player;

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
    this->symbol = "|@|";

    // Animation and direction shoot
    //int dir_shoot = 0;


    if (right) { 
        //dir_shoot = 1; 
        this->symbol = "|@>";
    }
    if (left) { 
        //dir_shoot = -1; 
        this->symbol = "<@|"; 
    }
    if (up) { 
        //dir_shoot = -2; 
        this->symbol = "/@\\"; 
    }
    if (down) { 
        //dir_shoot = 2; 
        this->symbol = "\\@/"; 
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

        // Treasure collision
        case i_empty: case i_door: case i_leftdoor: case i_rightdoor: case i_stairs2: case i_stairs3: case i_stairs4: case i_stairs5: case i_stairs6: case i_stairs7: 
        break;

        case i_treasure:
            current_map[this->y][this->x] = 0;
            this->open_treasure = 1;
        break;

        case i_key:
            current_map[this->y][this->x] = 0;
            this->have_key = 1;
        break;

        case i_npc:     // npc
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->chat_npc = 1;
        break;

        case i_monster:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->saw_monster = 1;
        break;

        default:
            this->x -= this->hrz;
            this->y -= this->vtrl;
        break;     
    }
}

/*
 testing
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

