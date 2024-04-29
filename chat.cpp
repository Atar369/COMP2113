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
        "The kingdom was full of peace and happiness...",
        "But one day, a great evil descended upon the land...",
        "The dragon, a fearsome beast, attacked the village...",
        "With his fiery breath and sharp claws, he destroyed everything in his path...",
        "His minions, the monsters, terrorized the villagers...",
        "The people were helpless, unable to defend themselves...",
        "They choose a place far away to rebuild their home...",
        "In this little village, a hero was born...",
        "He was destined to rise and save the day...",
        "That hero is you...",
        "You are the chosen one, the one who will defeat the dragon and bring peace back...",
        "Your journey begins now...",
        }
    },
    {"librarian", {
        "......",
        "(the librarian is reading a book)",
        "......",
        "(turn another page of the book)",
        "......?",
        "Oh, I'm sorry. I didn't see you there.",
        "Welcome to the library.",
        "Please feel free to look around.",
        "If you have any questions, I'll be happy to help.",
        }
    },
    {"penny", {
        "Welcome to the store.",
        "I'm Penny, the store owner.",
        "If you need anything, just let me know.",
        "I have a wide selection of items for sale.",
        "I'm sure you'll find something you like.",
        "Feel free to look around.",
        }
    },
    {"cooper", {
        "......",
        "...",
        "......",
        "...",
        "...how long have you been staring at me?",
        "......",
        "...i have nothing to say to you...",
        "......",
        }
    },
    {"cooper the guider", {
        "......",
        "...",
        "......",
        "...",
        "...you are the hero, aren't you?",
        "...",
        "I can see it in your eyes...",
        "...",
        "You have the determination...",
        "just like the last hero...",
        "......",
        "You are not yet capable of the fighting skills.",
        "Every act, every move, every steps... got its own meaning.",
        "I shall teach you the art of combat.",
        "Follow my lead.",
        }
    },
    {"fight class1", {
        "(Press the correct key to follow Cooper's instructions.)",
        "'Fighting requires not only physical strength but also mental agility.'",
        "He took a step back and assumed a defensive stance, motioning for you to do the same.",
        "'Let's start with the basics.'",
        "'Stand with your feet shoulder-width apart, knees slightly bent.", 
        "This will give you a stable foundation.'",
        "(Press P to stay balanced)"
        }
    },
    {"fight class2", {
        "You followed Cooper's instructions, mirroring their stance.",
        "'Good. Now, raise your arms and keep your fists clenched. This will help you protect yourself.'",
        "You adjusted their posture and clenched their fists, ready to learn.",
        "'Remember, fighting isn't just about attacking. It's also about defending.'",
        "'Keep your guard up at all times, protecting your face and body from incoming strikes.'",
        "'Now, let's move on to footwork. Agility is key in battle.'",
        "'Practice moving swiftly and smoothly, maintaining your balance at all times.'",
        "He demonstrated various footwork techniques",
        "(Press G to mimic)"
        }
    },
    {"fight class3", {
        "You observed and tried to mimic the movements.",
        "'Well done, young hero. You're starting to get the hang of it.'", 
        "'Now, let's talk about attacking. In combat, you must strike with precision and timing.'",
        "'Remember, it's not just about throwing punches randomly.'",
        "'Analyze your opponent's movements, anticipate them, and strike when the opportunity arises.'",
        "Cooper explained different striking techniques to showcase the proper form.",
        "(Press F to follow)"
        }
    },
    {"fight class4", {
        "You try to perform the techniques as Cooper instructed.",
        "You listened intently, absorbing every word and movement.",
        "'Excellent. You're a quick learner, young hero.'",
        "'Now, let's put your skills to the test. I'll be your sparring partner.'",
        "He assumed a fighting stance, motioning for you to do the same.",
        "'Remember everything I taught you. Focus on your footwork, guard, and striking.'",
        "'Don't hold back. Show me what you've got.'",
        "You took a deep breath, ready to face Cooper in combat.",
        "(Press K to be ready)"
        }
    },
    {"fight class5", {
        "You first focused on your footwork.", 
        "You move swiftly and smoothly to evade his strikes and find openings for your own attacks.",
        "Cooper moved with grace and precision, testing your skills and reflexes.",
        "He threw a series of punches and kicks, challenging you to react and counter.",
        "(Press C to dodge)"
        }
    },
    {"fight class6", {
        "You dodged his strikes and landed a few hits of your own.",
        "(Press J to strike back)",
        }
    },
    {"fight class7", {
        "The sound of your fists meeting filled the air, echoing through the training area.",
        "After a few minutes of intense combat, Cooper stepped back and smiled.",
        "'Impressive, young hero. You have great potential.'",
        "'Keep honing your skills, and you'll become a formidable warrior.'",
        "'Remember, practice makes perfect. Train hard, and you'll be ready to face any challenge.'",
        "'Here, take this.'",
        "Cooper gave you a small pouch.",
        "Inside, you found a white magic stone and a note.",
        "'This stone will enhance your abilities. Use it wisely.'",
        "You thanked Cooper, feeling more confident in your abilities.",
        "You left the training area, determined to continue your journey and become a true hero.",
        }
    },
    {"after fight class", {
        "I have taught you everything I know.",
        "You can do this, Hero.",
        "You are the greatest hero I have ever seen.",
        "Your potential is limitless.",
        "Go and save the world.",
        }
    },
    {"robert", {
        "......",
        "...can i add this?...",
        "...no...",
        "...",
        "...or this...",
        "...huh...",
        "(He is busy working on a weapon.)",
        }
    },
    {"saw key", {
        "...",
        "...?",
        "You found a key hidden in the forest.",
        "It looks old and rusty, but it might come in handy.",
        "You noticed there are more.",
        }
    },
    {"saw treasure", {
        "You spend a while searching the forest.",
        "You finally collected all the keys.",
        "At the moment, they broke into pieces.",
        "Pointing to the direction of the treasure.",
        }
    },
    {"open treasure", {
        "Following the light, you found a treasure chest hidden in the forest.",
        "You opened it. Inside, you found a black magic stone.",
        "It radiated a mysterious energy, pulsing with power.",
        "But you felt a strange presence emanating from it.",
        "You picked it up and put it in your pocket.",
        }
    },
    {"old man hero", {
        "(In the middle of woods, you saw weird house)",
        "(You never noticed it before)",
        "(An old man was sitting in front of the house)",
        "(He was looking at you)",
        "I've been waiting for you, Hero.",
        "The dragon has taken the castle and threatens the villages.",
        "His power is too great for us to defeat.",
        "Under his control, the monsters have become more aggressive.",
        "We have been waiting for a hero to save us.",
        "But now you still not ready to face the dragon.",
        "You still not determined enough.",
        "Go and find the blacksmith Robert, he will help you.",
        "May the light guide you, Hero.",
        }
    },
    {"old man talked", {
        "I have told you everything you need to know.",
        "The rest is up to you.",
        "Be brave, Hero.",
        "May the light guide you.",
        }
    },
    {"old man robert took", {
        "I see you have met Robert the blacksmith, are't you?",
        "The sword he made is the only weapon that can defeat the dragon.",
        "But the sword is not complete yet.",
        "You need to find the three magic stones to unlock its full power.",
        "The first one is kept by a villager hidden in the village.",
        "He was the teacher of last hero, but the last hero...",
        "...",
        "Anyway, he can help you to become stronger.",
        "Go and find him.",
        "The second one is hidden in the forest.",
        "The third one is very close to the castle.",
        "The monster swallowed it, and the aggresive magic inside is weakening his body.",
        "It's your chance to defeat him and take the stone.",
        "Find them and bring them to me.",
        "I will complete the sword for you.",
        "May the light guide you.",
        }
    },
    {"old man robert leave", {
        "You did't take the sword are't you?",
        "You are not the one I'm looking for.",
        "Go back and enjoy your life.",
        "...hero...",
        }
    }, 
    {"old man all treasure", {
        "You have collected all the magic stones.",
        "Good job, Hero.",
        "Now, I will complete the sword for you. Give me the stones.",
        "......",
        "...",
        "......ha",
        "...ha......HAHA...",
        }

    },
    {"boss no rewind", {
        "HAHAHAHAHAHAHAHAHAHAHAHAHAHA",
        "You idiot...",
        "No..all of you are idiots...",
        "I am been searching for so long...",
        "The power of the magic stones...",
        "They hide them so well...",
        "Oh right my lovely player, I am terribly sorry for the interruption of the movie.",
        "I will let you continue after I end this.",
        "I was so harrassed by those humans and monsters...",
        "No matter how many times I kill them, reset the movie, brainwash them...",
        "Eventually they will overcome the control and take revenge on me...",
        "Although it is useless, it still makes me feel uncomfortable...",
        "But...but......BUT...",
        "In one of the timelines, I found that all monsters and humans sacrificed themselves...",
        "to build up these magic stones. Hero, Girl and Dragon, with these stones...",
        "ALMOST, almost defeated me...",
        "Glad that I found them before they did...",
        "But the stones are lost in the timeline...",
        "I have been searching for so long...",
        "Finally, I found them...",
        "BUT!! I can't take them! I can feel their existence... But I just can't reach it...",
        "Only the hero can take them...",
        "Player, thank you for your help...",
        "Just hand them to me, I will let you enjoy your movie.",
        "No, even more. I can add more fun to it.",
        "I can intensify the conflict, make them suffer more...",
        "I can make them kill each other...",
        "Blood, tears, despair, hatred, anger, fear, pain, ...",
        "... sorrow, regret, guilt, betrayal, revenge, death...",
        "... disease, disaster, war, famine, poverty, corruption, ...",
        "You can enjoy all of these scenes in this theater.",
        "That's the real art of the life... The TRUE entertainment of life!!!!",
        "HAHAHAHAAAA",
        "  Give it to GM                   No  ",
        "> GIVE IT TO GM <                 No  ",
        "Thank you for your cooperation.",
        "Let's restart the movie.",
        "All things will become normal...",
        "You will forget everything...",
        "Just be a good player and enjoy the movie.",
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
        "You found the person that the old man was talking about.",
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
    {"monster notice", {
        "Drawing nearer, the wounded monster sensed your presence.",
        "He raised his head, eyes glowing with a mix of pain and fury. ",
        "With a thunderous roar, he bared his jagged teeth, attempting to strike fear into your soul.",
        "But you got no fear.",
        "(touch the monster)"
        }
    },
    {"hero kill", {
        "A fierce battle ensued.",
        "The monster opens his mouth, trying to swallow you whole.",
        "You switch your position quickly. He missed.",
        "After that, you strike back.",
        "You are deeply focusing, your sword dancing with deadly precision.",
        "...",
        "The last attack goes for his neck.",
        "The clash of steel against scales reverberating through the air.",
        "The monster's eyes widened in shock as he realized his fate.",
        "'...You...humans...as always...'",
        "'...stole...our home...took everything...'",
        "'...I...will...never...forgive...'",
        "'...'",
        "His words have no effect on you.",
        "You thrust your sword into his heart.",
        "His body fell to the ground.",
        "You found a white stone fell out from his body.",
        "You picked it up and took a look at it.",
        "It emits a mysterious power, with some hidden pattern of lines sparkling.",
        "You can feel the pure energy inside it, friendly and warm.",
        "You put it into your pocket.",
        "......",
        "You look at the monster's body.",
        "His eyes still staring at you.",
        "With anger, and with sadness.",
        "......",
        "His body slowly dissolves into the air...",
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
    {"intro house", {
        "???: You are the chosen one.",
        "???: I will give a part of my power to you.",
        "???: Ummmmm......let me see.",
        "???: Ok! Time rewinding. This will be your super power.",
        "???: Remember, kid, use your power to do the right thing.",
        "...",
        "*** Woke up ***",
        "You: What was that? Was that a dream?",
        "\"Super power... Time rewinding...\"",
        "*** You tried to memorize the dream ***",
        "You: Such a weird dream...",
        "You: Whatever.",
        "*** stomach growling ***",
        "You: I need some food.",
        "You: Oh no! The apple is spoiled.",
        "...",
        "You: Time rewind... what if that was not a dream.",
        "You: TIME REWIND!!!",
        "The apple on your hand became a fresh, fragant apple in a flash.",
        "You: Oh my goodness! It actually worked! The apple... it's fresh again! This power... it's real",
        "But wait, what if someone finds out? What if they want me to use it for their own purposes?",
        "I can't let anyone know about this time rewinding power. I need to come up with a cover story.",
        "...",
        "Healing power... yes, that could work.",
        "You quickly finished your breakfast and headed out of your room, ready to face the day.",
        }
    },
    {"enter village", {
        "You step out of your house, the sun shining brightly above you.",
        "You hear villagers chatting and children laughing in the distance.",
        "Let's see what are they talking about.",
        }
    },
    {"enter forest", {
        "You step into the forest, the trees towering above you.",
        "Driven by curiosity, you really want to find out if the rumours are real.",
        "However, there are multiple paths in the forest, and you don't know which ones lead to the castle.",
        }
    },
    {"enter castle", {
        "You found the castle."
        "The castle stands tall and majestic."
        "The beauty of the surroundings captivates your senses,"
        "But your attention is quickly drawn to a figure standing in front of the throne..."
        "...the one known for its fierceness, its fearsomeness..."
        "...the evil Dragon."
        "Although you have mentally prepared yourself for this moment,"
        "The sight of the Dragon still sends a shiver down your spine."
        "But you know that this is the moment you have been waiting for..."
        "...the moment to find out the truth."
        }
    },
    {"talk to dragon", {
        "You: Dragon, at long last our paths have crossed.",
        "Dragon: Human, do you dare to stand before me?",
        "Dragon: Do you not fear me?",
        "You: I heard that you have been searching for a girl with healing powers.",
        "You: And here I am.",
        "You: You can use my power for your own purposes. I won't object.",
        "Dragon: If you believe I would harm you, why do you still stand here?",
        "You: I have had enough of the life in the village...",
        "You: With everyone telling me that I will be caught one day...",
        "You: I am tired...",
        "You: Instead of waiting for that day to come, I will face it now.",
        "Dragon: You are very brave, my girl.",
        "Dragon: I am sorry to hear about you life.",
        "Dragon: But I can't use your power.",
        "Dragon: It's your power, not mine. I have no right to use it.",
        "Dragon: I am sorry for what my ancestor have done to your village.",
        "Dragon: But I have no wish to repeat the history.",
        "Dragon: It just saddens me to know that the villagers still fear me",
        "At that moment, a realization dawns upon you —-",
        "the girl with healing powers and the 'evil' dragon are not so different after all...",
        "...living under the control of others' words, unable to live the life you truly desire.",
        "You meet his gaze, feeling a profound sense of connection between you and him."
        "He slowly steps closer to you, and you didn't step back...",
        "His arms extend towards you, and you don't flinch..."
        "You feel his embrace enveloping you...",
        "you feel his warmth, his kindness, his sorrow, his loneliness...",
        "...",
        "Dragon: I understand you,",
        "He whispers softly at your ear.",
        "...",
        "Something within you clicks..."
        "You feel a sense of peace, a sense of understanding, a sense of acceptance...",
        "A power that has the greatest healing effect of all...",
        "A feeling that you have never felt before...",
        "You hope that this moment will last forever...",
        "Dragon: Come back whenever you want.",
        "Dragon: I am always here for you.",
        "Dragon: The sun is setting. You should go back to the village.",
        }
    },
    {"back village", {
        "You still can't believe what you have just experienced.",
        "The sunset is particularly beautiful today, painting the sky in shades of red and purple.",
        "You: I have to protect him."
        "You: I must unveil the truth to the villagers.",
        }
    },
    {"no one believe", { 
        "You went to the village square, where the villagers were gathered.",
        "You told them about the Dragon.",
        "Villagers: She is seduced by the evil Dragon!",
        "Villagers: She is trying to deceive us!",
        }
    },
    {"all dead", {
        "You step into the castle, the heavy doors creaking open...",
        "It is strangely quiet...",
        "*** Sniff, sniff ",
        "You caught a whiff of something foul, a stench that made you wrinkle your nose in disgust.",
        "As you cautiously made your way further inside...",
        "the scene before you left you in a state of utter disbelief and horror...",
        "Blood. Everywhere. Bodies scattered across the floor, lifeless and still.",
        }
    },
    {"hero save you", {
        "Hero walk into your eyesight.",
        "Hero: Ah yes, you are here.",
        "Hero: I have killed all them.",
        "Hero: You are safe now.",
        "You: ...",
        "Hero: You must be very scared just now...",
        "Hero: Let's go back to the village.",
        "Hero: They are waiting for you.",        
        }
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
                        return "I can feel it.... The smell of the dragon...";
                    case 2:
                        return "The dragon took me... I'm scared...";
                    case 3:
                        return "The days haven't been going well...";
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
    vector<vector<short> > temp (31, vector<short> (36, 0));
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
    else if (charactor == "intro") {
        int line = 0;

        if (this->is_Hero) {
            while (line < Hero_chat_map[charactor].size()) {
                temp[9][27] = i_mystery;
                window.build_buffer(Hero_chat_map[charactor][line]);
                window.Print_buffer(temp, player, color);
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
                window.Print_buffer(temp, player, color);
                keyboard.get_userInput();
                while (keyboard.key != KEY_SPACE) {
                keyboard.get_userInput();
                }
                line ++;
            }
        }
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
    }
        system("clear");   
    
    
}
