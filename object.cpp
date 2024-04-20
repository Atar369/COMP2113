#include <string>
#include "constant.h"
#include "player.h"
using namespace std;

struct class_obj {
    int hrz, vtcl;
    int x, y;
    int direction;
    string symbol;
};

// Create objects
class_obj player = {};

// set obj Parametrs
void obj_init(class_obj *obj, int x, int y, int dir, string objname) {
    obj->x = x;
    obj->y = y;
    obj->direction = dir;
    obj->symbol = objname;
}


// Collsiion
void player_collision(short current_map[][COLS]) {
    switch(current_map[player.y][player.x]) {
        
        // Collision
        case i_wall:    // wall
        case i_npc:     // box
        case i_door:    // door
        case i_empty:   // space
            player.x -= player.hrz;
            player.y -= player.vtcl;
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
