#include "draw.h"

// Draw instance
void draw_instance(int y, int x, int obj, string symbol) {
    string effect = "";
    string color = color_mapping[obj];
    if (effect_mapping.find(obj) != effect_mapping.end())
        effect = effect_mapping.at(obj);
    cout << color << effect << symbol << reset << "";
}

// Draw Current Map
void draw_map(short current_map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == player.y && j == player.x) {
                cout << player.symbol << "";
            } 
            else {
                switch(current_map[i][j]) {

                    // Draw static object
                    case i_empty:  draw_instance(i, j, c_empty, s_empty);  break;
                    case i_wall:   draw_instance(i, j, c_wall, s_wall);  break;
                    case i_treasure: draw_instance(i, j, c_treasure, s_treasure); break;
                    case i_door:   draw_instance(i, j, c_door, s_door);  break;
                    case i_chair:  draw_instance(i, j, c_chair, s_chair); break;
                    case i_npc:    draw_instance(i, j, c_npc, s_npc);    break;
                    case i_monster: draw_instance(i, j, c_monster, s_monster); break;
                    case i_grass:  draw_instance(i, j, c_grass, s_grass);  break;
                    case i_closet: draw_instance(i, j, c_closet, s_closet); break;
                    case i_dragon: draw_instance(i, j, c_dragon, s_dragon); break;
                    case i_key:    draw_instance(i, j, c_key, s_key);    break;
                    case i_table:  draw_instance(i, j, c_table, s_table);  break;
                    case i_bed:    draw_instance(i, j, c_bed, s_bed);    break;
                    case i_lightoff: draw_instance(i, j, c_lightoff, s_lightoff); break;
                    case i_lighton:  draw_instance(i, j, c_lighton, s_lighton);  break;
            }
        }
        cout << endl;
    }
}
