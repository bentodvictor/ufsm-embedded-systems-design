/*
		Giuliano Bohn Benedeti Becker
		Keli Tauana Ruppenthal
		Victor Dallagnol Bento
*/


#include <asf.h>
#include <conf_quick_start.h>

struct tcc_module tcc_instance[7];
struct tcc_config config_tcc[7];

// Função para configurar PWM
void pwm_config(uint8_t pwm_num, uint8_t pin){
	
	tcc_get_config_defaults(&config_tcc[pwm_num], CONF_PWM_MODULE);
	
	config_tcc[pwm_num].counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV256;
	config_tcc[pwm_num].counter.period = 0xFFFF;
	config_tcc[pwm_num].compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
	config_tcc[pwm_num].compare.match[CONF_PWM_CHANNEL] = (0xFFFF / 8);
	
	// Seta LED como ligado inicialmente
	config_tcc[pwm_num].pins.enable_wave_out_pin[CONF_PWM_OUTPUT] = 1;
	config_tcc[pwm_num].pins.wave_out_pin[CONF_PWM_OUTPUT]        = pin;
	config_tcc[pwm_num].pins.wave_out_pin_mux[CONF_PWM_OUTPUT]    = CONF_PWM_OUT_MUX;
	
	tcc_init(&tcc_instance[pwm_num], CONF_PWM_MODULE, &config_tcc[pwm_num]);
}


void pwm_on(uint8_t pwm_num){ // ligar
	tcc_enable(&tcc_instance[pwm_num]);
}


void pwm_off(uint8_t pwm_num){ // desligar
	tcc_disable(&tcc_instance[pwm_num]);
}


void pwm_set(uint8_t pwm_num, uint16_t duty){ //trocar duty cycle (razão cíclica)
	config_tcc[pwm_num].compare.match[CONF_PWM_CHANNEL] = duty;
	tcc_reset(&tcc_instance[pwm_num]);
	tcc_init(&tcc_instance[pwm_num]. CONF_PWM_MODULE, &tcc_config[pwm_num]);
}

int main(void)
{
	system_init();
	int counter = 0;
	
	pwm_config(3, CONF_PWM_OUTPUT);
	
	while (true) {		
		while(counter < 100000000){
			counter++;
			pwm_off(3);
		}
		if (counter == 100000000)
			pwm_on(3);
		counter = 0;
	}
}