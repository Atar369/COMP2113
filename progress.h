#pragma once

#include <fstream>
#include "player.h"
#include "maps.h"
#include "format.h"
using namespace std;

// Progress class, used to save and load game progress for both characters
class Progress {

    public: 
    int scn_num;
    int map_code;
    int event_num;
    int ending_num;

    // for hero
    bool can_enterMonster;
    bool can_enterCastle;
    bool first_time_entering_castle;
    bool first_time_entering_store;
    bool talked_to_oldman;
    bool talked_to_robert;
    bool talked_to_cooper;
    bool saw_key;
    bool saw_treasure;
    bool saw_monster;
    bool monster_noticed;
    bool monster_killed;
    bool dragonnpc_killed;
    bool dragon_killed;
    bool get_treasure1;
    bool get_treasure2;
    bool get_treasure3;
    bool all_treasure;
    int key_take_count;
    bool hero_know_fact;
    bool hero_killed_all;

    // for girl
    bool finish_intro;
    bool first_time_entering_village;
    bool first_time_entering_forest;
    bool first_time_entering_back_village;
    bool get_certificate;
    bool talked_to_monster;
    bool talked_to_dragon;
    bool girl_know_fact;
    bool girl_rewind;

    public:
        void save_progress(Player player);
        bool checking_loading();
        void load_progress(Player &player);
        void reset_progress();
        void delete_progress();
        
};

extern Progress progress;
