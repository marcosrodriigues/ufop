#include <iostream>
using namespace std;

int main() {

	int vetor[101], j = 0;
	
	for(int i = 100; i <= 200; i++, j++) {
		vetor[j] = i;
	}
	
	for(int i = 0; i <= 100; i++) {
		cout << vetor[i] << endl;
	}

	return 0;
}