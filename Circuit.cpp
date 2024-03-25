/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E9.3

Simulates a highway lapm with siwtches at both sides
*/
#include "Circuit.hpp"

int Circuit::get_first_switch_state() { return first_switch; };

int Circuit::get_second_switch_state() { return second_switch; };

int Circuit::get_lamp_state() { return lamp_state; };

void Circuit::toggle_first_switch() {
  first_switch = !first_switch;
  lamp_state = !lamp_state;
};

void Circuit::toggle_second_switch() {
  second_switch = !second_switch;
  lamp_state = !lamp_state;
};
