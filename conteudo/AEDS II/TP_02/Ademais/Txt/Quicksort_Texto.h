#ifndef __QUICKSORT_H_INCLUDED__
#define __QUICKSORT_H_INCLUDED__

#include "Include.h"
#include "TRegistro.h"

#define TAM_AREA 20
#define SIZEOF_REGISTRO 101
#define MAX_REGISTRO 471705

typedef struct TipoArea {
	TRegistro area[TAM_AREA];
	int n;
}TArea;

/*	FUNÇÕES PARA O QUICKSORT */
void QuicksortExterno (fstream& ArqLi, fstream& ArqEi, fstream& ArqLEs, int Esq, int Dir);
void LeSup (fstream& ArqLEs, TRegistro *Registro, int *Ls, short *OndeLer);
void LeInf (fstream& ArqLi, TRegistro *Registro, int *Li, short *OndeLer);
void InserirArea (TArea *Area, TRegistro *Registro, int *NRArea);
void EscreveMax (fstream& ArqLEs, TRegistro R, int *Es);
void EscreveMin (fstream& ArqEi, TRegistro R, int *Ei);
void RetiraMax (TArea *Area, TRegistro *R, int *NRArea);
void RetiraMin (TArea *Area, TRegistro *R, int *NRArea);
void Particao (fstream& ArqLi, fstream& ArqEi, fstream& ArqLEs, TArea Area, int Esq, int Dir, int *i, int *j);

/*	FUNÇÕES PARA MANIPULAR A ÁREA */
void FAVazia (TArea *Area);
void InsereItem (TRegistro Registro, TArea *Area);
void RetiraUltimo (TArea *Area, TRegistro *R);
void RetiraPrimeiro (TArea *Area, TRegistro *R);
int ObterNumCelOcupadas (TArea Area);

/*	Funções adicionais	*/
void StringPraRegistro(string DadosLidos, TRegistro *Registro);
#endif