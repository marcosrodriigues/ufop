#include "Utility.h"

FILE* chooseFile(int situation) {
	char fileName[50];
	sprintf(fileName, "%s%d%s", FILE_NAME, situation, FILE_EXT);
	FILE *file = fopen(fileName, "r+b");

	if (file == NULL) {
		cout << "ERROR CODE 587X09KUJ, IMPOSSIBLE TO OPEN THE FILE" << endl;
		return NULL;
	}

	return file;
}

bool argumentsOk(int argc, char const *argv[]) {

	if (argc != 5 && argc != 6) return false;

	/* Atribuindo os parametros para as variáveis */
	int method	 	= atoi(argv[1]);
	int amount		= atoi(argv[2]);
	int situation	= atoi(argv[3]);
	int key			= atoi(argv[4]);
	//bool showAll = (argc == 6) ? true : false;

	if (method < 1 || method > 4) return false;
	if (amount < MIN_REGISTER || amount > MAX_REGISTER) return false;
	if (situation < 1 || situation > 3) return false;
	if (key < 0) return false;

	return true;
}

double getTimeExecution(clock_t end, clock_t start) {
	clock_t clockTicksTaken = end - start;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	return timeInSeconds;
}

void showInfo(TRegistro reg, int nTransfer, int nCompare, double middle_search, double middle_mount, FILE *arqSaida) {
	
	cout << "REGISTRO ENCONTRADO NO ARQUIVO: " << endl;
	cout << "Chave..........: " << reg.chave << endl;
	cout << "Dado 01........: " << reg.dado1 << endl;
	cout << "Dado 02........: " << reg.dado2 << endl;
	cout << "Numero de transferencias (leitura) de itens da memoria externa e interna: " << nTransfer << endl;
	cout << "Numero de comparacoes entre chaves de pesquisa: " << nCompare << endl;
	cout << "Tempo de execucao da pesquisa: " << setprecision(6) << fixed << middle_search << " segundos" <<endl;

	cout << "Tempo de execucao da criacao: " << setprecision(6) << fixed << middle_mount << " segundos" <<endl;
	

	//fprintf(arqSaida, "REGISTRO ENCONTRADO..............: %d\nTransferencias...................: %d\nComparacoes......................: %d\nTempo Pesquisa...................: %.6f\nTempo Execucao...................: %.6f\n\n\n", reg.chave, nTransfer, nCompare, middle_search, middle_mount);

}
