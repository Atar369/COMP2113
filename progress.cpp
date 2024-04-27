#include "progress.h"

Progress progress;

// store the state of the game to the file
void Progress::save_progress(Player player) { 
    ofstream fout("2113_Gp15_mini_game_saving.txt", ofstream::trunc);
    fout << this->scn_num << endl;
    fout << this->map_code << endl;
    fout << this->event_num << endl;
    fout << this->can_enterMonster << endl;
    fout << this->can_enterCastle << endl;
    fout << this->first_time_entering_castle << endl;
    fout << this->first_time_entering_store << endl;
    fout << this->talked_to_oldman << endl;
    fout << this->talked_to_robert << endl;
    fout << this->talked_to_cooper << endl;
    fout << this->saw_key << endl;
    fout << this->saw_treasure << endl;
    fout << this->saw_monster << endl;
    fout << this->monster_noticed << endl;
    fout << this->monster_killed << endl;
    fout << this->dragonnpc_killed << endl;
    fout << this->dragon_killed << endl;
    fout << this->get_treasure1 << endl;
    fout << this->get_treasure2 << endl;
    fout << this->get_treasure3 << endl;
    fout << this->all_treasure << endl;
    fout << this->key_take_count << endl;
    fout << this->hero_know_fact << endl;
    fout << this->hero_killed_all << endl;
    

    fout << this->girl_saved_monster << endl;
    fout << this->girl_rewind << endl;

    fout << player.x << endl;
    fout << player.y << endl;
    fout << player.color << endl;
    fout << this->ending_num << endl;
    //fout <<  << endl;
    fout.close();
}

bool Progress::checking_loading() {

    ifstream fin("2113_Gp15_mini_game_saving.txt");
    if (!fin) {
        return 0;
    }

    fin.close();

    return 1;
}

// load the state of the game from the file
void Progress::load_progress(Player &player) {

    ifstream fin("2113_Gp15_mini_game_saving.txt");

    fin >> this->scn_num;
    fin >> this->map_code;
    fin >> this->event_num;
    fin >> this->can_enterMonster;
    fin >> this->can_enterCastle;
    fin >> this->first_time_entering_castle;
    fin >> this->first_time_entering_store;
    fin >> this->talked_to_oldman;
    fin >> this->talked_to_robert;
    fin >> this->talked_to_cooper;
    fin >> this->saw_key;
    fin >> this->saw_treasure;
    fin >> this->saw_monster;
    fin >> this->monster_noticed;
    fin >> this->monster_killed;
    fin >> this->dragonnpc_killed;
    fin >> this->dragon_killed;
    fin >> this->get_treasure1;
    fin >> this->get_treasure2;
    fin >> this->get_treasure3;
    fin >> this->all_treasure;
    fin >> this->key_take_count;
    fin >> this->hero_know_fact;
    fin >> this->hero_killed_all;

    fin >> this->girl_saved_monster;
    fin >> this->girl_rewind;

    fin >> player.x;
    fin >> player.y;
    fin >> player.color;
    fin >> this->ending_num;

    fin.close();

}


void Progress::reset_progress() {
    this->scn_num = 0;
    this->map_code = 0;
    this->event_num = 0;
    this->ending_num = 0;

    // for hero
    this->can_enterMonster = 1;
    this->can_enterCastle = 1;
    this->first_time_entering_castle = 1;
    this->first_time_entering_store = 1;
    this->talked_to_oldman = 0;
    this->talked_to_robert = 0;
    this->talked_to_cooper = 0;
    this->saw_key = 0;
    this->saw_treasure = 0;
    this->saw_monster = 0;
    this->monster_noticed = 0;
    this->monster_killed = 0;
    this->dragonnpc_killed = 0;
    this->dragon_killed = 0;
    this->get_treasure1 = 0;
    this->get_treasure2 = 0;
    this->get_treasure3 = 0;
    this->all_treasure = 0;
    this->key_take_count = 0;
}

void Progress::delete_progress() {
    remove("2113_Gp15_mini_game_saving.txt");
    this->reset_progress();
    this->hero_know_fact = 0;
    this->hero_killed_all = 0;
    this->girl_saved_monster = 0;
    this->girl_rewind = 0;
}

