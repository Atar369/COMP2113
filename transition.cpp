#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void clearScreen() {
    // Function to clear the console screen
    cout << "\033[2J\033[1;1H";
}

void MapTransition() {
    // Function to print animation
    clearScreen();
    cout << "Map chaning..." << endl;
}

int main() {
    // Map transition loop
    while (true) {
        MapTransition();
        this_thread::sleep_for(chrono::milliseconds(1000)); // Delay for displaying
    }

    clearScreen()
    
    return 0;
}
