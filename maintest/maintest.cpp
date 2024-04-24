#include "maintest.h"

// Escape sequences for cursor positioning and movement
// \033[<L>;<C>H -> move cursor to line L, column C

int main() {
    // Enum for game states
    typedef enum {
        STATE_MENU,
        STATE_HTP,
        STATE_ACHIEVE,
        STATE_GAME,
        STATE_CONTIN,
        STATE_EXIT,
    } game_states;

    // Get the dimensions of the terminal window
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int rows = w.ws_row;
    int cols = w.ws_col;
    
     // Calculate the coordinates for centering the text
    int startRow = rows / 2;
    int startCol = cols / 2; // Adjust for the length of the longest string
    
    // Init current state
    game_states current_state;
    current_state = STATE_MENU;
    
    Progress progress;
    Keyboard keyboard;
    Window window;
    Player player;

    ////////////////
    // Main loop
    ///////////////

    // Menu menu
    // Buttons
    const string button_start_game[2] = {
        "> NEW GAME <",
        "  New Game  ",
    };

    const string button_continue[2] = {
        "> CONTINUE <",
        "  Continue  ",
    };

    const string button_HTP[2] = {
        "> HOW TO PLAY <",
        "  How to Play  ",
    };

    const string button_achieve[2] = {
        "> ACHIEVEMENTS <",
        "  Acheivements  ",
    };

    const string button_exit[2] = {
        "> EXIT <",
        "  Exit  ",
    };

    const string how_to_play[8] = {
        "How to Play",
        "W - Move Up                    E - Action                ",
        "A - Move Left                  Q - Exit to menu          ",
        "S - Move Down                  SPACE - Next page         ",
        "D - Move Right                 ENTER - Confirm           ",
        "Unlock different endings with different choices",
        "Enjoy the movie...                             ",
        "Good luck"
    };
    
    static int menu_button = 0;

    while (current_state != STATE_EXIT) {
        // Clear screen
        system("clear");
        std::cout << save_cursor_position; // Save cursor position
        std::cout << hide_cursor;  

  /**     int check_waiting = keyboard.waiting(keyboard.key);

        int check_pressed_key = keyboard.key_pressed(keyboard.key);
        
        // Check if the key is pressed
        while (check_pressed_key) {
            keyboard.get_userInput();
        }
        */

       // Predine the variables
        int select_start_game = 1, select_HTP = 1, select_achieve = 1, select_exit = 1, select_continue = 1;
        int choice_button = 0;

        // In menu state
        switch(current_state) {
            
            // Menu
            case STATE_MENU:

                system("clear");
                keyboard.key = 0;

                while (keyboard.key != KEY_ENTER) {
                    // Draw the logo
                    draw_logo(rows, cols);

                    // button
                    if (keyboard.key == KEY_UP) {
                        menu_button--;
                        if (menu_button <= 0) {
                            menu_button = 0;
                        }
                    }
                        
                    if (keyboard.key == KEY_DOWN) {
                        menu_button++;
                    } 

                    // if the player saved 
                    if (progress.checking_loading()) {
                        if (menu_button >= 4) {
                            menu_button = 4;
                        }

                        // check the button
                        if (menu_button == 0) {
                            select_start_game = 0;
                            select_continue = 1;
                            select_HTP = 1;
                            select_achieve = 1;
                            select_exit = 1;
                        } 
                        else if (menu_button == 1) {
                            select_start_game = 1;
                            select_continue = 0;
                            select_HTP = 1;
                            select_achieve = 1;
                            select_exit = 1;
                        }
                        else if (menu_button == 2) {
                            select_start_game = 1;
                            select_continue = 1;
                            select_HTP = 0;
                            select_achieve = 1;
                            select_exit = 1;
                        }
                        else if (menu_button == 3) {
                            select_start_game = 1;
                            select_continue = 1;
                            select_HTP = 1;
                            select_achieve = 0;
                            select_exit = 1;
                        }
                        else if (menu_button == 4){
                            select_start_game = 1;
                            select_continue = 1;
                            select_HTP = 1;
                            select_achieve = 1;
                            select_exit = 0;
                        }

                        // Position the cursor and print the text at the center
                        std::cout << default_format << startRow - logo_h_size + 9 << ";" << startCol - (button_start_game[select_start_game].length())/2 << "H" << button_start_game[select_start_game] << endl;

                        std::cout << default_format << startRow - logo_h_size + 11 << ";" << startCol - (button_continue[select_continue].length())/2 << "H" << button_continue[select_continue] << endl;

                        std::cout << default_format << startRow - logo_h_size + 13 << ";" << startCol - (button_HTP[select_HTP].length())/2 << "H" << button_HTP[select_HTP] << endl;

                        std::cout << default_format << startRow - logo_h_size + 15 << ";" << startCol - (button_achieve[select_achieve].length())/2 << "H" << button_achieve[select_achieve] << endl;

                        std::cout << default_format << startRow - logo_h_size + 17 << ";" << startCol - (button_exit[select_exit].length())/2 << "H" << button_exit[select_exit] << endl;

                        // Click handler
                        switch(menu_button) {
                            case 0:
                                current_state = STATE_GAME;
                                break;
                            case 1:
                                current_state = STATE_CONTIN;
                                break;
                            case 2:
                                current_state = STATE_HTP;
                                break;
                            case 3:
                                current_state = STATE_ACHIEVE;
                                break;
                            case 4:
                                current_state = STATE_EXIT;
                                break;    
                        }
                    }

                    else {
                        if (menu_button >= 3) {
                            menu_button = 3;
                        }
                        // check the button
                        if (menu_button == 0) {
                            select_start_game = 0;
                            select_HTP = 1;
                            select_achieve = 1;
                            select_exit = 1;
                        } 
                        else if (menu_button == 1) {
                            select_start_game = 1;
                            select_HTP = 0;
                            select_achieve = 1;
                            select_exit = 1;
                        }
                        else if (menu_button == 2) {
                            select_start_game = 1;
                            select_HTP = 1;
                            select_achieve = 0;
                            select_exit = 1;
                        }
                        else if (menu_button == 3){
                            select_start_game = 1;
                            select_HTP = 1;
                            select_achieve = 1;
                            select_exit = 0;
                        }

                        // Position the cursor and print the text at the center
                        std::cout << default_format << startRow - logo_h_size + 9 << ";" << startCol - (button_start_game[select_start_game].length())/2 << "H" << button_start_game[select_start_game] << endl;

                        std::cout << default_format << startRow - logo_h_size + 11 << ";" << startCol - (button_HTP[select_HTP].length())/2 << "H" << button_HTP[select_HTP] << endl;

                        std::cout << default_format << startRow - logo_h_size + 13 << ";" << startCol - (button_achieve[select_achieve].length())/2 << "H" << button_achieve[select_achieve] << endl;

                        std::cout << default_format << startRow - logo_h_size + 15 << ";" << startCol - (button_exit[select_exit].length())/2 << "H" << button_exit[select_exit] << endl;

                        // Click handler
                    switch(menu_button) {
                        case 0:
                            current_state = STATE_GAME;
                            break;
                        case 1:
                            current_state = STATE_HTP;
                            break;
                        case 2:
                            current_state = STATE_ACHIEVE;
                            break;
                        case 3:
                            current_state = STATE_EXIT;
                            break;    
                    }
                    
                    }
                    keyboard.get_userInput();
                }

                break;

            // Info
            case STATE_HTP:
                // How to play
                std::cout << default_format << 10 << ";" << startCol - (how_to_play[0].length())/2 << "H" << how_to_play[0] << endl; // title
                std::cout << default_format << 17 << ";" << startCol - (how_to_play[1].length())/2 << "H" << how_to_play[1] << endl; // keys
                std::cout << default_format << 19 << ";" << startCol - (how_to_play[2].length())/2 << "H" << how_to_play[2] << endl;
                std::cout << default_format << 21 << ";" << startCol - (how_to_play[3].length())/2 << "H" << how_to_play[3] << endl;
                std::cout << default_format << 23 << ";" << startCol - (how_to_play[4].length())/2 << "H" << how_to_play[4] << endl;
                std::cout << default_format << 25 << ";" << startCol - (how_to_play[5].length())/2 << "H" << how_to_play[5] << endl; // words
                std::cout << default_format << 27 << ";" << startCol - (how_to_play[6].length())/2 << "H" << how_to_play[6] << endl;
                std::cout << default_format << 30 << ";" << startCol - (how_to_play[7].length())/2 << "H" << how_to_play[7] << endl;

                keyboard.get_userInput();

                // Exit to menu
                if (keyboard.key == KEY_EXIT)
                    current_state = STATE_MENU;
                
                break;

            case STATE_ACHIEVE:
                std::cout << "Achievements" << endl;
                // to be implemented
                keyboard.get_userInput();

                // Exit to menu
                if (keyboard.key == KEY_EXIT)
                    current_state = STATE_MENU;
                break;

           // Game
            case STATE_GAME:

                // Clear previous progress
                progress.delete_progress();
                
                window.intro_character_choice(player);

                if (window.is_Hero) {
                    player.x = 4;
                    player.y = 4;
                    player.symbol = "|@|";
                    player.color = font_blue;
                    progress.map_code = 0;
                    progress.event_num = 1;
                    
                    // Start game
                    Hero_run(progress.scn_num, progress.map_code, progress.event_num, player);
                }
                else if (window.is_Girl) {
                    player.x = 4;
                    player.y = 4;
                    player.symbol = "|%|";
                    player.color = font_purple;
                    progress.map_code = 0;
                    progress.event_num = 2;
                    // Start game
                    //Hero_run(progress.scn_num, progress.map_code, progress.event_num, player);
                }    

                window.handle_save_choice(choice_button, progress.map_code, player);

                if (choice_button == 0) 
                    // save progress
                    progress.save_progress(progress.scn_num, progress.map_code, progress.event_num, player);

                current_state = STATE_MENU; 

                break;

            case STATE_CONTIN:
            
                progress.load_progress(player);

                if (player.color == font_blue) {
                    window.is_Hero = true;
                    player.symbol = "|@|";
                    // Continue game
                    Hero_run(progress.scn_num, progress.map_code, progress.event_num, player);
                }
                else if(player.color == font_purple) {
                    window.is_Girl = true;
                    player.symbol = "|%|";
                    // Continue game
                    //Hero_run(progress.scn_num, progress.map_code, progress.event_num, player);
                }
                
                window.handle_save_choice(choice_button, progress.map_code, player);

                if (choice_button == 0) 
                    // save progress
                    progress.save_progress(progress.scn_num, progress.map_code, progress.event_num, player);
                

                current_state = STATE_MENU; 

                break;

            case STATE_EXIT:
                std::cout << "Goodbye!" << endl;
                break;
                }
 
        }
    
    system("clear"); // Clear screen
    std::cout << restore_cursor_position; // Restore cursor position
    std::cout << show_cursor; // Show cursor
    return 0;
    
}
