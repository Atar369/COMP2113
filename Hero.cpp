#include "Hero.h"

// testing
void Hero_run() {

    typedef enum {
    hero_house,
    girl_house,
    villager_house,
    village_top_left,
    village_top_right,
    village_bottom_left,
    village_bottom_right,
    woods,
    puzzle,
    castle,
    } map_transition;

    // Player - Hero
    player.x = 4;
    player.y = 4;
    player.symbol = "|@|";

    Window window;

    vector<vector<short> > current_map;
    
    map_transition map_state;

    int map_code = 0;
    map_state = hero_house; // Hero start at hero house
    current_map = map_code_mapping.at(map_code);

    while (true) {
        int offsety = 0;
        int offsetx = 0;
        // Clear screen
        system("clear");

        switch(map_state) {

            case hero_house: // hero house
                map_code = 0;
                if (window.event_num == 1) {
                    window.handle_choice(current_map);
                }
                if (current_map[player.y][player.x] == i_door)  {
                    map_state = village_top_left;
                    offsety = 6;
                }
                // door transition    
            break;
            
            case girl_house: // girl's house
                map_code = 1;
                if (current_map[player.y][player.x] == i_door)  {
                    map_state = village_top_right;
                    offsety = 10;
                }
            break;

            case villager_house: 
                map_code = 2;
                if (current_map[player.y][player.x] == i_door)  {
                    map_state = village_top_right;
                    //player.y = 15;
                }
            break;

            case village_top_left:
                map_code = 3;
                if (player.x >= MAP_HEIGHT) {
                    map_state = village_bottom_left;
                    //player.x = 1;
                }
                if (player.y >= MAP_WIDTH) {
                    //player.y = 1;
                    map_state = village_top_right;
                }
            break;
        }
        
        current_map = map_code_mapping.at(map_code); 

        draw_map(current_map);

        player.x -= offsetx;
        player.y -= offsety;

        int key_pressed = keyboard.key_pressed();

        while (key_pressed) {
            keyboard.get_userInput();
        }
        
        if (keyboard.key == KEY_EXIT) {
            break;
        }
        if (keyboard.key == KEY_UP) {
            moveUp();
        }
        if (keyboard.key == KEY_DOWN) {
            moveDown();
        }
        if (keyboard.key == KEY_LEFT) {
            moveLeft();
        }
        if (keyboard.key == KEY_RIGHT) {
            moveRight();
        }

        // Move the player
        player_move(keyboard.key, current_map);
        player_collision(current_map);
    }
}

/* test
int main() {
    Hero_run();
    cout << show_cursor;
}  */ 
