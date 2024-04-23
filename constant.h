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
const short c_bush = 53;
const short c_brick = 54;
const short c_castle = 55;
const short c_flag = 56;
const short c_hole = 57;
const short c_stairs1 = 58;
const short c_stairs2 = 59;
const short c_stairs3 = 60;
const short c_stairs4 = 61;
const short c_stairs5 = 62;
const short c_stairs6 = 63;
const short c_stairs7 = 64;
const short c_dragonnpc = 65;
const short c_dragon = 66;
const short c_deaddragonnpc = 67;
const short c_deaddragon = 68;
const short c_player = 69;
const short c_oldman = 70;
const short c_rooftop1 = 71;
const short c_rooftop2 = 72;
const short c_rooftop3 = 73;
const short c_rooftop4 = 74;
const short c_knob = 75;
const short c_rooftop5 = 76;
const short c_rooftop6 = 77;

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
#define i_c_bush 53
#define i_c_brick 54
#define i_c_castle 55
#define i_c_flag 56
#define i_c_hole 57
#define i_c_stairs1 58
#define i_c_stairs2 59
#define i_c_stairs3 60
#define i_c_stairs4 61
#define i_c_stairs5 62
#define i_c_stairs6 63
#define i_c_stairs7 64
#define i_c_dragonnpc 65
#define i_c_dragon 66
#define i_c_deaddragonnpc 67
#define i_c_deaddragon 68
#define i_c_player 69
#define i_c_oldman 70
#define i_c_rooftop1 71
#define i_c_rooftop2 72
#define i_c_rooftop3 73
#define i_c_rooftop4 74
#define i_c_knob 75
#define i_c_rooftop5 76
#define i_c_rooftop6 77

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
#define s_treeright "\\  "
#define s_grass "wWw"
#define s_leaveleft "=  "
#define s_leaveright "  ="
#define s_dmbottomleft " ╚═"
#define s_dmbottomright "═╝ "
#define s_bush " _ "
#define s_brick "║║║"
#define s_castle "_═_"
#define s_flag " ⚑ "
#define s_hole " o "
#define s_stairs1 "  |"
#define s_stairs2 "|  "
#define s_stairs3 "__/"
#define s_stairs4 "\\__"
#define s_stairs5 " |_"
#define s_stairs6 "_| "
#define s_stairs7 "___"
#define s_dragonnpc "^N^"
#define s_dragon "^@^"
#define s_deaddragonnpc "^░^"
#define s_deaddragon "^▒^"
#define s_player "/@\\"
#define s_oldman "/▼\\"
#define s_rooftop1 " /_"
#define s_rooftop2 "/  "
#define s_rooftop3 "_\\ "
#define s_rooftop4 "  \\"
#define s_knob "  ."
#define s_rooftop5 " __"
#define s_rooftop6 "__ "
