#include "progress.h"

Progress progress;

// store the state of the game to the file
void Progress::save_progress(int scn_num, int map_code, int event_num, Player player) { 
    ofstream fout("2113_Gp15_mini_game_saving", ofstream::trunc);
    fout << scn_num << endl;
    fout << map_code << endl;
    fout << event_num << endl;
    fout << player.x << endl;
    fout << player.y << endl;
    fout << player.color << endl;
    //fout <<  << endl;
    fout.close();
}

bool Progress::checking_loading() {

    ifstream fin("2113_Gp15_mini_game_saving");
    if (!fin) {
        return 0;
    }

    fin.close();

    return 1;
}

// load the state of the game from the file
void Progress::load_progress(Player &player) {

    ifstream fin("2113_Gp15_mini_game_saving");

    fin >> this->scn_num;
    fin >> this->map_code;
    fin >> this->event_num;
    fin >> this->x;
    fin >> this->y;
    fin >> this->player_color;

    player.x = this->x;
    player.y = this->y;
    player.color = this->player_color;

    fin.close();

}

void Progress::delete_progress() {
    remove("2113_Gp15_mini_game_saving");
    this->scn_num = 0;
    this->map_code = 0;
    this->event_num = 1;
}

