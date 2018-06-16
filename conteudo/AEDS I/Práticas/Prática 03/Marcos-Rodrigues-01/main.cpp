#include <iostream>
using namespace std;;

int somaElementosVetor(int* vet, int n, int soma) {
	if (n == 0) {
		soma = soma + vet[0];
		return soma;
	}
	
	int sum = 0;
	sum = soma + vet[n];
	soma = somaElementosVetor(vet, n - 1, sum);
	return soma;
}

int main () {
	
	int *vetor;
	int num, soma = 0;
	
	cin >> num;
	vetor = new int[num];
	
	for(int i = 0; i < num; i++) {
		cin >> vetor[i];
	}

	soma = somaElementosVetor(vetor, num - 1, soma);

	cout << soma << endl;

	return 0;
}