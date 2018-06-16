#include <iostream>
#include "Funcoes.h"
using namespace std;

void BubbleSort(TItem *vetor, int n, int *c, int *m) {
	TItem aux;
	int troca, mov = 0, com = 0;
	
	com++; // coloquei o *c++ aqui porque a cada for, ele tem que comparar se o valor de I é inferior ao valor de N - 1
	for (int i = 0; i < n - 1; i++) {
		com++; // mesma explicação acima
		for (int j = 1; j < n - 1; j++) {
			com++;
			if (vetor[j].chave < vetor[j-1].chave) {
				aux = vetor[j];
				vetor[j] = vetor[j-1];
				vetor[j-1] = aux;
				troca++;
				mov = mov + 3; // troca++ é incrementação e não movimentação, por isso não incrementa
			}
		}
		com++;
		if (troca == 0) break;
	}
	
	*m = mov;
	*c = com;
}

void SelectionSort(TItem *vetor, int n, int *c, int *m) {
	int min, mov = 0, com = 0;
	TItem aux;
	com++;
	for (int i = 0; i < n - 1; i++) {
		mov++;
		min = i; // min recebe valor de outra variavel, logo, movimenta
		com++;
		for (int j = i + 1; j < n; j++) {
			com++;
			if (vetor[j].chave < vetor[min].chave) {
				min = j;
				mov++;
			}
		}
		com++;
		if (i != min) {
			aux = vetor[min];
			vetor[min] = vetor[i];
			vetor[i] = aux;
			mov = mov + 3;
		}
	}

	*c = com;	
	*m = mov;
}

void InsertionSort(TItem *vetor, int n, int *c, int *m) {
	TItem aux;
	int j, mov = 0, com = 0;
	for (int i = 1; i < n; i++) {
		com++;
		aux = vetor[i];
		j = i - 1;
		while (j >= 0 && aux.chave < vetor[j].chave) {
			com = com + 2;
			vetor[j + 1] = vetor[j];
			j--;
			mov = mov + 2;
		}
		mov++;
		vetor[j + 1] = aux;
	}
	
	*c = com;
	*m = mov;
}

void MergeSort(TItem *vetor, int n, int *c, int *m) {
	
	int com = 0;
	int mov = 0;
	
	mergeSort_ordena(vetor, 0, n - 1, &com, &mov);
	
	*c = com;
	*m = mov;
	return;
}

void mergeSort_ordena(TItem *vetor, int esq, int dir, int *c, int *m) {
	(*c)++;
	if (esq < dir) {
		int meio = (esq + dir) / 2;
		mergeSort_ordena(vetor, esq, meio, c, m);
		mergeSort_ordena(vetor, meio + 1, dir, c, m);	
		mergeSort_intercala(vetor, esq, meio, dir, c, m);
	}
}

void mergeSort_intercala(TItem *vetor, int esq, int meio, int dir, int *c, int *m) {
	int a_tam = meio - esq + 1;
	int b_tam = dir - meio;
	
	TItem *a = new TItem[a_tam];
	TItem *b = new TItem[b_tam];
	
	for (int i = 0; i < a_tam; i++) a[i] = vetor[i + esq];
	*c = (*c) + a_tam;
	*m = (*m) + a_tam;
	
	for (int i = 0; i < b_tam; i++) b[i] = vetor[i + meio + 1];
	*c = (*c) + b_tam;
	*m = (*m) + b_tam;
	
	(*c)++;
	for (int i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam) { vetor[k] = b[j++]; (*c)++; }
		else if (j == b_tam) { vetor[k] = a[i++]; (*c) = (*c) + 2;}
		else if (a[i].chave < b[j].chave) { vetor[k] = a[i++]; (*c) = (*c) + 3; }
		else { vetor[k] = b[j ++]; (*c) = (*c) + 4; }
	}
	
	delete[] a;
	delete[] b;
	
	return;
}

void QuickSort(TItem *vetor, int n, int *c, int *m) {
	
	int com = 0;
	int mov = 0;
	
	QuickSort_ordena(vetor , 0, n - 1, &com, &mov);
	
	*c = com;
	*m = mov;
	return;
}

void QuickSort_ordena(TItem *vetor, int esq, int dir, int *c, int *m) {
	int i, j;
	
	QuickSort_particao(vetor, esq, dir, &i, &j, c, m);
	
	(*c)++;
	if (esq < j) QuickSort_ordena(vetor, esq, j, c, m);
	
	(*c)++;
	if (i < dir) QuickSort_ordena(vetor, i, dir, c, m);
	return;
}

void QuickSort_particao (TItem *vetor, int esq, int dir, int *i, int *j, int *c, int *m) {
	TItem pivo, aux;
	
	*i = esq;
	*j = dir;
	
	pivo = vetor[(*i + *j) / 2];
	
	do {
		(*c)++;
		while (!(pivo.chave <= vetor[*i].chave)) { (*i)++; (*c)++;}
		
		(*c)++;
		while (pivo.chave < vetor[*j].chave) { (*j)--; (*c)++; }
		
		(*c)++;
		if (*i <= *j) {
			aux = vetor[*i];
			vetor[*i] = vetor[*j];
			vetor[*j] = aux;
			(*i)++; 
			(*j)--;
			*m = (*m) + 3;
		}
		
		(*c)++;
	} while (*i <= *j);
	
	return;
}

void CopiarVetor(TItem *vetorCopiar, TItem *vetorCopiado, int n) {
	for (int i = 0; i < n; i++)
		vetorCopiado[i].chave = vetorCopiar[i].chave;
	
	return;
}