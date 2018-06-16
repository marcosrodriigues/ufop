#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int A1, Q, N;
	double P;
	
	cout << "Entre com o valor do primeiro termo: \n";
	cin >> A1;
	cout << "Entre com o valor da razao: \n";
	cin >> Q;
	cout << "Entre com a quantidade dos N primeiros termos que gostaria de obter o produto: \n";
	cin >> N;
	
	P = pow(A1, N) * pow(Q, N * (N - 1) / 2);
	
	cout << "O produto dos " << N << " primeiros termos da P.G eh " << P << "\n";	

	return 0;
}