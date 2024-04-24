#pragma once

#include <fstream>
#include "player.h"
#include "maps.h"
using namespace std;

class Progress {

    public: 
    int scn_num;
    int map_code;
    int event_num;
    int x, y;
    string player_color;

    public:
        void save_progress(int scn_num, int map_code, int event_num, Player player);
        bool checking_loading();
        void load_progress(Player &player);
        void delete_progress();
};

extern Progress progress;
