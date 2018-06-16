#include "Sequential_Access.h"

int Sequential_Search (TIndice tab[], int tam, TRegistro* registro, FILE *arq, int key, int *nTransfer, int *nCompare) {
	TRegistro pagina[ITENS_PAGINA];
	int i, qtdDados;
	long desloc;

	//Procura a página onde o item pode estar
	i = 0;

	while (i < tam && tab[i].chave <= key) {
		(*nCompare)++;
		i++;	
	} 

	//Caso a chave desejada seja menor que a 1º chave, o item não existe no arquivo
	if (i == 0) return 0;
	else {
		//A ultima página pode não estar completa
		if (i < tam) qtdDados = ITENS_PAGINA;
		else {
			fseek(arq, 0, SEEK_END);
			(*nTransfer)++;
			qtdDados = (ftell(arq)/sizeof(TRegistro)) % ITENS_PAGINA;
			if(qtdDados == 0){
				qtdDados = ITENS_PAGINA;
			}
		}

		//Le a página desejada do arquivo
		desloc = (tab[i - 1].posicao - 1) * ITENS_PAGINA * sizeof(TRegistro);
		fseek(arq, desloc, SEEK_SET);
		(*nTransfer)++;
		fread(&pagina, sizeof(TRegistro), qtdDados, arq);

		//Pesquisa sequencial na página lida
		for (i = 0; i < qtdDados; i++) {
			(*nCompare)++;
			if (pagina[i].chave == key) {
				*registro = pagina[i];
				return 1;
			}
		}

		return 0;
	}
}

int fillUpTIndex(FILE *file, TIndice *tab, int amount) {
	TRegistro regAux;
	int cont = 0;
	int indexTable = 0;
	while ((fread(&regAux, sizeof(regAux), 1, file) == 1) && cont <= amount) {
		cont++;
		if (cont % ITENS_PAGINA == 1) {
			tab[indexTable].chave = regAux.chave;
			tab[indexTable].posicao = indexTable + 1;
			indexTable++;
		}
	}

	return indexTable;
}
