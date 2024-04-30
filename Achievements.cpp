#include "Achievements.h"

unordered_map<int, string> HeroEndingMap = {
    {0, "Ending: ???"},
    {1, "Ending 1: Dreamer"},
    {2, "Ending 2: Killer"},
    {3, "Ending 3: Crazy"},
    {4, "Ending 4: 'Monster'"},
    {5, "Ending 5: Why you try?"},
    {7, "True Ending"},
};

unordered_map<int, string> GirlEndingMap = {
    {0, "Ending: ???"},
    //Unlocked achievements
    {1, "Ending 1: Cold-Blooded Animal"},
    {2, "Ending 2: 'Three People Become Tigers'"},
    {3, "Ending 3: Happy Ending?"},
    {4, "Ending 4: The Untold Truth"},
    {5, "Continue?"},
};

//Achievement not yet unlocked
void Achievements::print_achievements() {
    vector<string> hero_end = {
        "Ending: ???",
        "Ending: ???",
        "Ending: ???",
        "Ending: ???",
        "Ending: ???",
        "Ending: ???"
    };
    vector<string> girl_end = {
        "Ending: ???",
        "Ending: ???",
        "Ending: ???",
        "Ending: ???",
        "Ending: ???"
    };
    for (int i: progress.hero_stored_endings) {
        hero_end[i] = HeroEndingMap[i];
    }
    for (int j: progress.girl_stored_endings) {
        girl_end[j] = GirlEndingMap[j];
    }
    cout << "Hero: " << endl;
    for (int i = 0; i < hero_end.size(); i++) {
        cout << hero_end[i] << endl;
    }
    cout << "Girl: " << endl;
    for (int j = 0; j < girl_end.size(); j++) {
        cout << girl_end[j] << endl;
    }       
}

/*
void print_if_true(bool test, std::string str) {
  if (test) {
    std::cout << str << std::endl;
  }
}

int main(){
  
  int num = 6;
  int i;
  cout << "Hero:" << endl;
  for ( i = 0; i < num; i++ ){
    print_if_true
    cout << "Ending 1: Dreamer" << endl;
    cout << "Ending 2: Killer" << endl;
    cout << "Ending 3: Crazy" << endl;
    cout << "Ending 4: 'Monster'" << endl;
    cout << "Ending 5: Why you try?" << endl;
  }
  num = 5;
  cout << "Girl:" << endl;
  for ( i = 0; i < num; i++ ){
    cout << "Ending 1: Cold-Blooded Animal" << endl;
    cout << "Ending 2: 'Three People Become Tigers'" << endl;
    cout << "Ending 3: Happy Ending?" << endl;
    cout << "Ending 4: The Untold Truth" << endl;
  }

  

  return 0;
}
