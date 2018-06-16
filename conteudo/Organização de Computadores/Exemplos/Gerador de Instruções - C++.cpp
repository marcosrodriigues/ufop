#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

#define TAM_FOR 300
#define TAM_MEM 16384
#define NUM_INS 10000
#define PROP_FOR 60 //Probabiidade de ocorrência do laço de repetição, um numero entre 1 e 100;

int main() {
	int i, j, k, aleatorio;
	srand(time(NULL));
	
	//Arquivo onde será salvo as instruções;
	FILE *arquivo=fopen("programa.txt", "w");
	if (arquivo==NULL) {
		cout << "Erro ao abrir arquivo!" << endl;
		return 0;
	}
	
	//N é o numero de instruções;
	int N=5;
	//instruc é o vetor que conta quantos parametros tem cada instrução;
	int instruc[]={1, 2, 3, 4, 5};//Instruções numeradas de 0 a N-1;
	
	//Gerando o laço de repetição do programa;
	vector< vector <int> > For;
	for (i=0; i<TAM_FOR; i++) {
		vector <int> aux;
		aleatorio=rand()%N;
		aux.push_back(aleatorio);
		for (j=0; j<instruc[aleatorio]; j++)
			aux.push_back(rand()%TAM_MEM);
		For.push_back(aux);
	}
	
	for (i=0; i<NUM_INS;) {
		aleatorio=rand()%100+1;
		if (aleatorio<=PROP_FOR) {
			for (j=0; j<TAM_FOR && i<NUM_INS; j++, i++) {
				fprintf(arquivo, "%d", For[j][0]);
				for (k=1; k<=instruc[For[j][0]]; k++)
					fprintf(arquivo, " %d", For[j][k]);
				fprintf(arquivo, "\n");
			}
		}
		else {
			i++;
			aleatorio=rand()%N;
			fprintf(arquivo, "%d", aleatorio);
			for (k=0; k<instruc[aleatorio]; k++)
				fprintf(arquivo, " %d", rand()%TAM_MEM);
			fprintf(arquivo, "\n");
		}
	}
	
	fclose(arquivo);
	return 0;
}