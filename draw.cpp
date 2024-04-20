#include <math.h>
#include <string>
#include <vector>
#include <map>
#include "constant.h"
#include "maps.h"
#include "player.h"
#include "keyboard.h"
#include "object.h"
#include "format.h"

using namespace std;

/*
void draw_instance(short current_map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            string effect = "";
            string symbol = symbol_mapping[current_map[i][j]];
            string color = color_mapping[current_map[i][j]];
            if (effect_mapping.find(current_map[i][j]) != effect_mapping.end())
                effect = effect_mapping.at(current_map[i][j]);
            cout << color << effect << symbol << reset << "";
            if (x == player.x && y == player.y) {
                        
                        break;
                    }

            switch(current_map[i][j]) {
                // Draw static object
                case i_empty: case i_wall: case i_treasure: case i_door: case i_chair: case i_npc: cout << color << effect << symbol << reset << ""; break;
                case i_player:   draw_instance(y, x, c_player, s_player);  break;
                case i_enemy:    draw_instance(y, x, c_enemy,  s_enemy);   break;
                case i_monster:  draw_instance(y, x, c_wall,  s_space); break;
                case i_grass:    draw_instance(y, x, c_grass, s_grass);  break;
                case i_closet:   draw_instance(y, x, c_wall,  s_space); break;
                case i_dragon:   draw_instance(y, x, c_wall,  s_space); break;
                case i_key:  draw_instance(y, x, c_wall,  s_space); break;
                case i_table:    draw_instance(y, x, c_wall,  s_space); break;
                case i_bed:  draw_instance(y, x, c_wall,  s_space); break;
                case i_lightoff: draw_instance(y, x, c_wall,  s_space); break;
                case i_lighton:  draw_instance(y, x, c_wall,  s_space); break;
                

                // Draw dynamic object
                default:

                    // Draw player
                    if (x == player.x && y == player.y) {
                        draw_instance(y, x, c_player, player.symbol);
                        break;
                    }

                    // Draw bullet
                    if (x == bullet.x && y == bullet.y) {
                        if (!bullet_shoot) {
                            break;
                        }
                        draw_instance(y, x, c_bullet, bullet.symbol);
                    }

                    // Draw enemy
                    for (int i = 0; i < 5; i++) {
                        if (x == enemy[i].x && y == enemy[i].y) {
                            draw_instance(y, x, c_enemy, s_enemy);
                            break;
                        }
                    }

                break;
            }

            // Open door
            if (score == apples_in_level) {
                if (lvl[y][x] == i_door) {
                    lvl[y][x] = 0;
                }
            }
        
        }
        cout << endl;
    } 
} */

/////////////
// MAPS
////////////

/* Set enemy and calck apple
void set_map_param(short current_map[][COLS], int clx, int cly) {
    static int i = 0;
    for (int y = 0; y < cly; y++) {
        for (int x = 0; x < clx; x++) {
            if (current_map[y][x] == i_enemy_v) {
                obj_init(&enemy[i], x, y, 1, "");
                i++;
            } else if (current_map[y][x] == i_enemy_h) {
                obj_init(&enemy[i], x, y, 2, "");
                i++;
            }
            if (i >= sizeof(enemy)/sizeof(enemy[0])) {
                i = 0;
            }
        }
    }

}*/

// Draw instance
void draw_instance(int y, int x, int obj, string symbol) {
    string effect = "";
    string color = color_mapping[obj];
    if (effect_mapping.find(obj) != effect_mapping.end())
        effect = effect_mapping.at(obj);
    cout << color << effect << symbol << reset << "";
}
        
// Check next map
bool next_map(short current_map[][COLS], short &map_code) {
    if (current_map[player.y][player.x] == i_door) {
        map_code++; // further modify if we want transition to another map，go back/ go up/down
        return true;
    }
    return false;
}

// Draw Current Map
void draw_map(short current_map[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch(current_map[i][j]) {

                // Draw static object
                case i_empty: cout << s_empty ; break;
                case i_wall:   draw_instance(i, j, c_wall, s_wall);  break;
                case i_treasure: draw_instance(i, j, c_treasure, s_treasure); break;
                case i_door:   draw_instance(i, j, c_door, s_door);  break;
                case i_chair:  draw_instance(i, j, c_chair, s_chair); break;
                case i_npc:    draw_instance(i, j, c_npc, s_npc);    break;
                case i_monster: draw_instance(i, j, c_monster, s_monster); break;
                case i_grass:  draw_instance(i, j, c_grass, s_grass);  break;
                case i_closet: draw_instance(i, j, c_closet, s_closet); break;
                case i_dragon: draw_instance(i, j, c_dragon, s_dragon); break;
                case i_key:    draw_instance(i, j, c_key, s_key);    break;
                case i_table:  draw_instance(i, j, c_table, s_table);  break;
                case i_bed:    draw_instance(i, j, c_bed, s_bed);    break;
                case i_lightoff: draw_instance(i, j, c_lightoff, s_lightoff); break;
                case i_lighton:  draw_instance(i, j, c_lighton, s_lighton);  break;

                // Draw dynamic object
                default:

                    // Draw player
                    if (j == player.x && i == player.y) {
                        draw_instance(i, j, c_player, player.symbol);
                        break;
                    }


                    /* // Draw bullet
                    if (x == bullet.x && y == bullet.y) {
                        if (!bullet_shoot) {
                            break;
                        }
                        draw_instance(y, x, c_bullet, bullet.symbol);
                    } 

                    // Draw enemy
                    for (int i = 0; i < 5; i++) {
                        if (x == enemy[i].x && y == enemy[i].y) {
                            draw_instance(y, x, c_enemy, s_enemy);
                            break;
                        }
                    }
*/
                break;
            }

            // Open door if key is found
            /* if (score == apples_in_level) {
                if (lvl[y][x] == i_door) {
                    lvl[y][x] = 0;
                }
            }*/
        }
        cout << endl;
    }
}

int main() {
    // Populate the map with your own data
    short current_map[ROWS][COLS];
    short Girl_house[ROWS][COLS] = {
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 14, 14, 14, 10, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 0, 0, 14, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 0, 0, 14, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 13, 13, 13, 2, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
        };

    // Assign the values of Girl_house to current_map
    memcpy(current_map, Girl_house, sizeof(Girl_house));
    // Call the draw_map function to print the map
    draw_map(current_map);

    int key = 0;
    while (key != KEY_EXIT) {
        get_userInput();
    }
    return 0;
} 

/*
class Map {
public:
    short current_map[ROWS][COLS];
    int width;
    int height;
    int priority = 0;

public:
    Map() {}
    Map(int width, int height);
    Map(const vector<string>& ma, const short & current_map[][]);
    Map(vector<string>& map);
    void init(vector<string>& map, vector<string>& current_map);
    void add_interact(int x, int y, char c);
};*/

/*
Draw colored instance
#define td_indent 2 // Top & down ident
#define symbol_count 3


void draw_instance(int y, int x, ColorPair &color, char name[]) {

    // Ending offset
    int ending_xoffset = COLS/2;
    int ending_yoffset = ROWS/2;
    
    // Level offset
    int map_xoffset = (COLS/2) * symbol_count + (COLS%2); // center of the screen
    int map_yoffset = (ROWS+(td_indent*2))/2-(1 +(ROWS%2)); 

    mvprintw(
         ceil(ending_yoffset - map_yoffset) + (y+td_indent), // Y pos 
         ceil(ending_xoffset - map_xoffset) + (x*symbol_count), // X pos 
         name // S pos 
    );
} 

int main() {
    // Draw the map
    ColorPair color = colorPairs.at(c_player);
    draw_instance(0, 0, color, s_player);
    return 0;
}

// testing
int main() {
    // Example usage
    SetColor(c_player);
    cout << "Player" << reset << endl;

    SetColor(c_treasure);
    cout << "Treasure" << reset << endl;

    SetColor(42); // Default color
    cout << "Default" << reset << endl;

    return 0;
} 

int main() {
    draw_instance(0, 0, c_player, s_player);
} 
*/
