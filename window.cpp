#include "window.h"

Window window;

// Choice of character, girl or Hero
const vector<string> player_button = {
"  Be the Boy  ", "> BE THE BOY <", "  Be the Girl  ", "> BE THE GIRL <",
};

// content of choice window, match with event num
unordered_map<int, vector<string> > Hero_choice_map_b4 = { // event num mapping

    {1,   {
        "The sun is shinning bright, and the birds are chirping in the woods.",
        "It's a beautiful day, isn't it?",
        "You wake up from a dream. Or... Is it really a dream?",
        "The mistery voice remains in your mind...",  
        "You decided to...",
        }
    },
    {2,   {
        "Robert, the blacksmith, stood in front of you.",
        "He said, 'I've been waiting for you.'",
        "'The new journey begins...'",
        "'The new hero has been chosen...'",
        "He silently handed you a sword.",
        "'This sword is the key to your destiny.'",
        "'Once you take it, there is no turning back.'",
        "'Are you ready?'",
        "The sword is shining, as if it has a life of its own.",
        "As what the blacksmith said, once you take it, you can't turn back.",
        "You decided to...",
        }
    },
    {3, { // wrong direction, saw monster first, being himself
        "You got lost in the forest.",
        "You saw a monster from a distance.",
        "It was a huge monster, with sharp teeth and red eyes.",
        "You decided to...",
        }
    },
    {4, { 
        "You decided to get closer to the monster.",
        "You could feel your own breath getting heavier as you approach.",
        "One step closer, and you could be swallowed.",
        "You could clearly see warning signs, but you still decided to...",
        }
    },

};

// scn num referring to what choice have been made
unordered_map<int, vector<string> > Hero_choice_map_after = { // scn num mapping

    {1, {
        "You have chosen to be yourself.",     
        },
    },    
    {2, {
        "You have chosen to be a Hero.",     
        }
    },
    {3, {
        "You picked up the sword and felt the power surging through your body.",
        "You knew that you were the chosen one.",
        "You decided to kill all the monsters and free the villagers from the threat of the Dragon.",
        "You are the savior of the people.",
        "You are the legend that will be told for generations to come.",
        "You are the Hero.",
        }
    },
    {4, {
        "You are scared to take the responsibilities of being a Hero.",
        "You are afraid of risking your life for others.",
        "You left the sword there.",
        "Robert was disappointed, but he understood.",
        "You decided to return to your normal life.",
        }
    },
    {5, {
        "You ignored the warning signs and got closer to the monster.",
        }
    },
    {6, {
        "You escaped.",     
        }
    },
    {7, {
        "You decided to fight the monster.",     
        } 
    },
    {8, {
        "You decided to talk to the monster.",
        "The monster surprised you by speaking back.",
        "The monster said that they will never attack humans unless provoked.",
        "You two talked for hours and became friends.",
        "You asked the monster if it saw a girl walking around.",
        "The monster said no, but he would be willing to help you looking for her.",
        "You agreed.",
        "...",     
        }   
    }       
};      
    
// choice_1, match with scn num
unordered_map <int, vector<string> > Hero_button_choice1 = {

    {1, { "> BE YOURSELF <", "  Be yourself  ", } },    
    {2, { "> TAKE THE SWORD <", "  Take the sword  ", } },
    {3, { "> GET CLOSER <", "  Get Closer  ", } },      
    {4, { "> FIGHT THE MONSTER <", "  Fight the monster  ", } }, 
};

// choice_2, match with scn num
unordered_map <int, vector<string> > Hero_button_choice2 = {

    {1, { "> BE HERO <", "  Be Hero  ", } },    
    {2, { "> LEAVE THE SWORD <", "  Leave the sword  ", } }, 
    {3, { "> RUN AWAY <", "  Run away  ", } },
    {4, { "> TALK TO THE MONSTER <", "  Talk to the monster  ", } },
};    


//Girl
unordered_map<int, vector<string> > Girl_choice_map_b4 = { // event num mapping

    {1,   {
        "You got lost in the forest.",
        "There is a monster in the distance.",
        "It was a huge monster with sharp teeth and red eyes.",
        "You: (whispering, voice trembling) What... what is that?",
        "But as your initial terror subsided, curiosity compelled you to take a closer look.",
        "The monster's body was covered in wounds—deep gashes and oozing cuts.",
        "You: Oh no... it's hurt... terribly hurt.",
        "As you neared, the monster recoiled, its red eyes narrowing with suspicion and defiance.",
        "Will you...",
        }
    },
    {2, { 
        "Your heart pounded in your chest.",
        "You: Shit! NOOOOO WAYYYYYYYYY!",
        "You rush towards the throne, where he always sat, the one I loved.",
        "Your eyes lock onto him, lying there in a pool of blood, unconscious.",
        "You: Dragon. How could you leave me alone here, surviving without you?",
        "*** The deadly silence ***",
        "The memory of you and Dragon flows up to your mind...",
        "...You remember how kindly he talked to you and shared.",
        "You: I would do whatever it takes, face any danger, to bring you back...",
        "You: TIME REWIND!!!!",
        "???: It's been a while since you last used your power.",
        "???: You need to understand that everything comes with a cost.",
        "???: The more changes you need to rewind, the greater the cost.",
        "???: In this case, I must warn you that you will have to sacrifice yourself to proceed with the power.",
        "???: That means you will forever vanish from this world.",
        "???: The world will be forever altered...",
        "...and those you care for will lose the memories of your existence.",
        "???: Are you willing to pay that price?",
        }
    },
};

unordered_map<int, vector<string> > Girl_choice_map_after = { // scn num mapping

    {1, {
        "You decided to leave the monster behind.",
        "You: I can't help you now. I need to find the dragon.",
        "Monster: Grrrrrr... hissssssss",
        "As you moved, the monster let out a deafening roar, sending a wave of fear down your spine.",
        "Without a second thought, you reach for your pocket knife to protect yourself.",
        },
    },    
    {2, {
        "You decided to save the monster.",
        "Monster: Grrrrrr... hissssssss",
        "You: It's okay, I won't hurt you.",
        "You carefully placed your hand on the monster's wound.",
        "You: (murmering) time rewind",
        "The deep gashes and oozing cuts on the monster's body began to enclose.",
        "The monster's eyes widened in surprise, and it let out a soft growl.",
        "Monster: Thank you...",
        "Monster: I will complete one wish for you, as a token of my gratitude.",
        "You: I am looking for the dragon, but I have no idea how to find her.",
        "Monster: Ah, I see. I will help get you to her.",
        }
    },    
    {3, {
        "With a heavy heart, you turn away from the wounded dragon, knowing that your journey will continue without him by your side.",
        "The castle, once a place of hope and love, now holds a bittersweet memory as you walk away.",
        "You: I will never forget you, my love.",
        },
    },    
    {4, {
        "You: Of course I will do everything to bring back you, my love.",
        "You: I could never survive without you.",
        "You: Even if it means disappearing from this world...",
        "You: Even if you forget about me...",
        "You: I still want to do it, to bring you back to life, my love.",
        "You: There will be another girl who will love you as much as I do.",
        "You: She will find the kindness and love in you.",
        "You: She will successfully persuade the villagers to accept you.",
        "You: She will do everything I couldn't do for you.",
        "You: She will be the one who will be with you forever.",
        "...",
        "...",
        "...",
        "...",
        "You eyes closed, feeling the tears running down your cheeks.",
        "You take a deep breath, and whisper...",
        "You: I love you dragon...",
        "You never have the chance to say it to him."
        "You take one last look at the throne, the blood, the bodies, the memories...",
        "You take one last breath...",
        "You: TIME REWINDDDD!!!!!!!!!",     
        }
    },  
}; 

unordered_map <int, vector<string> > Girl_button_choice1 = {
    {1, { "> LEAVE THE MONSTER <", "  Leave the monster  ", } },    
    {2, { "> DO NOTHING <", "  Do nothing  ", } }, 
};

unordered_map <int, vector<string> > Girl_button_choice2 = {
    {1, { "> SAVE THE MONSTER <", "  Save the monster  ", } },    
    {2, { "> USE TIME REWIND <", "  Use time rewind  ", } },   
};


// build buffer for the window
void Window::build_buffer(const string & content) {

    // Resize the window_buffer vector to the required dimensions
    window_buffer.resize(height, vector<string>(width));

    // fill the buffer with content
    const int content_length = content.size();
    int w = (width - content_length) / 2;
    int h = height / 2;

    for (int i = 0; i < content_length; i++) {
        window_buffer[h][w + i] = content[i];
    }

    // fill the buffer with standard shape
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j <= 2 || j >= width - 3) 
                window_buffer[i][j] = "#";
            else if (window_buffer[i][j] != "")
                continue;        
            else 
                window_buffer[i][j] = " ";
        }
    }
}

// reset buffer, to all empty
void Window::reset_buffer() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            window_buffer[i][j] = " ";
        }
    }
}

// print buffer on the screen
void Window::Print_buffer(vector<vector<short> > current_map, Player &player, string color) { // position wanted to display
    // Get the dimensions of the terminal window
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int rows = w.ws_row;
    int cols = w.ws_col;

    // centering
    int xoffset = (cols - 36 * 3) / 2;
    int yoffset = rows/2;

    system("clear");
    int k = 0;

    while (k < height) {
        current_map.pop_back();
        k++;
    }

    draw_map(current_map, player);

    for (int i = 0; i < height; i++) {
        cout << default_format << yoffset + i << ";" << xoffset << "H";
        for (int j = 0; j < width; j++) {
            cout << color << window_buffer[i][j];
        }
        cout << reset_format << endl;
    }

    reset_buffer();
}

// intro character choice
void Window::intro_character_choice(Player &player) {
    
    string intro = "Choose your character: ";

    build_buffer(intro);


    // Get the dimensions of the terminal window
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int rows = w.ws_row;
    int cols = w.ws_col;

    // centering
    int xoffset = (cols - 36*3) / 2;
    int yoffset = (rows - window_buffer.size()) / 2;

    for (int i = 0; i < window_buffer.size(); i++) {
        cout << default_format << yoffset + i << ";" << xoffset << "H" << endl;
        for (int j = 0; j < window_buffer[0].size(); j++) {
            cout << window_buffer[i][j];
        }
        cout << endl;
    }

    // save quit loop
    while (true) {
        
        int select_hero = 0;
        int select_girl = 2;

        if (choice_button == 0) {
            select_hero = 1;
            select_girl = 2;

        } 
        else {
            select_hero = 0;
            select_girl = 3;
        }  

        reset_buffer();
        if (!progress.girl_rewind) {
            build_buffer(player_button[select_hero] + "                         " + player_button[select_girl]);
        }
        else {
            build_buffer(player_button[select_hero] + "                         " + + "               ");
        }
        system("clear");
        
        for (int i = 0; i < window_buffer.size(); i++) {
            cout << default_format << yoffset + i << ";" << xoffset << "H" << endl;
            for (int j = 0; j < window_buffer[0].size(); j++) {
                cout << font_yellow << window_buffer[i][j];
            }
            cout << endl;
        }        

        keyboard.get_userInput();
        
        // button
        if (keyboard.key == KEY_LEFT) {
            choice_button--;
            if (choice_button <= 0) {
                choice_button = 0;
            }
        }
            
        if (!progress.girl_rewind) {
            if (keyboard.key == KEY_RIGHT) {
                choice_button++;
                if (choice_button >= 1) {
                    choice_button = 1;
                }
            }
        }
        else {
            choice_button = 0;
        }

        if (keyboard.key == KEY_ENTER) 
            break;
    }

    if (choice_button == 0) {
        is_Hero = true;
        player.color = font_blue;
    } 
    else {
        is_Girl = true;
        player.color = font_purple;
    }

    reset_buffer();
}

// handle choice
void Window::handle_choice(Progress &progress, Player &player){
    string choice1_content;
    string choice2_content;

    vector<vector<short> >current_map = map_code_mapping.at(progress.map_code);

    vector<string> content_b4;

    // based on the player color (character chose), load the content
    if (player.color == font_blue) {
        is_Hero = true;
        content_b4 = Hero_choice_map_b4[progress.event_num];     
    }
    else {
        is_Girl = true;
        content_b4 = Girl_choice_map_b4[progress.event_num];     
    } 

    int line = 0;
    while(line < content_b4.size()) {
        build_buffer(content_b4[line]);    
        Print_buffer(current_map, player, font_white);
        line ++;
        keyboard.get_userInput();
        while (keyboard.key != KEY_SPACE) {
        keyboard.get_userInput();
        }
    }

    int select_choice_1 = 1;
    int select_choice_2 = 1;

    // make choice loop
    while (true) {

        string choice_contents = "";
        
        if (is_Hero) {
            choice1_content = Hero_button_choice1[progress.event_num][select_choice_1];
            choice2_content = Hero_button_choice2[progress.event_num][select_choice_2];        
        }
        else {
            choice1_content = Girl_button_choice1[progress.event_num][select_choice_1];
            choice2_content = Girl_button_choice2[progress.event_num][select_choice_2];       
        }

        choice_contents = choice1_content + "         " + choice2_content;

        build_buffer(choice_contents);
        Print_buffer(current_map, player, font_white);

        keyboard.get_userInput();
        
        // button
        if (keyboard.key == KEY_LEFT) {
            choice_button--;
            if (choice_button <= 0) {
                choice_button = 0;
            }
        }
            
        if (keyboard.key == KEY_RIGHT) {
            choice_button++;
            if (choice_button >= 1) {
                choice_button = 1;
            }
        } 
    
        // check the button
        if (choice_button == 0) {
            select_choice_1 = 0;
            select_choice_2 = 1;
        } 
        else if (choice_button == 1) {
            select_choice_1 = 1;
            select_choice_2 = 0;
        }

        // modify event num, scn num after choice made
        if (keyboard.key == KEY_ENTER) {
            if (is_Hero) {
                switch (progress.event_num) {
                    case 1: 
                        if (choice_button == 0) {
                            progress.scn_num = 1;
                            progress.event_num = 3;
                        } 
                        else if (choice_button == 1) {
                            progress.scn_num = 2;
                            progress.event_num = 2;
                        }
                    break;

                    case 2: 
                        if (choice_button == 0) {
                            progress.scn_num = 3;
                            progress.event_num = 0;
                        } 
                        else if (choice_button == 1) {
                            progress.scn_num = 4;
                            progress.event_num = 0;
                        }
                    break;  

                    case 3:  
                        if (choice_button == 0) {
                            progress.scn_num = 5;
                            progress.event_num = 4;
                        } 
                        else if (choice_button == 1) {
                            progress.scn_num = 6;
                            progress.event_num = 0; // reset effect num as no more choices can be made
                        }
                    break;

                    case 4:
                        if (choice_button == 0) {
                            progress.scn_num = 7;
                            progress.event_num = 0;
                            progress.ending_num = 5;
                            player.reach_ending = true;
                        } 
                        else if (choice_button == 1) {
                            progress.scn_num = 8;
                            progress.event_num = 0;
                            progress.ending_num = 4;
                            player.reach_ending = true;
                        }
                    break;        
                }
        }
        else { // for girl case
            switch (progress.event_num) {
                case 1:
                    if (choice_button == 0) {
                        progress.scn_num = 1;
                        progress.event_num = 0;
                    } 
                    else if (choice_button == 1) {
                        progress.scn_num = 2;
                        progress.event_num = 0;
                    }
                break;
                
                case 2: 
                    if (choice_button == 0) {
                        progress.scn_num = 3;
                        progress.event_num = 0;
                    } 
                    else if (choice_button == 1) {
                        progress.scn_num = 4;
                        progress.event_num = 0;
                    }
                break;  
            }
        }        
        break;
        }
    }

    // print after 
    vector<string> content_after;
    
    if (is_Hero) {
        content_after = Hero_choice_map_after[progress.scn_num];
    }
    else if (is_Girl) {
        content_after = Girl_choice_map_after[progress.scn_num];
    }

    line = 0;
    while(line < content_after.size()) {
        build_buffer(content_after[line]);    
        Print_buffer(current_map, player, font_white);
        line ++;
        keyboard.get_userInput();
        while (keyboard.key != KEY_SPACE) {
        keyboard.get_userInput();
        }
    } 

    system("clear");   

}


// handle save choice, user can choose to save or not
void Window::handle_save_choice(int &choice_button, int &map_code, Player &player) {

    vector<vector<short> > temp_map (32, vector<short>(36, 0));
    
    temp_map = map_code_mapping.at(map_code);

    build_buffer("Save progress?");
    Print_buffer(temp_map, player, font_white);

    while (keyboard.key != KEY_SPACE) {
            keyboard.get_userInput();
    }

    // save quit loop
    while (true) {
        
        if (choice_button == 0) {
            select_yes = 0;
            select_no = 3;

        } 
        else {
            select_yes = 1;
            select_no = 2;
        }  

        build_buffer(save_options[select_yes] + save_options[select_no]);
        Print_buffer(temp_map, player, font_white);

        keyboard.get_userInput();
        
        // button
        if (keyboard.key == KEY_LEFT) {
            choice_button--;
            if (choice_button <= 0) {
                choice_button = 0;
            }
        }
            
        if (keyboard.key == KEY_RIGHT) {
            choice_button++;
            if (choice_button >= 1) {
                choice_button = 1;
            }
        }

        if (keyboard.key == KEY_ENTER) 
            break;
    }

}

// a fighting scene if the player choose to be a hero
void Window::Print_fighting(string contents, Player &player, string color, int key_required) {
    system("clear");
    vector<vector<short> > fighting (31, vector<short>(36, 0));
    vector<string> fightclass = Hero_chat_map.at(contents);
    fighting[12][9] = i_hero;
    fighting[12][27] = i_cooper;
    for (int i = 0; i < fightclass.size(); i++) {
        build_buffer(fightclass[i]);
        Print_buffer(fighting, player, color);
        if (i != fightclass.size() - 1) {
            keyboard.get_userInput();
            while (keyboard.key != KEY_SPACE) {
                keyboard.get_userInput();
            }
        }
    }

    if (contents != "fight class7") {
        keyboard.get_userInput();
        while (keyboard.key != key_required) {
            switch(chat.getRandomNumber(1, 3)) {
                case 1:
                    build_buffer("Cooper hits you on the head.");
                    break;
                case 2:
                    build_buffer("'Pay attention, young hero! You need to focus!'");
                    break;
                case 3:
                    build_buffer("'That's not the right move. Try again.'");
                    break;
            }
            Print_buffer(fighting, player, font_red);
            keyboard.get_userInput();
        }
    }
    system("clear");    
}

// a healing scene if the player choose
void Window::Print_healing(string contents, Player &player, string color) {
    system("clear");
    vector<vector<short> > healing (31, vector<short>(36, 0));
    vector<string> patient = Girl_chat_map.at(contents);
    healing[6][9] = i_girl;
    healing[6][27] = i_cooper;
    healing[12][7] = i_rightwardrobe;
    healing[12][29] = i_leftwardrobe;

    for (int i = 0; i < patient.size(); i++) {
        build_buffer(patient[i]);
        Print_buffer(healing, player, color);
        keyboard.get_userInput();
        while (keyboard.key != KEY_SPACE) {
            keyboard.get_userInput();
        }
    }

    int spc = 0, j = 8;
    while (true) {
        if (keyboard.key == KEY_SPACE) {
            spc++; 
            if (contents == "patient1") {
                    if (spc % 3 == 0) {
                        healing[12][j] = i_castlewall;
                        j++;
                    }
                    if (spc > 63) {
                        spc = 0;
                        j = 8;
                        for (int k = 8; k < 29; k++) {
                                healing[12][k] = i_empty;
                        }
                    }
            }
            if (contents == "patient2") {
                    if (spc % 7 == 0) {
                        healing[12][j] = i_castlewall;
                        j++;
                    }
                    if (spc > 147) {
                        spc = 0;
                        j = 8;
                        for (int k = 8; k < 29; k++) {
                            healing[12][k] = i_empty;
                        }
                    }
            }
            if (contents == "patient3") {
                if (spc % 5 == 0) {
                    healing[12][j] = i_castlewall;
                    j++;
                }
                if (spc > 105) {
                    spc = 0;
                    j = 8;
                    for (int k = 8; k < 29; k++) {
                        healing[12][k] = i_empty;
                    }
                }
            }
        }
        Print_buffer(healing, player, color);
        keyboard.get_userInput();
        if (keyboard.key == KEY_ENTER) {
            if (contents == "patient1") {
                if (spc == 63) {
                    for (int k = 8; k < 29; k++) {
                        healing[12][k] = i_empty;
                    }
                    break;
                }
            }

            if (contents == "patient2") {
                if (spc == 147) {
                    for (int k = 8; k < 29; k++) {
                        healing[12][k] = i_empty;
                    }
                    break;
                }
            }

            if (contents == "patient3") {
                if (spc == 105) {
                    for (int k = 8; k < 29; k++) {
                        healing[12][k] = i_empty;
                    }
                    break;
                }
            }

            keyboard.get_userInput();
        }                 
    }   
    system("clear");    
}

// print endings
void Window::Print_endings(vector<string> contents, string color) {
    system("clear");
    vector<vector<short> > endings (31, vector<short>(36, 0));

    for (int i = 0; i < contents.size(); i++) {
        build_buffer(contents[i]);
        Print_buffer(endings, player, color);
        keyboard.get_userInput();
        while (keyboard.key != KEY_SPACE) {
            keyboard.get_userInput();
        }
    }

    sleep(1);
    system("clear");
}
