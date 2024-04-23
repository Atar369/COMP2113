#pragma once

#include <vector>
#include <string>
using namespace std;

// Game board size
#define COLS 36
#define ROWS 32

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
const short c_empty         = 0;
const short c_dtopleft     = 1;
const short c_dtopright    = 2;
const short c_dbottomleft  = 3;
const short c_dbottomright = 4;
const short c_dhorizontal  = 5;
const short c_dverticalleft = 6;
const short c_dverticalright = 7;
const short c_dverticalmiddle = 8;
const short c_dtopcross = 9;
const short c_dbottomcross = 10;
const short c_dleftcross = 11;
const short c_drightcross = 12;
const short c_dmiddlecross = 13;
const short c_stopleft = 14;
const short c_srightleft = 15;
const short c_sbottomleft = 16;
const short c_sbottomright = 17;
const short c_shorizontal = 18;
const short c_sverticalleft = 19;
const short c_sverticalright = 20;
const short c_sverticalmiddle = 21;
const short c_stopcross = 22;
const short c_sbottomcross = 23;
const short c_sleftcross = 24;
const short c_srightcross = 25;
const short c_smiddlecross = 26;
const short c_bed = 27;
const short c_bedleft = 28;
const short c_bedright = 29;
const short c_bedcentre = 30;
const short c_bedmiddle = 31;
const short c_leftchair = 32;
const short c_rightchair = 33;
const short c_door = 34;
const short c_leftdoor = 35;
const short c_rightdoor = 36;
const short c_lightoff = 37;
const short c_lighton = 38;
const short c_treasure = 39;
const short c_key = 40;
const short c_leftcupboard = 41;
const short c_rightcupboard = 42;
const short c_npc = 43;
const short c_tree = 44;
const short c_treebranch = 45;
const short c_treeleft = 46;
const short c_treeright = 47;
const short c_grass = 48;
const short c_leaveleft = 49;
const short c_leaveright = 50;
const short c_dmbottomleft = 51;
const short c_dmbottomright = 52;


// Index map object
#define i_empty        0
#define i_c_dtopleft   1
#define i_c_dtopright  2
#define i_c_dbottomleft 3
#define i_c_dbottomright 4
#define i_c_dhorizontal 5
#define i_c_dverticalleft 6
#define i_c_dverticalright 7
#define i_c_dverticalmiddle 8
#define i_c_dtopcross  9
#define i_c_dbottomcross 10
#define i_c_dleftcross 11
#define i_c_drightcross 12
#define i_c_dmiddlecross 13
#define i_c_stopleft   14
#define i_c_srightleft 15
#define i_c_sbottomleft 16
#define i_c_sbottomright 17
#define i_c_shorizontal 18
#define i_c_sverticalleft 19
#define i_c_sverticalright 20
#define i_c_sverticalmiddle 21
#define i_c_stopcross 22
#define i_c_sbottomcross 23
#define i_c_sleftcross 24
#define i_c_srightcross 25
#define i_c_smiddlecross 26
#define i_c_bed 27
#define i_c_bedleft 28
#define i_c_bedright 29
#define i_c_bedcentre 30
#define i_c_bedmiddle 31
#define i_c_leftchair 32
#define i_c_rightchair 33
#define i_c_door 34
#define i_c_leftdoor 35
#define i_c_rightdoor 36
#define i_c_lightoff 37
#define i_c_lighton 38
#define i_c_treasure 39
#define i_c_key 40
#define i_c_leftcupboard 41
#define i_c_rightcupboard 42
#define i_c_npc 43
#define i_c_tree 44
#define i_c_treebranch 45
#define i_c_treeleft 46
#define i_c_treeright 47
#define i_c_grass 48
#define i_c_leaveleft 49
#define i_c_leaveright 50
#define i_c_dmbottomleft 51
#define i_c_dmbottomright 52

// Symbol map object
#define s_empty         "   "
#define s_dtopleft     "╔══"
#define s_dtopright    "══╗"
#define s_dbottomleft  "╚══"
#define s_dbottomright "══╝"
#define s_dhorizontal  "═══"
#define s_dverticalleft "║  "
#define s_dverticalright "  ║"
#define s_dverticalmiddle " ║ "
#define s_dtopcross "═╦═"
#define s_dbottomcross "═╩═"
#define s_dleftcross "╠══"
#define s_drightcross "══╣"
#define s_dmiddlecross "═╬═"
#define s_stopleft "┌──"
#define s_srightleft "──┐"
#define s_sbottomleft "└──"
#define s_sbottomright "──┘"
#define s_shorizontal "───"
#define s_sverticalleft "│  "
#define s_sverticalright "  │"
#define s_sverticalmiddle " │ "
#define s_stopcross "─┬─"
#define s_sbottomcross "─┴─"
#define s_sleftcross "├──"
#define s_srightcross "──┤"
#define s_smiddlecross "─┼─"
#define s_bed "==="
#define s_bedleft "== "
#define s_bedright " =="
#define s_bedcentre " = "
#define s_bedmiddle "= ="
#define s_leftchair "║██"
#define s_rightchair "██║"
#define s_door "---"
#define s_leftdoor "{--"
#define s_rightdoor "--}"
#define s_lightoff "[']"
#define s_lighton "[`]"
#define s_treasure "{$}"
#define s_key "[*]"
#define s_leftcupboard "│ ═"
#define s_rightcupboard "═ │"
#define s_npc "/N\\"
#define s_tree "|=|"
#define s_treebranch "/=\\"
#define s_treeleft "  /"
