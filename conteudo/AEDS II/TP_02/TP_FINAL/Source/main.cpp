/*
	Execução do programa: pesquisa <metodo> <quantidade> <situacao> <chave> [-P]
		ordena:			nome do arquivo;
		<metodo>:		1 à 3, de acordo com os metodos implementados;
		<quantidade>:	quantidade de registros no arquivo;
		<situacao>:		1 (ordenado ascendente); 2 (ordenado descendente); 3 (desordenado aleartóriamente);
		<chave>:		Chave a ser pesquisada;
		[-P]:			Argumento opcional, representa que as chaves de pesquisa dos registros do arquivo apareçam na tela;

	Métodos:
		- INTERCALACAO_01:	1
		- INTERCALACAO_02:	2
		- QUICK_SORT:		3

	Situacao:
		- ORDENADO_CRESCENTE:		1
		- ORDENADO_DECRESCENTE:		2
		- ALEARTÒRIO:				3
*/

#include <chrono>

#include "Utility.h"
#include "Quicksort.h"
#include "Intercalacao_01.h"

using namespace std::chrono;

int main(int argc, char const *argv[]) {
	
	/*	Função que verifica os argumentos de entrada do sistema */
	if(!argumentsOk(argc, argv)) {
		cout << "Argumentos inválidos" << endl;
		return 1;
	}

	/* Atribuindo os parametros para as variáveis */
	int method	 	= atoi(argv[1]);
	int amount		= atoi(argv[2]);
	int situation	= atoi(argv[3]);
	bool showAll 	= (argc == 5);
	
	int nTransferRead = 0;
	int nTransferWrite = 0;
	int nCompare = 0;

	duration<double> time_span2;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	//Escolhendo o metodo que irá rodar no arquivo
	switch(method) {
		case INTERCALACAO_01:	
			if (situation == ORDEM_ASCE) {
				//Ordena Crescente

				FILE *arquivo 	= openFile();

				IntercalacaoBalanceada(arquivo, amount);

				/*FILE* arq = openFile();

				TRegistro R;
				fseek(arq, 0, SEEK_SET);
				int count = 1;
				while (fread(&R, sizeof(TRegistro), 1, arq) && count <= amount) {
					cout << R.nota << " - " << R.curso << endl;
					count++;
				}
				cout << endl;
*/

			} else if (situation == ORDEM_DESC) {
				//Ordena decrescente
			}

			break;
		case INTERCALACAO_02:
			if (situation == ORDEM_ASCE) {
				//Ordena Crescente

			} else if (situation == ORDEM_DESC) {
				//Ordena decrescente
			}

			break;
		case QUICK_SORT:
			if (situation == ORDEM_ASCE) {
				//Ordena Crescente

				FILE *ArqLEs 	= openFile();
				FILE *ArqEi		= openFile();
				FILE *ArqLi		= openFile();
				
				QuicksortExterno(&ArqLi, &ArqEi, &ArqLEs, 1, amount, &nTransferRead, &nTransferWrite, &nCompare);

				cout << "Leitura: " << nTransferRead << " - Escrita: " << nTransferWrite << " - Compare: " << nCompare << endl;

				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				duration<double> time_span = duration_cast<duration<double> >(t2 - t1);

				fflush(ArqLi);
				fclose(ArqEi); fclose(ArqLEs);

				if (showAll) {
					TRegistro R;
					fseek(ArqLi, 0, SEEK_SET);
					int count = 1;
					while (fread(&R, sizeof(TRegistro), 1, ArqLi) && count <= amount) {
						cout << R.nota << " - " << R.curso << endl;
						count++;
					}
					cout << endl;
					cout << "Tempo: " << time_span.count() << "ms" << endl;
				}

				fclose(ArqLi);

			} else if (situation == ORDEM_DESC) {
				//Ordena decrescente

				FILE *ArqLEs 	= openFile();
				FILE *ArqEi		= openFile();
				FILE *ArqLi		= openFile();
				
				QuicksortExterno_Decrescente(&ArqLi, &ArqEi, &ArqLEs, 1, amount, &nTransferRead, &nTransferWrite, &nCompare);

				cout << "Leitura: " << nTransferRead << " - Escrita: " << nTransferWrite << " - Compare: " << nCompare << endl;

				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				duration<double> time_span = duration_cast<duration<double> >(t2 - t1);

				fflush(ArqLi);
				fclose(ArqEi); fclose(ArqLEs);

				if (showAll) {
					TRegistro R;
					fseek(ArqLi, 0, SEEK_SET);
					int count = 1;
					while (fread(&R, sizeof(TRegistro), 1, ArqLi) && count <= amount) {
						cout << R.nota << " - " << R.curso << endl;
						count++;
					}
					cout << endl;
					cout << "Tempo: " << time_span.count() << "ms" << endl;

				}

				fclose(ArqLi);
			}

			break;
		default:
			break;
	}
	return 0;
}
