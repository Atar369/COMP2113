#include "maintest.h"

// Escape sequences for cursor positioning and movement
// \033[<L>;<C>H -> move cursor to line L, column C

int main() {
    // Enum for game states
    typedef enum {
        STATE_MENU,
        STATE_HTP,
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
    
    // current state of the game
    game_states current_state;
    current_state = STATE_MENU;
    
    // Progress, keyboard, window, player declaration
    Progress progress;
    Keyboard keyboard;
    Window window;
    Player player;

    // load progress
    if (progress.checking_loading()) {
        progress.load_progress(player);
    }
    
    // if ending is 7, which is the true ending, don allow to play
    if (progress.ending_num == 7) {
        system("clear");
        while (progress.ending_num == 7) {
            cout << font_blue << dim;
            draw_logo(rows, cols);
            cout << reset_format;

            string contents = "Determine your own destiny! We are living a happy life here. ----- By Hero";

            cout << default_format << startRow - logo_h_size + 9 << ";" << startCol - (contents.length())/2 << "H" << contents << endl;

            keyboard.get_userInput();
            if (keyboard.key == KEY_EXIT || keyboard.key == KEY_ENTER || keyboard.key == KEY_SPACE) {
                system("clear");
                cout << show_cursor << endl; // Show cursor
                return 0;
            }
        }
    }
    
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

    const string button_exit[2] = {
        "> EXIT <",
        "  Exit  ",
    };

    // content for how to play
    const string how_to_play[10] = {
        "How to Play",
        "W - Move Up                    E - Action       ",
        "A - Move Left                  Q - Exit to menu ",
        "S - Move Down                  SPACE - Next page",
        "D - Move Right                 ENTER - Confirm  ",
        "Walk away to cancel chat with NPCs                ",
        "Exit to menu and save your progress by pressing Q ",            
        "Unlock different endings with different choices   ",
        "Enjoy the movie...                                ",
        "Good luck"
    };
    
    static int menu_button = 0;

    // Main loop
    while (current_state != STATE_EXIT) {
        // Clear screen
        system("clear");
        std::cout << save_cursor_position; // Save cursor position
        std::cout << hide_cursor;  

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

                    // if the player saved, will have continue button
                    if (progress.checking_loading()) {
                        if (menu_button >= 3) {
                            menu_button = 3;
                        }

                        // check the button
                        if (menu_button == 0) {
                            select_start_game = 0;
                            select_continue = 1;
                            select_HTP = 1;
                            select_exit = 1;
                        } 
                        else if (menu_button == 1) {
                            select_start_game = 1;
                            select_continue = 0;
                            select_HTP = 1;
                            select_exit = 1;
                        }
                        else if (menu_button == 2) {
                            select_start_game = 1;
                            select_continue = 1;
                            select_HTP = 0;
                            select_exit = 1;
                        }
                        else if (menu_button == 3){
                            select_start_game = 1;
                            select_continue = 1;
                            select_HTP = 1;
                            select_exit = 0;
                        }

                        // Position the cursor and print the text at the center
                        std::cout << default_format << startRow - logo_h_size + 9 << ";" << startCol - (button_start_game[select_start_game].length())/2 << "H" << button_start_game[select_start_game] << endl;

                        std::cout << default_format << startRow - logo_h_size + 11 << ";" << startCol - (button_continue[select_continue].length())/2 << "H" << button_continue[select_continue] << endl;

                        std::cout << default_format << startRow - logo_h_size + 13 << ";" << startCol - (button_HTP[select_HTP].length())/2 << "H" << button_HTP[select_HTP] << endl;

                        std::cout << default_format << startRow - logo_h_size + 15 << ";" << startCol - (button_exit[select_exit].length())/2 << "H" << button_exit[select_exit] << endl;

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
                                current_state = STATE_EXIT;
                                break;    
                        }
                    }

                    else {
                        if (menu_button >= 2) {
                            menu_button = 2;
                        }
                        // check the button
                        if (menu_button == 0) {
                            select_start_game = 0;
                            select_HTP = 1;
                            select_exit = 1;
                        } 
                        else if (menu_button == 1) {
                            select_start_game = 1;
                            select_HTP = 0;
                            select_exit = 1;
                        }
                        else if (menu_button == 2) {
                            select_start_game = 1;
                            select_HTP = 1;
                            select_exit = 0;
                        }

                        // Position the cursor and print the text at the center, without continue button
                        std::cout << default_format << startRow - logo_h_size + 9 << ";" << startCol - (button_start_game[select_start_game].length())/2 << "H" << button_start_game[select_start_game] << endl;

                        std::cout << default_format << startRow - logo_h_size + 11 << ";" << startCol - (button_HTP[select_HTP].length())/2 << "H" << button_HTP[select_HTP] << endl;

                        std::cout << default_format << startRow - logo_h_size + 13 << ";" << startCol - (button_exit[select_exit].length())/2 << "H" << button_exit[select_exit] << endl;

                        // Click handler
                    switch(menu_button) {
                        case 0:
                            current_state = STATE_GAME;
                            break;
                        case 1:
                            current_state = STATE_HTP;
                            break;
                        case 2:
                            current_state = STATE_EXIT;
                            break;    
                    }
                    
                    }
                    keyboard.get_userInput();
                }

                
                break;

            // how to play
            case STATE_HTP:
    
                // How to play
                for (int i = 0; i < 9; i++) {
                    std::cout << default_format << 20 + i * 3 << ";" << startCol - (how_to_play[i].length())/2 << "H" << how_to_play[i] << endl;
                }

                keyboard.get_userInput();

                // Exit to menu
                if (keyboard.key == KEY_EXIT)
                    current_state = STATE_MENU;
                
                break;

           // Game
            case STATE_GAME:

                // Clear previous progress
                progress.delete_progress();
                window.is_Hero = false;
                window.is_Girl = false;
                player.reset_player();
                window.intro_character_choice(player);

                if (window.is_Hero) {
                    // Set player as hero
                    player.x = 9;
                    player.y = 9;
                    player.symbol = "|@|";
                    player.color = font_blue;
                    progress.map_code = 0;
                    progress.event_num = 1;
                    progress.ending_num = 0;

                    // Start game
                    Hero_run(progress, player);
                }
                else if (window.is_Girl) {
                    // set player as girl
                    player.x = 9;
                    player.y = 9;
                    player.symbol = "|%|";
                    player.color = font_purple;
                    progress.map_code = 1;
                    progress.event_num = 0;
                    progress.ending_num = 0;

                    // Start game
                    Girl_run(progress, player);
                }    

                // Ending 7 is the true ending, then the game will end
                if (progress.ending_num == 7) {
                    system("clear");
                    progress.save_progress(player);
                    while (progress.ending_num == 7) {
                        cout << font_blue << dim;
                        draw_logo(rows, cols);
                        cout << reset_format;

                        string contents = "Determine your own destiny! We are living a happy life here. ----- By Hero";

                        cout << default_format << startRow - logo_h_size + 9 << ";" << startCol - (contents.length())/2 << "H" << contents << endl;

                        keyboard.get_userInput();
                        if (keyboard.key == KEY_EXIT || keyboard.key == KEY_ENTER || keyboard.key == KEY_SPACE) {
                            system("clear");
                            cout << show_cursor << endl; // Show cursor
                            return 0;
                        }
                    }
                }

                // player can choose to save or not if not yet reach the ending
                if (!player.reach_ending) {
                    window.handle_save_choice(choice_button, progress.map_code, player);
                }
                else if (progress.ending_num != 7){
                    // reset progress after reaching the ending, return to menu directly without choice
                    progress.reset_progress();
                    if (player.color == font_blue) {
                        player.x = 9;
                        player.y = 9;
                        progress.event_num = 1;
                    }
                    else if (player.color == font_purple) {
                        player.x = 9;
                        player.y = 9;
                        progress.event_num = 0;
                        progress.map_code = 1;
                    }    
                    progress.save_progress(player);
                    current_state = STATE_MENU; 
                }

                if (choice_button == 0)
                    // save progress
                    progress.save_progress(player);
                
                // reset progress
                current_state = STATE_MENU;  

                break;

            case STATE_CONTIN:
                // Load progress
                progress.load_progress(player);
                
                // Check if the player has reached the ending
                if (player.reach_ending) {
                    progress.reset_progress();
                    window.is_Girl = false;
                    window.is_Hero = false;
                    window.intro_character_choice(player);
                    if (player.color == font_blue) {
                        player.x = 9;
                        player.y = 9;
                        progress.event_num = 1;
                    }
                    else if (player.color == font_purple) {
                        player.x = 9;
                        player.y = 9;
                        progress.event_num = 0;
                        progress.map_code = 1;
                    }  
                    player.reset_player();
                }
                
                if (player.color == font_blue) {
                    window.is_Hero = true;
                    player.symbol = "|@|";
                    // Continue game
                    Hero_run(progress, player);
                }
                else if(player.color == font_purple) {
                    window.is_Girl = true;
                    player.symbol = "|%|";
                    // Continue game
                    Girl_run(progress, player);
                }

                // Ending 7 is the true ending, then the game will end
                if (progress.ending_num == 7) {
                    system("clear");
                    progress.save_progress(player);
                    while (progress.ending_num == 7) {
                        cout << font_blue << dim;
                        draw_logo(rows, cols);
                        cout << reset_format;

                        string contents = "Determine your own destiny! We are living a happy life here. ----- By Hero";

                        cout << default_format << startRow - logo_h_size + 9 << ";" << startCol - (contents.length())/2 << "H" << contents << endl;

                        keyboard.get_userInput();
                        if (keyboard.key == KEY_EXIT || keyboard.key == KEY_ENTER || keyboard.key == KEY_SPACE) {
                            system("clear");
                            cout << show_cursor << endl; // Show cursor
                            return 0;
                        }
                    }
                }

                // player can choose to save or not if not yet reach the ending
                if (!player.reach_ending) {
                    window.handle_save_choice(choice_button, progress.map_code, player);
                }
                else if (progress.ending_num != 7) {
                    // reset progress after reaching the ending and return to menu directly without choice
                    progress.reset_progress();  
                    progress.save_progress(player);
                        
                    current_state = STATE_MENU; 
                }
                

                if (choice_button == 0)
                    // save progress
                    progress.save_progress(player);
                
                // reset progress
                current_state = STATE_MENU;     
                
                break;

            case STATE_EXIT:
                break;
            }
 
        }
    
    
    system("clear");
    std::cout << show_cursor << endl; // Show cursor
    return 0;
    
}
