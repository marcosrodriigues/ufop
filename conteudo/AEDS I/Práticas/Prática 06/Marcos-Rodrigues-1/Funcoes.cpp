#include <iostream>
#include "Funcoes.h"
using namespace std;

void BubbleSort(TItem *vetor, int n, int *c, int *m) {
	TItem aux;
	int troca;

	*c++; // coloquei o *c++ aqui porque a cada for, ele tem que comparar se o valor de I é inferior ao valor de N - 1
	for (int i = 0; i < n - 1; i++) {
		*c++; // mesma explicação acima
		for (int j = 1; j < n - 1; j++) {
			*c++;
			if (vetor[j].chave < vetor[j-1].chave) {
				aux = vetor[j];
				vetor[j] = vetor[j-1];
				vetor[j-1] = aux;
				troca++;
				*m = *m + 4; // troca++ é incrementação e não movimentação, por isso não incrementa
			}
		}
		*c++;
		if (troca == 0) break;
	}
}
void SelectionSort(TItem *vetor, int n, int *c, int *m) {
	int min;
	TItem aux;
	*c++;
	for (int i = 0; i < n - 1; i++) {
		*m++;
		min = i; // min recebe valor de outra variavel, logo, movimenta
		*c++;
		for (int j = i + 1; j < n; j++) {
			*c++;
			if (vetor[j].chave < vetor[min].chave) {
				min = j;
				*m++;
			}
			*c++;
			if (i != min) {
				aux = vetor[min];
				vetor[min] = vetor[i];
				vetor[i].chave = min;
				*m = *m + 3;
			}
		}
	}
}
void InsertionSort(TItem *vetor, int n, int *c, int *m) {
	TItem aux;
	int j;
	for (int i = 1; i < n; i++) {
		*c = *c + 2;
		aux = vetor[i];
		j = i - 1;
		while (j >= 0 && aux.chave < vetor[j].chave) {
			*c = *c + 2;
			vetor[j + 1] = vetor[j];
			j--;
			*m = *m + 2;
		}
		*m++;
		vetor[j + 1] = aux;
	}
}