#include "player.h"

// temp
Player player;

// calculate player's move
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

void Player::player_move(int key, vector<vector<short> > &current_map) {
    // Key check
    bool left  = ( key == KEY_LEFT ) ? 1 : 0;
    bool right = ( key == KEY_RIGHT ) ? 1 : 0;
    bool down  = ( key == KEY_DOWN ) ? 1 : 0;
    bool up    = ( key == KEY_UP ) ? 1 : 0;

    // Reset player movement
    this->stopMovement();

    if (this->color == font_blue) {
        this->symbol = "|@|";
    } 
    else {
        this->symbol = "|%|";
    }


    if (right) { 
        if (this->color == font_blue) {
            this->symbol = "|@>";
        } 
        else {
            this->symbol = "|%>";
        }
    }
    if (left) { 
        if (this->color == font_blue) {
            this->symbol = "<@|";
        } 
        else {
            this->symbol = "<%|";
        }
    }
    if (up) { 
        if (this->color == font_blue) {
            this->symbol = "/@\\";
        } 
        else {
            this->symbol = "/%\\";
        }
    }
    if (down) { 
        if (this->color == font_blue) {
            this->symbol = "\\@/";
        } 
        else {
            this->symbol = "\\%/";
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

        // Treasure collision
        case i_empty: case i_door: case i_leftdoor: case i_rightdoor: case i_stairs3: case i_stairs4: case i_stairs5: case i_stairs6: case i_stairs7:
            break;

        case i_treasure:
            current_map[this->y][this->x] = 0;
            this->open_treasure = 1;
        break;

        case i_key:
            this->touch_key = 1;
        break;

        case i_npc:     // npc
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->chat_npc = 1;
        break;

        case i_monster:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->touch_monster = 1;
        break;

        case i_oldman:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->touch_oldman = 1;
        break;

        case i_librarian:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->touch_librarian = 1;
        break;

        case i_penny:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->touch_penny = 1;
        break;    

        case i_cooper:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->touch_cooper = 1;
         break;

        case i_robert:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->touch_robert = 1;
        break;        

        case i_dragon:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->touch_dragon = 1;
        break;

        case i_dragonnpc:
            this->x -= this->hrz;
            this->y -= this->vtrl;
            this->touch_dragonnpc = 1;
        break;        

        default:
            this->x -= this->hrz;
            this->y -= this->vtrl;
        break;     
    }
}
