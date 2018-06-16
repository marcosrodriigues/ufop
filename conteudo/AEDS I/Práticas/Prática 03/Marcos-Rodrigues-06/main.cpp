#include <iostream>
using namespace std;

double AoQuadrado (double K, int N) {
	if (N == 0)
		return 1;
	else if (N == 1)
		return K;
	
	return K * AoQuadrado(K, --N);
}

int main () {
	
	double K;
	int N;
	
	cin >> K;
	
	do {
		cin >> N;	
	} while (N < 0);
		
	cout << AoQuadrado(K, N) << endl;
	
	return 0;
}