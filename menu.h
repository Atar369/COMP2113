#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "format.h"

using namespace std;

extern const char* menu_logo[7];

#define logo_h_size 7

int get_logo_w_size();

void draw_logo(int h, int w);
