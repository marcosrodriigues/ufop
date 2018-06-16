#include <iostream>
using namespace std;

void numeroRomano(int numArabico) {	
	int nArabico = numArabico;
	
	
	if (nArabico >= 51) {
		cout << "Erro: numero imcompativel.";
		return;
	}
	
	if (nArabico == 50) {
		cout << "L";
		nArabico -= 50;
	}
	
	while (nArabico >= 10) {
		if (nArabico >= 40) {
			cout << "XL";
			nArabico -= 40;
		}
		
		if (nArabico >= 10) {
			cout << "X";
			nArabico -= 10;
		}
	}
	
	while (nArabico >= 1) {
		if (nArabico >= 9) {
			cout << "IX";
			nArabico -= 9;
		}
		
		if (nArabico >= 5) {
			cout << "V";
			nArabico -= 5;
		}
		
		if (nArabico >= 4) {
			cout << "IV";
			nArabico -= 4;
		}
		
		if (nArabico >= 1){
			cout << "I";
			nArabico--;
		}
	}
}

int main() {
	
	int nArabico;
	
	cin >> nArabico;
	
	while (nArabico != 0) {
		numeroRomano(nArabico);
		cout << endl;
		cin >> nArabico;	
	}
	
	return 0;	
}