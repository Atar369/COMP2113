#pragma once

#include <string>
#include <vector>
using namespace std;

#include "format.h"

struct class_obj {
    string symbol;
    int hrz, vtrl;
    int x, y;
    int direction;
};

// Create objects
class_obj player = {};
//struct class_obj bullet = {};
//struct class_obj enemy[5]={};
//const int arr_size_x = 27;

//void enemy_move(short current_map[][COLS], int index);

//void enemy_update(short current_map[][COLS]);

//void clear_enemy();

void obj_init(struct class_obj *obj, int x, int y, int dir, char *objname);

void player_collision(short current_lvl[][COLS]);


/*
class Object {
public:
    int x;
    int y;
    vector<string> s;
    int priority = 1;
    vector<Format> formats{};

public:
    Object(){}; // default constructor
    Object(int x, int y, vector<string> s);
    Object(int x, int y, vector<string> s, Format format);
    Object(int x, int y, string s, Format format);
    Object(int x, int y, string s);
    void script_to_format();
}; 

vector<Format> check_format(string &s, int i, int j = 0);*/
