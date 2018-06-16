/*
	Marcos Rodrigues - 13.2.4341
	Estrutura de Dados Heterogêneas I - Exercício 01
*/

#include <iostream>
#define MAX 500
using namespace std;

struct Habitante {
	int age, sunNumber;
	string sexo;
	double salary;
	
};

void save(Habitante *hab);
double media(Habitante hab[MAX]);

int main() {
	Habitante hab[MAX];
	double med;
	
	for (int i = 0; i < MAX; i++) {
		save(&hab[i]);
	}
	
	med = media(hab);
	
	cout << "Media dos salarios: " << med << endl;
	
	return 0;
}

void save(Habitante *hab) {

	cout << "Digite a Idade, o Salario e o Numero de Filhos: " << endl;
	cin >> hab->age >> hab->salary >> hab->sunNumber;
	
	//Limpa o Buffer do CIN
	fflush(stdin);
	
	cout << "Digite o sexo: " << endl;
	getline(cin, hab->sexo);
	
	return;
		
}

double media(Habitante hab[MAX]) {
	double med = 0.0;
	for (int i = 0; i < MAX; i++)
		med = med + hab[i].salary;
		
	med = med / MAX;
	
	return med;
}

