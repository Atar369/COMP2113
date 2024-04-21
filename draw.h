#pragma once

#include <math.h>
#include <string>
#include <map>
//#include "maps.h"
//#include "object.h"
#include "format.h"
#include "player.h"

using namespace std;

void draw_instance(int y, int x, int obj, string symbol);

//bool next_map(short current_map[ROWS][COLS], short &map_code);

void draw_map(short current_map[ROWS][COLS]);
