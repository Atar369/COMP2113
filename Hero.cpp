#include "Hero.h"

// testing
void Hero_run(int &scn_num, int &map_code, int &event_num, Player &player) {
    typedef enum {
    hero_house,
    girl_house,
    oldman_house,
    village,
    outside_village,
    forest,
    monster,
    castle,
    back_village,
    all_dead,
    } map_transition;

    vector<vector<short> > current_map;
        
    map_transition map_state;    

    switch(map_code) {
        case 0:
            map_state = hero_house;
        break;

        case 1:
            map_state = girl_house;
        break;

        case 2:
            map_state = oldman_house;
        break;

        case 3:
            map_state = village;
        break;

        case 4:
            map_state = outside_village;
        break;

        case 5:
            map_state = forest;
        break;

        case 6:
            map_state = monster;
        break;

        case 7:
            map_state = back_village;
        break;

        case 8:
            map_state = all_dead;
        break;

        case 9:
            map_state = castle;
        break;
    }
    
    current_map = map_code_mapping.at(map_code);

    while (true) {
        int offsety = 0;
        int offsetx = 0;
        // Clear screen
        system("clear");
        
        switch(map_state) {

            case hero_house: // hero house
                map_code = 0;

                // event 1
                if (event_num == 1)
                    window.handle_choice(current_map, scn_num, event_num, player);
                
                // door transition
                if (current_map[player.y][player.x] == i_door || current_map[player.y][player.x] == i_leftdoor || current_map[player.y][player.x] == i_rightdoor)   {
                    map_state = village;
                    offsety = - player.y;
                }
                   
            break;
            
            case girl_house: // girl's house
                map_code = 1;
                if (current_map[player.y][player.x] == i_door || current_map[player.y][player.x] == i_leftdoor || current_map[player.y][player.x] == i_rightdoor)  {
                    map_state = village;
                    offsety = - player.y;
                }
            break;

            case oldman_house: 
                map_code = 2;
                if (current_map[player.y][player.x] == i_door || current_map[player.y][player.x] == i_leftdoor || current_map[player.y][player.x] == i_rightdoor)  {
                    map_state = forest;
                }

            break;

            case village:
                map_code = 3;

                if (player.y <= 0 && player.x <= 24 && player.x >= 22) {
                    map_state = hero_house;
                    offsety = 32 - 1;
                }

                if (player.y <= 0 && player.x <= 14 && player.x >= 12) {
                    map_state = girl_house;
                    offsety = 32 - 1;
                }    
/*
                if (player.x >= 32) {
                    map_state = forest;
                    //player.x = 1;
                }

                if (player.y >= 324) {
                    //player.y = 1;
                    map_state = monster;
                }
*/
                if (player.chat_npc) {
                    
                    keyboard.key = KEY_SPACE;

                    while (keyboard.key == KEY_SPACE) {
                        chat.loadChat("npc", map_code, scn_num, player);
                        window.Print_buffer(current_map, player, font_white);
                        keyboard.get_userInput();
                    }
                    
                    system("clear");
                    player.chat_npc = 0;

                }

            break;

            case outside_village:
                map_code = 4;
            break;

            case forest:
                map_code = 5;
            break;

            case monster:
                map_code = 6;
            break;
            
            case castle:
                map_code = 7;
            break;

            case back_village:
                map_code = 8;
            break;

            case all_dead:
                map_code = 9;
            break; 
        }
        
        current_map = map_code_mapping.at(map_code); 

        draw_map(current_map, player);

        player.x += offsetx;
        player.y += offsety;

        while (keyboard.key_pressed()) {
            keyboard.get_userInput();
        }
        
        if (keyboard.key == KEY_EXIT) {
            break;
        }
        if (keyboard.key == KEY_UP) {
            player.moveUp();
        }
        if (keyboard.key == KEY_DOWN) {
            player.moveDown();
        }
        if (keyboard.key == KEY_LEFT) {
            player.moveLeft();
        }
        if (keyboard.key == KEY_RIGHT) {
            player.moveRight();
        }

        // Move the player
        player.player_move(keyboard.key, current_map);
        player.player_collision(current_map);

    }

}

/* test
int main() {
    Hero_run();
    cout << show_cursor;
}  */ 
