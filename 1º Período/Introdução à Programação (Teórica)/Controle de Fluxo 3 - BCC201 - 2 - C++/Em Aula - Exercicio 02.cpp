#include <iostream>
using namespace std;

int main() {
	
	int qtdPessoas, idade, i = 0;
	double media;
	
	cout << "Entre com a quantidade de pessoas: \n";
	cin >> qtdPessoas;
	
	for(i = 0; i < qtdPessoas; i++) {
		cout << "Entre com a idade da " << (i + 1) << "? pessoa: \n";
		cin >> idade;
		
		if (idade >= 0)
			media += idade;
	}
	
	if (qtdPessoas > 0) {
	
		media = media / qtdPessoas;
	
		if (media >= 0 && media <= 25)
			cout << "A turma eh jovem. \n";
		else if (media >= 26 && media <= 60)
			cout << "A turma eh adulta. \n";
		else
			cout << "A turma eh idosa.\n";
	}
				
	return 0;
	
}