/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E9.3

Simulates a highway lapm with siwtches at both sides
*/

class Circuit {
public:
  int get_first_switch_state() { return first_switch; }
  int get_second_switch_state() { return second_switch; }
  int get_lamp_state() { return lamp_state; }
  void toggle_first_switch() {
    first_switch = !first_switch;
    lamp_state = !lamp_state;
  }
  void toggle_second_switch() {
    second_switch = !second_switch;
    lamp_state = !lamp_state;
  }

private:
  int first_switch = 0;
  int second_switch = 0;
  int lamp_state = 0;
};
