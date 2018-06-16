#include "ShiftAnd_Exato.h"

void ShiftAndExato(TipoTexto Texto, long n, TipoPadrao Padrao, long m, int *numComparacoes, int *numDeslocamentos) {
	long 	Mascara[MAX_CHAR], 
			i;

	long 	R, 
			Ri;

	//Inicialização das máscaras binárias
	for (i = 0; i < MAX_CHAR; i++) Mascara[i] = 0;
	for (i = 1; i <= m; i++) Mascara[Padrao[i - 1] + 127] |= 1 << (m -i); 

	R = 0;
	Ri = 1 << (m - 1);

	int MAX = 0;

	for (i = 1; i <= n; i++) {
		(*numDeslocamentos)++;
		//Formula para obter a nova máscara
		R = ((((unsigned long)R) >> 1) | Ri) & Mascara[Texto[i] + 127];
		
		(*numComparacoes)++;
		if((R & 1) != 0)  {
			printf("Casamento na posicao %6ld\n", i - m + 1);	
			MAX++;
		}
	}

	cout << "MAX: " << MAX << endl;
}