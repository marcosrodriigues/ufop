#include <iostream>
#include <limits.h>
using namespace std;

void isTwoTaller(int n1, int n2, int n3, int n4, int n5, int *segundo, int *quarto) {

	const int MAX = 5;
	int aux = 0;
	
	int vetor[MAX] = { n1, n2, n3, n4, n5 };
	
	for (int i = 0; i < MAX; i++) {
		for (int j = i; j < MAX; j++) {
			if (vetor[i] >= vetor[j]) {
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
		
	}	
	
	*quarto = vetor[3];
	*segundo = vetor[1];
}

int main() {

	int n1, n2, n3, n4, n5, segundo = 0, quarto = 0;

	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	
	while (n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0 || n5 != 0) {
		isTwoTaller(n1, n2, n3, n4, n5, &segundo, &quarto);
	
		cout << quarto << " " << segundo << endl;
		cin >> n1 >> n2 >> n3 >> n4 >> n5;	
	}

	return 0;
}