#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int vetImpar[20], countImpar = 0;
	
	for (int i = 1; i <= 20; i++) {
		if (i % 2 != 0) {
			vetImpar[countImpar] = pow(i, 2);
			countImpar++;
		}
	}

	for (int i = 0; i < countImpar; i++) {
		cout << vetImpar[i] << endl;
	}
	
	return 0;
}