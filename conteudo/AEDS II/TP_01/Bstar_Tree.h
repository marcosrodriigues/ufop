#ifndef __B_STAR_TREE_H_INCLUDED__
#define __B_STAR_TREE_H_INCLUDED__

#define M 2
#define MM M * 2

#include "TRegistro.h"

typedef enum {
	INTERNA, EXTERNA
}TIntExt;

typedef struct TipoPaginaEstrela *TipoApontadorEstrela;

typedef struct TipoPaginaEstrela {
	TIntExt PT;
	union {
		struct {
			int ni;
			TRegistro ri[MM];
			TipoApontadorEstrela pi[MM + 1];
		} U0;
		struct {
			int ne;
			TRegistro re[MM * 2];
		} U1;
	} UU;
}TipoPaginaEstrela;

void New_BStar (TipoApontadorEstrela *Tree);
void Search_BStar (TRegistro *reg, TipoApontadorEstrela *Ap, int key, int *nTransfer, int *nCompare);
void Mount_BStar (FILE* file, int amount, TipoApontadorEstrela* Tree);
void Ins_Star (TRegistro reg, TipoApontadorEstrela Ap, short *Cresceu, TRegistro *RegRetorno, TipoApontadorEstrela *ApRetorno);
void Insert_Star (TRegistro reg, TipoApontadorEstrela *Ap);
void InsertInPage_Star (TipoApontadorEstrela Ap, TRegistro Reg, TipoApontadorEstrela ApDir);
void escreverValor(TipoApontadorEstrela *Ap);

#endif
