#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "keyboard.h"
#include "draw.h"
#include "maps.h"
using namespace std;


class Window {
    int choice_button = 0;
    bool choice_made = false;
    int x_coor = 0, y_coor = MAP_HEIGHT * 2 / 3;
    int width = MAP_WIDTH*3;
    int height = MAP_HEIGHT/2;
    vector<vector<string> > window_buffer;

    public:
        int scn_num = 0;
        int event_num = 1;
        void build_buffer(const string & content) ;
        void reset_buffer();
        void Print_buffer(vector<vector<short> > current_map);
        void handle_choice(vector<vector<short> >current_map);

};
