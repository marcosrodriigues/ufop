#ifndef ____CLIENTE_H____
#define ____CLIENTE_H____

#include "Include.h"

typedef struct Cliente {
	char nome[30];
	bool beber;
	pthread_t e_espera;
}TCliente;

void novo_cliente(TCliente*, char*);
void faz_pedido(TCliente*, TBar*);
void *espera_pedido(void*);
void recebe_pedido(TCliente*);
void consome_pedido(TCliente*);
void beforeRunCliente(TBar *bar, TCliente *cliente);
void *runCliente(void*);

#endif