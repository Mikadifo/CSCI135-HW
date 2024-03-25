// #ifndef _SWITCH
#define _SWITCH
#include <string>

using namespace std;

class Switch {
public:
  Switch();
  int get_first_switch_state();
  int get_second_switch_state();
  int get_lamp_state();
  void toggle_first_switch();
  void toggle_second_switch();

private:
  bool first_switch;
  bool second_switch;
  bool lamp_state;
};
