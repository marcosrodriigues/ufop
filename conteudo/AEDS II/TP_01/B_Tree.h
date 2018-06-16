#ifndef __B_TREE_H_INCLUDED__
#define __B_TREE_H_INCLUDED__

#include "TRegistro.h"

#define M 4
#define MM M * 2

typedef struct TipoPagina* TipoApontador;

typedef struct TipoPagina{
	short n;
	TRegistro r[MM];
	TipoApontador p[MM + 1];
}TipoPagina;

void New_Tree (TipoApontador *Tree);
void Search_Tree (TRegistro *reg, TipoApontador Ap, int key, int *nTransfer, int *nCompare);
void Ins_Tree (TRegistro reg, TipoApontador Ap, short *Cresceu, TRegistro *RegRetorno, TipoApontador *ApRetorno);
void Insert_Tree (TRegistro reg, TipoApontador *Ap);
void InsertInPage_Tree (TipoApontador Ap, TRegistro Reg, TipoApontador ApDir);
void Mount_Tree (FILE* file, int amount, TipoApontador* Tree);

#endif
