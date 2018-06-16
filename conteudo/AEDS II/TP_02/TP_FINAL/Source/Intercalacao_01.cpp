#include "Intercalacao_01.h"

/*	METODOS USADOS	*/
bool SalvarArquivo(char* nomeArquivo, TRegistro* VRegistro, int TamVetor, int MudarLinha) {
	FILE *f;
	if((f = fopen(nomeArquivo, "ab")) == NULL) {
		cout << "Não foi possivel abrir o arquivo " << nomeArquivo << " em SalvarArquivo" << endl;
		return false;
	}

	for (int i = 0; i < TamVetor; ++i)	{
		fwrite(&VRegistro[i], sizeof(TRegistro), 1, f);
	}

	fclose(f);

	return true;
}

/*	METODOS PARA ORDENAÇÃO CRESCENTE	*/
bool InserirVetorNaFita(TRegistro* V, TFita* Fita, int cont) {
	int i = 0;
	TRegistro Registro;
	Registro.matricula = 999999;
	Registro.nota = 127;

	fwrite(V, sizeof(TRegistro), (MEM_INT + 1), Fita->arquivo);

	Fita->nBlocos++;
	Fita->Ativo = true;
	return true;
}

void OrdenaCrescente (TRegistro *Registro, int total) {

	TRegistro aux;
	TRegistro ultimo;
	for (int i = 0; i < total; ++i)	{
		//if (Registro[i].matricula == -1 || Registro[i].nota == -1.0) continue;	//Registro nulo
		for (int j = i; j < total; ++j)	{
		//	if (Registro[j].matricula == -1 || Registro[j].nota == -1.0) continue;
			if (Registro[i].nota > Registro[j].nota) {
				aux = Registro[i];
				Registro[i] = Registro[j];
				Registro[j] = aux;
			}
		}

		
	}
}

bool CriarArquivosOrdenados(FILE* arquivo, TFita* Fitas, int amount) {
	TRegistro V[MEM_INT + 1];

	int cont = 0,	//Contador para as minhas FITAS
		total = 0;	// Contador para o número de registros que já inseri no bloco

	char arqNovo[20];
	bool AlcanceiMaximoDeFitas = false;
	/*
	FILE *arquivo;
	if((arquivo = fopen(nomeArquivo, "a+b")) == NULL) {
		cout << "Não foi possivel abrir o arquivo " << nomeArquivo << " em CriarArquivosOrdenados" << endl;
		return 0;
	}
	*/

	//Abrindo todas as fitas
	for (int i = 0; i < F_ENTRADA; i++) {
		sprintf(arqNovo, "ENTRADA/Fita_%d.bin", i + 1);
		if((Fitas[i].arquivo = fopen(arqNovo, "a+b")) == NULL) {
			cout << "Não foi posśivel abrir o arquivo " << arqNovo << " no CriarArquivosOrdenados" << endl;
			return false;
		}
		Fitas[i].nBlocos = 0;
		Fitas[i].Ativo = false;
	}

	TRegistro RNulo;
	RNulo.matricula = INT_MAX;
	RNulo.nota = FLT_MAX_EXP;
	int i = 0;
	while((fread(&V[total], sizeof(TRegistro), 1, arquivo)) == 1 && i < amount) {
		i++;
		total++;


		//Se alcancei o máximo de elementos que cabe na memória, crio um registro nulo, salvo os registros na minha fita e vou pra próxima fita
		if (total == MEM_INT) {
			cont++;

			//Salvo o elemento "nulo" e salvo no arquivo. O elemento nulo é a separação dos meus blocos. Ordena o meu vetor
			V[total] = RNulo;
			total++;

			OrdenaCrescente(V, total);
			
			//Salvo os dados ordenados na minha fita
			InserirVetorNaFita(V, &Fitas[cont - 1], cont);

			//Se repetir dados demais, tente isso
			//Zerando meu Vetor de registro para evitar que dados se repitam
			/*for (int i = 0; i < total; ++i)	{
				V[i] = RNulo;
			}*/

			total = 0;
		}

		//Se meu contador chegar no máximo de fitas que eu posso ter, eu zero meu TOTAL, zero meu CONT, e continuo a operação a partir do próximo bloco da 1º fita
		if (cont == (F_ENTRADA)) {
			AlcanceiMaximoDeFitas = true;
			total = 0;
			cont = 0;
		}
	}	

	if(total > 0) {
		cont++;
		//Crio um elemento "nulo" e salvo no arquivo. O elemento nulo é a separação dos meus blocos
		V[total] = RNulo;
		total++;
		OrdenaCrescente(V, total);
		InserirVetorNaFita(V, &Fitas[cont - 1], cont);
		total = 0;
	}
	fclose(arquivo);

	//VerificarSeTemRegistroNulo(Fitas, Fitas);
	for (int i = 0; i < F_ENTRADA; ++i)	{
		fclose(Fitas[i].arquivo);	
	}

	//EXIBE A QUANTIDADE DE BLOCOS EM CADA FITA
	for (int k = 0; k < F_ENTRADA; k++) {
		//cout << "Blocos na Fita " << (k + 1) << ": " << Fitas[k].nBlocos << endl;
	}
	
	return AlcanceiMaximoDeFitas ? F_ENTRADA : cont;
}

int IntercalacaoBalanceada(FILE* arquivo, int amount) {
	char arqNovo[20];

	for (int i = 0; i < F_ENTRADA; ++i) {
		sprintf(arqNovo, "ENTRADA/Fita_%d.bin", i + 1);
		remove(arqNovo);
		sprintf(arqNovo, "SAIDA/Fita_%d.bin", i + 1);
		remove(arqNovo);
	}

	TFita* Fitas = new TFita[F_ENTRADA];
	
	if (CriarArquivosOrdenados(arquivo, Fitas, amount)) {
		if(IntercalarFitasCrescente(Fitas))  {
			cout << "Fitas Intercaladas" << endl;
			FILE *file;
			if((file = fopen("ENTRADA/Fita_1.bin", "r+b")) == NULL) {
				cout << "Não abriu arquivo em IntercalacaoBalanceada" << endl;
				return 1;	
			}
			TRegistro r;
			while(fread(&r, sizeof(TRegistro), 1, file)) {
				cout << "Nota: " << r.nota << endl;
			}
		}
		else
			cout << "Nao foi possivel intercalar as fitas" << endl;
	}
	else
		cout << "Nao foi possivel criar os arquivos ordenados";
	

	return 0;
	
/*	
	for (int i = 0; i < NumeroFitas; ++i)	{
		sprintf(novo, "Temp_%d_Entrada.bin", i + 1);
		remove(novo);
	}
*/
}

void VerificarSeTemRegistroNulo(TFita* FitaEntrada, TFita* FitaSaida) {
	TRegistro r;
	int count, nulo;
	for (int i = 0; i < F_ENTRADA; ++i){
		count = 0;
		nulo = 0;
		while ((fread(&r, sizeof(TRegistro), 1, FitaEntrada[i].arquivo))) {
			count++;
			if (r.nota == FLT_MAX_EXP || r.matricula == INT_MAX) {
				cout << "============== REGISTRO ENCONTRADO =================" << endl;
				cout << "R.MATRICULA: " << r.matricula << endl;
				cout << "R.NOTA: " << r.nota << endl;
				cout << "ARQUIVO: Fita de Entrada - Númeo " << i + 1 << endl;
				cout << "============== REGISTRO ENCONTRADO =================" << endl;
				nulo++;
			}
		}
		cout << "FIM DO ARQUIVO " << i + 1 << " COM " << count << " REGISTROS E " << nulo << " NULOS." << endl;

		fseek(FitaEntrada[i].arquivo, 0, SEEK_SET);
	}
/*
	for (int i = 0; i < F_SAIDA; ++i){
		count = 0;
		nulo = 0;
		while ((fread(&r, sizeof(TRegistro), 1, FitaSaida[i].arquivo))) {
			count++;
			if (r.nota == FLT_MAX_EXP || r.matricula == INT_MAX) {
				cout << "============== REGISTRO ENCONTRADO =================" << endl;
				cout << "R.MATRICULA: " << r.matricula << endl;
				cout << "R.NOTA: " << r.nota << endl;
				cout << "ARQUIVO: Fita de Entrada - Númeo " << i + 1 << endl;
				cout << "============== REGISTRO ENCONTRADO =================" << endl;
				nulo++;
			}
		}
		cout << "FIM DO ARQUIVO " << i + 1 << " COM " << count << " REGISTROS E " << nulo << " NULOS." << endl;
	}*/
	
}

bool IntercalarFitasCrescente(TFita* FitasEntrada) {
	if (FitasEntrada == NULL) return false;

	char fita[20];

	//Abro as fitas de entrada
	for (int i = 0; i < F_ENTRADA; ++i) {
		sprintf(fita, "ENTRADA/Fita_%d.bin", i + 1);
		if ((FitasEntrada[i].arquivo = fopen(fita, "r+b")) == NULL) {
			cout << "Não foi possivel abrir o arquivo " << fita << " no IntercalarFitasCrescente" << endl;
			return false;
		}
	}

	TFita* FitasSaida = new TFita[F_SAIDA];

	//Crio e abro as fitas de saida
	for (int i = 0; i < F_SAIDA; ++i) {
		sprintf(fita, "SAIDA/Fita_%d.bin", i + 1);
		if ((FitasSaida[i].arquivo = fopen(fita, "ab")) == NULL) {
			cout << "Não foi possivel abrir o arquivo " << fita << " no IntercalarFitasCrescente" << endl;
			return false;
		}
		FitasSaida[i].nBlocos = 0;
		FitasSaida[i].Ativo = false;
	}	

	TRegistro* 	Registro 	= new TRegistro[MEM_INT],
				RegAux,
				RegNulo;
	int 	QtdMaximoBlocos 	= FitasEntrada[0].nBlocos, //A quantidade máxima de blocos é o número de blocos na minha primeira fita
			BlocoCorrente 		= 0,
			FitaCorrenteSaida	= 0,
			QtdFitasAtivas		= 0,
			PosicaoFitaSaida	= 0,
			PosicaoFitaEntrada	= 0;	

	float LIMITE_NOTA = FLT_MAX_EXP;

	RegNulo.matricula 	= INT_MAX;
	RegNulo.nota 		= FLT_MAX_EXP;

	//VerificarSeTemRegistroNulo(FitasEntrada, FitasEntrada/*FitasSaida*/);
	int p = 0;
	bool t = false;
	while (QtdMaximoBlocos > 1) {
		
		t = (p == 2);

		for (int i = 0; i < F_ENTRADA; ++i) {
			if (FitasEntrada[i].Ativo) { //Leio o primeiro registro livre de cada fita
				fread(&Registro[i], sizeof(TRegistro), 1, FitasEntrada[i].arquivo);
				
				QtdFitasAtivas++;

				if(t)	{
				cout << "FITA_"<<i<<" DEPOIS DE GERAR" << endl;
				cout << "FitasEntrada[" << i << "].Ativo: " << FitasEntrada[i].Ativo << endl;
		//		getchar();
			}
			}
		}

		QtdMaximoBlocos 	= FitasEntrada[0].nBlocos;
		BlocoCorrente 		= 0;
		FitaCorrenteSaida	= 0;
		LIMITE_NOTA 		= FLT_MAX_EXP;
		PosicaoFitaSaida 	= 0;
		p++;
		
		cout << "QtdMaximaBlocos:" << QtdMaximoBlocos << endl;
		getchar();

		if (t) {
			cout << "DEPOIS DE LER O ARQUIVO" << endl;
			for (int i = 0; i < F_ENTRADA; ++i)	{
				cout << "Registro[" << i << "]: " << Registro[i].nota << endl;
			}
		//	getchar();	
		}

		while (BlocoCorrente < QtdMaximoBlocos) {		//Enquanto tiver blocos na fita
			//cout << "Bloco Corrente: " << BlocoCorrente << " - QtdMaximoBlocos: " << QtdMaximoBlocos << endl;
			//getchar();
			//Primeira passada nas fitas

			if (t) {
				cout << "ANTES DA QTDFITASATIVA" << endl;
				for (int i = 0; i < F_ENTRADA; ++i)	{
					cout << "Registro[" << i << "]: " << Registro[i].nota << endl;
				}
		//		getchar();	
			}
			

			while (QtdFitasAtivas > 0) {		//Enquanto eu tiver Fita que possuem registros nos blocos
				if(t)  {
					cout << "QtdFitasAtivas: " << QtdFitasAtivas << endl;
		//			getchar();
				}
				//cout << QtdFitasAtivas << " fitas no Bloco: " << BlocoCorrente << endl;
				LIMITE_NOTA = FLT_MAX_EXP;

				if (t) {

					cout << "ANTES DA CONDICAO T" << endl;
					for (int i = 0; i < F_ENTRADA; ++i)	{
						cout << "Registro[" << i << "]: " << Registro[i].nota << endl;
					}
		//			getchar();

					//cout << "BlocoCorrente: " << BlocoCorrente << endl;
					//cout << "QtdFitasAtivas: " << QtdFitasAtivas << endl;
					cout << "Verificando Nulo: " << endl;
					//VerificarSeTemRegistroNulo(FitasEntrada, FitasSaida);
					cout << "QtdMaximoBlocos: " << QtdMaximoBlocos << endl;
					//getchar();

					cout << "ANTES DO FOR F_ENTRADA" << endl;
					for (int i = 0; i < F_ENTRADA; ++i)	{
						cout << "Registro[" << i << "]: " << Registro[i].nota << endl;
					}
		//			getchar();
				}
				
				

				/*
					Busco a menor chave da minha fita
					F_ENTRADA + 1 
				*/
				for (int i = 0; i < (F_ENTRADA); ++i) {	

					if (FitasEntrada[i].Ativo)
						if (Registro[i].nota <= LIMITE_NOTA) {
							PosicaoFitaSaida = i;
							LIMITE_NOTA = Registro[i].nota;
						}

						if(t) {
							cout << "Registro[" << i << "]: " << Registro[i].nota << " ATIVO ? " << FitasEntrada[i].Ativo << endl;
		//					getchar();		
						}
					
					if(Registro[i].nota == FLT_MAX_EXP || Registro[i].matricula == INT_MAX) {

						if(t) {
							cout << "================ ACHOU ===================" << endl;
							cout << "Registro " << i + 1 << ": " << Registro[i].matricula << " - " << Registro[i].nota << endl;
		//					getchar();
						}
						

						FitasEntrada[i].Ativo = false;
						if (i != F_ENTRADA) {	//A posição F_ENTRADA eh a posição do meu registro nulo
							QtdFitasAtivas--;
							FitasEntrada[i].nBlocos--;	
						}
						continue;
					}
					//cout << endl;
					//cout << "Registro[" << i << "] Lido: " << Registro[i].nota << endl;
					//cout << "LIMITE_NOTA: " << LIMITE_NOTA << endl;
					//cout << "ATIVO: " << FitasEntrada[i].Ativo << endl;

					
					//cout << "PosicaoFitaSaida: " << PosicaoFitaSaida << endl;
				}

				if(t) cout << "PosicaoFitaSaida " << PosicaoFitaSaida << " com o registro " << Registro[PosicaoFitaSaida].nota << endl;
				//getchar();
				//Ativa a fita de saida para inserir o registro
				if (!FitasSaida[PosicaoFitaSaida].Ativo) FitasSaida[PosicaoFitaSaida].Ativo = true;

//				if(t) cout << "FitaSaida.Ativo: " << FitasSaida[PosicaoFitaSaida].Ativo << endl;
				//Insiro o Registro de menor chave na Fita de Saida
				fwrite(&Registro[PosicaoFitaSaida], sizeof(TRegistro), 1, FitasSaida[FitaCorrenteSaida].arquivo);
//				if(t) cout << "Registro Inserido na Fita de Saida: " << Registro[PosicaoFitaSaida].nota << endl;
				//Busco o próximo registro da fita no qual o registro foi inserido na saida
				fread(&RegAux, sizeof(TRegistro), 1, FitasEntrada[PosicaoFitaSaida].arquivo);

				if (RegAux.nota != FLT_MAX_EXP && RegAux.matricula != INT_MAX) {
					Registro[PosicaoFitaSaida] = RegAux;
				} else {
					FitasEntrada[PosicaoFitaSaida].Ativo = false;
					FitasEntrada[PosicaoFitaSaida].nBlocos--;
					QtdFitasAtivas--;
				}
			}

			//cout << "QtdMaximoBlocos: " << QtdMaximoBlocos << endl;

			if(QtdMaximoBlocos != 1) {
			//fclose(FitasEntrada[FitaCorrenteSaida].arquivo);
			//sprintf(fita, "/ENTRADA/Fita_%d.bin", FitaCorrenteSaida);
			//FitasEntrada[FitaCorrenteSaida].arquivo = fopen(fita, "ab");
				fwrite(&RegNulo, sizeof(TRegistro), 1, FitasSaida[FitaCorrenteSaida].arquivo);
			}
			//fclose(FitasEntrada[FitaCorrenteSaida].arquivo);
			//sprintf(fita, "/ENTRADA/Fita_%d.bin", FitaCorrenteSaida);
			//FitasEntrada[FitaCorrenteSaida].arquivo = fopen(fita, "r+b");
			fread(&RegAux, sizeof(TRegistro), 1, FitasEntrada[FitaCorrenteSaida].arquivo);

			FitasSaida[FitaCorrenteSaida].nBlocos++;

			//Ativo minhas fitas de entrada para a segunda passada
			for (int i = 0; i < F_ENTRADA; ++i) {
				if(FitasEntrada[i].nBlocos > 0) {
					FitasEntrada[i].Ativo = true;
					fread(&Registro[i], sizeof(TRegistro), 1, FitasEntrada[i].arquivo);	//Preencho a memória com a fita de entrada
					QtdFitasAtivas++;	
				}
			}

			//Incremento 01 na posição da minha fita de saida
			FitaCorrenteSaida++;
			if (FitaCorrenteSaida == F_SAIDA) {
				FitaCorrenteSaida = 0;
			}
			BlocoCorrente++;
		}

		//cout << "Bloco Corrente: " << BlocoCorrente << " - QtdMaximoBlocos " << QtdMaximoBlocos << endl;

		//Limpo minha fita de entrada
		for (int i = 0; i < F_ENTRADA; ++i) {
			rewind(FitasEntrada[i].arquivo);
			FitasEntrada[i].nBlocos = 0;
		}

		
		//Fecho todos os meus arquivos
		for (int i = 0; i < F_ENTRADA; ++i)	fclose(FitasEntrada[i].arquivo);
		for (int i = 0; i < F_SAIDA; ++i) fclose(FitasSaida[i].arquivo);

		//Transformo minhas fitas de saida em fitas de entrada
		//getchar();

		cout << "antes de deletar" << endl;
		getchar();
		char fitaSaida[20];
		for (int i = 0; i < F_ENTRADA; ++i)	{
			sprintf(fita, "ENTRADA/Fita_%d.bin", i + 1);
			sprintf(fitaSaida, "SAIDA/Fita_%d.bin", i + 1);

			remove(fita);
			rename(fitaSaida, fita);
			remove(fitaSaida);

			//cout << "Renomeou " << fita << " PARA " << fitaSaida << endl;
		}
		cout << "depois de deletar" << endl;
		getchar();

		//Reabro as fitas de entrada e de saida
		for (int i = 0; i < F_ENTRADA; ++i) {
			sprintf(fita, "ENTRADA/Fita_%d.bin", i + 1);
			if ((FitasEntrada[i].arquivo = fopen(fita, "r+b")) == NULL) {
				cout << "Não foi possivel abrir o arquivo " << fita << " no IntercalarFitasCrescente" << endl;
				return false;
			}
			FitasEntrada[i].nBlocos = FitasSaida[i].nBlocos;
			FitasEntrada[i].Ativo = FitasSaida[i].Ativo;

			cout << "FitasEntrada[" << i << "].nBlocos: " << FitasEntrada[i].nBlocos << endl;
			cout << "FitasEntrada[" << i << "].Ativo: " << FitasEntrada[i].Ativo << endl;
			cout << endl;

			if (true){
				cout << "NUMERO DE BLOCOS DE " << i + 1 << ": " << FitasEntrada[i].nBlocos << endl;
		//		getchar();
				TRegistro R;
				cout << "REGISTRO TRANSFERIDO DE SAIDA PRA ENTRADA " << i + 1 << ": " << endl;
				//getchar();
				while(fread(&R, sizeof(TRegistro), 1, FitasEntrada[i].arquivo)) {
					cout << "FLT_MAX_EXP: " <<  FLT_MAX_EXP << " - R.nota " << R.nota << endl;
					if (R.nota == FLT_MAX_EXP || R.matricula == INT_MAX) {
						cout << "ACHOU" << endl;
						cout << "MATRICULA: " << R.matricula << " - NOTA: " << R.nota << endl;
						//getchar();
					} else {
						cout << "MATRICULA: " << R.matricula << " - NOTA: " << R.nota << endl;	
					}
				}
//				getchar();	
			}
		}
		//getchar();

		cout << "TERMINOU DE PASSAR OS ITENS DA SAIDA PRA ENTRADA" << endl;
		//getchar();	

		for (int i = 0; i < F_SAIDA; ++i) {
			sprintf(fita, "SAIDA/Fita_%d.bin", i + 1);
			if ((FitasSaida[i].arquivo = fopen(fita, "ab")) == NULL) {
				cout << "Não foi possivel abrir o arquivo " << fita << " no IntercalarFitasCrescente" << endl;
				return false;
			}
			FitasSaida[i].nBlocos = 0;
			FitasSaida[i].Ativo = false;
		}	
	}

	for (int i = 0; i < F_ENTRADA; ++i)	fclose(FitasEntrada[i].arquivo);
	for (int i = 0; i < F_SAIDA; ++i) fclose(FitasSaida[i].arquivo);

	return true;
}

/*	METODOS PARA ORDENAÇÃO DECRESCENTE	*/
// int CriarArquivosOrdenadosDecrescente(char* nomeArquivo) {
// 	TRegistro V[MEM_INT];

// 	int cont = 0,	//Contador para as minhas FITAS
// 		total = 0;	// Contador para o número de registros que já inseri no bloco

// 	char arqNovo[20];

// 	bool	AlcanceiMaximoDeFitas = false,
// 			AlcanceiMaximoDoBloco = false;

// 	FILE *arquivo;
// 	if((arquivo = fopen(nomeArquivo, "a+b")) == NULL) {
// 		cout << "Não foi possivel abrir o arquivo " << nomeArquivo << " em CriarArquivosOrdenados" << endl;
// 		return 0;
// 	}

// 	TRegistro RNulo;
// 	RNulo.matricula = -1;
// 	RNulo.nota = -1.0;
// 	while((fread(&V[total], sizeof(TRegistro), 1, arquivo)) == 1) {
// 		total++;

// 		//Se alcancei o máximo de elementos que cabe na memória, crio um registro nulo, salvo os registros na minha fita e vou pra próxima fita
// 		if (total == (MEM_INT - 1)) {
// 			cont++;

// 			//Salvo o elemento "nulo" e salvo no arquivo. O elemento nulo é a separação dos meus blocos
// 			V[total] = RNulo;
// 			total++;
// 			sprintf(arqNovo, "Temp_%d_Entrada.bin", cont);
// 			OrdenaDecrescente(V, total);
// 			SalvarArquivo(arqNovo, V, total, 0);

// 			total = 0;
// 		}

// 		//Se meu contador chegar no máximo de fitas que eu posso ter, eu zero meu TOTAL, zero meu CONT, e continuo a operação a partir do próximo bloco da 1º fita
// 		if (cont == (F_ENTRADA)) {
// 			AlcanceiMaximoDeFitas = true;
// 			total = 0;
// 			cont = 0;
// 		}
// 	}	

// 	if(total > 0) {
// 		cont++;
// 		//Crio um elemento "nulo" e salvo no arquivo. O elemento nulo é a separação dos meus blocos
// 		V[total] = RNulo;
// 		total++;

// 		sprintf(arqNovo, "Temp_%d_Entrada.bin", cont);
// 		OrdenaDecrescente(V, total);
// 		SalvarArquivo(arqNovo, V, total, 0);
// 		total = 0;
// 	}
// 	fclose(arquivo);

// 	TRegistro R;
// 	FILE *f;
// 	char n[20];
// 	int cc = 0;
	
// 	for (int k = 0; k < F_ENTRADA; k++) {
// 		sprintf(n, "Temp_%d_Entrada.bin", k + 1);
// 		f = fopen(n, "r+b");
// 		while((fread(&R, sizeof(TRegistro), 1, f)) == 1) {
// 			if (R.nota == -1) {
// 				cc++;
// 			}
// 		}
// 		fclose(f);
// 		cout << "Blocos na fita " << k + 1 << ": " << cc << endl;
// 		cc = 0;
// 	}
// 	getchar();
	
// 	return AlcanceiMaximoDeFitas ? F_ENTRADA : cont;
// }

// int ProcurarMaior(TFita* arquivo, int NumMaximoFitas, int MaximoDadosFita, TRegistro *maior) {
// 	int posAtual = -1;
// 	for (int i = 0; i < NumMaximoFitas; ++i)
// 		if (arquivo[i].posicao < arquivo[i].MAXIMO) 
// 			if (posAtual == -1)
// 				posAtual = i;
// 			else 
// 				if (arquivo[i].dados[arquivo[i].posicao].nota > arquivo[posAtual].dados[arquivo[posAtual].posicao].nota)
// 						posAtual = i;
			
// 	if (posAtual != -1) {
// 		*maior = arquivo[posAtual].dados[arquivo[posAtual].posicao];
// 		arquivo[posAtual].posicao++;
// 		if(arquivo[posAtual].posicao == arquivo[posAtual].MAXIMO)
// 			PreencherDados(&arquivo[posAtual], MaximoDadosFita);
// 		return 1;
// 	} else {
// 		return 0;
// 	}
// }

// bool IntercalaDecrescente(char* nomeArquivo, int NumMaximoFitas, int MaximoDadosFita) {
// 	char arqNovo[20];

// 	TRegistro *registro = new TRegistro[MaximoDadosFita];
// 	TFita* bloco = new TFita[NumMaximoFitas];

// 	for (int i = 0; i < NumMaximoFitas; ++i) {
// 		sprintf(arqNovo, "Temp_%d_Entrada.bin", i + 1);
		
// 		if ((bloco[i].arquivo = fopen(arqNovo, "r+b")) == NULL) {
// 			cout << "Impossivel abrir o arquivo " << arqNovo << " no metodo INTERCALA DECRESCENTE" << endl;
// 			return false;
// 		}

// 		bloco[i].posicao = 0;
// 		bloco[i].MAXIMO = 0;
// 		bloco[i].dados = new TRegistro[MaximoDadosFita];
// 		PreencherDados(&bloco[i], MaximoDadosFita);
// 	}

// 	TRegistro maior;
// 	int qtdDados = 0;
// 	while (ProcurarMaior(bloco, NumMaximoFitas, MaximoDadosFita, &maior) == 1) {
// 		registro[qtdDados] = maior;
// 		qtdDados++;

// 		if(qtdDados == MaximoDadosFita) {
// 			SalvarArquivo(nomeArquivo, registro, MaximoDadosFita, 1);
// 			qtdDados = 0;
// 		}
// 	}

// 	if (qtdDados != 0) SalvarArquivo(nomeArquivo, registro, qtdDados, 1);

// 	for (int i = 0; i < NumMaximoFitas; ++i)
// 		free(bloco[i].dados);
	
// 	free(bloco);
// 	free(registro);

// 	return true;
// }

// int IntercalacaoBalanceadaDecrescente(char* nomeArquivo) {
// 	char arqNovo[20];
// 	/*int NumeroFitas = CriarArquivosOrdenados(nomeArquivo);
// 	int DadosNoBloco = MEM_INT / (NumeroFitas + 1);

// 	remove(nomeArquivo);
// 	IntercalaDecrescente(nomeArquivo, NumeroFitas, DadosNoBloco);

// / *	for (int i = 0; i < NumeroFitas; ++i)	{
// 		sprintf(novo, "Temp_%d_Entrada.bin", i + 1);
// 		remove(novo);
// 	}
// */
// }

// /*	INSERE ORDENADO	CRESCENTE */


// /*	INSERE ORDENADO	DECRESCENTE */
// void OrdenaDecrescente (TRegistro *Registro, int total) {

// 	TRegistro aux;
// 	cout << "Ordenado Decrescente: ";
// 	for (int i = 0; i < total; ++i)	{
// 		if (Registro[i].matricula == -1 || Registro[i].nota == -1.0) continue;	//Registro nulo
// 		for (int j = i; j < total; ++j)	{
// 			if (Registro[i].nota < Registro[j].nota) {
// 				aux = Registro[i];
// 				Registro[i] = Registro[j];
// 				Registro[j] = aux;
// 			}
// 		}

// 		//cout << Registro[i].nota << " - ";
// 	}
// }