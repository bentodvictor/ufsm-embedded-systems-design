/* 
			Giuliano Bohn
			Keli Ruppenthal
			Victor Bento
*/

#include <asf.h>
#include <stdio.h>
#include <stdlib.h>
#include "library/timer-driver.h"		// Biblioteca do timer
#define MAX_RX_BUFFER_LENGTH   70		// tamanho do buffer para enviar e receber dados

// Função para interrupção (Timer)
void Tratamento();

// Declaração das funções dos callbacks
void usart_read_callback(struct usart_module *const usart_module);
void usart_write_callback(struct usart_module *const usart_module);

// Configuração para callbacks
void configure_usart(void); 
void configure_usart_callbacks(void);

struct usart_module usart_instance;


// Buffer recebe dados
volatile uint8_t rx_buffer[MAX_RX_BUFFER_LENGTH];


// Funções de callback.
void usart_write_callback(struct usart_module *const usart_module)
{
	usart_read_buffer_job(&usart_instance, (uint8_t *)rx_buffer, MAX_RX_BUFFER_LENGTH);
}
void usart_read_callback(struct usart_module *const usart_module)
{
	usart_write_buffer_job(&usart_instance, (uint8_t *)rx_buffer, MAX_RX_BUFFER_LENGTH);
}

void configure_usart(void)
{
	// Configuração padrão
	struct usart_config config_usart;
	usart_get_config_defaults(&config_usart);
	
	config_usart.baudrate    = 9600;
	config_usart.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	config_usart.pinmux_pad0 = EDBG_CDC_SERCOM_PINMUX_PAD0;
	config_usart.pinmux_pad1 = EDBG_CDC_SERCOM_PINMUX_PAD1;
	config_usart.pinmux_pad2 = EDBG_CDC_SERCOM_PINMUX_PAD2;
	config_usart.pinmux_pad3 = EDBG_CDC_SERCOM_PINMUX_PAD3;
	
	stdio_serial_init(&usart_instance, EDBG_CDC_MODULE, &config_usart);

	usart_enable(&usart_instance);
}

void configure_usart_callbacks(void)
{
    //Setar o callBack
	usart_register_callback(&usart_instance, usart_write_callback, USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_register_callback(&usart_instance, usart_read_callback, USART_CALLBACK_BUFFER_RECEIVED);


    //Habilita o callback.
	usart_enable_callback(&usart_instance, USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_enable_callback(&usart_instance, USART_CALLBACK_BUFFER_RECEIVED);
}

// Gera callBack a cada 100us.
void TC3_Handler() {		// Função padrão para tratamento do microcontrolador
	// overflow gera interrupcao
	if ( TC3->COUNT8.INTFLAG.bit.OVF == 1) {
		REG_PORT_OUTTGL1 = PORT_PB30;
		Tratamento();		// Função para tratamento da interrupção
		
		REG_TC3_INTFLAG = TC_INTFLAG_OVF;
	}
	
	// erro gera interrupcao
	else if (TC3->COUNT8.INTFLAG.bit.ERR == 1) {
		
		REG_TC3_INTFLAG = TC_INTFLAG_ERR;
	}
}


// GLobais
int vetor_de_valores[] = {0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100};

// Resultados.
int Y[32];

// indice dos vetores
int indice = 0;

int segundo = 0;

void Tratamento(){
	segundo++;
	
	Y[(indice+1) % 32] = (vetor_de_valores[(indice % 16)]  +  15 * Y[(indice % 32)]) / 16 ;
	

	if( segundo == 10 ){		// Se atingiu 1 segundo
		
		segundo = 0;		// Reseta o contador do segundo;
		
		printf("Y_Atual[%d] = %d\n", indice % 32, Y[indice]);
	}
	
	indice++;	// Olha para proximo elemento do vetor
	
}

int main(void)
{
	system_init();
	
	configure_usart();
	configure_usart_callbacks();
	
	//	Data Direction Set 1
	REG_PORT_DIRSET1 = PORT_PB30;
	
	// Incializa com 0.
	Y[0] = 0;
	
	int 100u = 10000;
	
	//Inicializar timer 100us
	init_TC3(100u);
	enable_interrupt_time();
	
	system_interrupt_enable_global();
	while (true) {}
}

