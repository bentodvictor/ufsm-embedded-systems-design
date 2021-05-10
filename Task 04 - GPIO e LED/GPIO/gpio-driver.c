//	Victor Dallagnol Bento
//	Victor Oliveira Costa

#include <asf.h>
#include <gpio-driver.h>

int port_vec[30];
struct port_config config_pin[30];

// Configuração da estrutura do pino e inicialização da porta do pino/grupo de pinos
void porta_config(uint8_t port_num, uint8_t pin, uint8_t dir) {
	port_vec[port_num] = pin;
	
	port_get_config_defaults(&config_pin[port_num]);
	
	config_pin[port_num].direction  = dir;					// Envia direção para port_num na estrutura
	port_pin_set_config(pin, &config_pin[port_num]);		// Escvreve num pino/porta de configuração
}

// Função para setar o estado da porta/pino
void porta_write(uint8_t port_num, uint8_t val) {
	if (val) {
		port_pin_set_output_level(port_vec[port_num], !true);
	} else {
		port_pin_set_output_level(port_vec[port_num], !false);
	}
}

// Lê(restaura) o estado da porta/pino
void porta_read(uint8_t port_num, uint8_t *val) {
	if (port_pin_get_output_level(port_vec[port_num])) {
		*val = 1;
	}	
}

// Alternancia
void porta_toggle(uint8_t port_num) {
	port_pin_toggle_output_level(port_vec[port_num]);
}

// Direção
int porta_dir(uint8_t port_num) {
	int dir;
	dir = config_pin[port_num].direction;
}

int main(void)
{
	system_init();

	/*Configure system tick to generate periodic interrupts */
	//SysTick_Config(system_gclk_gen_get_hz(GCLK_GENERATOR_0));

	int led = 1;
	int t = 0;

	porta_config(led, LED_0_PIN, PORT_PIN_DIR_OUTPUT);

	porta_write(led, 1);	

	while (true) {
		if (t == 100000) {
			porta_toggle(led);
			t = 0;
		} else
			t++;
	}
}
