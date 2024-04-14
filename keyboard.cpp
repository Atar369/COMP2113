#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <vector>
using namespace std;

const int COLS = 20;
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
    } else {
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

void displayBoard(const vector<vector<string>>& board) {
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
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    vector<vector<string>> board(ROWS, vector<string>(COLS, " "));

    while (true) {
        // Clear the console
        cout << "\033[2J\033[1;1H";

        // Display the board
        displayBoard(board);

        cout << "Enter a key: " << endl;
        char userInput = getchar();
        switch (userInput) {
        case 'W': case 'w': case '\033[A': // Up arrow
            player_move("UP");
            break; // Added break statement
        case 'A': case 'a': case '\033[D': // Left arrow
            player_move("LEFT");
            break; // Added break statement
        case 'S': case 's': case '\033[B': // Down arrow
            player_move("DOWN");
            break; // Added break statement
        case 'D': case 'd': case '\033[C': // Right arrow
            player_move("RIGHT");
            break; // Added break statement
        case 'Q': case 'q':
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid key pressed" << endl;
            break;
        }

        // Update the board with the player's position
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                board[i][j] = " ";
            }
        }
        board[player.y][player.x] = player.symbol;
        /*
        // Print the player animation
        cout << "Player position: (" << player.x << ", " << player.y << ")" << endl;
        cout << "Player animation: " << player.symbol << endl; */
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    return 0;

}
