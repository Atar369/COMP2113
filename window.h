#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unistd.h>
#include <sys/ioctl.h>
#include "keyboard.h"
#include "draw.h"
#include "maps.h"
#include "player.h"
using namespace std;


class Window {
    
    int choice_button = 0;
    //int x_coor = 0, y_coor = ROWS * 2 / 3;
    int width = COLS*3;
    int height = ROWS*2/3;
    vector<vector<string> > window_buffer;

    // Save options
    int select_yes, select_no;
    vector<string> save_options = {"> YES <", "  Yes  ", "> NO <", "  No  "};
    vector<vector<short> > temp_map;

    public:
        bool is_Hero = false;
        bool is_Girl = false;
        void build_buffer(const string & content);
        void reset_buffer();
        void Print_buffer(vector<vector<short> > current_map, Player &player, string color);
        void intro_character_choice(Player &player);
        void handle_choice(vector<vector<short> > current_map, int &scn_num, int &event_num, Player &player);
        void handle_save_choice(int &choice_button, int &map_code, Player &player);

};

extern Window window;
