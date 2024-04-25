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
const short c_empty = 0;
const short c_wall = 1;
const short c_hero = 2;
const short c_girl = 3;
const short c_bed = 4;
const short c_bedleft = 5;
const short c_bedright = 6;
const short c_bedcentre = 7;
const short c_bedmiddle = 8;
const short c_leaveleft = 9;
const short c_leaveright = 10;
const short c_table = 11;
const short c_chair = 12;
const short c_door = 13;
const short c_leftdoor = 14;
const short c_rightdoor = 15;
const short c_lightoff = 16;
const short c_lighton = 17;
const short c_treasure = 18;
const short c_key = 19;
const short c_leftcupboard = 20;
const short c_rightcupboard = 21;
const short c_npc = 22;
const short c_tree = 23;
const short c_treebranch = 24;
const short c_treeleft = 25;
const short c_treeright = 26;
const short c_grass = 27;
const short c_bush = 28;
const short c_brick = 29;
const short c_castle = 30;
const short c_flag = 31;
const short c_hole = 32;
const short c_stairs1 = 33;
const short c_stairs2 = 34;
const short c_stairs3 = 35;
const short c_stairs4 = 36;
const short c_stairs5 = 37;
const short c_stairs6 = 38;
const short c_stairs7 = 39;
const short c_dragonnpc = 40;
const short c_dragon = 41;
const short c_deaddragonnpc = 42;
const short c_deaddragon = 43;
const short c_oldman = 44;
const short c_rooftop1 = 45;
const short c_rooftop2 = 46;
const short c_rooftop3 = 47;
const short c_rooftop4 = 48;
const short c_rooftop5 = 49;
const short c_rooftop6 = 50;
const short c_knob = 51;
const short c_leftwardrobe = 52;
const short c_rightwardrobe = 53;
const short c_librarian = 54;
const short c_penny = 55;
const short c_haley = 56;
const short c_cooper = 57;
const short c_robert = 58;
const short c_castlewall = 59;
const short c_stairs8 = 60;
const short c_stairs9 = 61;
const short c_chair1 = 62;
const short c_chair2 = 63;
const short c_chair3 = 64;
const short c_chair4 = 65;
const short c_chair5 = 66;
const short c_chair6 = 67;
const short c_chair7 = 68;
const short c_chair8 = 69;
const short c_chair9 = 70;
const short c_chair10 = 71;
const short c_chair11 = 72;
const short c_chair12 = 73;
const short c_chair13 = 74;
const short c_chair14 = 75;
const short c_chair15 = 76;
const short c_chair16 = 77;
const short c_chair17 = 78;
const short c_chair18 = 79;
const short c_chair19 = 80;
const short c_lamp1 = 81;
const short c_lamp2 = 82;
const short c_lamp3 = 83;
const short c_lamp4 = 84;
const short c_lamp5 = 85;
const short c_lamp6 = 86;
const short c_lamp7 = 87;
const short c_lamp8 = 88;
const short c_chair20 = 89;
const short c_chair21 = 90;
const short c_chair22 = 91;
const short c_chair23 = 92;
const short c_lamp9 = 93;
const short c_lamp10 = 94;
const short c_monster = 95;

#define i_empty         0
#define i_wall          1
#define i_hero          2
#define i_girl          3
#define i_bed           4
#define i_bedleft       5
#define i_bedright      6
#define i_bedcentre     7
#define i_bedmiddle     8
#define i_leaveleft     9
#define i_leaveright    10
#define i_table         11
#define i_chair         12
#define i_door          13
#define i_leftdoor      14
#define i_rightdoor     15
#define i_lightoff      16
#define i_lighton       17
#define i_treasure      18
#define i_key           19
#define i_leftcupboard  20
#define i_rightcupboard 21
#define i_npc           22
#define i_tree          23
#define i_treebranch    24
#define i_treeleft      25
#define i_treeright     26
#define i_grass         27
#define i_bush          28
#define i_brick         29
#define i_castle        30
#define i_flag          31
#define i_hole          32
#define i_stairs1       33
#define i_stairs2       34
#define i_stairs3       35
#define i_stairs4       36
#define i_stairs5       37
#define i_stairs6       38
#define i_stairs7       39
#define i_dragonnpc     40
#define i_dragon        41
#define i_deaddragonnpc 42
#define i_deaddragon    43
#define i_oldman        44
#define i_rooftop1      45
#define i_rooftop2      46
#define i_rooftop3      47
#define i_rooftop4      48
#define i_rooftop5      49
#define i_rooftop6      50
#define i_knob          51
#define i_leftwardrobe  52
#define i_rightwardrobe 53
#define i_librarian     54
#define i_penny         55
#define i_haley         56
#define i_cooper        57
#define i_robert        58
#define i_castlewall    59
#define i_stairs8       60
#define i_stairs9       61
#define i_chair1        62
#define i_chair2        63
#define i_chair3        64
#define i_chair4        65
#define i_chair5        66
#define i_chair6        67
#define i_chair7        68
#define i_chair8        69
#define i_chair9        70
#define i_chair10       71
#define i_chair11       72
#define i_chair12       73    
#define i_chair13       74
#define i_chair14       75
#define i_chair15       76
#define i_chair16       77
#define i_chair17       78
#define i_chair18       79
#define i_chair19       80
#define i_lamp1         81
#define i_lamp2         82
#define i_lamp3         83
#define i_lamp4         84
#define i_lamp5         85
#define i_lamp6         86
#define i_lamp7         87
#define i_lamp8         88
#define i_chair20       89    
#define i_chair21       90
#define i_chair22       91
#define i_chair23       92
#define i_lamp9         93
#define i_lamp10        94
#define i_monster       95
