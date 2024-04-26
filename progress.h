#pragma once

#include <fstream>
#include "player.h"
#include "maps.h"
#include "format.h"
using namespace std;

class Progress {

    public: 
    int scn_num;
    int map_code;
    int event_num;
    int ending_num;

    public:
        void save_progress(Player player);
        bool checking_loading();
        void load_progress(Player &player);
        void reset_progress();
        void delete_progress();
        
};

extern Progress progress;
