#include <init.h>
#include <preoperat.h>

void Initialization_state::on_entry()
{
  Serial.println("Start initialization");
}

void Initialization_state::on_exit()
{
  Serial.println("End intialization");
}

void Initialization_state::on_do()
{
	Serial.println("Device starts up and initialize internal parameters");
    
    // LED setup
    this->context_->led_ptr->init();

    // Photocell setup
    this->context_->photocell_ptr->init();

    // Filter setup
    this->context_->filter_ptr->init();

	this->context_->transition_to(new Preoperational_state);
}

void Initialization_state::on_command_reset(){

}

void Initialization_state::on_command_config_ambient()
{

}

void Initialization_state::on_command_config_high()
{
    
}

void Initialization_state::on_command_config_low()
{
    
}

void Initialization_state::on_command_operation()
{
    
}

void Initialization_state::on_command_preoperation()
{
    
}