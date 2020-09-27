#include <preoperat.h>
#include <init.h>
#include <operat.h>




void Preoperational_state::on_do()
{
    // Timer stuff as interrupt
    delay(100);
}

void Preoperational_state::on_entry()
{
    Serial.println("Start Timer to toggle LED for 1Hz.");
    this->context_->timer1_ptr->stop();
    this->context_->timer1_ptr->start();
    Serial.println("Configurate Operational Behavior by typing 'a', 'h' or 'l' for ambient, high or low mode.");
    Serial.println("Change to Operational_State by typing 'o'.");
}

void Preoperational_state::on_exit()
{
    Serial.println("Stop Timer");
    this->context_->timer1_ptr->stop();
}
  
void Preoperational_state::on_command_reset() 
{
    Serial.println("set state to initialization");
    this->context_->transition_to(new Initialization_state);
}

void Preoperational_state::on_command_config_ambient()
{
    Serial.println("The operational behavior is now in the ambient mode");
    this->context_->mode = 2;
}

void Preoperational_state::on_command_config_high()
{
    Serial.println("The operational behavior is now in the high mode");
    this->context_->mode = 1;
}

void Preoperational_state::on_command_config_low()
{
    Serial.println("The operational behavior is now in the low mode");
    this->context_->mode = 0;
}

void Preoperational_state::on_command_operation()
{
    Serial.println("set state to operation");
    this->context_->transition_to(new Operational_state);  
}

void Preoperational_state::on_command_preoperation()
{   
  
}