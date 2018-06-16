/*
	Chico tem 1,50m e cresce 2 centímetros por ano, enquanto Juca tem 1,10m e cresce 3 centímetros  por  ano.  
	Construir  um  programa  que  calcule  iterativamente  e  imprima quantos anos serão necessários para que Juca seja maior que Chico. 
*/
#include <iostream>
using namespace std;

int main() {
	
	double alturaChico = 1.50, alturaJuca = 1.10;
	int qtdAnos = 0;
	
	//Somente "<" pois o programa quer para que Juca seja MAIOR que Chico, e não da mesma altura.
	while(alturaJuca < alturaChico) {
		qtdAnos++;
		alturaChico = alturaChico + 0.02;
		alturaJuca = alturaJuca + 0.03;
	}
	
	cout << "Serao necessarios " << qtdAnos << " anos para que Juca fique maior que Chico.\n";
	
	return 0;
}