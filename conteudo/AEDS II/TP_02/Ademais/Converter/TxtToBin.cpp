#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct {
	long matricula;
	float nota;
	char estado[3];
	char cidade[51];
	char curso[31];
}TRegistro;

int main(int argc, char const *argv[]) {
	
	FILE *txt, *bin;
	if ((txt = fopen("PROVAO.TXT", "r")) == NULL) {
		cout << "Impossível abrir o arquivo" << endl;
		return 1;
	}

	if ((bin = fopen("PROVAO.BIN", "w+b")) == NULL) {
		cout << "Impossível abrir o arquivo" << endl;
		return 1;	
	}

	TRegistro reg;
	while (fscanf(txt, "%ld %f %2[A-Z a-z] %50[^*] %30[^*]", &reg.matricula, &reg.nota, reg.estado, reg.cidade, reg.curso) != EOF) {
		/*cout << "Matricula: " << reg.matricula << endl;
		cout << "Nota: " << reg.nota << endl;
		cout << "Estado: " << reg.estado << endl;
		cout << "Cidade: " << reg.cidade << endl;
		cout << "Curso: " << reg.curso << endl;
		cout << endl;*/
		fwrite(&reg, sizeof(TRegistro), 1, bin);
		//getchar();
	}

	return 0;
}