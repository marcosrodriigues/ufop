/*
	Construa  um  programa  que  receba  um  número  e  verifique  se  ele  é  um  número triangular. 
	(Um número  é triangular quando é resultado do produto de três números consecutivos. Exemplo: 24 = 2 x 3 x 4) 
	
	
	Comentário:
		Não encontrei a definição dada para numero triangular. Busquei na internet e achei 3 links, nos quais usei para tomar como base para fazer
		o exercício
		
		Links:
			http://www.atractor.pt/mat/numeros/triangulares/
			http://www.paulomarques.com.br/arq2-9.htm
			http://pt.wikipedia.org/wiki/N%C3%BAmero_triangular
*/
#include <iostream>
using namespace std;

int main() {

	int numero, soma;
	bool ehTriangular = false;
	
	cout << "Digite um numero: \n";
	cin >> numero;
	
	for (int i = 1; i <= numero; i++) {
		soma = soma + i;
		
		if(soma == numero) {
			ehTriangular = true;
			break;
		}
	}

	if(ehTriangular)
		cout << "O numero " << numero << " eh um numero triangular.\n";
	else
		cout << "O numero " << numero << " nao eh um numero triangular.\n";
	
	return 0;
}