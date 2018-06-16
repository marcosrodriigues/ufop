#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Bar.h"
#include "Cliente.h"
#include "Garcom.h"

int main() {

	TCliente cliente[30];
	TGarcom garcom[30];
	TBar bar;

	int n_clientes, n_garcom, capacidade_garcom, max_rodadas;

	printf("Digite o N de clientes:\n");
	scanf("%d", &n_clientes);

	printf("Digite o N de garcom:\n");
	scanf("%d", &n_garcom);

	printf("Digite a capacidade de atendimento do garcom:\n");
	scanf("%d", &capacidade_garcom);

	printf("Digite o maximo de rodadas:\n");
	scanf("%d", &max_rodadas);



	return 0;
}