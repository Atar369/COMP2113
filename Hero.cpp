#include "Hero.h"

unordered_map<int, vector<string> > Hero_endings = {

    {1, {
        "You saw monsters everywhere.",
        "You were scared.",
        "You ran away.",
        "Ran as far as you could.",
        "Until you went back to the village.",
        "Rushed into your house.",
        "You was safe.",
        "..."
        "You chose to be a Hero.",
        "But you are scared to become a Hero.",
        "One day, you get out of your room. You saw another 'Hero'.",
        "'He' was the one, you knew it.",
        "With 'his' powerful sword, shining under the sunlight.",
        "His eyes, full of courage and determination.",
        "Suddenly, you realized that you are just",
        "a normal person",
        "who dreamed to be a Hero.",
        "Ending 1: Dreamer"
        }
    },
    {2, { // not yet done
        "You decided to hide from the monster.",
        "You found a hiding spot and stayed there for hours.",
        "You yelled in despair 'Why!!!!! I shouldn't die here!!! I... I am the ch...'",
        "The monster located you by tracking your footsteps, staring at you at the moment.",
        "The monster swallowed you before he finished talking.",
        "You were never seen again.",
        "Ending 2 : The Puny Hero"
        }
    },
    {3, { // not yet done
        "You decided to befriend the monster.",
        "You offered the monster some food and you became friends.",
        "The monster protected you from other dangers.",
        "You lived happily ever after.",
        "Ending 3 : Peace At Last"
        }
    },
    {4, {
        "After searching for days, you still couldn't find her and went back to the village.",
        "But the villagers saw you talking to a monster happily.",
        "They think you betrayed them.",
        "You supported the evil side.",
        "You will make them all die.",
        "No matter how hard you tried to explain, you couldn't make them believe you.",
        "You are being hated by the villagers.",
        "Suddenly, you realized that the real 'monsters' are ... ",
        "... the villagers.",
        "Or maybe, it's humans.",
        "Biased, selfish, and ignorant.",
        "'Monsters' that you can't defeat.",
        "Ending 4: 'Monster'"
        }
    },
    {5, {
        "You decided to fight the monster.",
        "You tried your best, but your attacks meant nothing to the monster.",
        "The monster opened its mouth and swallowed you whole.",
        "You were never seen again.",
        "Ending 5: Why you try?"     
        }
    },
    {6, {
        "                    ",
        "                    ",
        "???: ... hey",
        "???: maybe you can try another character",
        "???: the hero is not the only one who can save the world",
        "???: they are on the same timeline",
        "???: one can affect the other",
        "???: put yourself into death, you will find the truth",
        "???: ...",
        "                     ",
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

    bool key_pressed = 0;

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

    if (progress.event_num == 1) {
        chat.loadChat("intro", 0, 0, player, font_white);
    }

    sleep(1);

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
                if (progress.event_num == 1) {
                    draw_map(current_map, player);
                    usleep(1000000);
                    window.handle_choice(progress, player);
                }

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
                    else if (progress.talked_to_oldman && progress.talked_to_robert && !(progress.get_treasure1 && progress.get_treasure2 && progress.get_treasure3)) {
                        if (progress.scn_num == 3) {
                            chat.loadChat("old man robert took", progress.map_code, progress.scn_num, player, font_cyan);
                        }
                        else if (progress.scn_num == 4) {
                            chat.loadChat("old man robert leave", progress.map_code, progress.scn_num, player, font_cyan);    
                        }
                    }
                    else if (progress.get_treasure1 && progress.get_treasure2 && progress.get_treasure3 && !progress.all_treasure) {
                        chat.loadChat("old man all treasure", progress.map_code, progress.scn_num, player, font_cyan);
                        progress.all_treasure = 1;
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

                if (player.x == 25 && player.y >= 4 && player.y <= 13 && progress.first_time_entering_store && progress.scn_num == 2 && progress.talked_to_oldman) { // enter store after talked to old man, finding sword
                    chat.loadChat("enter store", progress.map_code, progress.scn_num, player, font_white); // enter store under the hint of oldman
                    progress.first_time_entering_store = false; 
                }

                if (player.touch_librarian) {
                    chat.loadChat("librarian", progress.map_code, progress.scn_num, player, font_green);
                    player.touch_librarian = 0;
                }

                if (player.touch_penny) {
                    chat.loadChat("penny", progress.map_code, progress.scn_num, player, font_blue);
                    player.touch_penny = 0;
                }

                if (player.touch_cooper) {
                    if ((progress.scn_num == 2 || progress.scn_num == 3) && !progress.talked_to_cooper) {
                        chat.loadChat("cooper the guider", progress.map_code, progress.scn_num, player, font_green);
                        sleep(1);
                        window.Print_fighting("fight class1", player, font_yellow, KEY_P);
                        window.Print_fighting("fight class2", player, font_yellow, KEY_G); 
                        window.Print_fighting("fight class3", player, font_yellow, KEY_F); 
                        window.Print_fighting("fight class4", player, font_yellow, KEY_K);  
                        window.Print_fighting("fight class5", player, font_yellow, KEY_C);
                        window.Print_fighting("fight class6", player, font_yellow, KEY_J);
                        window.Print_fighting("fight class7", player, font_yellow, 0);
                        progress.get_treasure1 = 1;
                        progress.talked_to_cooper = 1;
                    }
                    else if ((progress.scn_num == 2 || progress.scn_num == 3) && progress.talked_to_cooper) {
                        chat.loadChat("after fight class", progress.map_code, progress.scn_num, player, font_yellow);
                    }
                    else {    
                        chat.loadChat("cooper", progress.map_code, progress.scn_num, player, font_green);
                    }
                    player.touch_cooper = 0;
                }

                if (player.touch_robert) {
                    if (progress.event_num == 2) {
                        window.handle_choice(progress, player);
                        progress.talked_to_robert = 1;
                        progress.can_enterCastle = 1;
                        progress.can_enterMonster = 1;
                        progress.talked_to_oldman = 1;
                    }
                    else {
                        chat.loadChat("robert", progress.map_code, progress.scn_num, player, font_yellow);
                    }
                    player.touch_robert = 0;
                }
                

                if (progress.scn_num == 6) {
                    progress.ending_num = 1;
                    player.reach_ending = true;
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

                if (progress.talked_to_oldman) {
                    if (player.touch_key) {
                        progress.key_take_count++;
                        player.touch_key = 0;
                    }
                }; 

            break;

            case monster:
                progress.map_code = 6;

                if (progress.event_num == 3 && player.y >= 5) { // scn 1 to event 3
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

                if (progress.scn_num == 2 && player.y >= 8) { // not yet have sword
                    chat.loadChat("no sword", progress.map_code, progress.scn_num, player, font_red);
                    progress.can_enterMonster = false;
                    progress.map_code = 5;
                    player.x = 18;
                    player.y = 30;
                    map_state = forest;
                }
                
                if (progress.scn_num == 3 && player.y == 5 && !progress.saw_monster) {
                    chat.loadChat("hero saw", progress.map_code, progress.scn_num, player, font_white);
                    progress.saw_monster = 1;
                }
                if (progress.scn_num == 3 && player.y == 8 && !progress.monster_noticed && progress.saw_monster) {
                    chat.loadChat("monster notice", progress.map_code, progress.scn_num, player, font_yellow);
                    progress.monster_noticed = 1;
                }
                if (progress.scn_num == 3 && player.touch_monster && !progress.monster_killed && progress.monster_noticed) {
                    chat.loadChat("hero kill", progress.map_code, progress.scn_num, player, font_yellow);
                    player.touch_monster = 0;
                    progress.monster_killed = 1;
                    progress.get_treasure3 = 1;
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

                if (progress.event_num == 4 && player.touch_monster) { // after scn 5
                    window.handle_choice(progress, player);
                    player.touch_monster = 0;
                }

                // transition to forest, keep col unchanged, row = 0
                if (player.y <= 0) {
                    map_state = forest;
                    offsety = 31;
                }

            break;
            
            case castle:
                progress.map_code = 7; 

                if (progress.first_time_entering_castle && (progress.scn_num == 1 || progress.scn_num == 6)) {
                    if (progress.girl_saved_monster) {
                        chat.loadChat("enter castle", progress.map_code, progress.scn_num, player, font_white);
                        progress.first_time_entering_castle = false;
                    }
                    else {
                        current_map = map_code_mapping.at(progress.map_code);
                        draw_map(current_map, player);
                        progress.map_code = 0;
                        player.x = 9;
                        player.y = 9;
                        progress.ending_num = 1;
                        map_state = hero_house;
                        player.reach_ending = true;
                    }
                }

                if (progress.scn_num == 2 && player.x >= 5) { // not yet have sword
                    chat.loadChat("no sword", progress.map_code, progress.scn_num, player, font_red);
                    progress.can_enterCastle = false;
                    progress.map_code = 5;
                    player.x = 34;
                    player.y = 16;
                    map_state = forest;
                }

                if (progress.first_time_entering_castle && progress.scn_num == 3 && player.x == 3) {
                    chat.loadChat("hero kill all", progress.map_code, progress.scn_num, player, font_red);
                    progress.first_time_entering_castle = false;
                }

                if (progress.scn_num == 3 && player.touch_dragon) {
                    map_state = all_dead;
                    player.touch_dragon = 0;
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
                current_map = map_code_mapping.at(progress.map_code);
                draw_map(current_map, player);
                sleep(2);
                system("clear");
                sleep(1);
                progress.ending_num = 2;
                player.reach_ending = true; 
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

        if (progress.map_code == 5 && progress.talked_to_oldman && !progress.get_treasure2) {
            

            if (progress.key_take_count == 0) {
                current_map[17][5] = i_key;
            }
            else if (progress.key_take_count == 1) {
                if (!progress.saw_key) {
                    chat.loadChat("saw key", progress.map_code, progress.scn_num, player, font_yellow);
                    progress.saw_key = 1;
                }
                current_map[26][26] = i_key;
            }
            else if (progress.key_take_count == 2) {
                current_map[3][32] = i_key;
            }

            if (progress.key_take_count >= 3 && !player.open_treasure) {
                if(!progress.saw_treasure) {
                    chat.loadChat("saw treasure", progress.map_code, progress.scn_num, player, font_yellow);
                    progress.saw_treasure = 1;
                    for (int i = 0; i < 32 - 8; i++) {
                        current_map[3][31 - i] = i_key;
                        draw_map(current_map, player);
                        usleep(100000);
                        system("clear");
                    }
                }
                
                current_map[2][8] = i_treasure;
                
            }

            if (player.open_treasure) {
                chat.loadChat("open treasure", progress.map_code, progress.scn_num, player, font_yellow);
                progress.get_treasure2 = 1;
            }
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

        if (progress.all_treasure && !progress.girl_rewind) {
            /*
            change_map(current_map, i_oldman, i_gamemaster);
            current_map[9][17] = i_gamemaster;*/
            chat.loadChat("boss no rewind", progress.map_code, progress.scn_num, player, font_red);
            sleep(1);
            progress.ending_num = 6;
            player.reach_ending = true;
            string color = Hero_ending_color_mapping.at(progress.ending_num);
            window.Print_endings(Hero_endings.at(progress.ending_num), color);
            system("clear");
            sleep(1);
            return;
        }
        else if (progress.all_treasure && progress.girl_rewind) {
            // chat.loadChat("boss rewind", progress.map_code, progress.scn_num, player, font_red);
        }

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
