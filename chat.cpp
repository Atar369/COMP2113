#include "chat.h"

using namespace std;

Chat chat;

// Function to generate a random number within a range
int Chat::getRandomNumber(int a, int b) {
    srand((int)time(NULL));
    return (rand() % (b-a+1))+ a; // Generate a random number between a and b, to be confirmed how many lines they will say
}

unordered_map<string, vector<string> > Hero_chat_map = {
    {"intro", {
        "Once upon a time, in a faraway land...",
        "The kingdom was in great peril...",
        "A hero was destined to rise and save the day...",
        }
    },
    {"old man hero", {
        "In the middle of woods, you saw weird house.",
        "You never noticed it before.",
        "An old man was sitting in front of the house.",
        "He said, 'I've been waiting for you, Hero.'",
        "'The dragon has taken the castle and threatens the villages.'",
        "'His power is too great for us to defeat.'",
        "'Under his control, the monsters have become more aggressive.'",
        "'We have been waiting for a hero to save us.'",
        "'But now you still not ready to face the dragon.'",
        "'You still not determined enough.'",
        "'Go and find the blacksmith Robert, he will help you.'",
        "'May the light guide you, Hero.'",
        }
    },
    {"old man talked", {
        "'I have told you everything you need to know.'",
        "'The rest is up to you.'",
        "'Be brave, Hero.'",
        "'May the light guide you.'",
        }
    },
    {"old man robert took", {
        "'I see you have met Robert the blacksmith, are't you?'",
        "'The sword he made is the only weapon that can defeat the dragon.'",
        "'But the sword is not complete yet.'",
        "'You need to find the three treasures to unlock its full power.'",
        "'The first treasure is kept by a villager in the village.'",
        "'He was the teacher of last hero, but the last hero...'",
        "...",
        "'Anyway, he will help you to become stronger.'",
        "'The second treasure is hidden in the forest.'",
        "'The third treasure is in the cave, guarded by a monster.'",
        "'Find them and bring them to Robert.'",
        }
    },
    {"old man robert leave", {
        "'You did't take the sword are't you?'",
        "'Then why are you here?'",
        "'You are not the one I'm looking for.'",
        "'Go back and enjoy your life.'",
        }
    },    
    {"enter castle", {
        "You enter the castle.",
        "You saw that the girl that you were looking for standing next to the evil Dragon.",
        "You said loudly, 'I'm here to save you! Dragon, leave her alone!'",
        "The Dragon laughed and said, 'What a fool, you dare challenge me as a mortal?'",
        "The Dragon was about to attack you, but the Girl stopped it.",
        "She said, 'This dragon...is a friend of mine now'",
        "'We have talked about this, right? You will no longer harm humans.'",
        "The Dragon flapped its wings and turned away with disdain, surprisingly not attacking you.",
        "The Girl said, 'Thank you for coming. But I'm fine now.'",
        "'The Dragon and monsters are not evil, they only fight with humans to survive.'",
        "'In the beginning, the monsters built this place and lived in peace.'",
        "'But humans came and took over the place, and the monsters were banished into this castle.'",
        }
    },
    {"hero kill all", {
        "You finally found a way to the Dragon's lair.",
        "You saw the Dragon and many monsters guarding the place.",
        "You said nothing. You pulled out your sword and charged at them.",
        "One after one..."
        }   
    },
    {"enter store", {
        "You enter the store",
        "The store is filled with villagers, talking and laughing.", 
        "The crowd accumulates, almost blocking your sight.",
        "You found the person that you were looking for.",
        "He is a blacksmith, with a big beard and a strong build.",
        }
    },  
    {"ending name", {"Alternate Ending : The Truth Revealed"}}, // ending names
    {"no sword", {
        "You don't have the power to face the monsters.",
        }
    }, 
    {"scare", {
        "(There is a scary monster there, let's find another way.)",
        }
    },
    {"hero saw", {
        "You saw a monster lying down on the groud next to the castle.",
        "He seems being hurt. His wings are bleeding.",
        "Without a moment's hesitation, you pull out your sword.",
        "The blade reflect your unwavering resolve. ",
        "With each step, determination radiated from their every movement.",
        "There was no room for fear in your heart...", 
        "only a burning desire to rid the world of these evil creatures.",
        }    
    },
    {"hero kill", {
        "Drawing nearer, the wounded monster sensed your presence.",
        "He raised his head, eyes glowing with a mix of pain and fury. ",
        "With a thunderous roar, he bared his jagged teeth, attempting to strike fear into your soul.",
        "But you got no fear.",
        "A fierce battle ensued.",
        "The monster opens his mouth, trying to swallow you whole.",
        "You switch your position quickly. He missed.",
        "You are deeply focusing, your sword dancing with deadly precision.",
        "...",
        "The last attack goes for his neck.",
        "The clash of steel against scales reverberating through the air.",
        "The monster's eyes widened in shock as he realized his fate.",
        "'...You...humans...as always...'",
        "'...you...will never...understand...'",
        "'...our pain...'",
        "His words have no effect on you.",
        "You thrust your sword into his heart.",
        "His body fell to the ground.",
        "His eyes still staring at you.",
        "With anger, and with sadness.",
        "...",
        "You continue your journey.",
        }
    },    
};

unordered_map<string, vector<string> > Girl_chat_map = {
    {"intro", {
        "Once upon a time, in a faraway land...",
        "The kingdom was in great peril...",
        "A hero was destined to rise and save the day...",
        }
    },
    {"enter castle", {
        "Hero enters the castle.",}
    },
};        

string Chat::oldmanchat() {
    int randomNumber = getRandomNumber(1, 6); // Generate a random number between 1 and 4

    switch (randomNumber) {
        case 1:
            return "Who are you?";
        case 2:
            return "Why are you here?";
        case 3:
            return "What do you want from me?";
        case 4:
            return "I'm not interested in talking to you.";
        case 5:
            return "You are not the one I'm looking for.";
        case 6:
            return "...";                    
    }

    return "...";
}    

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
                        return "";
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

void Chat::loadChat(string charactor, int map_code, int scn_num, Player &player, string color) {
    string contents;
    if (player.color == font_blue) {
        this->is_Hero = true;
    }
    else if (player.color == font_purple) {
        this->is_Girl = true;
    } 

    if (charactor == "npc") {
        contents = this->getRandomVillagerChat(player.color, scn_num);
        window.build_buffer(contents);
        //window.Print_buffer(map_code_mapping[map_code], player, font_white);
    }

    else {
        int line = 0;
        
        if (this->is_Hero) {
            while (line < Hero_chat_map[charactor].size()) {
                window.build_buffer(Hero_chat_map[charactor][line]);
                window.Print_buffer(map_code_mapping[map_code], player, color);
                keyboard.get_userInput();
                while (keyboard.key != KEY_SPACE) {
                keyboard.get_userInput();
                }
                line ++;
            }
        }
        else if (this->is_Girl) {
            while (line < Girl_chat_map[charactor].size()) {
                window.build_buffer(Girl_chat_map[charactor][line]);
                window.Print_buffer(map_code_mapping[map_code], player, color);
                keyboard.get_userInput();
                while (keyboard.key != KEY_SPACE) {
                keyboard.get_userInput();
                }
                line ++;
            }
        } 

        system("clear");   
    }
    
}
