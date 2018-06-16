
#include <iostream>
using namespace std;;

int MaiorElemento (int *vet, int i, int maior) {
	maior = (vet[i] < maior) ? maior : vet[i];
	
	if (i == 0)
		return maior;

	i--;
	maior = MaiorElemento(vet, i, maior);
	return maior;
}

int main () {
	
	int numPos, *vet;
	
	do {
		cin >> numPos;	
	} while (numPos < 0);
	
	vet = new int[numPos];
	
	for (int i = 0; i < numPos; i++) 
		do {
			cin >> vet[i];
		} while (vet[i] < 0);
		
	numPos--;
	cout << MaiorElemento(vet, numPos, 0) << endl;
	
	return 0;
}