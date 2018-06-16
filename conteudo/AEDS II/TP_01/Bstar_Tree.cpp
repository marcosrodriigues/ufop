#include "BStar_Tree.h"

void New_BStar (TipoApontadorEstrela *Tree) {
	Tree = NULL;
}

void Search_BStar(TRegistro *x, TipoApontadorEstrela *Ap, int key, int *nTransfer, int *nCompare) {

	if ((*Ap) == NULL) {
		printf("TipoRegistro nao esta presente na arvore\n");
		return;
	}

	int i;
  	TipoApontadorEstrela Pag;
  	Pag = *Ap;

  	cout << (*Ap)->PT << endl;

  	if ((*Ap)->PT == INTERNA) {
  		i = 1;
    	while (i < Pag->UU.U0.ni && key > Pag->UU.U0.ri[i - 1].chave) i++;
    	
    	if (key < Pag->UU.U0.ri[i - 1].chave) Search_BStar(x, &Pag->UU.U0.pi[i - 1], key, nTransfer,  nCompare);
    	else Search_BStar(x, &Pag->UU.U0.pi[i], key, nTransfer, nCompare); 

    	return;
  	}

  	i = 1;
  
  	while (i < Pag->UU.U1.ne && key > Pag->UU.U1.re[i - 1].chave) i++;
	
//	cout << "Chave que existe: " << Pag->UU.U1.re[i - 1].chave;

  	if (key == Pag->UU.U1.re[i - 1].chave) *x = Pag->UU.U1.re[i - 1];
  	else printf("TipoRegistro nao esta presente na arvore\n");
}

void Mount_BStar (FILE* file, int amount, TipoApontadorEstrela* Tree) {
	TRegistro reg;
	int cont = 0;
	while ((fread(&reg, sizeof(reg), 1, file) == 1) && cont < amount) {
		Insert_Star(reg, Tree);
		cont++;
	}
}


void Ins_Star (TRegistro reg, TipoApontadorEstrela Ap, short *Cresceu, TRegistro *RegRetorno, TipoApontadorEstrela *ApRetorno) {
	long i = 1;
	long j;
	TipoApontadorEstrela ApTemp;
	if (Ap == NULL) {
		*Cresceu = true;
		(*RegRetorno) = reg;
		(*ApRetorno) = NULL;
		return;
	}
	while (i < Ap->UU.U0.ni && reg.chave > Ap->UU.U0.ri[i - 1].chave) i++;
	
	if (reg.chave == Ap->UU.U0.ri[i - 1].chave) {  
		//printf("ERRO: Registro já existente\n");
		InsertInPage_Star (Ap, *RegRetorno, *ApRetorno);
		*Cresceu = false; 
		Ap->PT = INTERNA;
		return; 
	}

	if (reg.chave < Ap->UU.U0.ri[i - 1].chave) i--;
	Ins_Star (reg, Ap->UU.U0.pi[i], Cresceu, RegRetorno, ApRetorno);
	if (!*Cresceu) return;
	if (Ap->UU.U0.ni < MM) { /* Página tem Espaço */
		InsertInPage_Star (Ap, *RegRetorno, *ApRetorno);
		*Cresceu = false;
		return;
	}

	/* Overflow: Página tem que ser dividida */
	ApTemp = (TipoApontadorEstrela)malloc(sizeof(TipoPaginaEstrela));
	ApTemp->UU.U0.ni = 0;
	ApTemp->UU.U0.pi[0] = NULL;

	if (i < M + 1) {

		InsertInPage_Star(ApTemp, Ap->UU.U0.ri[MM - 1], Ap->UU.U0.pi[MM]);
		Ap->UU.U0.ni--;
		InsertInPage_Star(Ap, *RegRetorno, *ApRetorno);
	} else InsertInPage_Star(ApTemp, *RegRetorno, *ApRetorno);
		
	for (j = M + 2; j <= MM; j++) InsertInPage_Star(ApTemp, Ap->UU.U0.ri[j - 1], Ap->UU.U0.pi[j]);

	Ap->UU.U0.ni = M;
	ApTemp->UU.U0.pi[0] = Ap->UU.U0.pi[M + 1];
	//*RegRetorno = Ap->UU.U0.ri[M];
	*ApRetorno = ApTemp;
}

void Insert_Star (TRegistro reg, TipoApontadorEstrela *Ap) {
	short Cresceu;
	TRegistro RegRetorno;
	TipoPaginaEstrela *ApRetorno, *ApTemp;
	Ins_Star (reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);
	
	if (Cresceu) { /* Arvore cresce na altura pela raiz */
		ApTemp = (TipoPaginaEstrela*)malloc(sizeof(TipoPaginaEstrela));
		ApTemp->UU.U1.ne = 1;
		ApTemp->UU.U1.re[0] = RegRetorno;
		ApTemp->UU.U0.pi[1] = ApRetorno;
		ApTemp->UU.U0.pi[0] = *Ap;
		*Ap = ApTemp;

	}

	escreverValor(Ap);
	
}

void InsertInPage_Star (TipoApontadorEstrela Ap, TRegistro Reg, TipoApontadorEstrela ApDir) {
	int k = Ap->UU.U1.ne;
	short NaoAchouPosicao = (k > 0);

	while(NaoAchouPosicao) {
		if (Reg.chave >= Ap->UU.U1.re[k - 1].chave) { NaoAchouPosicao = false; break; }
		Ap->UU.U1.re[k] = Ap->UU.U1.re[k - 1];
		Ap->UU.U0.pi[k + 1] = Ap->UU.U0.pi[k];
		k--;	
		if (k < 1) NaoAchouPosicao = false;
	}

	Ap->UU.U1.re[k] = Reg;
	Ap->UU.U0.pi[k + 1] = ApDir;
	Ap->UU.U1.ne++;
	//Ap->PT = EXTERNA;

}

void escreverValor(TipoApontadorEstrela *Ap) {
	if ((*Ap)->PT == INTERNA) {
		for (int i = 0; i < (*Ap)->UU.U0.ni; ++i) {
			cout << "PT: " << (*Ap)->PT << " -- Codigo: " << (*Ap)->UU.U0.ri[i].chave << endl;
		}
	} else {
		for (int i = 0; i < (*Ap)->UU.U1.ne; ++i) {
			cout << "PT: " << (*Ap)->PT << " -- Codigo: " << (*Ap)->UU.U1.re[i].chave << endl;
		}
	}
}
