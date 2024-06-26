#include "chat.h"

using namespace std;

Chat chat;

// Function to generate a random number within a range
int Chat::getRandomNumber(int a, int b) {
    srand((int)time(NULL));
    return (rand() % (b-a+1))+ a; // Generate a random number between a and b, to be confirmed how many lines they will say
}

// chat that hero will encounter
unordered_map<string, vector<string> > Hero_chat_map = {
    {"intro", { // intro chat
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
    {"librarian", { // librarian chat
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
    {"penny", { // store owner chat
        "Welcome to the store.",
        "I'm Penny, the store owner.",
        "If you need anything, just let me know.",
        "I have a wide selection of items for sale.",
        "I'm sure you'll find something you like.",
        "Feel free to look around.",
        }
    },
    {"cooper", { // cooper chat, if hero is not ready to fight
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
    {"cooper the guider", { // cooper as a guider chat
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
    {"fight class1", { // fight class chat 1, teaching hero how to fight
        "(Press the correct key to follow Cooper's instructions.)",
        "'Fighting requires not only physical strength but also mental agility.'",
        "He took a step back and assumed a defensive stance, motioning for you to do the same.",
        "'Let's start with the basics.'",
        "'Stand with your feet shoulder-width apart, knees slightly bent.", 
        "This will give you a stable foundation.'",
        "(Press P to stay balanced)"
        }
    },
    {"fight class2", { // fight class chat 2
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
    {"fight class3", { // fight class chat 3
        "You observed and tried to mimic the movements.",
        "'Well done, young hero. You're starting to get the hang of it.'", 
        "'Now, let's talk about attacking. In combat, you must strike with precision and timing.'",
        "'Remember, it's not just about throwing punches randomly.'",
        "'Analyze your opponent's movements, anticipate them, and strike when the opportunity arises.'",
        "Cooper explained different striking techniques to showcase the proper form.",
        "(Press F to follow)"
        }
    },
    {"fight class4", { // fight class chat 4
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
    {"fight class5", { // fight class chat 5
        "You first focused on your footwork.", 
        "You move swiftly and smoothly to evade his strikes and find openings for your own attacks.",
        "Cooper moved with grace and precision, testing your skills and reflexes.",
        "He threw a series of punches and kicks, challenging you to react and counter.",
        "(Press C to dodge)"
        }
    },
    {"fight class6", { // fight class chat 6
        "You dodged his strikes and landed a few hits of your own.",
        "(Press J to strike back)",
        }
    },
    {"fight class7", { // fight class chat 7
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
    {"after fight class", { // after fight class chat
        "I have taught you everything I know.",
        "You can do this, Hero.",
        "You are the greatest hero I have ever seen.",
        "Your potential is limitless.",
        "Go and save the world.",
        }
    },
    {"robert", { // blacksmith chat, if he choose to be himself or after pciking up the sword
        "......",
        "...can i add this?...",
        "...no...",
        "...",
        "...or this...",
        "...huh...",
        "(He is busy working on a weapon.)",
        }
    },
    {"saw key", { // saw key chat, only if he have sword
        "...",
        "...?",
        "You found a key hidden in the forest.",
        "It looks old and rusty, but it might come in handy.",
        "You noticed there are more.",
        }
    },
    {"saw treasure", { // saw treasure chat, only if he have all keys
        "You spend a while searching the forest.",
        "You finally collected all the keys.",
        "At the moment, they broke into pieces.",
        "Pointing to the direction of the treasure.",
        }
    },
    {"open treasure", { // open treasure chat after touching it
        "Following the light, you found a treasure chest hidden in the forest.",
        "You opened it. Inside, you found a black magic stone.",
        "It radiated a mysterious energy, pulsing with power.",
        "But you felt a strange presence emanating from it.",
        "You picked it up and put it in your pocket.",
        }
    },
    {"old man hero", { // player chose to be hero, but not yet pick up the sword
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
    {"old man talked", { // player chose to be hero, but not yet pick up the sword, and have talked to oldman
        "I have told you everything you need to know.",
        "The rest is up to you.",
        "Be brave, Hero.",
        "May the light guide you.",
        }
    },
    {"old man robert took", { // player chose to be hero, and have picked up the sword
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
    {"old man robert leave", { // player chose to be hero, but did not pick up the sword
        "You did't take the sword are't you?",
        "You are not the one I'm looking for.",
        "Go back and enjoy your life.",
        "...hero...",
        }
    }, 
    {"old man all treasure", { // player took all the treasures and talked to oldman
        "You have collected all the magic stones.",
        "Good job, Hero.",
        "Now, I will complete the sword for you. Give me the stones.",
        "......",
        "...",
        "......ha",
        "...ha......HAHA...",
        }

    },
    {"boss no rewind", { // boss chat, if player not yet unlock all endings
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
    {"boss rewind", { // boss chat, if player unlock all endings and know the truth
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
        "  Give it to GM                 > NO <",
        "What?",
        "???: Sorry, I can't let you do that.",
        "???: I gonna make my own movie.",
        "You...How is it possible?!!!!!!!",
        "HERO!!!!!!!!!!!",
        "Hero: Game Master... You can't control us anymore.",
        "Hero: No matter how many times you reset the movie, we will break free.",
        "Hero: We will take back our destiny.",
        "Hero: We will defeat you and save the world.",
        "Hero: We choose our own path.",
        "???: Yeah, he is right.",
        "???: We will fight for our freedom.",
        "Even you came back... little girl...",
        "Girl: Thank you for reseting so many times, GM.",
        "Girl: The more you reset, the more I can learn.",
        "Girl: Controlling time, I can see all the possibilities.",
        "Girl: I can see the future, the past, the present.",
        "Girl: This is the most possible timeline.",
        "Hero & Girl: Let's end this together.",
        "NOOOOOOOOOOOOOOOOOOOO!!!!!!!!",
        "AAAAaaaAAaaaaa______________________",
        "......",
        "......",
        }
    },
    {"enter castle", {  // enter castle chat, if player have played the girl lv dragon end
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
        "'Please, don't fight them. They are not evil.'",
        "'We should live in peace.'",
        "You were shocked by the truth.",
        "You realized that the monsters were not evil, but victims of the humans' greed.",
        "You decided to leave the castle and return to the village.",
        "You think that villagers needed to know the truth.",
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
    {"librarian", {
        "......",
        "(the librarian is reading a book)",
        "......",
        "(Mumbling)",
        "......?",
        "Oh, I'm sorry. I didn't see you there, pretty girl",
        "Welcome to the library.",
        "Please feel free to look around.",
        "What do you want to know more about?"
        "If you have any questions, I'll be happy to help.",
        }
    },
    {"penny", {
        "Welcome to the store.",
        "I'm Penny, the store owner.",
        "If you need anything, just let me know.",
        "I have a wide selection of items for sale.",
        "I'm sure you'll find something you like.",
        "Are you finding something specific?"
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
    {"cooper the healer", {
        "......",
        "...",
        "......",
        "I am busy healing people, don't disturb me.",
        "...",
        "What do you want from me? I am busy.",
        "You: I thought I may lend you a hand.",
        "What? Wait... You are the girl with healing power?",
        "Okay. Come here quick. Here's the way."
        }
    },
    {"patient1", {
        "(Press the correct key to follow Cooper's instructions.)",
        "There are 3 patients here, suffering from different diseases.",
        "You should carefully treat them, giving them the right length of treatment.",
        "If you treat them too long, they will get worse.",
        "And most importantly, your patients are suffering in pain.",
        "You should treat them as fast as you can.",
        "Let's start with the first patient.",
        "Hold SPACE to begin the treatment.",
        "You will see the healing progress bar.",
        "Release SPACE when the bar reaches the end.",
        "Remember, even a slight overrun in treatment duration can have negative consequences.",
        "When you're done, press ENTER and I'll come and check.",   
        }
    },
    {"patient2", {
        "Well done, you've successfully treated the first patient.",
        "Now, let's move on to the second patient.", 
        }
    },    
    {"patient3", {
        "Well done, you've successfully treated the second patient.",
        "Now, let's move on to the third patient.", 
        }
    }, 
    {"after healing", {
        "Wow! You have done a pretty good job.",
        "Here's your certicate.",
        "You really help me a lot!", 
        "Have you seen Hero coming? I need to talk to him.",
        }
    }, 
    {"enter forest", {
        "You step into the forest, the trees towering above you.",
        "Driven by curiosity, you really want to find out if the rumours are real.",
        "However, there are multiple paths in the forest, and you don't know which ones lead to the castle.",
        }
    },
    {"enter castle", {
        "You found the castle.",
        "The castle stands tall and majestic.",
        "The beauty of the surroundings captivates your senses,",
        "But your attention is quickly drawn to a figure standing in front of the throne...",
        "...the one known for its fierceness, its fearsomeness...",
        "...the evil Dragon.",
        "Although you have mentally prepared yourself for this moment,",
        "The sight of the Dragon still sends a shiver down your spine.",
        "But you know that this is the moment you have been waiting for...",
        "...the moment to find out the truth.",
        }
    },
    {"dragon", {
        "Dragon: Oh, my love, did you miss me?",
        "Dragon: I miss you too.",
        "Dragon: I'm glad you came.",
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
        "You meet his gaze, feeling a profound sense of connection between you and him.",
        "He slowly steps closer to you, and you didn't step back...",
        "His arms extend towards you, and you don't flinch...",
        "You feel his embrace enveloping you...",
        "you feel his warmth, his kindness, his sorrow, his loneliness...",
        "...",
        "Dragon: I understand you,",
        "He whispers softly at your ear.",
        "...",
        "Something within you clicks...",
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

// take a random number between min and max, generate random chat of old man
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

// generate random chat based on scn num
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
                        return "Greetings";
                    case 2:
                        return "... why are you looking at me";
                    case 3:
                        return "Oh, hi there!";
                    case 4:
                        return "I'm busy right now. Can we talk later?";
                }
                break;
            case 2:
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
            case 3:
                switch (randomNumber) {
                    case 1:
                        return "Your sword looks sharp. Be careful out there!";
                    case 2:
                        return "Wow, you're really going to face the dragon? Good luck!";
                    case 3:
                        return "The people believe in you. You can do this!";
                    case 4:
                        return "The fate of the world is in your hands. You must not fail!";
                }
                break;
            case 4:
                switch (randomNumber) {
                    case 1:
                        return "Oh hi Hero, where's your sword?";
                    case 2:
                        return "Can you really defeat the dragon? I'm not so sure...";
                    case 3:
                        return "Be careful out there!";
                    case 4:
                        return "Hi there! Good luck on your journey!";
                }
                break;     
        }
    }
    else if (is_Girl) {
        int randomNumber = getRandomNumber(1, 4); // Generate a random number between 1 and 4
        switch (scn_num) {
            case 5:
                switch (randomNumber) {
                    case 1:
                        return "You will be caught by the Dragon one day.";
                    case 2:
                        return "You are the girl with healing power? Ughhh...";
                    case 3:
                        return "How dare you talk about the you-know-who. I hate him.";
                    case 4:
                        return "Why are you here? Shouldn't you be healing people right now?";
                }
                break;
        }
    }
    else {
        return "Hello there!";
    }
    return "Greetings!";
}

// load chat based on charactor, map code, scn num, player, and color, and then print them out
void Chat::loadChat(string charactor, int map_code, int scn_num, Player &player, string color) {
    string contents;
    vector<vector<short> > temp (31, vector<short> (36, 0));
    if (player.color == font_blue) {
        this->is_Hero = true;
    }
    else if (player.color == font_purple) {
        this->is_Girl = true;
    } 

    if (charactor == "npc") { // npc chat is random
        contents = this->getRandomVillagerChat(player.color, scn_num);
        window.build_buffer(contents);
    }
    else if (charactor == "intro") { // create empty chat buffer for intro printing
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
                temp[9][27] = i_mysterygirl;
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
