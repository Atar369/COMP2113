#include "window.h"
#include "draw.h"
#include "player.h"
#include "keyboard.h"
#include "progress.h"

Window window;

// Choice of character, girl or Hero
const vector<string> player_button = {
"/@\\", "\\@/", "/%\\", "\\%/", "Be the Boy", "Be the Girl"
};

// content of choice window, match with scn num
unordered_map<int, vector<string> > Hero_choice_map_b4 = {
    {1,   {
        "The sun is shining, and the birds are chirping.",
        "It's a beautiful day, isn't it?",
        "Hero wakes up from the dream. Or... Is it really a dream?",
        "The mistery voice still remains in his mind...",  
        "He decided to...",
        }
    },
    {2,   {
        "Hero enters the store", 
        "He saw tons of people around there.",
        "Suddenly, a weird object in the corner grapped his attention.",
        "It was a sword, shining in the dark.",
        "After noticing the sword, he decied to...",
        }
    },
    {3, { // wrong direction, saw monster first, being himself
        "Hero got lost in the forest.",
        "He saw a monster in the distance.",
        "It was a huge monster, with sharp teeth and red eyes.",
        "He decided to...",
        }
    },
    {4, { 
        "He decided to get closer to the monster.",
        "He could felt the hard breath. One step closer, he could be swallowed.",
        "He could clearly see warning signs, but he still decided to...",
        }
    },

};

unordered_map<int, vector<string> > Hero_choice_map_after = {
    {"Scn 1", {
        "He has chosen to be himself.",     
        },
    },    
    {"Scn 2", {
        "He has chosen to be a Hero.",     
        }
    },
    {"Scn 3", {
        "He picked it up and felt the power surging through his body.",
        "He knew that he was the chosen one.",
        "He decided to kill all the monsters and free the villagers from the control of the Dragon.",
        }
    },
    {"Scn 4", {
        "He is not sure if it is other's belongings or not.",
        "He decided to leave it there and continue his journey.",
        }
    },
    {"Scn 5", {
        "He ignored the warning signs and got closer to the monster.",
        }
    },
    {"Scn 6", {
        "He escaped.",     
        }
    },
    {"Scn 6", {
        "He decided to fight the monster.",     
        } 
    }      
};        
    
// choice_1, match with scn num
unordered_map <string, vector<string> > button_choice1 = {
    {"event 1", { "> BE HIMSELF <", "  Be himself  ", } },    
    {"event 2", { "> TAKE THE SWORD <", "  Take the sword  ", } },
    {"event 3", { "> GET CLOSER <", "  Get Closer  ", } },      
    {"event 4", { "> FIGHT THE MONSTER <", "  Fight the monster  ", } }, 
};

// choice_2, match with scn num
unordered_map <string, vector<string> > button_choice2 = {
    {"event 1", { "> BE HERO <", "  Be Hero  ", } },    
    {"event 2", { "> LEAVE THE SWORD <", "  Leave the sword  ", } }, 
    {"event 3", { "> RUN AWAY <", "  Run away  ", } },
    {"event 4", { "> TALK TO THE MONSTER <", "  Talk to the monster  ", } },
};    

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

void Window::reset_buffer() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            window_buffer[i][j] = " ";
        }
    }
}

void Window::Print_buffer(vector<vector<short> > current_map, Player &player, string color) { // position wanted to display
    system("clear");

    int k = 0;

    while (k < height) {
        current_map.pop_back();
        k++;
    }

    draw_map(current_map, player);
    // print buffer window on top of current map, x, y are the top left corner of the window
    //cout << "\033[" << y_coor << ";" << x_coor << "H"; // move cursor to the top left corner of the window

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << color << window_buffer[i][j];
        }
        cout << reset << endl;
    }
    
    reset_buffer();
}

void Window::intro_character_choice(Player &player) {
    string intro = "Choose your character: ";

    build_buffer(intro);

    for (int i = 0; i < this->window_buffer.size(); i++) {
        for (int j = 0; j < this->window_buffer[0].size(); j++) {
            cout << this->window_buffer[i][j];
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
        build_buffer(player_button[select_hero] + "                         " + player_button[select_girl]);

        system("clear");

        for (int i = 0; i < this->window_buffer.size(); i++) {
            for (int j = 0; j < this->window_buffer[0].size(); j++) {
                cout << font_yellow << this->window_buffer[i][j];
            }
            cout << endl;
        }        

        cout << default_format << 8 << ";" << 35 << "H" << font_blue << "Be the Boy" << endl;
        cout << default_format << 8 << ";" << 63 << "H" << font_purple << "Be the girl" << reset << endl;

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

    if (choice_button == 0) {
        is_Hero = true;
    } 
    else {
        is_Girl = true;
    }

}

void Window::handle_choice(vector<vector<short> >current_map, int &scn_num, int &event_num, Player &player){
    string choice1_content;
    string choice2_content;

    vector<string> content_b4;

    // choice description
    content_b4 = Hero_choice_map_b4[event_num];
           

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
        
        switch(event_num) {
            case 1:
                    choice1_content = button_choice1["event 1"][select_choice_1];
                    choice2_content = button_choice2["event 1"][select_choice_2];        
                break;
            case 2:
                    choice1_content = button_choice1["event 2"][select_choice_1];
                    choice2_content = button_choice2["event 2"][select_choice_2];  
                break;
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
            if (event_num == 1) {
                if (choice_button == 0) {
                    scn_num = 1;
                    event_num = 2;
                } 
                else if (choice_button == 1) {
                    scn_num = 2;
                    event_num = 3;
                }
            } 
            else if (event_num == 2) {
                if (choice_button == 0) {
                    scn_num = 3;
                } 
                else if (choice_button == 1) {
                    scn_num = 4;
                }
            }

            event_num++;
            break;
        }
    }

    // print after 
    vector<string> content_after;
    
    if(scn_num == 1) 
        content_after = Hero_choice_map_after["Scn 1"];
    else if(scn_num == 2) 
        content_after = Hero_choice_map_after["Scn 2"];
    else if(scn_num == 3) 
        content_after = Hero_choice_map_after["Scn 3"];
    else if(scn_num == 4) 
        content_after = Hero_choice_map_after["Scn 4"];
    else if(scn_num == 5)
        content_after = Hero_choice_map_after["Scn 5"];
    else if(scn_num == 6) {
        content_after = Hero_choice_map_after["Scn 6"]; 
        player.reach_ending = true;
        progress.ending_num = 5;   
    }

    if (player.reach_ending) {
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
        player.reach_ending = false; 
        progress.save_progress(player);
        //progress.delete_progress();
        return;
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



 void Window::handle_save_choice(int &choice_button, int &map_code, Player &player) {
    
    temp_map = map_code_mapping.at(map_code);

    window.build_buffer("Save progress?");
    window.Print_buffer(temp_map, player, font_white);

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

        window.build_buffer(save_options[select_yes] + save_options[select_no]);
        window.Print_buffer(temp_map, player, font_white);

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

/*
// testing
int main() {
    // Player - Hero
    player.x = 4;
    player.y = 4;
    player.symbol = "|@|";

    Window window;
    
    vector<vector<short> > current_map;

    // Assign the values of Girl_house to current_map
    current_map = map_code_mapping.at(0);

    progress.event_num = 1;
    while (true) {
        
        // Clear screen
        system("clear");
        
        if (progress.event_num == 1) {
            window.handle_choice(current_map, progress.scn_num, progress.event_num, player);
        }

        draw_map(current_map, player);
        
        int key_pressed = keyboard.key_pressed();

        while (key_pressed) {
            keyboard.get_userInput();
        }
        
        if (keyboard.key == KEY_EXIT) {
            break;
        }
        if (keyboard.key == KEY_UP) {
            player.moveUp();
        }
        if (keyboard.key == KEY_DOWN) {
            player.moveDown();
        }
        if (keyboard.key == KEY_LEFT) {
            player.moveLeft();
        }
        if (keyboard.key == KEY_RIGHT) {
            player.moveRight();
        }

        // Move the player
        player.player_move(keyboard.key, current_map);
        player.player_collision(current_map);
        
        draw_map(current_map, player);
        }

    return 0;
} */
