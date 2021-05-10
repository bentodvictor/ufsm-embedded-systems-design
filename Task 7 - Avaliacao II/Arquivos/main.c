/*
		Giuliano Bohn Benedeti Becker
		Keli Tauana Ruppenthal
		Victor Dallagnol Bento
*/

#include <asf.h>
#include <driver-timer.h>
#include <gpio-driver.h>
#include <led-driver.h>
#include <pwm-driver.h>

//					ATIVIDADE 1
int main (void)
{
	system_init();
	
	int counter = 1;
	pwm_config(3, CONF_PWM_OUTPUT);
	porta_config(led, LED_0_PIN, PORT_PIN_DIR_OUTPUT);
	
	while (true){		
		if (counter == 10){		// Periodo máximo do PWM = 0xFFFF
			pwm_set(3, 6553);	// Seta o pino e altera a razão cíclica para 10% do brilho 0xFFF
			counter = 1;		// Reseta contador
			delay_ms(1000);		// Delay de 1 segundo para coseguir ver LED
		}else{
			if(port_pin_get_input_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE){	// Se botão estiver pressionado 
				pwm_set(3, counter*6553);	// Seta o pino e altera a razão cíclica para +10% do brilho
				counter++;
			delay_ms(1000);		// Delay de 1 segundo para coseguir ver LED
			}
		}
	}
		
}

// 					ATIVIDADE 1, 2 e 3 integradas

// Globais
int click = 0;		// Variável para pegar o numero de clicks
int state = 1;		// Define qual será a atividade
int counter = 1;	// Contador para aumentar o brilho do LED a cada 10%
int segundos = 0;	// Variável que controla quantos segundos passaram
uint32_t r_time;	// retorna da função time 

int main(){
	system_init();											// Inicia sistema
	pwm_config(3, CONF_PWM_OUTPUT);							// Configura PWM
	porta_config(led, LED_0_PIN, PORT_PIN_DIR_OUTPUT);		// Configura LED
	timer_config(1, 1000);									// configura timer para 2 Segundos

	
	while(1){
		timer_start(1);		// Começa a contagem do timer
		
		if(state == 1)		// Começa no Estado 1
			ex_1();
		else if (state == 2)
			// Max brilho no LED
			pwm_set(3, 1);				// Numero máximo 0xFFFF (65535) divido por 1
			ex_1();
		else
			ex_1();			// Chama função 1 que verifica se deu click
	}
}

void ex_1(){
	if (counter == 10){			// Periodo máximo do PWM = 0xFFFF
			pwm_set(3, 6553);	// Seta o pino e altera a razão cíclica para 10% do brilho 0xFFF
			counter = 1;		// Reseta contador
			delay_ms(1000);		// Delay de 600 ms para coseguir ver LED
	}else{
		if(port_pin_get_input_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE){	// Se botão estiver pressionado 
			state = 1;
			pwm_set(3, counter*6553);	// Seta o pino e altera a razão cíclica para +10% do brilho
			counter++;					// Incrementa contador
			click++;					// Botão foi clicado
			r_time = timer_count(1)		// Pega tempo
			if (r_time == 1000){		// Verifica se deu 1s
				ex_2();					// Salta para função ex_2
			}
		}else{
			state = 3;		// Recebe estado 3, mas o LED pode estar piscando ou no brilho maximo (state = 2)
							// Para isso ele precisa sempre retornar a função ex_1 para verificar o botão e voltar para o estado inicial
		}
		delay_ms(600);		// Delay de 600 ms para coseguir ver LED
	}
}

void ex_2(){
	int btn_value;		// Recebe estado do botão
	
	if(click >= 3){		// Caso ocorra mais de 3 cliques por segundo
		state = 3;
		timer_start(1);		// Recomeça a contagem do segundo
		ex_3();		  		// pisca LED
	}else{
		segundos++;			// Incrementa segundo
		timer_start(1);		// Recomeça a contagem do segundo
		click = 0;			// Zera o numero de cliques
	}
	if (segundos == 2){		// Se atingiu 2 segundos
		btn_value = port_pin_get_input_level(LED0, &btn_value);		// Pega o estado do botão
		if(btn_value == ON)	{		// Se ele estiver pressionado vai para o estado 2
			state = 2;
		}
	}
}

void ex_3(){
	if(state == 3){				// Se estiver no estado 3, pisca o LED
		led_toggle(led);
	}
}
