#include "Utility.h"

bool ReadTexto(FILE* ArqTexto, TipoTexto Texto) {
	long i = 0;
	while(!feof(ArqTexto)) Texto[i++] = getc(ArqTexto);
	return true;
}

bool VerificarArgumentos(int argc, char const *argv[]) {
	if (argc < 4 || argc > 5) return false;

	int metodo 		= atoi(argv[1]);
	char* texto 	= (char*) argv[2];
	char* padrao 	= (char*) argv[3];
	bool _P_		= (argc == 5);

	if (metodo < 1 || metodo > 4) 	return false;

	return true;
}

void MostrarInformacoes(int Metodo, int NumComparacoes, int NumDeslocamento) {
	switch(Metodo) {
		case FORCA_BRUTA:
			cout << "METODO: FORCA BRUTA" << endl;
			break;
		case BM:
			cout << "METODO: BOYER MOORE COM HEURISTICA OCORRENCIA" << endl;
			break;
		case BMHS:
			cout << "METODO: BOYER-MOORE-HORSPOOL-SUNDAY " << endl;
			break;
		case SHIFT_AND_EXATO:
			cout << "METODO: SHIFT AND EXATO" << endl;
			break;
	}

	cout << "Numero de comparacoes: " << NumComparacoes << endl;
	cout << "Numero de deslocamentos: " << NumDeslocamento << endl;
}