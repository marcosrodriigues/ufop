#include <iostream>
using namespace std;

void Binario (int N) {
	if (N > 0) {
		Binario(N / 2);
		cout << ((N % 2 == 0) ? 0 : 1);
	}
}

int main () {
	
	int N;
	
	do {
		cin >> N;	
	} while (N < 0);
		
	
	Binario(N);
	
	return 0;
}