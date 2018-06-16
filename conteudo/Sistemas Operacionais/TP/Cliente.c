#include "Cliente.h"
#include "Bar.h"

void novo_cliente(TCliente *cliente, char nome[30]) {
	
	for (int i = 0; i < 30; i++){
		cliente->nome[i] = nome[i];
	}

	cliente->beber = true;
}

void faz_pedido(TCliente *cliente, TBar *bar) {
	
	//chance do cliente beber nessa rodada
	srand(time(NULL));
	int chance = rand() % 3;

	if (chance == 2) {
		//se for 3 o cliente nao bebe
		cliente->beber = false;

		printf("Cliente %s nao vai beber\n", cliente->nome);
		//espera todos beberem pra acabar a rodada
		espera_beberem(bar);
	} else {
		cliente->beber = true;
		//se coloca pra ser atendido
		pedir(bar, cliente);
	}
}

void *espera_pedido(void *argumentos) {
	TCliente cliente = *(TCliente*) argumentos; 

	printf("Cliente %s esperando\n", cliente.nome);
	sleep(5000);
}

void recebe_pedido(TCliente *cliente) {
	//1 segundo pra ele pegar o pedido
	sleep(1000);
	printf("Cliente %s bebendo\n", cliente->nome);


}

void consome_pedido(TCliente *cliente) {
	sleep(1000);
	printf("Cliente %s bebeu\n", cliente->nome);

}

void beforeRunCliente(TBar *bar, TCliente *cliente) {
	pthread_t thread_cliente;
	while (!fechouBar(bar)) {
		pthread_create(&thread_cliente, NULL, runCliente, cliente);
	}
}

void *runCliente(void *argumentos) {
	TCliente cliente = *(TCliente*) argumentos;
	TBar bar;
	faz_pedido(&cliente, &bar);
	if (cliente.beber) {
		espera_pedido(&cliente);
		recebe_pedido(&cliente);
		consome_pedido(&cliente);	
	}

	return;
}