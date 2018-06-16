#include <string>
using namespace std;

typedef struct Contact {
	string name;
	int birthday;
	long phone;
} TContact;

typedef struct Dictionary{
	TContact *contact;
	int n, max;
} TDictionary;

/* Arvore Binaria de Pesquisa */
typedef struct No{
	TContact contact;
	struct No *pEsq, *pDir;
} TNo;

typedef TNo* TArvore;
typedef TNo* TArvoreAVL;
/* Fim Arvore Binaria de Pesquisa */

TDictionary* newDictionary(int n);
void insertDictionary(TDictionary *dict, TContact contact);
int searchSequential(TDictionary *dict, long phone, int *compare);
int searchBinary(TDictionary *dict, long phone, int *compare);
int insideSearchBinary(TDictionary *dict, long phone, int *compare);

/* Arvore Binaria de Pesquisa */
void TArvore_Inicia (TNo **raiz);
TNo *TNo_Cria(TContact contact);
int TArvore_Pesquisa(TArvore pRaiz, long phone, TContact *contact, int *totalCompare);
int TArvore_Insere(TNo **ppR, TContact contact);
int TArvore_Retira (TNo **p, TContact cont);
void TArvore_Sucessor(TNo *q, TNo **r);
/* Fim Arvore Binaria de Pesquisa */

/* Arvore AVL */
int FB(TNo *pRaiz);
int Altura(TNo *pRaiz);
void RSE (TNo **ppRaiz);
void RSD(TNo **ppRaiz);
int BalancaEsquerda(TNo **ppRaiz);
int BalancaDireita(TNo **ppRaiz);
int Balanceamento(TNo **ppRaiz);
int Insere(TNo **ppRaiz, TContact *contact);
int Remove(TNo **ppRaiz, TContact *contact);
int EhArvoreAVL(TNo *pRaiz);
/* Fim Arvore AVL */