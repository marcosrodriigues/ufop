/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Função - Exercício Em Casa - 02
*/
#include <stdio.h>

int pot (int base, int expoente) {
	int result = 1.0;
	
	if (base == 0.0) {
		result = 0.0;
	} else {
		int i;
	
		for (i = 1; i <= expoente; i++) {
			result = result * base;
		}
	}
	
	return result;
}

int main() {

	int base, result;
	int exp;
	
	printf("Digite o valor da base: ");
	scanf("%d", &base);
	
	printf("Digite o valor do expoente: ");
	scanf("%d", &exp);
	
	result = pot(base, exp);
	
	printf("O valor de %d elevado a %d eh: %d", base, exp, result);
	
	return 0;
}