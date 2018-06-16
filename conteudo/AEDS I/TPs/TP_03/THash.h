#define MAX_HASH 27
#define MAX_PESO 27
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

typedef struct Cidade {
	string uf;
	string nome;
	unsigned long populacao;
	float IDH;
}TCidade;

typedef struct No{
	TCidade cidade;
	struct No *pEsq, *pDir;
} TNo;

typedef TNo* TArvore;

typedef struct hash {
	int n; //numero de posicoes do hash;
	int nro_arvore; //tamanho do array de arvores
	int nro_pesos; //tamanho do array de pesos;
	int *p; //array de pesos;
	TArvore *raiz; //array de arvore
}THash;


//Hash com lista Encadeada
THash* THash_Inicia();
int THash_H(THash *hash, TCidade cidade);
int THash_Pesquisa(THash *hash, TCidade *cidade);
int THash_Insere(THash *hash, TCidade cidade);
int THash_Edita(THash *hash, TCidade cidade);
int THash_Excluir(THash *hash, TCidade cidade);
int THash_PesquisarTodos(THash hash);

//Arvore de Pesquisa
void TArvore_Inicia (TNo **raiz);
int TArvore_EhVazia(TNo **raiz);
TNo *TNo_Cria(TCidade cidade);
int TArvore_Pesquisa(TArvore pRaiz, TCidade *cidade);
int TArvore_Insere(TNo **ppR, TCidade cidade);
int TArvore_Edita(TNo **ppR, TCidade cidade);
int TArvore_Excluir(TNo **p, TCidade cidade);
void TArvore_Sucessor(TNo *noExcluido, TNo **proximo);
void TArvore_PesquisarTodosCentral(TNo *p);

//Funcoes do metodo Main
void TCidade_MostrarDados(TCidade cidade, bool uf);
string strToUpper(string str);
void cOut(string msg);