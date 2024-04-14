#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <cmath>
#include <iostream>
#include "maps.h"
using namespace std;

//////////////////
//  COLORSHEME
//////////////////
// Set color
void SetColor() {
    start_color();
    init_pair(c_wall,   COLOR_BLUE,     COLOR_BLACK);
    init_pair(c_apple,  COLOR_WHITE,    COLOR_BLACK);
    init_pair(c_door,   COLOR_RED,      COLOR_BLACK);   
    init_pair(c_space,  COLOR_BLACK,    COLOR_BLACK);
    init_pair(c_life,   COLOR_GREEN,    COLOR_BLACK);
    init_pair(c_player, COLOR_MAGENTA,  COLOR_BLACK);
    init_pair(c_bullet, COLOR_GREEN,    COLOR_BLACK);
    init_pair(c_enemy,  COLOR_RED,      COLOR_BLACK);
    init_pair(c_box,    COLOR_YELLOW,   COLOR_BLACK);
}

// Draw colored instance
#define td_indent 2 // Top & down ident
#define symbol_count 3

void draw_instance(int y, int x, int color, char name[]) {
    attron(COLOR_PAIR(color));

    // Win offset
    int win_xoffset = w/2;
    int win_yoffset = h/2;
    
    // Level offset
    int lvl_xoffset = (current_lvl_x/2)*symbol_count+(current_lvl_x%2);
    int lvl_yoffset = (current_lvl_y+(td_indent*2))/2-(1 /* +1 indent hud */+(current_lvl_y%2));

    mvprintw(
        /* Y pos */ ceil(win_yoffset - lvl_yoffset) + (y+td_indent), 
        /* X pos */ ceil(win_xoffset - lvl_xoffset) + (x*symbol_count), 
        /* S pos */ name
    );

    attroff(COLOR_PAIR(color));
}


