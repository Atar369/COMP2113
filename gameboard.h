// gameboard.h

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <string>
using namespace std;

const int COLS = 27;
const int ROWS = 20;

extern vector<vector<string> > board(ROWS, vector<string> (COLS, " ")); // Declare the extern variable

#endif // GAMEBOARD_H
