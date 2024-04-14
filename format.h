// ANSI escape code for text formatting
// Format: \033[XXXm

#pragma once

#include <string>
#include <map>
using namespace std;

// define format codes
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define REVERSE "\033[7m"
#define CONCEALED "\033[8m"

// Define font colours
#define FONT_BLACK "\033[30m"
#define FONT_RED "\033[31m"
#define FONT_GREEN "\033[32m"
#define FONT_YELLOW "\033[33m"
#define FONT_BLUE "\033[34m"
#define FONT_PURPLE "\033[35m"
#define FONT_CYAN "\033[36m"
#define FONT_WHITE "\033[37m"

// Define background colours
#define BACK_BLACK "\033[40m"
#define BACK_RED "\033[41m"
#define BACK_GREEN "\033[42m"
#define BACK_YELLOW "\033[43m"
#define BACK_BLUE "\033[44m"
#define BACK_PURPLE "\033[45m"
#define BACK_CYAN "\033[46m"
#define BACK_WHITE "\033[47m"

// Define printing settings
#define MOVE_UP_BY_N "\033[nA"
#define MOVE_DOWN_BY_N "\033[nB"
#define MOVE_RIGHT_BY_N "\033[nC"
#define MOVE_LEFT_BY_N "\033[nD"
#define CLEAR_SCREEN "\033[2J"
#define ROMOVE_WHOLE_LINE "\033[K"

const map<string, string> mod_map = {{"bold", BOLD}, {"underline", UNDERLINE}, {"blink", BLINK}, {"reverse", REVERSE}, {"concealed", CONCEALED}};
const map<string, string> font_map = {{"black", FONT_BLACK}, {"red", FONT_RED}, {"green", FONT_GREEN}, {"yellow", FONT_YELLOW}, {"blue", FONT_BLUE}, {"purple", FONT_PURPLE}, {"cyan", FONT_CYAN}, {"white", FONT_WHITE}};
const map<string, string> back_map = {{"black", BACK_BLACK}, {"red", BACK_RED}, {"green", BACK_GREEN}, {"yellow", BACK_YELLOW}, {"blue", BACK_BLUE}, {"purple", BACK_PURPLE}, {"cyan", BACK_CYAN}, {"white", BACK_WHITE}};


class Format {
    public:
        int x;
        int y;
        int length;
        string format;

    public:
        Format(int x, int y, int length, string format);
};
