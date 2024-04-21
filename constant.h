#pragma once

#include <vector>
#include <string>
using namespace std;

// Game board size
#define COLS 27
#define ROWS 20

// Game Global var
//short choice = 1;
//short option = 0;
//short Scn_num = 0;
//short map_code = 0;
// short lifes = 3;

//int apples_in_level = 0;
//int bullet_shoot = false;


// Window width & Height
//int w, h;

// Color
const short c_empty      = 0;
const short c_wall       = 1;
const short c_treasure   = 2;
const short c_door       = 3;
const short c_chair      = 4;
const short c_npc        = 5;
const short c_player     = 6;
const short c_enemy      = 7;
const short c_monster    = 8;
const short c_grass      = 9;
const short c_closet     = 10;
const short c_dragon     = 11;
const short c_key        = 12;
const short c_table      = 13;
const short c_bed        = 14;
const short c_lightoff   = 15;
const short c_lighton    = 16;


// Index map object
#define i_empty     0
#define i_wall      1
#define i_treasure  2
#define i_door      3
#define i_chair     4
#define i_npc       5
#define i_player    6
#define i_enemy     7
#define i_monster   8
#define i_grass     9
#define i_closet    10
#define i_dragon    11
#define i_key       12
#define i_table     13
#define i_bed       14
#define i_lightoff  15
#define i_lighton   16

// Symbol map object
#define s_empty         "   "
#define s_wall          "///"
#define s_treasure      "[$]"
#define s_door          "{ }"
#define s_chair         "|-|"
#define s_npc           "/N\\"
#define s_player        "|@|"
#define s_enemy         "(-)"
#define s_monster       "(?)"
#define s_grass         "www"
#define s_closet        "[=]"
#define s_dragon        "^@^"
#define s_key           "[*]"
#define s_table         "[T]"
#define s_bed           "==="
#define s_lightoff      "[']"
#define s_lighton       "[`]" 

#define ROWS 20
#define COLS 27
