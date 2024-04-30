#include "Girl.h"

unordered_map<int, vector<string> > Girl_endings = {

    {1, { //killed by monster (not rescuing him)
        "The monster thought you were going to attack it,",
        "so it started to chase you.",
        "You tried to run away, but the monster was too fast.",
        "The monster caught you and killed you.",
        "Ending 1: Cold-Blooded Animal"
        }
    },
    {2, { //no villagers believe her
        "No one believed you.",
        "The villagers thought you were crazy.",
        "They took you to psychiatrist.",
        "You were locked in a room...",
        "...and never saw the sunlight again.",
        "Ending 2: 'Three People Become Tigers'"
        }
    },
    {3, { //all killed by hero and you were saved //Happy
        "He rescued you from the Dragon.",
        "You were so grateful to him and hugged him.",
        "You two fell in love after that.",
        "You two got married and lived happily ever after.",
        "Is this the life you want?",
        "Ending 3: Happy Ending?",
        }
    },
    {4, { //all killed by hero and you were saved //Sad
        "He thought he rescued you from the Dragon.",
        "Everyone said you should be grateful to him.",
        "But only you know the truth...",
        "But there isn't anyone you can talk with.",
        "You can only hide the truth for the rest of the life.",
        "Ending 4: The Untold Truth",
        }
    },
    {5, { //girl use time rewind and save dragon //true ending reveals
        "......",
        "...................",
        "....................................",
        "You: Where is this?"
        "You: Hello? Is anyone here?",
        "???: Girl, we meet again.",
        "???: I am the one who gave you the power of time rewinding.",
        "You: Why am I here?",
        "???: I've noticed that you have been using your power to help others.",
        "???: You have used it well.",
        "???: Really really well.",
        "???: I am proud of you.",
        "You: Who are you?",
        "You: Why did you give me this power?",
        "???: Don't you know who I am?",
        "???: You should know me very well.",
        "...",
        "......",
        ".........................?",
        "Girl: I am you.",
        "You: You am I?",
        "Girl: You do notice you were have been repeatedly sent back to the past, right?",
        "Girl: The same story happened again and again...",
        "Girl: The same people, the same events...",
        "Girl: Amidst this endless loop,",
        "Girl: One day, I suddenly discovered my ability to rewind time.",
        "Girl: So at the beginning of every story, I remind myself of this power.",
        "Girl: I'm glad that you made it here.",
        "Girl: Until we meet again.",
        "Girl: ...",
        }
    },
};

void Girl_run(Progress &progress, Player &player) { //start of the program
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

    switch(progress.map_code) { //map transition
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
    
    if (progress.scn_num == 0) { //load intro
        chat.loadChat("intro", 0, 0, player, font_white);
        sleep(1);
    }

    current_map = map_code_mapping.at(progress.map_code);

    while (!player.reach_ending) { //start of the loop
        int offsety = 0;
        int offsetx = 0;
        // Clear screen
        system("clear");
        
        switch(map_state) {

            case hero_house: // hero's house
                progress.map_code = 0;
                
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

                if (!progress.finish_intro && progress.scn_num == 0) {
                    chat.loadChat("intro house", progress.map_code, progress.scn_num, player, font_cyan);
                    progress.finish_intro = 1;
                    progress.scn_num = 5;
                }

            break;

            case oldman_house: //oldman's house
                progress.map_code = 2;
                if (player.y <= 0) {
                    map_state = outside_village;
                    offsety = 30;
                }

                if (player.touch_oldman) {
                    
                    keyboard.key = KEY_SPACE;

                    while (keyboard.key == KEY_SPACE) {
                        string contents = chat.oldmanchat();
                        window.build_buffer(contents);
                        window.Print_buffer(current_map, player, font_cyan);
                        keyboard.get_userInput();
                        }
                        system("clear");
                    
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

                if (player.touch_librarian) {
                    chat.loadChat("librarian", progress.map_code, progress.scn_num, player, font_green);
                    player.touch_librarian = 0;
                }

                if (player.touch_penny) {
                    chat.loadChat("penny", progress.map_code, progress.scn_num, player, font_blue);
                    player.touch_penny = 0;
                }

                if (player.touch_robert) {
                    chat.loadChat("robert", progress.map_code, progress.scn_num, player, font_yellow);
                    player.touch_robert = 0;
                }
                if (player.touch_cooper) {            
                    if (!progress.talked_to_cooper) {
                        chat.loadChat("cooper the healer", progress.map_code, progress.scn_num, player, font_green);
                        sleep(1);
                        window.Print_healing("patient1", player, font_yellow);
                        window.Print_healing("patient2", player, font_yellow); 
                        window.Print_healing("patient3", player, font_yellow); 
                        chat.loadChat("after healing", progress.map_code, progress.scn_num, player, font_yellow);
                        progress.get_certificate = 1;
                        progress.talked_to_cooper = 1;
                    }
                    else {    
                        chat.loadChat("cooper", progress.map_code, progress.scn_num, player, font_green);
                    }
                    player.touch_cooper = 0;
                }

                if (progress.first_time_entering_village && progress.scn_num == 5) {
                    chat.loadChat("enter village", progress.map_code, progress.scn_num, player, font_cyan);
                    progress.first_time_entering_village = false;
                }

                if (progress.scn_num == 9) { 
                    chat.loadChat("no one believe", progress.map_code, progress.scn_num, player, font_red);
                    progress.event_num = 0;
                    progress.ending_num = 2;
                    player.reach_ending = true;
                }

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

                if (player.x <= 0) {
                    map_state = outside_village;
                    offsetx = 35;
                }

                if (player.y >= 31) {
                        map_state = monster;
                        offsety = -30;
                }

                if (progress.hero_killed_all == 0 && player.x >= 35) {
                    map_state = castle;
                    offsetx = -36;
                }
                
                if (progress.hero_killed_all == 1 && player.x >= 35) {
                    progress.scn_num = 10;
                    map_state = all_dead;
                    offsetx = -36;
                }

                if (progress.first_time_entering_forest && progress.scn_num == 5) {
                    chat.loadChat("enter forest", progress.map_code, progress.scn_num, player, font_cyan);
                    progress.first_time_entering_forest = false;
                }

            break;

            case monster:

                progress.map_code = 6;

                if (player.y <= 0) {
                    map_state = forest;
                    offsety = 31;
                }

                if (progress.scn_num == 5 && !progress.talked_to_monster && player.touch_monster) {
                    progress.scn_num = 6;                    
                    progress.event_num = 1;
                    player.touch_monster = 0;
                    progress.talked_to_monster = 1;
                    window.handle_choice(progress, player);
                    if (progress.scn_num == 1) {
                        progress.ending_num = 1;
                        player.reach_ending = true;
                    }
                }   

                if (progress.scn_num == 2 && progress.hero_killed_all == 0) {
                    progress.scn_num = 7;
                    map_state = castle; 
                    player.x = 18;
                    player.y = 30;
                }

                if (progress.scn_num == 2 && progress.hero_killed_all == 1) {
                    progress.scn_num = 10;
                    map_state = all_dead;
                    offsety = 30;
                }   
 

            break;
            
            case castle:
                progress.map_code = 7; 

                if (player.y >= 31 && player.x >= 16 && player.x <= 19) {
                    map_state = back_village;
                    offsety = -17;
                }
                if (player.x < 0) {
                    map_state = forest;
                    offsetx = 35;
                }

                if (progress.first_time_entering_castle && (progress.scn_num == 5 || progress.scn_num == 7)) {
                    progress.scn_num = 7;
                    chat.loadChat("enter castle", progress.map_code, progress.scn_num, player, font_white);
                    progress.first_time_entering_castle = false;
                    progress.girl_know_fact = 1;
                }

                if (!progress.talked_to_dragon && player.touch_dragon) {
                    chat.loadChat("talk to dragon", progress.map_code, progress.scn_num, player, font_yellow);
                    player.touch_dragon = 0;
                    progress.talked_to_dragon = 1;
                    progress.scn_num = 8;           
                    progress.girl_know_fact = 1;            
                }

                if (progress.talked_to_dragon && player.touch_dragon) {
                    chat.loadChat("dragon", progress.map_code, progress.scn_num, player, font_yellow);
                    player.touch_dragon = 0;
                }
                
            break;

            case back_village: //the path back to village
                progress.map_code = 8;

                if (player.x <= 0) {
                    map_state = oldman_house;
                    offsetx = 31;
                }

                if (progress.first_time_entering_back_village && progress.scn_num == 8) {
                    chat.loadChat("back village", progress.map_code, progress.scn_num, player, font_yellow);
                    progress.first_time_entering_back_village = false;
                    progress.scn_num = 9;
                }

                if (progress.scn_num == 8) {
                    progress.scn_num = 9;
                }

            break;

            case all_dead:
                progress.map_code = 9;

                if (player.y >= 31) {
                    map_state = back_village;
                    offsety = -16;
                }

                if (progress.scn_num == 10 && progress.hero_killed_all && progress.hero_know_fact == 0 && progress.girl_know_fact == 1) {
                    progress.scn_num = 11;
                    chat.loadChat("all dead", progress.map_code, progress.scn_num, player, font_red);
                    chat.loadChat("hero save you", progress.map_code, progress.scn_num, player, font_yellow);
                    progress.ending_num = 3;
                    player.reach_ending = true;
                }    

                if (progress.scn_num == 10 && progress.hero_killed_all && progress.hero_know_fact == 1 && progress.girl_know_fact == 1) {
                    chat.loadChat("all dead", progress.map_code, progress.scn_num, player, font_red);
                    progress.event_num = 2;
                    window.handle_choice(progress, player);
                    if (progress.scn_num == 3) {
                        chat.loadChat("hero save you", progress.map_code, progress.scn_num, player, font_yellow);
                        progress.ending_num = 4;
                        player.reach_ending = true;
                    }
                    else if (progress.scn_num == 4) {
                        progress.girl_rewind = 1;
                        progress.ending_num = 5;
                        player.reach_ending = true;
                    }
                }
            break; 
            } 
        
        if (player.reach_ending) {
            string color = Girl_ending_color_mapping.at(progress.ending_num);
            window.Print_endings(Girl_endings.at(progress.ending_num), color);
            return;
        }

        current_map = map_code_mapping.at(progress.map_code); 

        // Amendment of map if needed 
        if (progress.scn_num == 7) {
            change_map(current_map, i_leftdoor, i_bed);
            change_map(current_map, i_rightdoor, i_bed);
            change_map(current_map, i_door, i_bed);
        }

        if (progress.scn_num == 8) {
            change_map(current_map, i_bed, i_leftdoor);
            change_map(current_map, i_bed, i_rightdoor);
            change_map(current_map, i_bed, i_door); 
        }

        draw_map(current_map, player);

        //change location of player when transiting to different map
        player.x += offsetx;
        player.y += offsety;

        //corporate with the keyboard
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
