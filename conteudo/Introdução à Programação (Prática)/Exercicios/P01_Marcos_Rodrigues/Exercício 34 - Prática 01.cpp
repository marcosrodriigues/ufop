#include <iostream>
using namespace std;

//Terminado *-*
int main(){
	
	double salMinimo, quiloWatts, valorCada, valorPago, newValue;
	
	cout << "Entre com o valor do salario minimo: ";
	cin >> salMinimo;
	cout << "Entre com a quantidade de Quilowatts gasta: ";
	cin >> quiloWatts;
	
	//Se 100 quiloWatts = SalarioMinimo / 7, então 1 quiloWatts é o mesmo que SalarioMinimo / 700.
	valorCada = salMinimo / 700;
	valorPago = valorCada * quiloWatts;
	newValue = valorPago - (valorPago * 0.1);
	
	cout << "O valor em reais de cada quilowatt ehhhhhhhh: " << valorCada << "\n";
	cout << "O valor em reais a ser pago ehhhhhhhh: " << valorPago << "\n";
	cout << "Como sou bonzinho, darei um desconto de 10%. O valor real a ser pago ehhhhhhhh: " << newValue << "\n";
	cout << "\n\nBejo !";
	
	return 0;
}