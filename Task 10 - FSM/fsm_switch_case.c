/*
 * fsm_switch_case.c
 */ 

#include "fsm_switch_case.h"

/* numero maximo de bytes do buffer de dados */
#define MAX_BUFFER 32

/* possiveis estados da maquina de estados de comunicacao */
typedef enum 
{
	ST_STX = 0, ST_QTD, ST_DATA, ST_CHK, ST_ETX
} States;

static uint8_t buffer[MAX_BUFFER];

/* Implementa��o da m�quina de estados */
void fsm_switch_case_processa(uint8_t *data, uint8_t qtd)
{
	static States state = ST_STX;	
	static uint8_t indBuffer = 0, qtdBuffer = 0;
	static uint8_t chkBuffer = 0;
	uint8_t i;
		
	for (i = 0; i < qtd; i++)
	{

		switch (state)
		{
				
			case ST_STX:
			if (data[i] == STX)
			{
				indBuffer = qtdBuffer = chkBuffer = 0;
				state = ST_QTD;
			}
			break;

			case ST_QTD:
			qtdBuffer = data[i];
			state = ST_DATA;
			break;

			case ST_DATA:
			buffer[indBuffer++] = data[i];
			chkBuffer ^= data[i];
			if (--qtdBuffer == 0)
			{
				state = ST_CHK;
			}
			break;

			case ST_CHK:
			if (data[i] == chkBuffer)
			{
				state = ST_ETX;
			}
			else
			{
				state = ST_STX;
			}
			break;

			case ST_ETX:
			state = ST_STX;
			if (data[i] == ETX)
			{
				/* fim */
				return;
			}			
			break;
		}
	}
}

#include "stdio.h"
#include "string.h"

void fsm_switch_case_teste(void)
{	
	uint8_t data1[] = { STX, 5, 11, 22, 33, 44 };
	uint8_t data2[] = { 55, 39, ETX };	
	uint8_t	resultado_esperado[] = {11, 22, 33, 44, 55};

	fsm_switch_case_processa(data1, sizeof(data1));
	fsm_switch_case_processa(data2, sizeof(data2));


	if(memcmp(resultado_esperado,buffer,sizeof(resultado_esperado)) == 0)
	{
		printf("teste: PASSOU\n");		
	}else
	{
		printf("teste: FALHOU\n");		
	}
}