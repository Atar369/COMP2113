#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "window.h"
using namespace std;

class Chat {

    bool is_Hero = false;
    bool is_Girl = false;

public:
    int getRandomNumber(int a, int b);
    string oldmanchat();
    string getRandomVillagerChat(string color, int scn_num);
    void loadChat(string charator, int map_code, int scn_num, Player &player, string color);

};

extern Chat chat;

extern unordered_map<string, vector<string> > Hero_chat_map;
