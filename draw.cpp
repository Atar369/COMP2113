#include "draw.h"

/* Set enemy and calck apple
void set_map_param(short current_map[][COLS], int clx, int cly) {
    static int i = 0;
    for (int y = 0; y < cly; y++) {
        for (int x = 0; x < clx; x++) {
            if (current_map[y][x] == i_enemy_v) {
                obj_init(&enemy[i], x, y, 1, "");
                i++;
            } else if (current_map[y][x] == i_enemy_h) {
                obj_init(&enemy[i], x, y, 2, "");
                i++;
            }
            if (i >= sizeof(enemy)/sizeof(enemy[0])) {
                i = 0;
            }
        }
    }

}*/

// Symbol map object
#define s_empty        "   "
#define s_wall "///"
#define s_hero "/@\\"
#define s_girl "/%\\"
#define s_bed "==="
#define s_bedleft "== "
#define s_bedright " =="
#define s_bedcentre " = "
#define s_bedmiddle "= ="
#define s_leaveleft "=  "
#define s_leaveright "  ="
#define s_table "[T]"
#define s_chair "|-|"
#define s_door "---"
#define s_leftdoor "{--"
#define s_rightdoor "--}"
#define s_lightoff "[']"
#define s_lighton "[`]"
#define s_treasure "{$}"
#define s_key "[*]"
#define s_leftcupboard "| ="
#define s_rightcupboard "= |"
#define s_npc "/N\\"
#define s_tree "|=|"
#define s_treebranch "/=\\"
#define s_treeleft "  /"
#define s_treeright "\\  "
#define s_grass "wWw"
#define s_bush " _ "
#define s_brick "|||"
#define s_castle "_=_"
#define s_flag " |-"
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
#define s_deaddragonnpc "xNx"
#define s_deaddragon "x@x"
#define s_oldman "/V\\"
#define s_rooftop1 " /_"
#define s_rooftop2 "/  "
#define s_rooftop3 "_\\ "
#define s_rooftop4 "  \\"
#define s_rooftop5 " __"
#define s_rooftop6 "__ "
#define s_knob "  ."
#define s_leftwardrobe "|=="
#define s_rightwardrobe "==|"
#define s_librarian "/L\\"
#define s_penny "/P\\"
#define s_haley "/H\\"
#define s_cooper "/C\\"
#define s_robert "/R\\"
#define s_castlewall " | "
#define s_stairs8 "/__"
#define s_stairs9 "__\\"
#define s_chair1 "| |"
#define s_chair2 "/_/"
#define s_chair3 "\\_\\"
#define s_chair4 "|__"
#define s_chair5 "__|"
#define s_chair6 " .."
#define s_chair7 ".. "
#define s_chair8 " ' "
#define s_chair9 "/ /"
#define s_chair10 "_//"
#define s_chair11 "\\\\_"
#define s_chair12 "|:."
#define s_chair13 ".:|"
#define s_chair14 "o) "
#define s_chair15 " (o"
#define s_chair16 " |_"
#define s_chair17 "_| "
#define s_chair18 "|__"
#define s_chair19 "__|"
#define s_lamp1 "  _"
#define s_lamp2 "_  "
#define s_lamp3 "/'-"
#define s_lamp4 "-'\\"
#define s_lamp5 "  ."
#define s_lamp6 ".  "
#define s_lamp7 " '|"
#define s_lamp8 "|' "
#define s_chair20 "..."
#define s_chair21 "  '"
#define s_chair22 "|_|"
#define s_chair23 "\\ \\"
#define s_lamp9 " _|"
#define s_lamp10 "|_ "

unordered_map<int, string> symbol_mapping = {
    {0, s_empty},
    {1, s_wall},
    {2, s_hero},
    {3, s_girl},
    {4, s_bed},
    {5, s_bedleft},
    {6, s_bedright},
    {7, s_bedcentre},
    {8, s_bedmiddle},
    {9, s_leaveleft},
    {10, s_leaveright},
    {11, s_table},
    {12, s_chair},
    {13, s_door},
    {14, s_leftdoor},
    {15, s_rightdoor},
    {16, s_lightoff},
    {17, s_lighton},
    {18, s_treasure},
    {19, s_key},
    {20, s_leftcupboard},
    {21, s_rightcupboard},
    {22, s_npc},
    {23, s_tree},
    {24, s_treebranch},
    {25, s_treeleft},
    {26, s_treeright},
    {27, s_grass},
    {28, s_bush},
    {29, s_brick},
    {30, s_castle},
    {31, s_flag},
    {32, s_hole},
    {33, s_stairs1},
    {34, s_stairs2},
    {35, s_stairs3},
    {36, s_stairs4},
    {37, s_stairs5},
    {38, s_stairs6},
    {39, s_stairs7},
    {40, s_dragonnpc},
    {41, s_dragon},
    {42, s_deaddragonnpc},
    {43, s_deaddragon},
    {44, s_oldman},
    {45, s_rooftop1},
    {46, s_rooftop2},
    {47, s_rooftop3},
    {48, s_rooftop4},
    {49, s_rooftop5},
    {50, s_rooftop6},
    {51, s_knob},
    {52, s_leftwardrobe},
    {53, s_rightwardrobe},
    {54, s_librarian},
    {55, s_penny},
    {56, s_haley},
    {57, s_cooper},
    {58, s_robert},
    {59, s_castlewall},
    {60, s_stairs8},
    {61, s_stairs9},
    {62, s_chair1},
    {63, s_chair2},
    {64, s_chair3},
    {65, s_chair4},
    {66, s_chair5},
    {67, s_chair6},
    {68, s_chair7},
    {69, s_chair8},
    {70, s_chair9},
    {71, s_chair10},
    {72, s_chair11},
    {73, s_chair12},
    {74, s_chair13},
    {75, s_chair14},
    {76, s_chair15},
    {77, s_chair16},
    {78, s_chair17},
    {79, s_chair18},
    {80, s_chair19},
    {81, s_lamp1},
    {82, s_lamp2},
    {83, s_lamp3},
    {84, s_lamp4},
    {85, s_lamp5},
    {86, s_lamp6},
    {87, s_lamp7},
    {88, s_lamp8},
    {89, s_chair20},
    {90, s_chair21},
    {91, s_chair22},
    {92, s_chair23},
    {93, s_lamp9},
    {94, s_lamp10},
};

// Draw instance
void draw_instance(int y, int x, int obj, string symbol) {
    string effect = "";
    string color = color_mapping[obj];
    if (effect_mapping.find(obj) != effect_mapping.end())
        effect = effect_mapping.at(obj);
    cout << color << effect << symbol << reset << "";
}

// Draw Current Map
void draw_map(vector<vector<short> > & current_map, Player &player) {
/*
    // Get the dimensions of the terminal window
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int rows = w.ws_row;
    int cols = w.ws_col;

    // centering
    int xoffset = (cols - current_map[0].size()) / 2;
    int yoffset = (rows - current_map.size()) / 2;

    cout << default_format << yoffset << ";" << xoffset << "H" << endl;
*/
    for (int i = 0; i < current_map.size(); i++) {
        for (int j = 0; j < current_map[0].size(); j++) {
            if (i == player.y && j == player.x) {
                cout << player.color << player.symbol <<  "";
            } 
            else {
                draw_instance(i, j, current_map[i][j], symbol_mapping[current_map[i][j]]);

                    // Draw static object
                    
/*
                // Draw dynamic object
                default:
                    
                    // Check if player position matches the current position
                    if (i == player.y && j == player.x) {
                        draw_instance(i, j, c_player, player.symbol); // Use player.symbol to draw the player
                    } 
                    else {
                        cout << current_map[i][j] << ""; // Print the current_map value if no object is present
                    }
                    break;

for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == player.y && j == player.x) {
                cout << player.symbol << "";
            } else {
                cout << current_map[i][j] << "";
            }
        }
        cout << endl;
    }                    
                     // Draw bullet
                    if (x == bullet.x && y == bullet.y) {
                        if (!bullet_shoot) {
                            break;
                        }
                        draw_instance(y, x, c_bullet, bullet.symbol);
                    } 

                    // Draw enemy
                    for (int i = 0; i < 5; i++) {
                        if (x == enemy[i].x && y == enemy[i].y) {
                            draw_instance(y, x, c_enemy, s_enemy);
                            break;
                        }
                    }
*/

            }

            // Open door if key is found
            /* if (key) {
                if (current_map[i][j] == i_door) {
                    current_map[i][j] = 0;
                }
            }*/
            }
            cout << endl;
        }
        
    }


 /*       
// Check next map
bool next_map(short current_map[ROWS][COLS], short &map_code) {
    if (current_map[player.y][player.x] == i_door) {
        map_code++; // further modify if we want transition to another map，go back/ go up/down
        return true;
    }
    return false;
} */

/*
class Map {
public:
    short current_map[ROWS][COLS];
    int width;
    int height;
    int priority = 0;

public:
    Map() {}
    Map(int width, int height);
    Map(const vector<string>& ma, const short & current_map[][]);
    Map(vector<string>& map);
    void init(vector<string>& map, vector<string>& current_map);
    void add_interact(int x, int y, char c);
};*/

/*
Draw colored instance
#define td_indent 2 // Top & down ident
#define symbol_count 3


void draw_instance(int y, int x, ColorPair &color, char name[]) {

    // Ending offset
    int ending_xoffset = COLS/2;
    int ending_yoffset = ROWS/2;
    
    // Level offset
    int map_xoffset = (COLS/2) * symbol_count + (COLS%2); // center of the screen
    int map_yoffset = (ROWS+(td_indent*2))/2-(1 +(ROWS%2)); 

    mvprintw(
         ceil(ending_yoffset - map_yoffset) + (y+td_indent), // Y pos 
         ceil(ending_xoffset - map_xoffset) + (x*symbol_count), // X pos 
         name // S pos 
    );
} 

int main() {
    // Draw the map
    ColorPair color = colorPairs.at(c_player);
    draw_instance(0, 0, color, s_player);
    return 0;
}

// testing
int main() {
    // Example usage
    SetColor(c_player);
    cout << "Player" << reset << endl;

    SetColor(c_treasure);
    cout << "Treasure" << reset << endl;

    SetColor(42); // Default color
    cout << "Default" << reset << endl;

    return 0;
} 

int main() {
    draw_instance(0, 0, c_player, s_player);
} 
*/
