#include <iostream>
using namespace std;

int main() {
	int diaDaSemana;
	
	cout << "Digite um dia da semana, entre 1 e 7:\n";
	cin >> diaDaSemana;
	
	//Usei o Switch/Case pois o professor já explicou na última aula.
	switch(diaDaSemana) {
		case 1:
			cout << "Domingo\n";
			break;
		case 2:
			cout << "Segunda-Feira\n";
			break;
		case 3:
			cout << "Terca-Feira\n";
			break;
		case 4:
			cout << "Quarta-Feira\n";
			break;
		case 5:
			cout << "Quinta-Feira\n";
			break;
		case 6:
			cout << "Sexta-Feira\n";
			break;
		case 7:
			cout << "Sabado\n";
			break;
		default:
			cout << "Nao existe dia da semana com este numero.\n";
			break;
	}
	return 0;
}