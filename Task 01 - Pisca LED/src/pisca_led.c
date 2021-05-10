// Victor Dallagnol Bento
// Victor Oliveira Costa

#include <asf.h>

// Código de interrupção
void SysTick_Handler(void)
{
	// xor no estado do pino do led
	port_pin_toggle_output_level(LED_0_PIN);
}

// Configura led e o deixa desligado por padrão
static void config_led(void)
{
	struct port_config pin_conf;
	// definição padrão obrigatória
	port_get_config_defaults(&pin_conf);
	
	// define pino como saída
	pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
	
	// define pino e escreve configuração no hardware
	port_pin_set_config(LED_0_PIN, &pin_conf);
	
	// deixa o led inicialmente ativo
	port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
}

int main(void)
{
	system_init();

	/*Configure system tick to generate periodic interrupts */
	config_led();
	
	// A cada x ciclos de clock, gera interrupção
	// x definido como um multiplo do clock genérico interno
	SysTick_Config(system_gclk_gen_get_hz(GCLK_GENERATOR_0)/10);

	while (true) {
	}
}
