#ifndef __BM__
#define __BM__

#include "Include.h"
#include "Define.h"

void Sufixos(TipoPadrao Padrao, long m, int *sufixo);
void Pre_Processamento(TipoPadrao Padrao, int m, int *sufixos);
void Boyer_Moore(TipoTexto Texto, int n, TipoPadrao Padrao, int m, int*, int*);

#endif