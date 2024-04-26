#include "Hero.h"

unordered_map<int, vector<string> > Hero_endings = {
        {0, {"testing ending"}},
    {1, {
        "He chosed to be a Hero.",
        "But he didn't know how to fight.",
        "He went everywhere but still doesn't know how to fight.",
        "No matter how hard he tried, he was never able to defeat any monster.",
        "He went back to the village.",
        "Surprisingly, he saw another 'Hero'.",
        "'He' was the one, he knew it.",
        "With 'his' powerful sword, shining under the sunlight.",
        "Suddenly, he realized that he was just himself.",
        "A normal person, ...",
        "...who dreamed to be a Hero."
        "Ending 1: Dreamer"
        }
    },
    {2, { // not yet done
        "He decided to hide from the monster.",
        "He found a hiding spot and stayed there for hours.",
        "The monster eventually found him and swallowed him whole.",
        "He was never seen again.",
        }
    },
    {3, { // not yet done
        "He decided to befriend the monster.",
        "He offered the monster some food and they became friends.",
        "The monster protected him from other dangers.",
        "He lived happily ever after.",
        }
    },
    {4, {
        "He decided to talk with to monster.",
        "The monster surprised him by speaking back.",
        "The monster said that they were not enemies.",
        "They talked for hours and became friends.",
        "He asked the monster if it saw a girl walking around.",
        "The monster said no, but it would help him find her.",
        "He refused politely and went on his way.",
        "After searching for days, he still couldn't find her and went back to the village.",
        "The villagers told him that the girl has already been saved by another Hero.",
        "He was being forgotten."
        "He was just a normal person...",
        "Ending 4: Forgotten"
        }
    },
    {5, {
        "He decided to fight the monster.",
        "He tried his best, but his attacks meant nothing to the monster.",
        "The monster opened its mouth and swallowed him whole.",
        "He was never seen again.",
        "Ending 5: Why you try?"     
        }
    },
};

void Hero_run(Progress &progress, Player &player) {
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

    keyboard.key = 0;

    switch(progress.map_code) {
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
    
    current_map = map_code_mapping.at(progress.map_code);

    while (true) {
        int offsety = 0;
        int offsetx = 0;
        // Clear screen
        system("clear");
        
        switch(map_state) {

            case hero_house: // hero house
                progress.map_code = 0;

                // event 1
                if (progress.event_num == 1) 
                    window.handle_choice(current_map, progress.scn_num, progress.event_num, progress.ending_num, player);
                
                // door transition
                if (current_map[player.y][player.x] == i_door || current_map[player.y][player.x] == i_leftdoor || current_map[player.y][player.x] == i_rightdoor)   {
                    map_state = village;
                    offsety = - 31;
                } 
                   
            break;
            
            case girl_house: // girl's house
                progress.map_code = 1;
                if (current_map[player.y][player.x] == i_door || current_map[player.y][player.x] == i_leftdoor || current_map[player.y][player.x] == i_rightdoor)  {
                    map_state = village; 
                    offsety = - 31;
                }

            break;

            case oldman_house: 
                progress.map_code = 2;
                if (player.y <= 0) {
                    map_state = outside_village;
                    offsety = 30;
                }

            break;

            case village:
                progress.map_code = 3; 

                if (player.y <= 0 && player.x <= 24 && player.x >= 22) {
                    map_state = hero_house;
                    offsety = 31;
                }

                if (player.y <= 0 && player.x <= 14 && player.x >= 12) {
                    map_state = girl_house;
                    offsety = 31;
                }

                if (player.y >= 31) {
                    map_state = outside_village;
                    offsety = - 31;
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
                        chat.loadChat("npc", progress.map_code, progress.scn_num, player);
                        window.Print_buffer(current_map, player, font_white);
                        keyboard.get_userInput();
                    }
                    
                    system("clear");
                    player.chat_npc = 0;

                }

            break;

            case outside_village:
                progress.map_code = 4;
                if (player.y >= 31) {
                    map_state = oldman_house;
                    offsety = - 31;
                } 

                if (player.y <= 0) {
                    map_state = village;
                    offsety = 31;
                }

                if (player.x >= 35) {
                    map_state = forest;
                    offsetx = - 35;
                }

            break;

            case forest:
                progress.map_code = 5;
                if (player.y >= 31) {
                    map_state = monster;
                    offsety = -30;
                }

                if (player.x <= 0) {
                    map_state = outside_village;
                    offsetx = 35;
                }

                if (player.x >= 35) {
                    map_state = castle;
                    offsetx = - 36;
                }

            break;

            case monster:
                progress.map_code = 6;
                if (player.y <= 0) {
                    map_state = forest;
                    offsety = 31;
                }

                if (progress.event_num == 3 && player.y >= 5) {
                    window.handle_choice(current_map, progress.scn_num, progress.event_num, progress.ending_num, player);
                }

                if (progress.event_num == 4 && player.touch_monster) {
                    window.handle_choice(current_map, progress.scn_num, progress.event_num, progress.ending_num, player);
                }


            break;
            
            case castle:
                progress.map_code = 7; 
                if (player.y >= 31) {
                    map_state = back_village;
                    offsety = -17;
                }
                if (player.x < 0) {
                    map_state = forest;
                    offsetx = 36;
                }

            break;

            case back_village:
                progress.map_code = 8;
                if (player.x <= 0) {
                    map_state = oldman_house;
                    offsetx = 31;
                }

            break;

            case all_dead:
                progress.map_code = 9;
                if (player.y >= 31) {
                    map_state = back_village;
                    offsety = -16;
                }

            break; 
            } 
        
        if (player.reach_ending) {
            window.Print_endings(Hero_endings.at(progress.ending_num), font_red);
            return;
        }

        current_map = map_code_mapping.at(progress.map_code); 

        draw_map(current_map, player);

        player.x += offsetx;
        player.y += offsety;

        while (keyboard.key_pressed()) {
            keyboard.get_userInput();
        }
        
        if (keyboard.key == KEY_EXIT) {
            return;
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
