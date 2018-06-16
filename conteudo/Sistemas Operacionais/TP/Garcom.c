#include "Garcom.h"

void novo_garcom(TGarcom* garcom, int max_cliente, char nome[30], TBar bar) {
	
	for (int i = 0; i < 30; i++){
		garcom->nome[i] = nome[i];
	}

	garcom->max_cliente = max_cliente;
	garcom->i = 0;
	garcom->bar = bar;
}

void recebe_max_pedidos(TGarcom *garcom) {

	while (garcom->i < garcom->max_cliente) {
		TCliente cliente = anotar_pedido(garcom);

			if (cliente.beber) {
				garcom->anotados[garcom->i] = cliente;
				garcom->i = garcom->i + 1;

				printf("Garçom %s recebeu o pedido do cliente %s\n", garcom->nome, cliente.nome);
			}
		
	}
}

void registra_pedido(TGarcom *garcom) {

	if (garcom->i > 0) {

		sleep(2000);
		printf("Garçom %s recebeu o pedido dos clientes:\n", garcom->nome);
		for (int i = 0; i < garcom->i; ++i) {
			printf("%s\n", garcom->anotados[i].nome);
		}
	}
}

void entrega_pedido(TGarcom *garcom) {

	TCliente cli;
	for (int i = 0; i < garcom->i; ++i) {
		printf("Garçom %s entregou o pedido ao cliente %s\n", garcom->nome, garcom->anotados[i].nome);
		garcom->anotados[i] = cli;
	}
	garcom->i = 0;

}

void beforeRunGarcom(TBar* bar, TGarcom* garcom) {
	pthread_t thread_garcom;
	while (!fechouBar(bar)) {
		pthread_create(&thread_garcom, NULL, runGarcom, garcom);
	}
}


void *runGarcom(void *argumentos) {
	TGarcom garcom = *(TGarcom*)argumentos;
	
	recebe_max_pedidos(&garcom);
	registra_pedido(&garcom);
	entrega_pedido(&garcom);
}