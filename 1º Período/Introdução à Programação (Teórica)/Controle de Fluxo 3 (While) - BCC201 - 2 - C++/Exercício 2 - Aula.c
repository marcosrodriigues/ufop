/*
	Marcos Rodrigues
	2014.2.4341
	Introdução à Programação	
*/
#include <stdio.h>
#include <limits.h>

int main () {
	int N, countPrimo, countTotal = 0;
	int imax = INT_MAX;
	
	
	printf("Digite a quantidade de numeros primos que deseja saber: \n");
	scanf("%d", &N);
	
	if(N > 0) {
		for(int i = 1; i < imax; i++) {
			countPrimo = 0;
			for(int j = i; j >= 1; j--) {
				if (i % j == 0) {
					countPrimo++;
				}
			}
			if(countPrimo == 1 || countPrimo == 2) {
				countTotal++;
				printf("O numero %d eh um numero primo.\n", i);
			}
			
			if(countTotal == N) {
				break;
			}
		}
	}
	
	
	return 0;
}