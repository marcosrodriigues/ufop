#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	double R, h, V;
	
	cout << "Entre com o valor do Raio: \n";
	cin >> R;
	cout << "Entre com o valor da Altura: \n";
	cin >> h;
	
	V = 3.14159 * pow(R, 2) * h;
	
	cout << "O valor do Volume da lata de óleo é: " << V;

	return 0;
}