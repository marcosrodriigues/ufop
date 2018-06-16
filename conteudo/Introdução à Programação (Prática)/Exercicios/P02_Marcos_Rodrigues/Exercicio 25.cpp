#include <iostream>
using namespace std;

int main(){
	int idade;
	
	cout << "Digite a idade: \n";
	cin >> idade;
	
	cout << "Categoria ";
	if (idade >= 5 && idade <= 7)
		cout << "Infantil - A.\n";
	else if (idade >= 8 && idade <= 10)
		cout << "Infantil - B.\n";
	else if (idade >= 11 && idade <= 13)
		cout << "Juvenil - A.\n";
	else if (idade >= 14 && idade <= 17)
		cout << "Juvenil - B.\n";
	else if (idade >= 18)
		cout << "Senior.\n";	
	else // Caso o usuario entre com um valor menor que 5, o sistema exibe o resultado.
		cout << "nao disponivel\n";
	
	return 0;
}