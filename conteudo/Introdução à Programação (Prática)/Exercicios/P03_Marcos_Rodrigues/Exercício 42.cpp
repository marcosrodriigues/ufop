/*
	A série de RICCI difere da série de FIBONACCI porque os dois primeiros termos são fornecidos pelo usuário. Os demais termos são gerados da mesma forma 
	que a série de FIBONACCI.  Criar  um  programa  que  imprima  os  N  primeiros  termos  da  série  de RICCI  e  a  soma  dos  termos  impressos,  sabendo-se
	que para  existir  esta  série  serão necessários pelo menos três termos. 
*/

#include <iostream>
using namespace std;

int main() {
	
	int soma, qtdTermos, n1, n2, nAtual;
		
	cout << "Digite os dois primeiros termos da serie: \n";
	cin >> n1 >> n2;
	
	cout << "Digite a quantidade de termos que deseja calcular: \n";
	cin >> qtdTermos;
	
	if(qtdTermos >= 3) {
		nAtual = n1 + n2;
		cout << n1 << " " << n2 << " " << nAtual;

		soma = n1 + n2 + nAtual;
		for(int i = 0; i < qtdTermos - 3; i++) {
			n1 = n2;
			n2 = nAtual;
			nAtual = n2 + n1;
			cout << " " << nAtual;
			
			soma = soma + nAtual;
		}
		
		cout << "\nA soma dos termos da sequencia eh: " << soma;
	} else { 
		cout << "Impossivel calcular a sequencia.";
	} 
	
	return 0;
}