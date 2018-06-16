#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int vetor[5];

	vetor[0] = 5;
	vetor[1] = 4;
	vetor[2] = 3;
	vetor[3] = 2;
	vetor[4] = 1;

	int aux = 0;
	int n = 5;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (vetor[j] < vetor[j-1]){
				aux = vetor[j];
				vetor[j] = vetor[j -1];
				vetor[j - 1] = aux;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << vetor[i] << "-";
	}
	cout << endl;
	return 0;
}