#include <iostream>
#include <string>

using namespace std;

void startNewGame();
void viewAchievements();
void continueGame();
void settings();

int main() {
    cout << "======== Game Menu ========" << endl;
    cout << "1. Start New Game" << endl;
    cout << "2. Continue" << endl;
    cout << "3. Achievements" << endl;
    cout << "4. Settings" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";
  
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            startNewGame();
            break;
        case 2:
            continueGame()();
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
    } while (choice != 5);

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
