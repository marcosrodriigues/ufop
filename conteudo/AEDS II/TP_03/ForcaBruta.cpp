#include "ForcaBruta.h"

void ForcaBruta(TipoTexto Texto, long n, TipoPadrao Padrao, long m, int *numComparacoes, int *numDeslocamentos) {
	long j, k;
	char c;
	int MAX = 0;
	for (long i = 0; i < n; ++i) {
		k = i;
		j = 1;
		
		//Pesquisa do padrão Padrao a partir da K-ésima posição do texto
		while(Texto[k - 1] == Padrao[j - 1] && j <= m) { 
			j++; k++; 
			(*numDeslocamentos)++;
		}

		(*numComparacoes)++;
		if (j > m) {
			printf("Casamento na posicao %6ld\n", i);	
			MAX++;
		} 
	}
	cout << "Total de " << MAX << " casamentos" << endl;
}