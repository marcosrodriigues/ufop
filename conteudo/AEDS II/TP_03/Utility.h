#ifndef __UTILITY_H_INCLUDED__
#define __UTILITY_H_INCLUDED__

#include "Include.h"
#include "Define.h"

bool ReadTexto(FILE*, TipoTexto);
bool VerificarArgumentos(int argc, char const *argv[]);
void MostrarInformacoes(int Metodo, int NumComparacoes, int NumDeslocamento);

#endif
