#include "arvoreBin.h"

void criaArvore(FILE* file, int amount, int *nTransfer, int *nCompare){
	FILE *arqArvore;
	TArvore auxArvore, auxAtualiza;
	TRegistro auxDados;
	bool raiz = true;
	int cont = 0, i, atualizaPonteiro, j = 0;
	
	if ((arqArvore = fopen("arvoreBinaria.bin","w+b")) == NULL) { 
		cout << "ERROR CODE 000x4T0F - Please check System Docs to understand what it means !" << endl;
		return;
	}
	
	while (fread(&auxDados, sizeof(TRegistro), 1, file) == 1 && j <= amount) {
		if (raiz){
			auxArvore.registro = auxDados;
			auxArvore.esq = -1;
			auxArvore.dir = -1;
			(*nTransfer)++;
			fwrite (&auxArvore, sizeof(TArvore), 1, arqArvore);
			cout << "Dado inserido: " << auxArvore.registro.chave <<  " - Direita: " << auxArvore.dir << " - Esquerda: " << auxArvore.esq << endl;
			raiz = false;
			cont++;
			
		}else{ //caso nao for raiz: preenche os dados e atualiza os ponteiros
			
			auxArvore.registro = auxDados;
			auxArvore.esq = -1;
			auxArvore.dir = -1;
			fwrite (&auxArvore, sizeof(TArvore), 1, arqArvore);
			cont++;
			i = 0;
			
			atualizaPonteiro = 1;
			while (atualizaPonteiro == 1){
				
				fseek (arqArvore, i*sizeof(TArvore), 0); //volta para o inicio do arquivo
				fread (&auxAtualiza, sizeof(TArvore), 1, arqArvore); //le os dados do inicio do arquivo
				
				if (auxAtualiza.registro.chave < auxArvore.registro.chave){
					
					if (auxArvore.esq == -1){ //verifica se tem filhos à esquerda
						auxArvore.esq = cont; //se nao tiver, atualiza
						
						fseek (arqArvore, i*sizeof(TArvore), 0); //como fread avança uma posição, tem que dar fseek de novo, pra voltar pra posicao que tem que alterar
						fwrite(&auxAtualiza, sizeof(TArvore), 1, arqArvore); //atualiza dir no arquivo
						
						atualizaPonteiro = 0;
					}
					else
						i = auxAtualiza.esq;
					
					fseek(arqArvore, cont*sizeof(TArvore), 0); //vai para a proxima chave do arquivo
				}
				
				else if (auxAtualiza.registro.chave > auxArvore.registro.chave){
					if (auxArvore.dir == -1){ //verifica se tem filhos à esquerda
						auxArvore.dir = cont; //se nao tiver, atualiza
							
						fseek(arqArvore, i*sizeof(TArvore), 0); //volta pro começo do arquivo
						fwrite(&auxAtualiza, sizeof(TArvore), 1, arqArvore); //atualiza esq no arquivo
						
						atualizaPonteiro = 0;
					}
					else	
						i = auxAtualiza.dir;
					
					fseek(arqArvore, cont*sizeof(TArvore), 0); //vai para a proxima chave do arquivo
				}

				cout << "AUXARVORE Dado inserido: " << auxArvore.registro.chave <<  " - Direita: " << auxArvore.dir << " - Esquerda: " << auxArvore.esq << endl;
				cout << "AUXATUALIZA Dado inserido: " << auxAtualiza.registro.chave <<  " - Direita: " << auxAtualiza.dir << " - Esquerda: " << auxAtualiza	.esq << endl;
					
			}

		}
		
		j++;
		
		
	}
	fclose(arqArvore);
}

void pesquisaArvore(TRegistro *reg, int key, int *nTransfer, int *nCompare) {
	FILE *arqArvoreBusca;
	TArvore arvoreBusca;
	
	if ((arqArvoreBusca = fopen("arvoreBinaria.bin","rb")) == NULL) { 
		cout << "ERROR CODE 000x4T0F - Please check System Docs to understand what it means !" << endl;;
	}
	
	rewind(arqArvoreBusca); //vai para o começo do arquivo
	
	while (true) {
		(*nCompare)++;
		fread(&arvoreBusca, sizeof(TArvore), 1, arqArvoreBusca);
		//se for igual a raiz, retorna
		if (arvoreBusca.registro.chave == key){
			*reg = arvoreBusca.registro;
			fclose(arqArvoreBusca);
			return;
		}else if (arvoreBusca.registro.chave < key){ //verifica se a chave procurada é maior que a chave da posição atual
			
			if (arvoreBusca.dir == -1){
				fclose(arqArvoreBusca);
				return;
			}
			
			fseek(arqArvoreBusca, sizeof(TArvore)*(arvoreBusca.dir), 0);
		}else if (arvoreBusca.registro.chave > key){ //verifica se a chave procurada é menor que a chave da posição atual
			
			if (arvoreBusca.esq == -1){
				fclose(arqArvoreBusca);
				return;
			}
			
			fseek(arqArvoreBusca, sizeof(TArvore)*(arvoreBusca.esq), 0);
		}
	}
}
