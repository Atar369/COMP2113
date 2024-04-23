#include "menu.h"

using namespace std;

// Menu
const char* menu_logo[7] = {
"░▒▓█▓▒░      ░▒▓█▓▒░▒▓████████▓▒░▒▓████████▓▒░      ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░░▒▓██████▓▒░▒▓████████▓▒░▒▓███████▓▒░░▒▓████████▓▒░", 
"░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░",        
"░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░",        
"░▒▓█▓▒░      ░▒▓█▓▒░▒▓██████▓▒░ ░▒▓██████▓▒░           ░▒▓█▓▒░   ░▒▓████████▓▒░▒▓██████▓▒░ ░▒▓████████▓▒░ ░▒▓█▓▒░   ░▒▓███████▓▒░░▒▓██████▓▒░",   
"░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░",        
"░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░",        
"░▒▓████████▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓████████▓▒░         ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░" 
};


// Get logo width
int get_logo_w_size() {
    int logo_w_size = 0;

    for (int i = 0; i < logo_h_size; i++) {
        int len = strlen(menu_logo[i]);
        if (len > logo_w_size) {
            logo_w_size = len;
        }
    }
    return logo_w_size;
}

// Draw the logo
void draw_logo(int h, int w) {
    // Draw
    for (int i = 0; i < logo_h_size; i++) {
        string line = menu_logo[i];
        cout << font_blue << default_format << logo_h_size + i << ";" << 37 << "H" << line << endl;
    }
    cout << reset;
}


/*
int main() {
    int h = 100;
    int w = get_logo_w_size();
    draw_logo(h, w);
    return 0;
} */
