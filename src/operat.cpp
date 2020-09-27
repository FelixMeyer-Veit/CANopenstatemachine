#include <operat.h>
#include <init.h>
#include <preoperat.h>


void Operational_state::on_do()
{
    Serial.print("Mode: ");
    Serial.println(this->context_->mode);
    
    if(this->context_->mode == 2)   // ambient
    {
        input_ph = this->context_->photocell_ptr->read(); 
        filtered_input_ph = this->context_->filter_ptr->smooth(input_ph);
        this->context_->led_ptr->set_val(filtered_input_ph);
    }
    else if(this->context_->mode == 1) this->context_->led_ptr->set_hi();   // high
    else if(this->context_->mode == 0) this->context_->led_ptr->set_lo();   // low
}

void Operational_state::on_entry()
{
    Serial.println("Start normal input-output behavior");
    Serial.println("In case of returning to initialization- or preoperation state, type 'r' or 'p'.");
}

void Operational_state::on_exit()
{
    Serial.println("End normal input-output behavior");
}
  
void Operational_state::on_command_reset() 
{
    Serial.println("set state to initialization");
    this->context_->transition_to(new Initialization_state);
}

void Operational_state::on_command_config_ambient()
{

}

void Operational_state::on_command_config_high()
{
    
}

void Operational_state::on_command_config_low()
{
    
}

void Operational_state::on_command_operation()
{
    
}

void Operational_state::on_command_preoperation()
{   
    Serial.println("set state to preoperation");
    this->context_->transition_to(new Preoperational_state);    
}