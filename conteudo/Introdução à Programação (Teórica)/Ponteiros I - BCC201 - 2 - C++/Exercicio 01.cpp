/*
	Marcos Rodrigues - 14.2.4341
	Ponteiros I - Exercício 01.
*/

/*
	O resultado a ser exibido é 8.
	Explicação:
		Declarou-se uma variável V e um ponteiro P, ambos do tipo int. 
		Atribuiu-se o valor 4 à variável V.
		Referenciou o vetor P ao endereço de memória da variável V;
		Uma vez com a referencia feita, todo valor atribuido ao Ponteiro é, automaticamente, 
	atribuido à variável, deixando o valor do Ponteiro com a referência para a variável V.
		Quando exibiu-se o valor de V, este estava com o valor atribuido ao *P, devido à referência.
		
		Beijos, tudo de bão, abraço no coração e um aperto na sua mão.
		E não precisa corrigir, pode dar 10 direto !
		Flw prof.
*/
#include <iostream>
using namespace std;

int main() {
	int v , *p ;
	v = 4;
	p = &v ;
	*p = 2 * *p ;
	cout << "\nValor: %" << v ;
	return 0;
}