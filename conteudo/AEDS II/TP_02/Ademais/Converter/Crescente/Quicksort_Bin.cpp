#include "Quicksort_Bin.h"

/*	FUNÇÕES PARA O QUICKSORT	*/
void QuicksortExterno (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir) {
	int i, j;

	TArea Area;
	
	//Se a Direita tiver passado a Esquerda, significa que já terminou percorreu o arquivo todo
	if(Dir - Esq < 1)	return;

	//Inicializa a área
	FAVazia(&Area);
	Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j);

	cout << "======== TERMINOU A PRIMEIRA PARTICAO: ========" << endl;
	cout << "Arquivo: " << endl;
	TRegistro R;
	while (fread(&R, sizeof(TRegistro), 1, *ArqLi)) {
		cout << R.nota << " - ";
	} 
	getchar();

	if (i - Esq < Dir - j) {
		/*	Ordena primeiro o subarquivo menor	*/
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
	} else {
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
	}
}

void Particao (FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TArea Area, int Esq, int Dir, int *i, int *j) {
	int Ls = Dir,
		Es = Dir,
		Li = Esq,
		Ei = Esq,
		NRArea = 0,
		Linf = INT_MIN,
		Lsup = INT_MAX;

	short OndeLer = true;
	TRegistro	UltLido,
				R;

	fseek (*ArqLi, (Li - 1) * sizeof(TRegistro), SEEK_SET);
	fseek (*ArqEi, (Ei - 1) * sizeof(TRegistro), SEEK_SET);

	*i = Esq - 1;
	*j = Dir + 1;

	while (Ls >= Li) {
		/*cout << "Condição: " << (Ls >= Li) << endl;
		cout << "I: " << *i << endl;
		cout << "Li: " << Li << endl;
		cout << "Ei: " << Ei << endl;
		cout << "Ls: " << Ls << endl;
		cout << "Es: " << Es << endl;
		cout << "J: " << *j << endl;
		cout << "NRArea: " << NRArea << endl;
		cout << "TAM_AREA: " << TAM_AREA << endl;
		ExibirArea(&Area);
		cout << "LInf: " << Linf << endl;
		cout << "Lsup: " << Lsup << endl;
		cout << "OndeLer " << OndeLer << endl;
		cout << endl;
		getchar();
		*/

		if (NRArea < TAM_AREA - 1) {

			OndeLer ? LeSup (ArqLEs, &UltLido, &Ls, &OndeLer) : LeInf (ArqLi, &UltLido, &Li, &OndeLer);

			InserirArea (&Area, &UltLido, &NRArea);
			continue;
		}

		if (Ls == Es) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer);
		else if (Li == Ei) LeInf (ArqLi, &UltLido, &Li, &OndeLer);
		else if (OndeLer) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer);
		else LeInf (ArqLi, &UltLido, &Li, &OndeLer);

		if (UltLido.nota > Lsup) {
			*j = Es;
			EscreveMax (ArqLEs, UltLido, &Es);
			continue;
		}

		if (UltLido.nota < Linf) {
			*i = Ei;
			EscreveMin (ArqEi, UltLido, &Ei);
			continue;
		}

		InserirArea (&Area, &UltLido, &NRArea);

		if (Ei - Esq < Dir - Es) {	
			RetiraMin (&Area, &R, &NRArea);
			EscreveMin (ArqEi, R, &Ei);
			Linf = R.nota;

		} else {
			RetiraMax (&Area, &R, &NRArea);
			EscreveMax (ArqLEs, R, &Es);
			Lsup = R.nota;
		}


	}

	/*cout << "Ls >= Li: " << endl;
	cout << "I: " << *i << endl;
	cout << "Li: " << Li << endl;
	cout << "Ei: " << Ei << endl;
	cout << "Ls: " << Ls << endl;
	cout << "Es: " << Es << endl;
	cout << "J: " << *j << endl;
	cout << "NRArea: " << NRArea << endl;
	cout << "TAM_AREA: " << TAM_AREA << endl;
	ExibirArea(&Area);
	cout << "LInf: " << Linf << endl;
	cout << "Lsup: " << Lsup << endl;
	cout << "OndeLer " << OndeLer << endl;
	cout << endl;
	getchar();
	*/
	while (Ei <= Es) {
		RetiraMin (&Area, &R, &NRArea);
		EscreveMin (ArqEi, R, &Ei);
	}
}

void LeSup (FILE **ArqLEs, TRegistro *Registro, int *Ls, short *OndeLer) {
	fseek(*ArqLEs, (*Ls - 1) * sizeof(TRegistro), SEEK_SET);
	fread(Registro, sizeof(TRegistro), 1, *ArqLEs);
	(*Ls)--;
	*OndeLer = false;
}

void LeInf (FILE **ArqLi, TRegistro *Registro, int *Li, short *OndeLer) {
	fread(Registro, sizeof(TRegistro), 1, *ArqLi);
	(*Li)++;
	*OndeLer = true;
}

void InserirArea (TArea *Area, TRegistro *Registro, int *NRArea) {
	/*	Insere o último dado lido de forma ORDENADA na Área	*/
	InsereItem (*Registro, Area);
	*NRArea = ObterNumCelOcupadas(Area);
}

void EscreveMax (FILE **ArqLEs, TRegistro R, int *Es) {
	fseek(*ArqLEs, (*Es - 1) * sizeof(TRegistro), SEEK_SET);
	fwrite(&R, sizeof(TRegistro), 1, *ArqLEs);
	(*Es)--;
}

void EscreveMin (FILE **ArqEi, TRegistro R, int *Ei) {
	fwrite(&R, sizeof(TRegistro), 1, *ArqEi);
	(*Ei)++;
}

void RetiraMax (TArea *Area, TRegistro *R, int *NRArea) {
	RetiraUltimo(Area, R);
	*NRArea = ObterNumCelOcupadas(Area);
}

void RetiraMin (TArea *Area, TRegistro *R, int *NRArea) {
	RetiraPrimeiro(Area, R);
	*NRArea = ObterNumCelOcupadas(Area);
}


/*	FUNÇÕES PARA O AREA	*/
void FAVazia (TArea *Area) {
	Area->n = 0;

	TRegistro *reg = new TRegistro();

	for(int i = 0; i < TAM_AREA; i++) {
		//DESCOMENTAR
		Area->area[i] = *reg;
	}
}

void InsereItem (TRegistro Registro, TArea *Area) {
	//Insere o item de forma ORDENADA

	if (Area->n == 0) {
		Area->area[0] = Registro;
		Area->n++;
		//ExibirArea(Area);
		return;
	} 

	//cout << "Antes de inserir " << Registro.nota << " na área: " << endl;
	//ExibirArea(Area);
	int i = 0;
	/*	
		Pegando a posição que eu irei inserir o item

		LÓGICA:
		Enquanto a nota a ser inserida for maior que a nota que está no vetor	
		E
		A posição do I estiver inferior ao (tamanho do vetor - 1)
	*/

	//cout << "Registro: " << Registro.nota << " - Nota: " << Area->area[i].nota << endl;
	while (Registro.nota > Area->area[i].nota && i < Area->n) i++;

	//Insere ordenadamente.
	Area->n++;
	for (int j = Area->n - 1; j >= i; j--) Area->area[j] = Area->area[j - 1];
	Area->area[i] = Registro;

	//cout << "Depois de inserir " << Registro.nota << " na área: " << endl;
	//ExibirArea(Area);
	//getchar();

	//ExibirArea(Area);
}

void RetiraUltimo (TArea *Area, TRegistro *R) {
	//cout << "Area antes de eu retirar o ultimo item: " << endl;
	//ExibirArea(Area);
	*R = Area->area[Area->n - 1];
	Area->n--;
	//cout << "Area depois de eu retirar o primeiro item: " << endl;
	//ExibirArea(Area);
	//getchar();
}

void RetiraPrimeiro (TArea *Area, TRegistro *R) {
	//cout << "Area antes de eu retirar o primeiro item: " << endl;
	//ExibirArea(Area);

	*R = Area->area[0];

	Area->n--;
	for (int i = 0; i < Area->n; i++) {
		Area->area[i] = Area->area[i + 1];
	}

	//cout << "Area depois de eu retirar o primeiro item: " << endl;
	//ExibirArea(Area);
	//getchar();
	
}

int ObterNumCelOcupadas (TArea *Area) {
	return Area->n;
}

void ExibirArea(TArea *Area) {
	cout << "Area: ";
	for (int k = 0; k < Area->n; k++) {
		cout << Area->area[k].nota << " - ";
	}
	cout << endl;
	//getchar();
}