/*
	Giuliano Bohn
	Keli Ruppenthal
	Victor D. Bento
*/

#include "../pt.h"
#include "../Scaf_Printf.h"

/*	Variável para enviar e receber  dados	*/
unsigned char chkData;		/*	Variável para verificar transmissão correta	*/ 
unsigned char tamanho;
unsigned char indice = 0;

PT_THREAD(protothread_decodifica(struct pt *pt, unsigned char x))
{
	
  PT_BEGIN(pt);
  PT_WAIT_UNTIL(pt, x == 2);
  PT_YIELD(pt);
  PT_WAIT_UNTIL(pt, x > 0);
	tamanho = x;
	unsigned char vetor_out[tamanho];
	PT_YIELD(pt);
  while (tamanho > 0)
  {
	  
	PT_WAIT_UNTIL(pt, x > 0);
	chkData ^= x;
	--tamanho;
	vetor_out[indice] = x;
	indice ++;
	PT_YIELD(pt);
  }
  PT_WAIT_UNTIL(pt, x > 0);
  if (x == chkData){
	  printf("Transmissao Correta\n");
  }
  else{
	  printf("Transmissao Incorreta\n");
  }
  for(int i = 0; i < indice; ++i)
	printf("[%i]: %i", i, vetor_out[i]);
	PT_YIELD(pt);
  
  PT_WAIT_UNTIL(pt, x == 3);
  printf("\n===============================\nFinal da Execucao");
  PT_END(pt);
}




/*			MAIN			*/
int main(){
	
	struct pt *pt_receiver;
	unsigned char data_in[9] = { 2, 5, 11, 22, 33, 44, 55, 39, 3 };
	int count = 0;
	
	for (count = 0; count < 9; count++)
	{
		protothread_decodifica(pt_receiver, data_in[count]);
	} 	
}