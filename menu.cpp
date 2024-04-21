#include <iostream>
#include <string>
#include <sys/ioct.h>
//#include "player.h"
//#include "draw.h"
//#include "keyboard.h"

using namespace std;

void startNewGame();
void viewAchievements();
void continueGame();
void settings();

int main() {
    do {
        // Display the game menu
        cout << "======== Game Menu ========" << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. Continue" << endl;
        cout << "3. Achievements" << endl;
        cout << "4. Settings" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";

        int choice;
        cin >> choice;

        // Execute the user's choice
        switch (choice) {
            case 1:
                startNewGame();
                break;
            case 2:
                continueGame   ();
                break;
            case 3:
                viewAchievements();
                break;
            case 4:
                settings();
                break;
            case 5:
                cout << "Exiting the game..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 1 || choice != 2 || choice != 3 || choice != 4 || choice != 5);

    return 0;
}

// Function definitions
void startNewGame() {
    cout << "Starting a new game..." << endl;
    // Add your game logic here
}

void viewAchievements() {
    cout << "Viewing achievements..." << endl;
    // Add your achievement display logic here
}

void continueGame() {
    cout << "Continuing the game..." << endl;
    // Add your game load logic here
}

void settings() {
    cout << "Accessing settings..." << endl;
    // Add your settings menu logic here
}
