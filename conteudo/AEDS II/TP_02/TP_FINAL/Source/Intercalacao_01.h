#ifndef __INTERCALACAO01_H_INCLUDED__
#define __INTERCALACAO01_H_INCLUDED__

#include "TRegistro.h"
#include "Include.h"
#include "Utility.h"

#define F_ENTRADA 20	/*	20 Fitas de entrada			*/
#define F_SAIDA 20		/*	20 Fitas de saída			*/
#define MEM_INT 20		/* 	Memória Interna disponível	*/

typedef struct Fita {
	FILE* arquivo;
	int nBlocos;
	bool Ativo;
}TFita;

/*	METODOS USADOS	*/
bool SalvarArquivo(char*, TRegistro*, int , int);
bool PreencherDados(TFita*, int);

/*	METODOS PARA ORDENAÇÃO CRESCENTE	*/
bool InserirVetorNaFita(TRegistro*, TFita*, int);
bool CriarArquivosOrdenados(FILE*, TFita*, int);
bool IntercalarFitasCrescente(TFita*);
int IntercalacaoBalanceada(FILE*, int);
void VerificarSeTemRegistroNulo(TFita*, TFita*);
/*	METODOS PARA ORDENAÇÃO DECRESCENTE	*/
// int CriarArquivosOrdenadosDecrescente(char*);
// int ProcurarMaior(TFita*, int, int, TRegistro*);
// bool IntercalaDecrescente(char*, int, int);
// int IntercalacaoBalanceadaDecrescente(char*);

void OrdenaCrescente (TRegistro*, int);
//void OrdenaDecrescente (TRegistro*, int);
#endif