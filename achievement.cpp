#include <iostream>
#include "
using namespace std;

void print_if_true(bool test, std::string str) {
  if (test) {
    std::cout << str << std::endl;
  }
}

int main(){
  bool HeroEnding1, HeroEnding2, HeroEnding3, HeroEnding4, HeroEnding5, GirlEnding1, GirlEnding2, GirlEnding3, GirlEnding4;
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