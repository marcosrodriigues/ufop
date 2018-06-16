#include "THash.h"
#include <stdlib.h>
using namespace std;

THash* THash_Inicia() {
	THash *hash = new THash;

	hash->n = 0;
	hash->nro_arvore = MAX_HASH;
	hash->nro_pesos = MAX_PESO;

	//inicializando as listas;
	hash->raiz = new TArvore[MAX_HASH];
	for (int i = 0; i < MAX_HASH; ++i)
		TArvore_Inicia(&hash->raiz[i]);

	hash->p = new int[MAX_PESO];
	for (int i = 0; i < MAX_PESO; ++i)
		hash->p[i] = rand() % 100000;

	return hash;
}

int THash_H(THash *hash, TCidade cidade) {
	int h = 0, len = cidade.uf.length();
	char character;
	if (len == 0) {
		return h;
	}

	for (int i = 0; i < len; i++) {
		character = cidade.uf.at(i);
		h = (31 * h) + (int)character;
	}

	return (h % hash->nro_arvore);
}

int THash_Pesquisa(THash *hash, TCidade *cidade) {
	int i = THash_H(hash, *cidade);
	
	if (TArvore_EhVazia(&hash->raiz[i]))
		return 0;

	return TArvore_Pesquisa(hash->raiz[i], cidade);
}

int THash_Insere(THash *hash, TCidade cidade) {
	int i = THash_H(hash, cidade);
	if(TArvore_Insere(&hash->raiz[i], cidade) == 1) {
		hash->n++;
		return 1;
	}
	return 0;
}

int THash_Edita(THash *hash, TCidade cidade) {
	int i = THash_H(hash, cidade);
	return TArvore_Edita(&hash->raiz[i], cidade);
}

int THash_Excluir(THash *hash, TCidade cidade) {
	int i = THash_H(hash, cidade);
	if (TArvore_Excluir(&hash->raiz[i], cidade) == 1) {
		hash->n--;
		return 1;
	}

	return 0;
}

int THash_PesquisarTodos(THash hash) {
	if(hash.n == 0)
		return 0;

	for(int i = 0; i < hash.nro_arvore; i++) {
		if (hash.raiz[i] == NULL) continue;

		cOut("DADOS DO ESTADO " + hash.raiz[i]->cidade.uf);
		TArvore_PesquisarTodosCentral(hash.raiz[i]);
	}

	return 1;
}

/* Arvore Binaria de Pesquisa */
void TArvore_Inicia (TNo **raiz) {
	*raiz = NULL;
}

int TArvore_EhVazia(TNo **raiz) {
	return (*raiz == NULL ? 1 : 0);
}

TNo *TNo_Cria(TCidade cidade) {
	TNo *pAux = new TNo;
	pAux->cidade = cidade;
	pAux->pEsq = NULL;
	pAux->pDir = NULL;
	return pAux;
}

int TArvore_Pesquisa(TArvore pRaiz, TCidade *cidade) {
	if (pRaiz == NULL)
		return 0;

	if (cidade->nome < pRaiz->cidade.nome)
		return TArvore_Pesquisa(pRaiz->pEsq, cidade);
	
	if (cidade->nome > pRaiz->cidade.nome)
		return TArvore_Pesquisa(pRaiz->pDir, cidade);

	*cidade = pRaiz->cidade;
	return 1;
}

int TArvore_Insere(TNo **ppR, TCidade cidade) {
	if (*ppR == NULL) {
		*ppR = TNo_Cria(cidade);
		return 1;
	}

	if (cidade.nome < (*ppR)->cidade.nome)
		return TArvore_Insere(&((*ppR)->pEsq), cidade);
	if (cidade.nome > (*ppR)->cidade.nome)
		return TArvore_Insere(&((*ppR)->pDir), cidade);

	return 0; //elemento ja existe
}

int TArvore_Edita(TNo **ppR, TCidade cidade) {
	if (*ppR == NULL)
		return 0;

	if (cidade.nome < (*ppR)->cidade.nome)
		return TArvore_Edita(&((*ppR)->pEsq), cidade);
	
	if (cidade.nome > (*ppR)->cidade.nome)
		return TArvore_Edita(&((*ppR)->pDir), cidade);

	(*ppR)->cidade = cidade;
	return 1;
}

int TArvore_Excluir(TNo **p, TCidade cidade) {
	if (*p == NULL)
		return 0;

	TNo *pAux;

	if (cidade.nome < (*p)->cidade.nome)
		return TArvore_Excluir(&((*p)->pEsq), cidade);
	else if (cidade.nome > (*p)->cidade.nome)
		return TArvore_Excluir(&((*p)->pDir), cidade);

	if((*p)->pEsq == NULL && (*p)->pDir == NULL) { //nao tem filho
		free(*p);
		*p = NULL;
		
	} else if ((*p)->pEsq != NULL && (*p)->pDir == NULL) { //tem filho a esquerda
		pAux = *p;
		*p = (*p)->pEsq;
		free(pAux);
	} else if ((*p)->pEsq == NULL && (*p)->pDir != NULL) { //tem filho a direita
		pAux = *p;
		*p = (*p)->pDir;
		free(pAux);
	} else {
		TArvore_Sucessor(*p, &((*p)->pDir));
	}

	return 1;

}

void TArvore_Sucessor(TNo *noExcluido, TNo **proximo) {
	if ((*proximo)->pEsq != NULL) {
		TArvore_Sucessor(noExcluido, &(*proximo)->pEsq);
		return;
	}

	TNo *pAux;

	noExcluido->cidade = (*proximo)->cidade;
	pAux = *proximo;
	*proximo = (*proximo)->pDir;
	free(pAux);
}

void TArvore_PesquisarTodosCentral(TNo *p) {
	if(p == NULL)
		return;

	TArvore_PesquisarTodosCentral(p->pEsq);
	TCidade_MostrarDados(p->cidade, false);
	cout << endl;
	TArvore_PesquisarTodosCentral(p->pDir);
}
/* Fim Arvore Binaria de Pesquisa */

/* Inicio das funcoes do Main */
void TCidade_MostrarDados(TCidade cidade, bool uf) {
	if(uf == true)
		cout << "UF: " << cidade.uf 					<< endl;

	cout << "Nome: " << cidade.nome 				<< endl;
	cout << "Populacao: " << cidade.populacao 		<< endl;
	cout << "IDH: " << cidade.IDH 					<< endl;
}

string strToUpper(string str) {
	for(int i = 0; i < str.size(); ++i)
		str[i] = toupper(str[i]);
	
	return str;
}

void cOut(string msg) {
	cout << "---- " << msg << " ----" << endl;
}
/* Fim das funcoes do main */