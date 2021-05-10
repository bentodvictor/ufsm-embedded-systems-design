// Victor Dallagnol Bento
// Victor Oliveira Costa

#include <asf.h>
#include <led-driver.h>

/* void SysTick_Handler(void)
{
	port_pin_toggle_output_level(LED_0_PIN);
}*/

/** Configure LED0, turn it off*/

//~~~~~~~~~~~~				FUNÇÃO ANTIGA 		~~~~~~~~~~~~~~~

/*static void config_led(void)
{
	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);

	pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(LED_0_PIN, &pin_conf);
	port_pin_set_output_level(LED_0_PIN, LED_0_INACTIVE);
}*/


int pin_vec[30];

// Configuração dos PINOS e do LED
void led_config(uint8_t led_num, uint8_t pin){
	pin_vec[led_num] = pin;
	
	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);
	pin_conf.direction = PORT_PIN_DIR_OUTPUT;

	port_pin_set_config(pin_vec[led_num], &pin_conf);
}

// LIGAR
void led_on(uint8_t led_num){
	
	port_pin_set_output_level(pin_vec[led_num], LED_0_ACTIVE);
}

// DESLIGAR
void led_off(uint8_t led_num){

	port_pin_set_output_level(pin_vec[led_num], LED_0_INACTIVE);
}

// ALTERAR ESTADO
void led_toggle(uint8_t led_num){
	port_pin_toggle_output_level(pin_vec[led_num]);
}

int main(void)
{
	system_init();

	/*Configure system tick to generate periodic interrupts */
	//SysTick_Config(system_gclk_gen_get_hz(GCLK_GENERATOR_0));

	led_config(0, LED_0_PIN);
	led_on(0);
	//led_off(0);
	//led_toggle(0);
	
	while (true) {
	}
}
