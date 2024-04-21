#include "format.h"

// Define color pairs 
unordered_map<short, string> effect_mapping = {
    {c_grass      ,   italic},
    {c_dragon     ,   bold},
    {c_key        ,   blink},
    {c_lightoff   ,   dim}
}; 

// Define effect pairs
unordered_map<short, string> color_mapping = {
    {c_wall       ,  font_white},
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
