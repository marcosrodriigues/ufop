/*
	Execução do programa: casamento <metodo> <texto> <padrao> [-P]
		casamento:		nome do programa
		<metodo>:		1 à 4, de acordo com os métodos implantados
		<texto>:		nome do arquivo que contém o texto
		<padrao>:		padrão a ser pesquisado
		[-P]:			Argumento opcional. Quando ativado, exibe o número de comparações, número de deslocamentos e tempo de execução

	Métodos:
		- FORCA_BRUTA:		1
		- BOYER_MOORE:		2
		- BMHS:				3
		- ShiftAndExato:	4
*/

#include "Define.h"
#include "ForcaBruta.h"
#include "BMHS.h"
#include "Utility.h"
#include "Include.h"
#include "BM.h"
#include "ShiftAnd_Exato.h"

int main(int argc, char const *argv[]) {
	
	//Verifica os argumentos passados na chamada do programa
	if(!VerificarArgumentos(argc, argv)) {
		cout << "Argumentos invalidos!" << endl;
		return 1;
	}

	//Atribui os valores dos argumentos para as variáveis
	int Metodo 			= atoi(argv[1]);
	char* NomeArquivo 	= (char*) argv[2];
	char* P 			= (char*) argv[3];
	bool MostrarInfo	= (argc == 5);

	//Abri o arquivo passado por argumento
	FILE* ArqTexto;
	if((ArqTexto = fopen(NomeArquivo, "r")) == NULL) {
		cout << "Nao foi possivel abrir o arquivo " << NomeArquivo << endl;
		return 1;
	}

	//Le o texto do arquivo
	TipoTexto Texto;
	if (!ReadTexto(ArqTexto, Texto)) {
		cout << "Nao foi possivel ler o arquivo " << NomeArquivo << endl;
		return 1;
	}

	//Não uso mais o arquivo. Fecho ele
	fclose(ArqTexto);

	//Atribuo o valor do meu padrao
	TipoPadrao Padrao;
	sprintf(Padrao, "%s", P);
	
	//Pego o tamanho do meu N e do meu M
	int N = strlen(Texto),
		M = strlen(Padrao);


	int NumComparacoes 		= 0,
		NumDeslocamentos	= 0;

	switch(Metodo) {
		case FORCA_BRUTA:

			ForcaBruta(Texto, N, Padrao, M, &NumComparacoes, &NumDeslocamentos);
			
			if(MostrarInfo)
				MostrarInformacoes(FORCA_BRUTA, NumComparacoes, NumDeslocamentos);

			break;
		case BM:

			Boyer_Moore(Texto, N, Padrao, M, &NumComparacoes, &NumDeslocamentos);

			if(MostrarInfo)
				MostrarInformacoes(BM, NumComparacoes, NumDeslocamentos);

			break;
		case BMHS:

			_BMHS_(Texto, N, Padrao, M, &NumComparacoes, &NumDeslocamentos);

			if(MostrarInfo)
				MostrarInformacoes(BMHS, NumComparacoes, NumDeslocamentos);

			break;
		case SHIFT_AND_EXATO:

			ShiftAndExato(Texto, N, Padrao, M, &NumComparacoes, &NumDeslocamentos);

			if(MostrarInfo)
				MostrarInformacoes(SHIFT_AND_EXATO, NumComparacoes, NumDeslocamentos);

			break;
		default:
			break;
	}

	return 0;
}