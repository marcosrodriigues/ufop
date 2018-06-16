#include "Include.h"
#include "Quicksort_Texto.h"
using namespace std;

int main(int argc, char const *argv[]) {
	
	fstream ArqLEs ("PROVAO.TXT", fstream::in | fstream::out | ifstream::binary);
	fstream ArqLi ("PROVAO.TXT", fstream::in | fstream::out | ifstream::binary);
	fstream ArqLe ("PROVAO.TXT", fstream::in | fstream::out | ifstream::binary);

	if (ArqLEs && ArqLi && ArqLe) {
		QuicksortExterno(ArqLi, ArqLe, ArqLEs, 1, MAX_REGISTRO);
		
/*
		is.seekg(0, is.end);
		//int length = is.tellg();
		int length = 101;
		is.seekg(4 * length, is.beg);

		//memoria alocada
		char *buffer = new char[length];

		is.read (buffer, length);
		cout.write(buffer, length);
		is.read (buffer, length);
		cout.write(buffer, length);

		is.close();

		delete [] buffer;
		*/
	} else {
		cout << "nao passou na leitura" << endl;
	}
	return 0;
}