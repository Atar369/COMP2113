// ANSI escape code for text formatting
// Format: \033[XXXm
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "constant.h"

using namespace std;
// Define standard 
#define default_format "\033[" // ansi escape code

// define format codes
#define reset_format "\033[0m"
#define bold "\033[1m"
#define dim "\033[2m"
#define italic "\033[3m"
#define underline "\033[4m"
#define blink "\033[5m"

// Define font colours
#define font_black "\033[30m"
#define font_red "\033[31m"
#define font_green "\033[32m"
#define font_yellow "\033[33m"
#define font_blue "\033[34m"
#define font_purple "\033[35m"
#define font_cyan "\033[36m"
#define font_white "\033[37m"

// Define printing settings
#define clear_screen "\033[2J"
#define remove_whole_line "\033[K"
#define save_cursor_position "\033[s"
#define restore_cursor_position "\033[u"
#define hide_cursor "\033[?25l"
#define show_cursor "\033[?25h"


// Define color pairs 
extern unordered_map<short, string> effect_mapping;

// Define effect pairs
extern unordered_map<short, string> color_mapping;

// Define ending color pairs
extern unordered_map<int, string> Hero_ending_color_mapping;
extern unordered_map<int, string> Girl_ending_color_mapping;




