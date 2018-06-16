#ifndef ____BAR_H____
#define ____BAR_H____

#include "Include.h"
#include "Cliente.h"

typedef struct Bar {
	int n_clientes, total_rodadas, total_anotado;
	int total_entregue, total_rodada,rodada;
	int falta_beber;

	int iQuer;
	int iNQuer;
	TCliente quer[9999];
	TCliente nao_quer[9999];
}TBar;

void novo_bar(TBar*, int, int);
void pedir(TBar*, TCliente*);
void espera_beberem(TBar*);
bool fechouBar(TBar*);
TCliente anotar_pedido(TBar*);

#endif