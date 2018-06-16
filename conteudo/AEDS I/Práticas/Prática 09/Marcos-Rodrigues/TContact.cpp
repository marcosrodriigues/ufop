#include "TContact.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

TDictionary* newDictionary(int n) {
    TDictionary *dict = new TDictionary;
    dict->n = 0;
    dict->max = n; 
    dict->contact = new TContact[n];

    return dict;
}

void insertDictionary(TDictionary *dict, TContact contact) {
	if (dict->n == (dict->max)){
		dict->max *= 2;
		dict->contact = (TContact*)realloc(dict->contact,sizeof(TContact) * dict->max);
	}

	dict->contact[dict->n++] = contact;
}

int searchSequential(TDictionary *dict, long phone, int *compare) {
	*compare = 0;
	for (int i = 0; i < dict->n - 1; ++i) {
		(*compare)++;
		if (dict->contact[i].phone == phone) 
			return i;
	}
	return -1;
}

int searchBinary(TDictionary *dict, long phone, int *compare) {
	(*compare)++;
	if (dict->n == 0)	
		return -1;

	int left = 0;
	int right = dict->max - 1;
	int middle;

	do {
		middle = (left + right) / 2;
		(*compare)++; //sum just one if, because it's compare just the if, the else always happen if 'if' doesn't it, so, it isn't a new compare
		if (phone > dict->contact[middle].phone) left = middle + 1;
		else right = middle - 1;
		*compare = *compare + 2; //sum two more compare, one for first comparation and another one for the other
	} while (phone != dict->contact[middle].phone && left <= right);

	(*compare)++;
	if (dict->contact[middle].phone == phone) return middle;

	return -1;
}


/* Arvore Binaria de Pesquisa */
void TArvore_Inicia (TNo **raiz) {
	*raiz = NULL;
}

TNo *TNo_Cria(TContact contact) {
	TNo *pAux = new TNo;
	pAux->contact = contact;
	pAux->pEsq = NULL;
	pAux->pDir = NULL;
	return pAux;
}

int TArvore_Pesquisa(TArvore pRaiz, long phone, TContact *contact, int *totalCompare) {
	(*totalCompare)++;
	if (pRaiz == NULL)
		return 0;

	(*totalCompare)++;
	if (phone < pRaiz->contact.phone)
		return TArvore_Pesquisa(pRaiz->pEsq, phone, contact, totalCompare);
	
	(*totalCompare)++;
	if (phone > pRaiz->contact.phone)
		return TArvore_Pesquisa(pRaiz->pDir, phone, contact, totalCompare);

	*contact = pRaiz->contact;
	return 1;
}

int TArvore_Insere(TNo **ppR, TContact contact) {
	if (*ppR == NULL) {
		*ppR = TNo_Cria(contact);
		return 1;
	}

	if (contact.phone < (*ppR)->contact.phone)
		return TArvore_Insere(&((*ppR)->pEsq), contact);
	if (contact.phone > (*ppR)->contact.phone)
		return TArvore_Insere(&((*ppR)->pDir), contact);

	return 0; //elemento ja existe
}

int TArvore_Retira (TNo **p, TContact cont) {
	TNo *pAux;

	if (*p == NULL)	return 0;

	if (cont.phone < (*p)->contact.phone)
		return TArvore_Retira(&((*p)->pEsq), cont);

	if (cont.phone > (*p)->contact.phone)
		return TArvore_Retira(&((*p)->pDir), cont);

	if ((*p)->pEsq == NULL && (*p)->pDir == NULL) { // no eh folha
		free(*p);
		*p = NULL;
		return 1;
	}

	if ((*p)->pEsq != NULL && (*p)->pDir == NULL) { // possui subarvores à esquerda
		//Duvida aki... se eu estou apontando o *p para pAux, quando eu der o free(pAux), pq eu nao deletarei o *p, se está referenciado com o msm endereço de memoria
		pAux = *p;
		*p = (*p)->pEsq;
		free(pAux);
		return 1;
	}

	if ((*p)->pEsq == NULL && (*p)->pDir != NULL) { // possui subarvores à direita
		pAux = *p;
		*p = (*p)->pDir;
		free(pAux);
		return 1;
	}

	//No possui os dois filhos
	TArvore_Sucessor(*p, &((*p)->pDir));

	return 1;
}

void TArvore_Sucessor(TNo *q, TNo **r) {
	TNo *pAux;

	if ((*r)->pEsq != NULL) {
		TArvore_Sucessor(q, &(*r)->pEsq);
		return;
	}

	q->contact = (*r)->contact;
	pAux = *r;
	*r = (*r)->pDir;
	free(pAux);
	return;
}

/* Fim Arvore Binaria de Pesquisa */


/* Arvore AVL */
int FB(TNo *pRaiz) {
	if (pRaiz == NULL)
		return 0;

	return Altura(pRaiz->pEsq) - Altura(pRaiz->pDir);
}

int Altura(TNo *pRaiz) {
	if (pRaiz == NULL)	return 0;

	int iEsq, iDir;

	iEsq = Altura(pRaiz->pEsq);
	iDir = Altura(pRaiz->pDir);

	return (iEsq > iDir ? iEsq + 1 : iDir + 1);
}

void RSE (TNo **ppRaiz) {
	TNo *pAux;
	pAux = (*ppRaiz)->pDir;
	(*ppRaiz)->pDir = pAux->pEsq;
	pAux->pEsq = (*ppRaiz);
	(*ppRaiz) = pAux;
}

void RSD(TNo **ppRaiz) {
	TNo *pAux;
	pAux = (*ppRaiz)->pEsq;
	(*ppRaiz)->pEsq = pAux->pDir;
	pAux->pDir = (*ppRaiz);
	(*ppRaiz) = pAux;
}

int BalancaEsquerda(TNo **ppRaiz) {
	int fbe = FB((*ppRaiz)->pEsq);

	if (fbe > 0) {
		RSD(ppRaiz);
		return 1;
	} else if (fbe < 0) { // Rotação dupla direita
		RSE(&((*ppRaiz)->pEsq));
		RSD(ppRaiz); /*&(*ppRaiz) <- não entendi*/
		return 1;
	}

	return 0;
}

int BalancaDireita(TNo **ppRaiz) {
	int fbd = FB((*ppRaiz)->pDir);

	if (fbd < 0) {
		RSE(ppRaiz);
		return 1;
	} else if (fbd > 0) { // Rotação Dupla Esquerda
		RSD(&((*ppRaiz)->pDir));
		RSE(ppRaiz); /*&(*ppRaiz) <- não entendi*/
		return 1;
	}

	return 0;
}

int Balanceamento(TNo **ppRaiz) {
	int fb = FB(*ppRaiz);
	if (fb > 1)
		return BalancaEsquerda(ppRaiz);
	else if (fb < -1)
		return BalancaDireita(ppRaiz);
	else
		return 0;
}

int Insere(TNo **ppRaiz, TContact *contact) {
	if (*ppRaiz == NULL) {
		*ppRaiz = new TNo;
		(*ppRaiz)->contact = *contact;
		(*ppRaiz)->pEsq = NULL;
		(*ppRaiz)->pDir = NULL;
		return 1;
	} else if ((*ppRaiz)->contact.phone > contact->phone) {
		if (Insere(&(*ppRaiz)->pEsq, contact)) {
			if (Balanceamento(ppRaiz)) { /*por que retorna 0 se o balanceamento der certo ?*/
				return 0;
			} else {
				return 1;
			}
		}
	} else if ((*ppRaiz)->contact.phone < contact->phone) {
		if (Insere(&(*ppRaiz)->pDir, contact)) {
			if (Balanceamento(ppRaiz)) { /*por que retorna 0 se o balanceamento der certo ?*/
				return 0;
			} else {
				return 1;
			}
		}
	}

	return 0; /*valor ja presente*/
}

int Remove(TNo **ppRaiz, TContact *contact) {
	if (*ppRaiz == NULL)	return 0;

	if ((*ppRaiz)->contact.phone == contact->phone) {
		*contact = (*ppRaiz)->contact;
		//Antecessor(ppRaiz, &((*ppRaiz)->pEsq);
		Balanceamento(ppRaiz);
	} else if ((*ppRaiz)->contact.phone > contact->phone) {
		if (Remove(&(*ppRaiz)->pEsq, contact)) {
			Balanceamento(ppRaiz);
			return 1;
		}
	} else {
		if (Remove(&(*ppRaiz)->pDir, contact)) {
			Balanceamento(ppRaiz);
			return 1;
		}
	}

	return 0;
}

int EhArvoreAVL(TNo *pRaiz) {
	if (pRaiz == NULL)	return 0;

	int fb;

	if (!EhArvoreAVL(pRaiz->pEsq))	return 0;
	if (!EhArvoreAVL(pRaiz->pDir))	return 0;

	fb = FB(pRaiz);

	return (((fb > 1) || (fb < -1)) ? 0 : 1);
}
/* Fim Arvore AVL */