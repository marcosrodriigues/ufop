#include "Quicksort_Texto.h"

/*	FUNÇÕES PARA O QUICKSORT	*/
void QuicksortExterno (fstream& ArqLi, fstream& ArqEi, fstream& ArqLEs, int Esq, int Dir) {
	int i, j;

	TArea Area;
	
	//Se a Direita tiver passado a Esquerda, significa que já terminou percorreu o arquivo todo
	if(Dir - Esq < 1)	return;

	//Inicializa a área
	FAVazia(&Area);
	cout << "Fez vazia" << endl;
	Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j);
	cout << "Fez Particao" << endl;

	if (i - Esq < Dir - j) {
		/*	Ordena primeiro o subarquivo menor	*/
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
	} else {
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
	}
}

void Particao (fstream& ArqLi, fstream& ArqEi, fstream& ArqLEs, TArea Area, int Esq, int Dir, int *i, int *j) {
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

	ArqLi.seekg((Li - 1) * SIZEOF_REGISTRO, ArqLi.beg);
	ArqEi.seekg((Li - 1) * SIZEOF_REGISTRO, ArqEi.beg);

	*i = Esq - 1;
	*j = Dir + 1;

	while (Ls >= Li) {
		//cout << "LS: " << Ls << " - LI: " << Li << endl;
		if (NRArea < TAM_AREA - 1) {
			if (OndeLer) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer);
			else LeInf (ArqLi, &UltLido, &Li, &OndeLer);
			InserirArea (&Area, &UltLido, &NRArea);
			continue;
		}
		
		if (Ls == Es) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer);
		else if (Li == Ei) LeInf (ArqLi, &UltLido, &Li, &OndeLer);
		else if (OndeLer) LeSup (ArqLEs, &UltLido, &Ls, &OndeLer);
		else LeInf (ArqLi, &UltLido, &Li, &OndeLer);
		/*
		cout << "Registro lido: " << UltLido.matricula << endl;
		getchar();
		*/
		if (UltLido.matricula > Lsup) {
			*j = Es;
			EscreveMax (ArqLEs, UltLido, &Es);
			continue;
		}

		if (UltLido.matricula < Linf) {
			*i = Ei;
			EscreveMin (ArqEi, UltLido, &Ei);
			continue;
		}

		InserirArea (&Area, &UltLido, &NRArea);

		if (Ei - Esq < Dir - Es) {	
			RetiraMin (&Area, &R, &NRArea);
			EscreveMin (ArqEi, R, &Ei);
		} else {
			RetiraMax (&Area, &R, &NRArea);
			EscreveMax (ArqLEs, R, &Es);
		}


	}

	while (Ei <= Es) {
		RetiraMin (&Area, &R, &NRArea);
		EscreveMin (ArqEi, R, &Ei);
	}
	
	cout << "Fim da particao. Valores:" << endl;
	cout << "Esq: " << Esq << " - Dir: " << Dir << " - I: " << *i << " - J: " << *j << endl;
	getchar();
	
}

void LeSup (fstream& ArqLEs, TRegistro *Registro, int *Ls, short *OndeLer) {
	ArqLEs.seekg((*Ls - 1) * SIZEOF_REGISTRO, ArqLEs.beg);
	char DadosLidos[101];
	ArqLEs.read(DadosLidos, SIZEOF_REGISTRO);
	//Criar uma função para transferir os DadosLidos para o TRegistro
	StringPraRegistro(DadosLidos, Registro);
	(*Ls)--;
	*OndeLer = false;
}

void LeInf (fstream& ArqLi, TRegistro *Registro, int *Li, short *OndeLer) {
	char DadosLidos[101];
	ArqLi.read(DadosLidos, SIZEOF_REGISTRO);
	(*Li)++;
	*OndeLer = true;
}

void InserirArea (TArea *Area, TRegistro *Registro, int *NRArea) {
	/*	Insere o último dado lido de forma ORDENADA na Área	*/
	InsereItem (*Registro, Area);
	*NRArea = ObterNumCelOcupadas(*Area);
}

void EscreveMax (fstream& ArqLEs, TRegistro R, int *Es) {
	//ArqLEs.seekg((*Es - 1) * SIZEOF_REGISTRO, ArqLEs.beg);
	ArqLEs.seekp((*Es - 1) * SIZEOF_REGISTRO, ArqLEs.beg);
	//Aqui eu preciso escrever o registro no ArqLEs
	//fwrite(&R, sizeof(TRegistro), 1, *ArqLEs);
	ArqLEs << R.matricula;
	ArqLEs << R.nota;
	ArqLEs << R.estado;
	ArqLEs << R.cidade;
	ArqLEs << R.curso;
	ArqLEs << endl;
/*
	cout << "Escrevendo..." << endl;
	cout << R.matricula << " - " << R.nota << " - " << R.estado << " - " << R.cidade << " - " << R.curso << endl;
	getchar();
*/
	(*Es)--;
}

void EscreveMin (fstream& ArqEi, TRegistro R, int *Ei) {
	//Aqui eu preciso escrever o registro no ArqEi
	//fwrite(&R, sizeof(TRegistro), 1, *ArqEi);
	ArqEi << R.matricula;
	ArqEi << R.nota;
	ArqEi << R.estado;
	ArqEi << R.cidade;
	ArqEi << R.curso;
	ArqEi << endl;
	(*Ei)++;
}

void RetiraMax (TArea *Area, TRegistro *R, int *NRArea) {
	RetiraUltimo(Area, R);
	*NRArea = ObterNumCelOcupadas(*Area);
}

void RetiraMin (TArea *Area, TRegistro *R, int *NRArea) {
	RetiraPrimeiro(Area, R);
	*NRArea = ObterNumCelOcupadas(*Area);
}


/*	FUNÇÕES PARA O AREA	*/
void FAVazia (TArea *Area) {
	Area->n = 0;

	TRegistro reg;
	reg.matricula = 0;
	reg.nota = 0.0;
	

	for(int i = 0; i < TAM_AREA; i++) {
		//DESCOMENTAR
		Area->area[i] = reg;
	}
}

void InsereItem (TRegistro Registro, TArea *Area) {
	//Insere o item de forma ORDENADA

	//Se a Area nao tiver nenhum elemento
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
		PS: O tamanho do vetor está (TAM_VETOR - 1), pra deixar um espaço para inserir o item.
		Se (i == 19), eu nao teria lugar para inserir, por isso o i deve ir até 18

	*/
	while (Registro.nota > Area->area[i].nota && i < (TAM_AREA - 1)) i++;

	//Insere ordenadamente.
	TRegistro aux = Area->area[i - 1];
	Area->area[i - 1] = Registro;
	for (int j = i; j < Area->n + 1; j++) {
		Area->area[i] = aux;
		aux = Area->area[i + 1];
	}

	Area->n++;
}

void RetiraUltimo (TArea *Area, TRegistro *R) {
	*R = Area->area[Area->n - 1];
	Area->n--;
}

void RetiraPrimeiro (TArea *Area, TRegistro *R) {
	*R = Area->area[0];
	for (int i = 0; i < Area->n; i++) {
		Area->area[i] = Area->area[i + 1];
	}
	Area->n--;
}

int ObterNumCelOcupadas (TArea Area) {
	return Area.n;
}

/*	Funções Adicionais	*/
void StringPraRegistro(string DadosLidos, TRegistro *Registro) {

	
	Registro->matricula = atol(DadosLidos.substr(0, 8).c_str());
	Registro->nota = atof(DadosLidos.substr(9, 5).c_str());
	DadosLidos.substr(15, 2).copy(Registro->estado, 3);
	DadosLidos.substr(18, 50).copy(Registro->cidade, 51);
	DadosLidos.substr(69, 30).copy(Registro->curso, 31);
	/*
	cout << "dados: " << endl;
	cout << "Matricula: " << Registro->matricula << endl;
	cout << "Nota: " << Registro->nota << endl;
	cout << "Estado: " << Registro->estado << endl;
	cout << "Cdade: " << Registro->cidade << endl;
	cout << "Curso: " << Registro->curso << endl;
	getchar();
	*/

}