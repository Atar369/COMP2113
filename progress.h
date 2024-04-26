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
    bool can_enterMonster;
    bool can_enterCastle;
    bool first_time_entering_castle;
    bool first_time_entering_store;
    bool talked_to_oldman;
    bool talked_to_robert;
    bool saw_monster;
    bool monster_killed;
    bool dragonnpc_killed;
    bool dragon_killed;

    public:
        void save_progress(Player player);
        bool checking_loading();
        void load_progress(Player &player);
        void reset_progress();
        void delete_progress();
        
};

extern Progress progress;
