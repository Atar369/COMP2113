#include "Hero.h"

unordered_map<int, vector<string> > Hero_endings = {

    {1, {
        "You saw monsters everywhere.",
        "You was scared.",
        "You ran away.",
        "Ran as far as you could.",
        "Until you went back to the village.",
        "Rushed into your house.",
        "You was safe.",
        "..."
        "You chosed to be a Hero.",
        "But you scare to be a Hero.",
        "One day, you get out of your room. You saw another 'Hero'.",
        "'He' was the one, you know it.",
        "With 'his' powerful sword, shining under the sunlight.",
        "His eyes, full of courage and determination.",
        "Suddenly, you realized that you are just",
        "a normal person",
        "who dreamed to be a Hero.",
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
        "After searching for days, you still couldn't find her and went back to the village.",
        "But the villagers saw you talked to a monster happily.",
        "They think you betrayed them.",
        "You supported the evil side.",
        "You will make them all die.",
        "No matter how hard you tried to explain, you couldn't make them believe you.",
        "You being hated by the villagers.",
        "Suddenly, you realized that is the true 'monster' is ... ",
        "... the villagers.",
        "Or maybe, it's human.",
        "Biased, selfish, and ignorant.",
        "'Monster' that you can't defeat.",
        "Ending 4: 'Monster'"
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

    while (!player.reach_ending) {
        int offsety = 0;
        int offsetx = 0;
        // Clear screen
        system("clear");
        
        switch(map_state) {

            case hero_house: // hero house
                progress.map_code = 0;

                // event 1
                if (progress.event_num == 1) 
                    window.handle_choice(progress, player);
                
                // door transition
                if (current_map[player.y][player.x] == i_door || current_map[player.y][player.x] == i_leftdoor || current_map[player.y][player.x] == i_rightdoor)   {
                    map_state = village;
                    offsety = - 31;
                } 

                // ending 1
                if (progress.scn_num == 4) {
                    player.x = 9;
                    player.y = 9;
                    progress.ending_num = 1;
                    player.reach_ending = true;
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

                if (player.touch_oldman) {
                    if (!progress.talked_to_oldman && progress.scn_num == 2){
                        chat.loadChat("old man hero", progress.map_code, progress.scn_num, player, font_cyan);
                        progress.talked_to_oldman = 1;
                    }    
                    else if (progress.talked_to_oldman && !progress.talked_to_robert) { // choice not yet made but have talked to the old man
                        chat.loadChat("old man talked", progress.map_code, progress.scn_num, player, font_cyan);
                    }
                    else if (progress.talked_to_oldman && progress.talked_to_robert) {
                        if (progress.scn_num == 3) {
                            chat.loadChat("old man robert took", progress.map_code, progress.scn_num, player, font_cyan);
                        }
                        else if (progress.scn_num == 4) {
                            chat.loadChat("old man robert leave", progress.map_code, progress.scn_num, player, font_cyan);    
                        }
                    }    
                    else {
                        keyboard.key = KEY_SPACE;

                        while (keyboard.key == KEY_SPACE) {
                        string contents = chat.oldmanchat();
                        window.build_buffer(contents);
                        window.Print_buffer(current_map, player, font_cyan);
                        keyboard.get_userInput();
                        }
                        system("clear");
                    }
                    player.touch_oldman = 0;
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

                if (player.x == 25 && player.y >= 4 && player.y <= 13 && progress.talked_to_oldman && progress.first_time_entering_store) { // enter store after talked to old man, finding sword
                        chat.loadChat("enter store", progress.map_code, progress.scn_num, player, font_white);
                        progress.first_time_entering_store = false;
                }

                if (progress.event_num == 2) {
                    if (player.touch_robert && progress.talked_to_oldman) {
                            window.handle_choice(progress, player);
                            player.touch_robert = 0;
                            progress.talked_to_robert = 1;
                            progress.can_enterCastle = 1;
                            progress.can_enterMonster = 1;
                    }
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
                        chat.loadChat("npc", progress.map_code, progress.scn_num, player, font_white);
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

                if (progress.can_enterMonster) {
                    if (player.y >= 31) {
                        map_state = monster;
                        offsety = -30;
                    }
                }
                else {
                    if (player.y >= 31) {
                        player.y = 30;
                        if (progress.scn_num == 2) {
                            chat.loadChat("no sword", progress.map_code, progress.scn_num, player, font_red);
                        }
                        else if (progress.scn_num == 6) {
                            chat.loadChat("scare", progress.map_code, progress.scn_num, player, font_red);
                        }
                    }
                } 

                if (player.x <= 0) {
                    map_state = outside_village;
                    offsetx = 35;
                }

                if (progress.can_enterCastle) {
                    if (player.x >= 35) {
                        map_state = castle;
                        offsetx = -36;
                    }
                }
                else {
                    if (player.x >= 35) {
                        player.x = 34;
                        if (progress.scn_num == 2) {
                            chat.loadChat("no sword", progress.map_code, progress.scn_num, player, font_red);
                        }
                    }
                } 

            break;

            case monster:
                progress.map_code = 6;

                if (progress.scn_num == 2 && player.y >= 8) { // not yet have sword
                    chat.loadChat("no sword", progress.map_code, progress.scn_num, player, font_red);
                    progress.can_enterMonster = false;
                    progress.map_code = 5;
                    player.x = 18;
                    player.y = 30;
                    map_state = forest;
                }
                
                // if the player chose to leave the sword, he will be teleported back to the village (scare and escaped)
                if (progress.scn_num == 4 && player.y >= 8) {
                    progress.map_code = 0;
                    player.x = 9;
                    player.y = 9;
                    progress.ending_num = 1;
                    map_state = hero_house;
                    player.reach_ending = true;
                }

                if (player.y <= 0) {
                    map_state = forest;
                    offsety = 31;
                }

                if (progress.event_num == 3 && player.y >= 5) {
                    window.handle_choice(progress, player);
                    // if the player chose to escape, the player will be teleported back to the forest and cannot enter the monster's lair
                    if (progress.scn_num == 6) {
                        progress.can_enterMonster = false;
                        progress.map_code = 5;
                        player.x = 18;
                        player.y = 30;
                        map_state = forest;
                    }
                }

                if (progress.event_num == 4 && player.touch_monster) {
                    window.handle_choice(progress, player);
                    player.touch_monster = 0;
                }

                if (progress.scn_num == 3 && player.y == 5 && !progress.saw_monster) {
                    chat.loadChat("hero saw", progress.map_code, progress.scn_num, player, font_white);
                    progress.saw_monster = 1;
                }
                if (progress.scn_num == 3 && player.y == 8 && !progress.monster_killed) {
                    chat.loadChat("hero kill", progress.map_code, progress.scn_num, player, font_yellow);
                    progress.monster_killed = 1;
                }

            break;
            
            case castle:
                progress.map_code = 7; 

                if (progress.scn_num == 2 && player.x >= 5) { // not yet have sword
                    chat.loadChat("no sword", progress.map_code, progress.scn_num, player, font_red);
                    progress.can_enterCastle = false;
                    progress.map_code = 5;
                    player.x = 34;
                    player.y = 16;
                    map_state = forest;
                }

                // if the player chose to leave the sword, he will be teleported back to the village (scare and escaped)
                if (progress.scn_num == 4 && player.x >= 5) {
                    progress.map_code = 0;
                    player.x = 9;
                    player.y = 9;
                    progress.ending_num = 1;
                    map_state = hero_house;
                    player.reach_ending = true;
                }

                if (player.y >= 31 && player.x >= 16 && player.x <= 19) {
                    map_state = back_village;
                    offsety = -17;
                }
                if (player.x < 0) {
                    map_state = forest;
                    offsetx = 36;
                }

                if (progress.first_time_entering_castle && (progress.scn_num == 1 || progress.scn_num == 6)) {
                    chat.loadChat("enter castle", progress.map_code, progress.scn_num, player, font_white);
                    progress.first_time_entering_castle = false;
                }

                if (progress.first_time_entering_castle && progress.scn_num == 3 && player.x == 5) {
                    chat.loadChat("hero kill all", progress.map_code, progress.scn_num, player, font_red);
                    progress.first_time_entering_castle = false;
                }

                if (progress.event_num == 5 && player.touch_dragon) {
                    window.handle_choice(progress, player);
                    player.touch_dragon = 0;
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
            string color = Hero_ending_color_mapping.at(progress.ending_num);
            window.Print_endings(Hero_endings.at(progress.ending_num), color);
            return;
        }

        current_map = map_code_mapping.at(progress.map_code); 

        if (progress.map_code == 6 && progress.monster_killed) {
            change_map(current_map, i_monster, i_deaddragonnpc);
        }
/*
        if (progress.map_code == 7 && progress.scn_num == 3) {
            if (player.touch_dragon) {
                change_map(current_map, i_dragon, i_deaddragon);
                player.touch_dragon = 0;
            }
            else if (player.touch_dragonnpc) {
                change_map(current_map, i_dragonnpc, i_deaddragonnpc);
                player.touch_dragonnpc = 0;
            }    
        }*/

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
