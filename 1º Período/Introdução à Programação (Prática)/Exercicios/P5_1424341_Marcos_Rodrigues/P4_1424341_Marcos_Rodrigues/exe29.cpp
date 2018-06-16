#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, M, countC = 0;
	bool jaPossui = false;
	
	cout << "Digite um valor menor ou igual a 30: \n";
	do {
		cin >> M;
	} while (M > 30);

	cout << "Digite um valor menor ou igual a 20: \n";
	do {
		cin >> N;
	} while (N > 20);
	
	int vetA[M] = { };
	int vetB[N] = { };
	int vetC[M + N] = { };
	
	cout << "Digite " << M << " valores: ";
	for (int i = 0; i < M; i++) {
		cin >> vetA[i];
	}
	
	cout << "Digite " << N << " valores: ";
	for (int i = 0; i < N; i++)
		cin >> vetB[i];
		
	//Verificando os valores de M que estão em C
	for (int i = 0; i < M; i++) {
		jaPossui = false;
		for (int j = (M + N - 1); j >= 0; j--) {
			if (vetC[j] == vetA[i])
				jaPossui = true;
		}
		
		if (!jaPossui) {
			vetC[countC] = vetA[i];
			countC++;
		} 
	}
	
	//Verificando os valores de N que estão em C
	for (int i = 0; i < N; i++) {
		jaPossui = false;
		for (int j = (M + N - 1); j >= 0; j--) {
			if (vetC[j] == vetB[i])
				jaPossui = true;
		}
		
		if (!jaPossui) {
			vetC[countC] = vetB[i];
			countC++;
		} 
	}
	
	for (int i = 0; i < (sizeof(vetC) / 4); i++) {	
		cout << vetC[i] << endl;
	}
	
	return 0;
}