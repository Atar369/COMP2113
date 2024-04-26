#include "progress.h"

Progress progress;

// store the state of the game to the file
void Progress::save_progress(Player player) { 
    ofstream fout("2113_Gp15_mini_game_saving.txt", ofstream::trunc);
    fout << this->scn_num << endl;
    fout << this->map_code << endl;
    fout << this->event_num << endl;
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
}

void Progress::delete_progress() {
    remove("2113_Gp15_mini_game_saving.txt");
    this->reset_progress();
}

