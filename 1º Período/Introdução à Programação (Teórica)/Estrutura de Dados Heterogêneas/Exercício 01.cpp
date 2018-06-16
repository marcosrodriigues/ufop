/*
	Marcos Rodrigues - 13.2.4341
	Estrutura de Dados Heterogêneas I - Exercício 01
*/

#include <iostream>
#define MAX 3
using namespace std;

struct Aluno {
	string name;
	int age, academyRegister;
};

int main() {
	Aluno students[MAX];
	int idade = 0;
	
	for(int i = 0; i < MAX; i++) {
		cout << "Digite o Nome, a Idade e o Registro Academico do " << i + 1 << ". aluno: \n";
		getline(cin, students[i].name);
		cin >> students[i].age >> students[i].academyRegister;
		
		//Limpa o Buffer do CIN
		fflush(stdin);
	}
	
	cout << "Digite uma idade: \n";
	cin >> idade;
	
	for (int i = 0; i < MAX; i++) {
		if (idade > students[i].age)
			cout << "Nome: " << students[i].name << ". Idade: " << students[i].age << endl;
	}
	
	return 0;
}