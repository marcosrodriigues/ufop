/*
	Marcos Rodrigues
	2014.2.4341
	Introdução à Programação
*/
#include <stdio.h>

int main() {
	
	double e = 0.0, fatorial;
	int i, j;
	
	for(i = 0; i <= 15; i++) {
	
		fatorial = 1;
		//Fatorial de I
		for(j = i; j >= 0; j--) {
			fatorial = fatorial * j;
		}
		
		e = e + (1 / fatorial);
	}
	
	printf("O valor do numero Neperiano 'e' vale %f .\n", e);
	
	return 0;
}