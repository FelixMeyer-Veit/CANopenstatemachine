#pragma once
#include <Arduino.h>
#include <state.h>
#include <analog_in.h>
#include <analog_out.h>
#include <filter.h>
#include <timer.h>

class State;

class Context
{
  /**
   * @var State A reference to the current state of the Context.
   */

private:
  State *state_;

public:

  Context(State *state);

  ~Context();

  /**
   * The Context allows changing the State object at runtime.
   */

  void transition_to(State *state);

  /**
   * The Context delegates part of its behavior to the current State object.
   */

  void do_work();

  void command_reset();
  void command_config_ambient();
  void command_config_high();
  void command_config_low();
  void command_operation();
  void command_preoperation();

  void getobjects(Analog_in *Photocell, Analog_out *Led, Filter *filter, Timer *timer1);

  //ptr
  Analog_in *photocell_ptr;
  Analog_out *led_ptr;
  Filter *filter_ptr;
  Timer *timer1_ptr;

  // attributes
  int8_t mode;
};