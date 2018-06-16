/*
	Marcos Rodrigues - 13.2.4341
	Ponteiros II - Exercício 02
	
	O exercício pedia para usar só ponteiros, porém, atribuir valor diretamente ao ponteiro não tem como. Pesquisei na internet e não achei.
	
	Link de alguns lugares pesquisados:
		http://pt.wikibooks.org/wiki/Programar_em_C/Ponteiros
		http://juliobattisti.com.br/tutoriais/katiaduarte/cbasico007.asp
		http://homepages.dcc.ufmg.br/~joaoreis/Site%20de%20tutoriais/c_int/ponteiros.htm
		http://www.mtm.ufsc.br/~azeredo/cursoC/aulas/c620.html
		
*/

#include <iostream>
using namespace std;

int main() {

	double *val1 = NULL, *val2 = NULL, v1, v2, media = 0.0;
	
	cout << "Digite dois valores: \n";
	cin >> v1 >> v2;
	
	val1 = &v1;
	val2 = &v2;
	
	media = (*val1 + *val2) / 2;
	
	cout << "Media aritmetica: " << media << endl;

	return 0;
}