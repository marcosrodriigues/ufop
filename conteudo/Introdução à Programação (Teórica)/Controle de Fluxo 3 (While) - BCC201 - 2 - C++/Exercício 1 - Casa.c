/*
	Marcos Rodrigues
	2014.2.4341
	Introdução à Programação
*/
#include <stdio.h>

int main() {

	int numero, numAuxiliar, numInvertido = 0, numAtual = 0;
	
	printf("Digite um numero: \n");
	scanf("%d", &numero);
	
	//numAuxiliar vai ter o valor de NUMERO para que eu nao perca esse valor na hora de comparar.
	numAuxiliar = numero;
	if (numAuxiliar >= 0) {
		while (numAuxiliar != 0) {
			//Pegando o a ultima casa decimal do numero
			numAtual = numAuxiliar % 10;
			//Adicionando a casa decimal no primeiro numero do numero invertido
			numInvertido = (numInvertido * 10) + numAtual;
			//Pegando o próximo valor do "numero", excluindo a ultima casa decimal
			numAuxiliar = numAuxiliar / 10;
		}
		
		if (numero == numInvertido) {
			printf("ESSE NUMERO E PALINDROMO!!!");
		} else {
			printf("ESSE NUMERO NAO E PALINDROMO");
		}
	} else {
		printf ("O numero precisa ser inteiro e positivo.\n");
	}
	
	return 0;
}