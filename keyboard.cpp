#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <vector>
using namespace std;

const int COLS = 27;
const int ROWS = 20;

struct Player {
    int x;
    int y;
    int hrz;
    int vtcl;
    string symbol;
};

Player player;

void moveUp() {
    player.vtcl = -1;
}

void moveDown() {
    player.vtcl = 1;
}

void moveLeft() {
    player.hrz = -1;
}

void moveRight() {
    player.hrz = 1;
}

void stopMovement() {
    player.hrz = 0;
    player.vtcl = 0;
}

int dir_x;
int dir_y;

void player_move(string key) {
    // Key check
    int key_left  = ( key == "LEFT" ) ? 1 : 0;
    int key_right = ( key == "RIGHT" ) ? 1 : 0;
    int key_down  = ( key == "DOWN" ) ? 1 : 0;
    int key_up    = ( key == "UP" ) ? 1 : 0;

    // Reset player's movement
    stopMovement();

    // Update player's movement based on key input
    if (key_left) {
        moveLeft();
    }
    if (key_right) {
        moveRight();
    }
    if (key_up) {
        moveUp();
    }
    if (key_down) {
        moveDown();
    }

    // Animation and direction shoot
    if (player.hrz == 0 && player.vtcl == 0) {
        player.symbol = "|@|";
    } 
    else {
        if (player.hrz == 1) {
            player.symbol = "|@>";
        }
        if (player.hrz == -1) {
            player.symbol = "<@|";
        }
        if (player.vtcl == -1) {
            player.symbol = "/@\\";
        }
        if (player.vtcl == 1) {
            player.symbol = "\\@/";
        }
    }

    player.x += player.hrz;
    player.y += player.vtcl;
}

void displayBoard(const vector<vector<string> >& board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == player.y && j == player.x) {
                cout << player.symbol << " ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    string key;
    struct termios oldSettings, newSettings;    // termios is a struct that contains terminal attributes
    tcgetattr(STDIN_FILENO, &oldSettings);  // write the current terminal attributes into oldSettings
    newSettings = oldSettings; 
    newSettings.c_lflag &= ~(ICANON | ECHO);    // Disable canonical mode (buffered i/o) and local echo to read the input character by character
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);     // int, action (immediate adjustment), settings

    player.x = 0;
    player.y = 0;

    vector<vector<string> > board(ROWS, vector<string>(COLS, " "));

    while (true) {
        // Clear the console
        cout << "\033[2J\033[1;1H";

        // Display the board
        displayBoard(board);

        cout << "Enter a key: " << endl;
        
        // Debug: Print the player animation
        // cout << "Player position: (" << player.x << ", " << player.y << ")" << endl;
        // cout << "Player animation: " << player.symbol << endl; 

        board[player.y][player.x] = " ";

        char userInput = getchar(); // Get the user input by 1 char

        switch (userInput) {
        case 'W': case 'w':
            player_move("UP");
            break;
        case 'A': case 'a':
            player_move("LEFT");
            break;
        case 'S': case 's':
            player_move("DOWN");
            break; 
        case 'D': case 'd':
            player_move("RIGHT");
            break; 
        case 'E': case 'e':
            
            break;
        
        case 'Q': case 'q':
            cout << "Exiting..." << endl;
            return 0;
        
        default:
            cout << "Invalid key pressed" << endl;
            break;
        }

        board[player.y][player.x] = player.symbol;

        // Update the board with the player's position
        displayBoard(board);
        
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    return 0;

}
