#include "Bar.h"

void novo_bar(TBar *bar, int n_clientes, int total_rodadas) {
	bar->n_clientes = n_clientes;
	bar->total_rodadas = total_rodadas;
	
	bar->total_anotado = 0;
	bar->falta_beber = n_clientes;
	bar->rodada = 0;

	bar->iQuer = 0;
	bar->iNQuer = 0;
}

void pedir(TBar *bar, TCliente *cliente) {
	bar->quer[bar->iQuer] = *cliente;
	bar->iQuer++;
}

void espera_beberem(TBar *bar) {
	//espera beberm
	if (bar->falta_beber - 1 == 0) {
		bar->falta_beber = bar->n_clientes;
		bar->rodada = bar->rodada + 1;

		if (bar->rodada == bar->total_rodadas) {
			printf("ACABOU!");
		} else {
			bar->total_anotado = 0;
		}
	} else {
		bar->falta_beber = bar->falta_beber - 1;
	}
}

bool fechouBar(TBar *bar) {
	return bar->total_rodadas == bar->rodada;
}

TCliente anotar_pedido(TBar *bar) {
	TCliente cliente_atendido;
	if (bar->total_anotado < bar->n_clientes) {
		cliente_atendido = bar->quer[0];

		for (int i = 1; i < bar->iQuer-1; ++i) {
			bar->quer[i - 1] = bar->quer[i];
		}
		bar->iQuer--;
		bar->total_anotado++;
	}

	return cliente_atendido;
}