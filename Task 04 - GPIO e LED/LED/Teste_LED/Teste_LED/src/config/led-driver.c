#include <asf.h>

int pin_vec[30];

void led_config(uint8_t led_num, uint8_t pin){
	pin_vec[led_num] = pin;
	
	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);
	pin_conf.direction = PORT_PIN_DIR_OUTPUT;

	port_pin_set_config(pin_vec[led_num], &pin_conf);
}

void led_on(uint8_t led_num){
	
	port_pin_set_output_level(pin_vec[led_num], LED_0_ACTIVE);
}

void led_off(uint8_t led_num){

	port_pin_set_output_level(pin_vec[led_num], LED_0_INACTIVE);
}

void	 led_toggle(uint8_t led_num){
	port_pin_toggle_output_level(pin_vec[led_num]);
}