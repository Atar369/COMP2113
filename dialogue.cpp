#pragma once
#include <vector>
#include <string>
#include <map>
#include <random>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main(){
  //if the player choose girl
  //scene 1
  "???: You are the chosen one."
  "???: I will give a part of my power to you."
  "???: Ummmmm......let me see."
  "???: Ok! Time rewinding. This will be your super power."
  "???: Remember, kid, use your power to do the right thing."
  "..."
  "(You woke up)"
  "You: What was that? Was that a dream?"
  "(Super power... Time rewinding...)"
  "(You cannot memorize the dream well)"
  "You: Such a weird dream..."
  "You: Whatever."
  "(You decided to have a breakfast first)"
  "You: Oh no! The apple is spoiled."
  "(You took up the apple and looked at it)"
  "You: Time rewind... what if that was not a dream."
  "You: TIME REWIND!!!"
  "(The apple on your hand became a fresh, fragant apple in a flash)"
  "You: Oh my god... this is real!"
  "(You were so panic and you wanted to tell some other people about this.)"
  "(You ran out of your house.)"
  ""
}

void print() {
    // Function to clear dialogue after printing it
    string dialogue;
    cout << "\033[2J\033[1;1H";
    cout << dialouge << endl;
}
