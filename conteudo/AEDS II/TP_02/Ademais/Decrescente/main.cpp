#include "Quicksort_Bin.h"
using namespace std;

int main(int argc, char const *argv[]) {
	
	FILE *ArqLEs, *ArqEi, *ArqLi;
	TRegistro R;		

	/*
	if ((ArqLi = fopen("PROVAO.BIN", "r+b")) == NULL) {
		cout << "Impossível abrir o arquivo" << endl;
		return 1;
	}

	if ((ArqEi = fopen("PROVAO.BIN", "r+b")) == NULL) {
		cout << "Impossível abrir o arquivo" << endl;
		return 1;
	}

	if ((ArqLEs = fopen("PROVAO.BIN", "r+b")) == NULL) {
		cout << "Impossível abrir o arquivo" << endl;
		return 1;
	}
	*/

	ArqLi = fopen("teste.dat", "wb");
	if (ArqLi == NULL) { cout << "Nao abriu" << endl; return 1; }
	R.matricula = 5; R.nota = 5; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 3; R.nota = 3; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 8; R.nota = 8; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 10; R.nota = 10; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 6; R.nota = 6; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 1; R.nota = 1; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 9; R.nota = 9; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 7; R.nota = 7; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 4; R.nota = 4; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	R.matricula = 2; R.nota = 2; fwrite(&R, sizeof(TRegistro), 1, ArqLi);
	fclose(ArqLi);

	if ((ArqLi = fopen("teste.dat", "r+b")) == NULL) {
		cout << "Impossível abrir o arquivo" << endl;
		return 1;
	}

	if ((ArqEi = fopen("teste.dat", "r+b")) == NULL) {
		cout << "Impossível abrir o arquivo" << endl;
		return 1;
	}

	if ((ArqLEs = fopen("teste.dat", "r+b")) == NULL) {
		cout << "Impossível abrir o arquivo" << endl;
		return 1;
	}

	QuicksortExterno(&ArqLi, &ArqEi, &ArqLEs, 1, MAX_REGISTRO);
	fflush(ArqLi);
	fclose(ArqEi); fclose(ArqLEs);
	fseek(ArqLi, 0, SEEK_SET);

	cout << " ================ TERMINOU O ALGORITMO ================" << endl;
	cout << "Arquivo: ";
	while (fread(&R, sizeof(TRegistro), 1, ArqLi)) {
		cout << R.matricula << " - ";
	} 

	getchar();
	fclose(ArqLi);

	return 0;
}