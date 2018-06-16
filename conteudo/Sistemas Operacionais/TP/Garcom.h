#ifndef ____GARCOM_H____
#define ____GARCOM_H____

#include "Include.h"

#include "Cliente.h"
#include "Bar.h"

typedef struct Garcom {
	char nome[30];
	int max_cliente, i;
	TCliente anotados[9999];
	TBar bar;
}TGarcom;

void novo_garcom(TGarcom*, int, char*, TBar);
void recebe_max_pedidos(TGarcom*);
void registra_pedido(TGarcom*);
void entrega_pedido(TGarcom*);
void beforeRunGarcom(TBar*, TGarcom*);
void *runGarcom(void*);


#endif