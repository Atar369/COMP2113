#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void clearScreen() {
    // Function to clear the console screen
    cout << "\033[2J\033[1;1H";
}

void printAnimationFrame() {
    // Function to print a frame of the animation
    clearScreen();
    cout << "   / \\___/ \\ " << endl;
    cout << "  /         \\ " << endl;
    cout << " |   O   O   | " << endl;
    cout << " |     >     | " << endl;
    cout << "  \\   ---   / " << endl;
    cout << "   \\_______/ " << endl;
    cout << "     /   \\ " << endl;
    cout << "    /     \\ " << endl;
    cout << "   /_______\\ " << endl;

    cout << "   / \\___/ \\ " << endl;
    cout << "  /         \\ " << endl;
    cout << " |   O   O   | " << endl;
    cout << " |     >     | " << endl;
    cout << "  \\   w   / " << endl;
    cout << "   \\_______/ " << endl;
    cout << "     /   \\ " << endl;
    cout << "    /     \\ " << endl;
    cout << "   /_______\\ " << endl;
}

void printNarratorBackground() {
    // Function to print the reserved space for the narrator's background information
    cout << "Once upon a time, in a faraway land..." << endl;
    cout << "The kingdom was in great peril..." << endl;
    cout << "A hero was destined to rise and save the day..." << endl;
}

int main() {
    // Animation loop
    while (true) {
        printAnimationFrame();
        this_thread::sleep_for(chrono::milliseconds(500)); // Delay between frames
    }
    
    printNarratorBackground();
    
    return 0;
}
