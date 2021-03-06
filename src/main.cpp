#include <Arduino.h>
#include <analog_out.h>
#include <analog_in.h>
#include <filter.h>
#include <context.h>
#include <init.h>
#include <timer.h>

// Create Objects
Analog_out led(PORTD5);
Analog_in photocell(PC0);
Filter filter;
Context *context;
Timer timer;

// Application
void setup()
{
  Serial.begin(9600);
  
  //Setup of CANopen state machine
  context = new Context(new Initialization_state);
}

ISR(TIMER1_COMPA_vect) {
	led.toggle();
}

void loop()
{
  int command = 0;

  delay(100);

  context->getobjects(&photocell, &led, &filter, &timer);
  context->do_work();

  if (Serial.available())
    command = Serial.read();

  if (command == 'r')
    context->command_reset();
  else if(command == 'a')
    context->command_config_ambient();
  else if(command == 'h')
    context->command_config_high();
  else if(command == 'l')
    context->command_config_low();
  else if(command == 'o')
    context->command_operation();
  else if(command == 'p')
    context->command_preoperation();   
}