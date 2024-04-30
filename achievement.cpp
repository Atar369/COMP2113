#include <iostream>
#include "

using namespace std;

void print_if_true(bool test, string str) {
  if (test) {
    cout << str << endl;
  }
}


bool HeroEnding[5] = {false, false, false, false, false}; 
bool GirlEnding[4] = {false, false, false, false};

int main(){
  cout << "Hero:" << endl;
  print_if_true(HeroEnding[1], "Ending 1: Dreamer");
  print_if_true(HeroEnding[2], "Ending 2: Killer");
  print_if_true(HeroEnding[3], "Ending 3: Crazy");
  print_if_true(HeroEnding[4], "Ending 4: 'Monster'");
  print_if_true(HeroEnding[5], "Ending 5: Why you try?";
  cout << "Girl:" << endl;
  print_if_true(GirlEnding[1], "Ending 1: Cold-Blooded Animal");
  print_if_true(GirlEnding[2], "Ending 2: 'Three People Become Tigers'");
  print_if_true(GirlEnding[3], "Ending 3: Happy Ending?");
  print_if_true(GirlEnding[4], "Ending 4: The Untold Truth");
  

  return 0;
}
