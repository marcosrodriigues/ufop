#include <iostream>
#include "Funcoes.h"
using namespace std;

int main() {
	
	int N_Vetor, N_CadaVetor, c1 = 0, m1 = 0, c2 = 0, m2 = 0, c3 = 0, m3 = 0;
	TItem *vetor, vetorAux;
	
	cin >> N_Vetor;
	
	for (int i = 0; i < N_Vetor; i++) {
		cin >> N_CadaVetor;
		vetor = new TItem[N_CadaVetor];
		for (int j = 0; j < N_CadaVetor; j++) {
			cin >> vetor[j].chave;
		}
		 
		vetorAux = *vetor;
		 
		cout << "Vetor " << i << ":" << endl;
		cout << "- Ordenacao:" << endl;
		
		BubbleSort(vetor, N_CadaVetor, &c1, &m1);
		cout << "- - Bubble....:";
		for (int k = 0; k < N_CadaVetor; k++) {
			cout << " " << vetor[k].chave;
		}
		cout << endl;
		
		*vetor = vetorAux;
		SelectionSort(vetor, N_CadaVetor, &c2, &m2);
		cout << "- - Selection.:";
		for (int k = 0; k < N_CadaVetor; k++) {
			cout << " " << vetor[k].chave;
		}
		cout << endl;
		
		*vetor = vetorAux;
		InsertionSort(vetor, N_CadaVetor, &c3, &m3);
		cout << "- - Insertion.:";
		for (int k = 0; k < N_CadaVetor; k++) {
			cout << " " << vetor[k].chave;
		}
		
		cout << endl;
		
		cout << "- Comparacoes | Movimentacoes: " << endl;
		cout << "- - Bubble....: " << c1 << " | " << m1 << endl;
		cout << "- - Selection.: " << c2 << " | " << m2 << endl;
		cout << "- - Insertion.: " << c3 << " | " << m3 << endl;
		
		delete[] vetor;	
	}
	
	return 0;
}