#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
//#include <unistd.h>
//#include <sys/ioctl.h>
#include "format.h"
#include "player.h"


using namespace std;

void draw_instance(int y, int x, int obj, string symbol);

//bool next_map(vector<vector<string> > current_map, short &map_code);

void draw_map(vector<vector<short> > &current_map, Player &player);
