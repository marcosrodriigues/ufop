#include "B_Tree.h"

void New_Tree (TipoApontador *Tree) {
	Tree = NULL;
}

void Search_Tree (TRegistro *reg, TipoApontador Ap, int key, int *nTransfer, int *nCompare) {
	long i = 1;

	if (Ap == NULL) {
		return;
	}
	
	while (i < Ap->n && key > Ap->r[i - 1].chave) {
		(*nCompare)++;
		i++;
	}

	(*nCompare)++;
	if (key == Ap->r[i - 1].chave) {
		*reg = Ap->r[i - 1];
		return;
	}
	
	(*nCompare)++;
	if (key < Ap->r[i - 1].chave) Search_Tree(reg, Ap->p[i - 1], key, nTransfer,  nCompare);
	else Search_Tree (reg, Ap->p[i], key, nTransfer, nCompare);
}

void Ins_Tree (TRegistro reg, TipoApontador Ap, short *Cresceu, TRegistro *RegRetorno, TipoApontador *ApRetorno) {
	long i = 1;
	long j;
	TipoApontador ApTemp;

	if (Ap == NULL) {
		*Cresceu = true;
		(*RegRetorno) = reg;
		(*ApRetorno) = NULL;
		return;
	}

	while (i < Ap->n && reg.chave > Ap->r[i - 1].chave) i++;
	
	if (reg.chave == Ap->r[i - 1].chave) { /* printf("ERRO: Registro já existente\n"); */ *Cresceu = false; return; }
	if (reg.chave < Ap->r[i - 1].chave) i--;
	Ins_Tree (reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);
	if (!*Cresceu) return;
	if (Ap->n < MM) { /* Página tem Espaço */
		InsertInPage_Tree (Ap, *RegRetorno, *ApRetorno);
		*Cresceu = false;
		return;
	}
	/* Overflow: Página tem que ser dividida */
	ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
	ApTemp->n = 0;
	ApTemp->p[0] = NULL;

	if (i < M + 1) {
		InsertInPage_Tree(ApTemp, Ap->r[MM - 1], Ap->p[MM]);
		Ap->n--;
		InsertInPage_Tree(Ap, *RegRetorno, *ApRetorno);
	} else InsertInPage_Tree(ApTemp, *RegRetorno, *ApRetorno);
		
	for (j = M + 2; j <= MM; j++) InsertInPage_Tree(ApTemp, Ap->r[j - 1], Ap->p[j]);

	Ap->n = M;
	ApTemp->p[0] = Ap->p[M + 1];
	*RegRetorno = Ap->r[M];
	*ApRetorno = ApTemp;
}

void Insert_Tree (TRegistro reg, TipoApontador *Ap) {
	short Cresceu;
	TRegistro RegRetorno;
	TipoPagina *ApRetorno, *ApTemp;
	Ins_Tree (reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);

	if (Cresceu) { /* Arvore cresce na altura pela raiz */
		ApTemp = (TipoPagina*)malloc(sizeof(TipoPagina));
		ApTemp->n = 1;
		ApTemp->r[0] = RegRetorno;
		ApTemp->p[1] = ApRetorno;
		ApTemp->p[0] = *Ap;
		*Ap = ApTemp;
	}
}

void InsertInPage_Tree (TipoApontador Ap, TRegistro Reg, TipoApontador ApDir) {
	int k = Ap->n;
	short NaoAchouPosicao = (k > 0);

	while(NaoAchouPosicao) {
		if (Reg.chave >= Ap->r[k - 1].chave) { NaoAchouPosicao = false; break; }
		Ap->r[k] = Ap->r[k - 1];
		Ap->p[k + 1] = Ap->p[k];
		k--;	
		if (k < 1) NaoAchouPosicao = false;
	}

	Ap->r[k] = Reg;
	Ap->p[k + 1] = ApDir;
	Ap->n++;

}

void Mount_Tree (FILE* file, int amount, TipoApontador* Tree) {
	TRegistro reg;
	int cont = 0;
	while ((fread(&reg, sizeof(reg), 1, file) == 1) && cont < amount) {
		Insert_Tree(reg, Tree);
		//cout << "REGISTRO CADASTRADO: " << reg.chave << " UHUULLL !! " << endl;
		cont++;
	}
}
