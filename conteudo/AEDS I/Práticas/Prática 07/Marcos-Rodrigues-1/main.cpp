#include <iostream>
#include "Funcoes.h"
using namespace std;

int main() {
	
	int N_Vetor, N_CadaVetor, c = 0, m = 0;
	TItem *vetor, *vetorAux;
	
	cin >> N_Vetor;
	
	for (int i = 0; i < N_Vetor; i++) {
		cin >> N_CadaVetor;
		vetor = new TItem[N_CadaVetor];
		vetorAux = new TItem[N_CadaVetor];
		for (int j = 0; j < N_CadaVetor; j++) {
			cin >> vetor[j].chave;
			vetorAux[j].chave = vetor[j].chave;
		}
		
		cout << "Vetor " << i + 1 << ":" << endl;
		cout << "- Ordenacao:" << endl;

		//Bubble Sort
		BubbleSort(vetor, N_CadaVetor, &c, &m);
		cout << "- - Bubble....:";
		for (int k = 0; k < N_CadaVetor; k++) {
			cout << " " << vetor[k].chave;
		}
		cout << endl;
		cout << " -- Comparacoes: " << c << " | Movimentacoes: " << m << endl << endl;
		
		//SelectionSort
		CopiarVetor(vetorAux, vetor, N_CadaVetor);
		SelectionSort(vetor, N_CadaVetor, &c, &m);
		cout << "- - Selection.:";
		for (int k = 0; k < N_CadaVetor; k++) {
			cout << " " << vetor[k].chave;
		}
		cout << endl;
		cout << " -- Comparacoes: " << c << " | Movimentacoes: " << m << endl << endl;
		
		//InsertionSort
		CopiarVetor(vetorAux, vetor, N_CadaVetor);
		InsertionSort(vetor, N_CadaVetor, &c, &m);
		cout << "- - Insertion.:";
		for (int k = 0; k < N_CadaVetor; k++) {
			cout << " " << vetor[k].chave;
		}
		cout << endl;
		cout << " -- Comparacoes: " << c << " | Movimentacoes: " << m << endl << endl;
		
		//MergeSort
		CopiarVetor(vetorAux, vetor, N_CadaVetor);
		MergeSort(vetor, N_CadaVetor, &c, &m);
		cout << "- - Merge.....:";
		for (int k = 0; k < N_CadaVetor; k++) {
			cout << " " << vetor[k].chave;
		}
		cout << endl;
		cout << " -- Comparacoes: " << c << " | Movimentacoes: " << m << endl << endl;
		
		//QuickSort
		CopiarVetor(vetorAux, vetor, N_CadaVetor);
		QuickSort(vetor, N_CadaVetor, &c, &m);
		cout << "- - Quick.....:";
		for (int k = 0; k < N_CadaVetor; k++) {
			cout << " " << vetor[k].chave;
		}
		cout << endl;
		cout << " -- Comparacoes: " << c << " | Movimentacoes: " << m << endl << endl;
		
		cout << endl;
		
		delete[] vetor;	
	}
	
	return 0;
}