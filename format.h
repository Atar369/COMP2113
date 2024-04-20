// ANSI escape code for text formatting
// Format: \033[XXXm
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "constant.h"

using namespace std;


// define format codes
#define reset "\033[0m"
#define bold "\033[1m"
#define dim "\033[2m"
#define italic "\033[3m"
#define underline "\033[4m"
#define blink "\033[5m"
#define reverse "\033[7m"
#define concealed "\033[8m"

// Define font colours
#define font_black "\033[30m"
#define font_red "\033[31m"
#define font_green "\033[32m"
#define font_yellow "\033[33m"
#define font_blue "\033[34m"
#define font_purple "\033[35m"
#define font_cyan "\033[36m"
#define font_white "\033[37m"

// Define background colours
#define back_black "\033[40m"
#define back_red "\033[41m"
#define back_green "\033[42m"
#define back_yellow "\033[43m"
#define back_blue "\033[44m"
#define back_purple "\033[45m"
#define back_cyan "\033[46m"
#define back_white "\033[47m"

// Define printing settings
#define move_up_by_n "\033[nA"
#define move_down_by_n "\033[nB"
#define move_right_by_n "\033[nC"
#define move_left_by_n "\033[nD"
#define clear_screen "\033[2J"
#define remove_whole_line "\033[K"

// Define color pairs
unordered_map<short, string> color_mapping = {
    {c_wall       ,   font_white},
    {c_grass      ,   italic},
    {c_dragon     ,   bold},
    {c_key        ,   blink},
    {c_lightoff   ,   dim}
};

// Define effect pairs
unordered_map<short, string> effect_mapping = {
    {c_treasure  ,   font_yellow},
    {c_door      ,   font_white},
    {c_chair     ,   font_cyan},
    {c_npc       ,   font_white},
    {c_player    ,   font_white},
    {c_enemy     ,   font_blue},
    {c_monster   ,   font_blue},
    {c_grass     ,   font_green},
    {c_closet    ,   font_cyan},
    {c_dragon    ,   font_red},
    {c_key       ,   font_white},
    {c_table     ,   font_cyan},
    {c_bed       ,   font_white},
    {c_lightoff  ,   font_yellow},
    {c_lighton   ,   font_yellow}
};
