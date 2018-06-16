#include <iostream>
using namespace std;

int main(){
	int hh, mm, total;
	
	do {
		cout << "Entre com a hora: \n";
		cin >> hh;	
	} while(hh < 0 || hh > 24);
	
	do {
		cout << "Entre com o valor em minutos: \n";
		cin >> mm;
	} while(mm < 0 || mm > 60);
	
	total = hh * 60 + mm;
	
	cout << "Total de minutos de 00:00 ate a hora informada: " << total;
	
	return 0;
}