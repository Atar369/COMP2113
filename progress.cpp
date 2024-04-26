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
    fout << this->saw_monster << endl;
    fout << this->monster_killed << endl;
    fout << this->dragonnpc_killed << endl;
    fout << this->dragon_killed << endl;
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
    fin >> this->saw_monster;
    fin >> this->monster_killed;
    fin >> this->dragonnpc_killed;
    fin >> this->dragon_killed;
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
    this->can_enterMonster = 1;
    this->can_enterCastle = 1;
    this->first_time_entering_castle = 1;
    this->first_time_entering_store = 1;
    this->talked_to_oldman = 0;
    this->talked_to_robert = 0;
    this->saw_monster = 0;
    this->monster_killed = 0;
    this->dragonnpc_killed = 0;
    this->dragon_killed = 0;
}

void Progress::delete_progress() {
    remove("2113_Gp15_mini_game_saving.txt");
    this->reset_progress();
}

