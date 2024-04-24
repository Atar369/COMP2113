#include "chat.h"

using namespace std;

Chat chat;

// Function to generate a random number within a range
int Chat::getRandomNumber(int a, int b) {
    srand(time(NULL));
    return rand() % b + a; // Generate a random number between a and b, to be confirmed how many lines they will say
}

unordered_map<string, vector<string> > chat_map = {
    {"Narrator", {
        "Once upon a time, in a faraway land...",
        "The kingdom was in great peril...",
        "A hero was destined to rise and save the day...",
        }
    },
    {"Hero", {
        "Zzz... Huh? What's that voice?",
        "I was chosen to be the Hero? This must be a dream...",
        }
    }, 
    {"Girl", {
        "Help! Help! Is anyone there?",
        "The dragon took me... I'm scared...",
        }
    }, 
    /*
    {"Villager", {
        "Ah, the chosen Hero! We've been waiting for you.",
        "Your mission is to defeat the evil dragon and save our world.",
        "But first, a girl has been captured by the dragon.",
        "Please, brave Hero, go and rescue her!",
        }
    },*/

    {"Dragon", {
        "You dare challenge me, mortal?",
        "Prepare to meet your doom!",
        "None can defeat the might of a dragon!",
        }
    },
    {"Endings", {
        "Ending: Idiot",
        "Ending: Genius",
        "Ending: Normal",
        "Ending: Bad",
        "Ending: Good",
        "Ending: Best",
        }
    },
};

string Chat::getRandomVillagerChat(string color, int scn_num) {

    if (color == font_blue) {
        this->is_Hero = true;
    }
    else if (color == font_purple) {
        this->is_Girl = true;
    }    

    if (is_Hero) {
        int randomNumber = getRandomNumber(1, 4); // Generate a random number between 1 and 4
        switch (scn_num) {
            case 1:
                switch (randomNumber) {
                    case 1:
                        return "Ah, the chosen Hero! We've been waiting for you.";
                    case 2:
                        return "Your mission is to defeat the evil dragon and save our world.";
                    case 3:
                        return "Today is a good day, isn't it?";
                    case 4:
                        return "A girl has been captured by the dragon. Please, brave Hero, go and rescue her!";
                }
                break;
            case 2:
                switch (randomNumber) {
                    case 1:
                        return "The dragon is getting stronger. You must hurry!";
                    case 2:
                        return "We need to find a way to weaken the dragon's defenses.";
                    case 3:
                        return "The villagers are counting on you to save us!";
                    case 4:
                        return "The fate of our world rests on your shoulders.";
                }
                break;
            case 3:
                switch (randomNumber) {
                    case 1:
                        return "You're getting closer to the dragon's lair. Be careful!";
                    case 2:
                        return "The dragon's lair is heavily guarded. Plan your moves wisely.";
                    case 3:
                        return "The people believe in you. You can do this!";
                    case 4:
                        return "The dragon's power is immense, but so is your determination!";
                }
                break;
        }
    }
    else if (is_Girl) {
        int randomNumber = getRandomNumber(1, 4); // Generate a random number between 1 and 4
        switch (scn_num) {
            case 1:
                switch (randomNumber) {
                    case 1:
                        return "";
                    case 2:
                        return "The dragon took me... I'm scared...";
                    case 3:
                        return "Please, someone save me!";
                    case 4:
                        return "I don't want to be dragon food!";
                }
                break;
            case 2:
                switch (randomNumber) {
                    case 1:
                        return "The dragon is getting closer. I can hear its roars!";
                    case 2:
                        return "I'm so scared... Will anyone come to save me?";
                    case 3:
                        return "Please, hurry! I don't know how much longer I can hold on!";
                    case 4:
                        return "I can't believe this is happening... Please, someone help me!";
                }
                break;
            case 3:
                switch (randomNumber) {
                    case 1:
                        return "Oh my goodness, you are back!";
                    case 2:
                        return "Where have you been? I thought you have been eaten by evil dragon!";
                    case 3:
                        return "I'm so glad you're here!";
                    case 4:
                        return "Did you see the dragon? He's so scary!";
                }
                break;
        }
    }
    else {
        return "Hello there!";
    }
    return "Greetings!";
}

void Chat::loadChat(string charactor, int map_code, int scn_num, Player &player) {
    string contents;

    if (charactor == "npc") {
        contents = this->getRandomVillagerChat(player.color, scn_num);
        window.build_buffer(contents);
        //window.Print_buffer(map_code_mapping[map_code], player, font_white);
    }

    else {
        int line = 0;
        while (line < chat_map[charactor].size()) {
            window.build_buffer(chat_map[charactor][0]);
            window.Print_buffer(map_code_mapping[map_code], player, font_white);
            line ++;
            keyboard.get_userInput();
            while (keyboard.key != KEY_SPACE) {
            keyboard.get_userInput();
            }
        }
    }
    
}
