#include <iostream>
using namespace std;

int main(){
	int placa, ultimoDigito;
	
	cout << "Entre com os 4 números da placa";
	cin >> placa;
	
	ultimoDigito = placa / 1000;
	
	cout << "O valor correspondente à unidade de milhar da placa é: " << ultimoDigito;
	
	return 0;
}
