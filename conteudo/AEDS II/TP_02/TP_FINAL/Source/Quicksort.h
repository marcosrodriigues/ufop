#ifndef __QUICKSORT_H_INCLUDED__
#define __QUICKSORT_H_INCLUDED__

#include "Include.h"
#include "TRegistro.h"

//#define TAM_AREA 20
//#define MAX_REGISTRO 471705
#define TAM_AREA 3
#define MAX_REGISTRO 10

typedef struct TipoArea {
	TRegistro area[TAM_AREA];
	int n;
}TArea;

/*	FUNÇÕES PARA O QUICKSORT */
void QuicksortExterno (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, int *nTransferRead, int *nTransferWrite, int *nCompare);
void LeSup (FILE **ArqLEs, TRegistro *Registro, int *Ls, short *OndeLer, int *nTransferRead);
void LeInf (FILE **ArqLi, TRegistro *Registro, int *Li, short *OndeLer, int *nTransferRead);
void InserirArea (TArea *Area, TRegistro *Registro, int *NRArea, int *nCompare);
void EscreveMax (FILE **ArqLEs, TRegistro R, int *Es, int *nTransferWrite);
void EscreveMin (FILE **ArqEi, TRegistro R, int *Ei, int *nTransferWrite);
void RetiraMax (TArea *Area, TRegistro *R, int *NRArea);
void RetiraMin (TArea *Area, TRegistro *R, int *NRArea);
void Particao (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TArea Area, int Esq, int Dir, int *i, int *j, int *nTransferRead, int *nTransferWrite, int *nCompare);

/*	FUNÇÕES PARA QUICKSORT DECRESCENTE */
void QuicksortExterno_Decrescente (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, int *nTransferRead, int *nTransferWrite, int *nCompare);
void Particao_Decrescente (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TArea Area, int Esq, int Dir, int *i, int *j, int *nTransferRead, int *nTransferWrite, int *nCompare);

/*	FUNÇÕES PARA MANIPULAR A ÁREA */
void FAVazia (TArea *Area);
void InsereItem (TRegistro Registro, TArea *Area, int *nCompare);
void RetiraUltimo (TArea *Area, TRegistro *R);
void RetiraPrimeiro (TArea *Area, TRegistro *R);
int ObterNumCelOcupadas (TArea *Area);

#endif