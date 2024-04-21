#include <iostream>
#include <sys/ioctl.h>
#include <string>
#include <unistd.h>
//#include "player.h"
//#include "draw.h"
//#include "object.h"
#include "menu.h"
//#include "format.h"
//#include "constant.h"
#include "keyboard.h"
using namespace std;

// Escape sequences for cursor positioning and movement
// \033[<L>;<C>H -> move cursor to line L, column C

int main() {
    // Enum for game states
    typedef enum {
        STATE_MENU,
        STATE_HTP,
        STATE_GAME,
        STATE_EXIT,
    } game_states;

    // Get the dimensions of the terminal window
    //struct winsize w;
    //ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    //int rows = w.ws_row;
    //int cols = w.ws_col;
    int rows = 40;
    int cols = 150;
     // Calculate the coordinates for centering the text
    int startRow = rows / 2;
    int startCol = cols / 2; // Adjust for the length of the longest string
    
    // Init current state
    game_states current_state;
    current_state = STATE_MENU;

    Keyboard keyboard;

    ////////////////
    // Main loop
    ///////////////

    // Menu menu
    // Buttons
    const string button_start_game[2] = {
        "> START GAME <",
        "  Start Game  ",
    };

    const string button_HTP[2] = {
        "> HOW TO PLAY <",
        "  How to Play  ",
    };

    const string button_exit[2] = {
        "> EXIT <",
        "  Exit  ",
    };

    const string how_to_play[8] = {
        "How to Play",
        "W - Move Up                    E - Action      ",
        "A - Move Left                  Q - Exit to menu",
        "S - Move Down                  SPACE - Hit     ",
        "D - Move Right                                 ",
        "Unlock different endings with different choices",
        "Enjoy the movie...                             ",
        "Good luck"
    };
    
    static int menu_button = 0;

    while (current_state != STATE_EXIT) {
        // Clear screen
        cout << clear_screen;
        cout << save_cursor_position; // Save cursor position
        cout << hide_cursor;  // Save cursor position

  /**     int check_waiting = keyboard.waiting(keyboard.key);

        int check_pressed_key = keyboard.key_pressed(keyboard.key);
        
        // Check if the key is pressed
        while (check_pressed_key) {
            keyboard.get_userInput();
        }
        */

        int select_start_game = 1, select_HTP = 1, select_exit = 1;

        // In menu state
        switch(current_state) {
            
            // Menu
            case STATE_MENU:

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
                        if (menu_button >= 2) {
                            menu_button = 2;
                        }
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

                    // Position the cursor and print the text at the center
                    cout << default_format << startRow - logo_h_size + 9 << ";" << startCol - (button_start_game[select_start_game].length())/2 << "H" << button_start_game[select_start_game] << endl;

                    cout << default_format << startRow - logo_h_size + 11 << ";" << startCol - (button_HTP[select_HTP].length())/2 << "H" << button_HTP[select_HTP] << endl;

                    cout << default_format << startRow - logo_h_size + 13 << ";" << startCol - (button_exit[select_exit].length())/2 << "H" << button_exit[select_exit] << endl;
                    
                    keyboard.get_userInput();
                }

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

                break;

            // Info
            case STATE_HTP:
                // How to play
                cout << default_format << 3 << ";" << startCol - (how_to_play[0].length())/2 << "H" << how_to_play[0] << endl; // title
                cout << default_format << 10 << ";" << startCol - (how_to_play[1].length())/2 << "H" << how_to_play[1] << endl; // keys
                cout << default_format << 12 << ";" << startCol - (how_to_play[2].length())/2 << "H" << how_to_play[2] << endl;
                cout << default_format << 14 << ";" << startCol - (how_to_play[3].length())/2 << "H" << how_to_play[3] << endl;
                cout << default_format << 16 << ";" << startCol - (how_to_play[4].length())/2 << "H" << how_to_play[4] << endl;
                cout << default_format << 20 << ";" << startCol - (how_to_play[5].length())/2 << "H" << how_to_play[5] << endl; // words
                cout << default_format << 24 << ";" << startCol - (how_to_play[6].length())/2 << "H" << how_to_play[6] << endl;
                cout << default_format << 28 << ";" << startCol - (how_to_play[7].length())/2 << "H" << how_to_play[7] << endl;

                keyboard.get_userInput();

                // Exit to menu
                if (keyboard.key == KEY_EXIT)
                    current_state = STATE_MENU;
                
                break;

           // Game
            case STATE_GAME:
                cout << "Game started" << endl;

                // Exit to menu
                if (keyboard.key == 'q')
                    current_state = STATE_MENU;
                break; 

            case STATE_EXIT:
                cout << "Exiting game" << endl;
                break;
            }

        }
    
    // Exit
    cout << restore_cursor_position; // Restore cursor position
    cout << show_cursor; // Show cursor
    return 0;
    
}
