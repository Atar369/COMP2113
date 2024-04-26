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
  "(You were so panic but you were trying to be claim)"
  "You: If I tell the others that I can rewind time, mayebe I will be kidnapped and exploited."
  "(You were pondering.)"
  "You: Time rewind... the effect of this power is actually similar to healing."
  "You: Maybe I can pretend to be a healer using this ability."
  "You: If people get hurted, I can fix their body by rewinding the time to the moment before ther are hurted."
  "You: It is easy for me to pretend to be a healer."
  "(You decided to hide your real abillity and pretend to be a healer.)"
  "(After you decided to hide your true power, you were going to the forest.)"
  "(You got lost in the forest.)"
  "(You saw a monster in the distance.)"
  "(It was a huge monster, with sharp teeth and red eyes.)"
  "(However, you saw many bleeding knife wounds on its body.)"
  "(You decided to...)"
  "(Run away          Rescue it)"
  
  //scene2 (branch 1)
  "(You decided to run away.)"
  "(However, the monster jumped to you)"
  "(The monster chased up you.)"
  "Monster: ARRRWWWWWWW, human! Die!"
  "(The monster ate you.)"
  "(You are dead)"
  "Ending: Cuisine"
  
  //scene3 (branch 2)
  "(You decided to rescue it.)"
  "Monster: You... saved me?"
  "You: Yes, as you seemed not feeling well."
  ""
}

void print() {
    // Function to clear dialogue after printing it
    string dialogue;
    cout << "\033[2J\033[1;1H";
    cout << dialouge << endl;
}
