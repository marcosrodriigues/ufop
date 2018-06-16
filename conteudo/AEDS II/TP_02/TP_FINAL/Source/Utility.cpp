#include "Utility.h"

char* nameFile() {
	char *fileName;
	sprintf(fileName, "%s%s", FILE_NAME, FILE_EXT);
	return fileName;
}

FILE* openFile() {
	char fileName[50];
	sprintf(fileName, "%s%s", FILE_NAME, FILE_EXT);
	FILE *file = fopen(fileName, "r+b");

	if (file == NULL) {
		cout << "Arquivo não aberto" << endl;
		return NULL;
	}

	return file;
}

bool argumentsOk(int argc, char const *argv[]) {

	if (argc != 4 && argc != 5) return false;

	/* Atribuindo os parametros para as variáveis */
	int method	 	= atoi(argv[1]);
	int amount		= atoi(argv[2]);
	int situation	= atoi(argv[3]);
	bool showAll = (argc == 4);

	if (method < 1 || method > 3) return false;
	if (amount < MIN_REGISTER || amount > MAX_REGISTER) return false;
	if (situation < 1 || situation > 3) return false;

	return true;
}

double getTimeExecution(clock_t end, clock_t start) {
	clock_t clockTicksTaken = end - start;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	return timeInSeconds;
}

void showInfo(TRegistro reg, int nTransfer, int nCompare, double middle_search, double middle_mount, FILE *arqSaida) {
	
	cout << "REGISTRO ENCONTRADO NO ARQUIVO: " << endl;
	cout << "Chave...........: " << reg.matricula << endl;
	cout << "Nota............: " << reg.nota << endl;
	cout << "Estado..........: " << reg.estado << endl;
	cout << "Cidade..........: " << reg.cidade << endl;
	cout << "Curso...........: " << reg.curso << endl;
	cout << "Numero de transferencias (leitura) de itens da memoria externa e interna: " << nTransfer << endl;
	cout << "Numero de comparacoes entre chaves de pesquisa: " << nCompare << endl;
	cout << "Tempo de execucao da pesquisa: " << setprecision(6) << fixed << middle_search << " segundos" <<endl;
	cout << "Tempo de execucao da criacao: " << setprecision(6) << fixed << middle_mount << " segundos" <<endl;
	

	//fprintf(arqSaida, "REGISTRO ENCONTRADO..............: %d\nTransferencias...................: %d\nComparacoes......................: %d\nTempo Pesquisa...................: %.6f\nTempo Execucao...................: %.6f\n\n\n", reg.chave, nTransfer, nCompare, middle_search, middle_mount);

}
