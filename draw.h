#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include "format.h"
#include "player.h"
#include "maps.h"


using namespace std;

void draw_instance(int y, int x, int obj, string symbol);

void draw_map(vector<vector<short> > &current_map, Player &player);

void change_map(vector<vector<short> > & current_map, int target, int new_obj);
