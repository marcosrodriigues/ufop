#include "Quicksort.h"

/*	FUNÇÕES PARA O QUICKSORT	*/
void QuicksortExterno (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, int *nTransferRead, int *nTransferWrite, int *nCompare) {
	int i, j;

	TArea Area;
	
	//Se a Direita tiver passado a Esquerda, significa que já terminou percorreu o arquivo todo
	if(Dir - Esq < 1)	return;

	//Inicializa a área
	FAVazia(&Area);
	Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j, nTransferRead, nTransferWrite, nCompare);

	if (i - Esq < Dir - j) {
		/*	Ordena primeiro o subarquivo menor	*/
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, nTransferRead, nTransferWrite, nCompare);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, nTransferRead, nTransferWrite, nCompare);
	} else {
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, nTransferRead, nTransferWrite, nCompare);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, nTransferRead, nTransferWrite, nCompare);
	}
}

void Particao (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TArea Area, int Esq, int Dir, int *i, int *j, int *nTransferRead, int *nTransferWrite, int *nCompare) {
	int Ls = Dir,
		Es = Dir,
		Li = Esq,
		Ei = Esq,
		NRArea = 0;
	
	float	Linf = FLT_MIN_EXP,
			Lsup = FLT_MAX_EXP;

	short OndeLer = true;
	TRegistro	UltLido,
				R;

	fseek (*ArqLi, (Li - 1) * sizeof(TRegistro), SEEK_SET);
	fseek (*ArqEi, (Ei - 1) * sizeof(TRegistro), SEEK_SET);

	*i = Esq - 1;
	*j = Dir + 1;

	while (Ls >= Li) {
		if (NRArea < TAM_AREA - 1) {

			OndeLer ? LeSup (ArqLEs, &UltLido, &Ls, &OndeLer, nTransferRead) : LeInf (ArqLi, &UltLido, &Li, &OndeLer, nTransferRead);

			InserirArea (&Area, &UltLido, &NRArea, nCompare);
			continue;
		}

		if (Ls == Es) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer, nTransferRead);
		else if (Li == Ei) LeInf (ArqLi, &UltLido, &Li, &OndeLer, nTransferRead);
		else if (OndeLer) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer, nTransferRead);
		else LeInf (ArqLi, &UltLido, &Li, &OndeLer, nTransferRead);

		(*nCompare)++;
		if (UltLido.nota > Lsup) {
			*j = Es;
			EscreveMax (ArqLEs, UltLido, &Es, nTransferWrite);
			continue;
		}

		(*nCompare)++;
		if (UltLido.nota < Linf) {
			*i = Ei;
			EscreveMin (ArqEi, UltLido, &Ei, nTransferWrite);
			continue;
		}

		InserirArea (&Area, &UltLido, &NRArea, nCompare);

		(*nCompare)++;
		if (Ei - Esq < Dir - Es) {	
			RetiraMin (&Area, &R, &NRArea);
			EscreveMin (ArqEi, R, &Ei, nTransferWrite);
			Linf = R.nota;

		} else {
			RetiraMax (&Area, &R, &NRArea);
			EscreveMax (ArqLEs, R, &Es, nTransferWrite);
			Lsup = R.nota;
		}


	}

	while (Ei <= Es) {
		RetiraMin (&Area, &R, &NRArea);
		EscreveMin (ArqEi, R, &Ei, nTransferWrite);
	}
}

void LeSup (FILE **ArqLEs, TRegistro *Registro, int *Ls, short *OndeLer, int *nTransferRead) {
	fseek(*ArqLEs, (*Ls - 1) * sizeof(TRegistro), SEEK_SET);
	fread(Registro, sizeof(TRegistro), 1, *ArqLEs);
	(*Ls)--;
	*OndeLer = false;
	(*nTransferRead)++;
}

void LeInf (FILE **ArqLi, TRegistro *Registro, int *Li, short *OndeLer, int *nTransferRead) {
	fread(Registro, sizeof(TRegistro), 1, *ArqLi);
	(*Li)++;
	*OndeLer = true;
	(*nTransferRead)++;
}

void InserirArea (TArea *Area, TRegistro *Registro, int *NRArea, int *nCompare) {
	/*	Insere o último dado lido de forma ORDENADA na Área	*/
	InsereItem (*Registro, Area, nCompare);
	*NRArea = ObterNumCelOcupadas(Area);
}

void EscreveMax (FILE **ArqLEs, TRegistro R, int *Es, int *nTransferWrite) {
	fseek(*ArqLEs, (*Es - 1) * sizeof(TRegistro), SEEK_SET);
	fwrite(&R, sizeof(TRegistro), 1, *ArqLEs);
	(*Es)--;
	(*nTransferWrite)++;
}

void EscreveMin (FILE **ArqEi, TRegistro R, int *Ei, int *nTransferWrite) {
	fwrite(&R, sizeof(TRegistro), 1, *ArqEi);
	(*Ei)++;
	(*nTransferWrite)++;
}

void RetiraMax (TArea *Area, TRegistro *R, int *NRArea) {
	RetiraUltimo(Area, R);
	*NRArea = ObterNumCelOcupadas(Area);
}

void RetiraMin (TArea *Area, TRegistro *R, int *NRArea) {
	RetiraPrimeiro(Area, R);
	*NRArea = ObterNumCelOcupadas(Area);
}

/*	FUNÇÕES PARA QUICKSORT EXTERNO DECRESCENTE	*/

void QuicksortExterno_Decrescente (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, int *nTransferRead, int *nTransferWrite, int *nCompare) {
	int i, j;

	TArea Area;
	
	//Se a Direita tiver passado a Esquerda, significa que já terminou percorreu o arquivo todo
	if(Dir - Esq < 1)	return;

	//Inicializa a área
	FAVazia(&Area);
	Particao_Decrescente(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j, nTransferRead, nTransferWrite, nCompare);

	if (i - Esq < Dir - j) {
		/*	Ordena primeiro o subarquivo menor	*/
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, nTransferRead, nTransferWrite, nCompare);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, nTransferRead, nTransferWrite, nCompare);
	} else {
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, nTransferRead, nTransferWrite, nCompare);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, nTransferRead, nTransferWrite, nCompare);
	}
}

void Particao_Decrescente (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TArea Area, int Esq, int Dir, int *i, int *j, int *nTransferRead, int *nTransferWrite, int *nCompare) {
	int Ls = Dir,
		Es = Dir,
		Li = Esq,
		Ei = Esq,
		NRArea = 0;

	float	Linf = FLT_MAX_EXP,
			Lsup = FLT_MIN_EXP;

	short OndeLer = true;
	TRegistro	UltLido,
				R;

	fseek (*ArqLi, (Li - 1) * sizeof(TRegistro), SEEK_SET);
	fseek (*ArqEi, (Ei - 1) * sizeof(TRegistro), SEEK_SET);

	*i = Esq - 1;
	*j = Dir + 1;

	while (Ls >= Li) {
		if (NRArea < TAM_AREA - 1) {

			OndeLer ? LeSup (ArqLEs, &UltLido, &Ls, &OndeLer, nTransferRead) : LeInf (ArqLi, &UltLido, &Li, &OndeLer, nTransferRead);

			InserirArea (&Area, &UltLido, &NRArea, nCompare);
			continue;
		}

		if (Ls == Es) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer, nTransferRead);
		else if (Li == Ei) LeInf (ArqLi, &UltLido, &Li, &OndeLer, nTransferRead);
		else if (OndeLer) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer, nTransferRead);
		else LeInf (ArqLi, &UltLido, &Li, &OndeLer, nTransferRead);

		(*nCompare)++;
		if (UltLido.nota < Lsup) {
			*j = Es;
			EscreveMax (ArqLEs, UltLido, &Es, nTransferWrite);
			continue;
		}

		(*nCompare)++;
		if (UltLido.nota > Linf) {
			*i = Ei;
			EscreveMin (ArqEi, UltLido, &Ei, nTransferWrite);
			continue;
		}

		InserirArea (&Area, &UltLido, &NRArea, nCompare);

		if (Ei - Esq < Dir - Es) {	
			RetiraMax (&Area, &R, &NRArea);
			EscreveMin (ArqEi, R, &Ei, nTransferWrite);
			Linf = R.nota;

		} else {
			RetiraMin (&Area, &R, &NRArea);
			EscreveMax (ArqLEs, R, &Es, nTransferWrite);
			Lsup = R.nota;
		}


	}

	while (Ei <= Es) {
		RetiraMax (&Area, &R, &NRArea);
		EscreveMin (ArqEi, R, &Ei, nTransferWrite);
	}
}

/*	FUNÇÕES PARA O AREA	*/
void FAVazia (TArea *Area) {
	Area->n = 0;

	TRegistro *reg = new TRegistro();

	for(int i = 0; i < TAM_AREA; i++) {
		Area->area[i] = *reg;
	}
}

void InsereItem (TRegistro Registro, TArea *Area, int *nCompare) {
	//Insere o item de forma ORDENADA

	if (Area->n == 0) {
		Area->area[0] = Registro;
		Area->n++;
		return;
	} 

	int i = 0;

	/*	
		Pegando a posição que eu irei inserir o item

		LÓGICA:
		Enquanto a nota a ser inserida for maior que a nota que está no vetor	
		E
		A posição do I estiver inferior ao (tamanho do vetor - 1)
	*/

	while (Registro.nota > Area->area[i].nota && i < Area->n) {
		i++;
		(*nCompare)++;
	}

	//Insere ordenadamente.
	Area->n++;
	for (int j = Area->n - 1; j >= i; j--) Area->area[j] = Area->area[j - 1];
	Area->area[i] = Registro;
}

void RetiraUltimo (TArea *Area, TRegistro *R) {
	*R = Area->area[Area->n - 1];
	Area->n--;
}

void RetiraPrimeiro (TArea *Area, TRegistro *R) {
	*R = Area->area[0];

	Area->n--;
	for (int i = 0; i < Area->n; i++) {
		Area->area[i] = Area->area[i + 1];
	}

}

int ObterNumCelOcupadas (TArea *Area) {
	return Area->n;
}