#include "Switch.hpp"

Switch::Switch() {
  first_switch = false;
  second_switch = false;
};

int Switch::get_first_switch_state() { return first_switch; };

int Switch::get_second_switch_state() { return second_switch; };

int Switch::get_lamp_state() { return lamp_state; };

void Switch::toggle_first_switch() {
  first_switch = !first_switch;
  lamp_state = !lamp_state;
};

void Switch::toggle_second_switch() {
  second_switch = !second_switch;
  lamp_state = !lamp_state;
};
