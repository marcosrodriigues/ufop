#include "tabuleiro.h"
using namespace std;

TTabuleiro* TJogo_Inicia (TJogador player1, TJogador player2) {
	TTabuleiro *tabuleiro = new TTabuleiro;

	int cPlayer1 = 0, cPlayer2 = 0;
	for (int i = 0; i < MAX_CASA; i++) {
		for (int j = 0; j < MAX_CASA; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)){
				tabuleiro->casa[i][j].caminhavel = true;
				tabuleiro->casa[i][j].pecaAtualPresente.numeroPeca = -1;
				if (i > 4) {
					//player2
					tabuleiro->casa[i][j].pecaAtualPresente = player2.peca[cPlayer2]; //coloca as pecas do jogador no tabuleiro
					tabuleiro->casa[i][j].temPeca = true;
					cPlayer2++;
				} else if (i < 3) {
					//player1
					tabuleiro->casa[i][j].pecaAtualPresente = player1.peca[cPlayer1];
					tabuleiro->casa[i][j].temPeca = true;
					cPlayer1++;
				}
			}
		}
	}

	return tabuleiro;
}

TJogador* TJogador_Inicia(int numJogador) {
	TJogador *jogador = new TJogador;
	jogador->comeuPeca = false;
	for (int i = 0; i < MAX_PECA; ++i) {
		jogador->peca[i].numeroPeca = i; //atribui o numero das pecas
		jogador->peca[i].comido = false;
		
		if (numJogador == 1)
			jogador->peca[i].cor = 'b';
		else
			jogador->peca[i].cor = 'p';
	}
	return jogador;
}

void MostrarJogo (TTabuleiro tabuleiro, TJogador player1, TJogador player2){
	for (int i = 0; i < MAX_CASA; i++) {
		for (int j = 0; j < MAX_CASA; j++) {
			if (tabuleiro.casa[i][j].temPeca == true && tabuleiro.casa[i][j].caminhavel == true){
				cout << "| " << tabuleiro.casa[i][j].pecaAtualPresente.cor << tabuleiro.casa[i][j].pecaAtualPresente.numeroPeca << " |";
			} else {
				cout << "| __ |";
			}
		}

		cout << endl << endl;
	}
}

bool TJogador_TemPeca(TTabuleiro tabuleiro, TJogador player, bool terminouJogada) { //verifica se ainda tem peca do jogador
	for (int i = 0; i < MAX_PECA; ++i) {
		if (player.peca[i].comido == false) {
			if (terminouJogada == true) {
				if (player.peca[i].cor == 'B' || player.peca[i].cor == 'P') {
					if (podeJogar(tabuleiro, player, i, 'D', 'F'))	return true;
					if (podeJogar(tabuleiro, player, i, 'D', 'T')) 	return true;
					if (podeJogar(tabuleiro, player, i, 'E', 'F'))	return true;
					if (podeJogar(tabuleiro, player, i, 'E', 'T'))	return true;
				} else {
					if (podeJogar(tabuleiro, player, i, 'D', ' '))	return true;
					if (podeJogar(tabuleiro, player, i, 'E', ' '))	return true;
				}	
			} else {
				return true;
			}
			
		}	
	}

	return false;
}

bool pecaExistente(TJogador player, int peca) { //verifica se peca existe para player
	if (player.peca[peca].comido == true)
		return false;
		
	return true;
}
//verifica se a jogada eh valida
bool podeJogar(TTabuleiro tabuleiro, TJogador jogador, int numPeca, char localMovido, char posicao) {
	int X, Y;
	//retorna a posicao do tabuleiro de onde a peca esta
	for (int i = 0; i < MAX_CASA; ++i) {
		for (int j = 0; j < MAX_CASA; ++j) {
			//verifica se na casa tem peca, se a peca que esta na casa eh da mesma cor da peca do jogador e se o numero da peca eh o memsmo
			if (tabuleiro.casa[i][j].temPeca == true && tabuleiro.casa[i][j].pecaAtualPresente.cor == jogador.peca[numPeca].cor && tabuleiro.casa[i][j].pecaAtualPresente.numeroPeca == numPeca) {
				X = i;
				Y = j;
			}
		}
	}
	
	if (jogador.peca[numPeca].cor == 'b' || jogador.peca[numPeca].cor == 'B') {
		//jogador 1
		if (jogador.peca[numPeca].cor == 'b') {
			//peca normal
			if (X >= 7 || (localMovido == 'D' && Y >= 7) || (localMovido == 'E' && Y <= 0)) {
				return false;
			} else {
				X = X + 1;
				if (localMovido == 'D') {
					Y = Y + 1;
					
					//verifica se tem peca na proxima casa
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//Verifica se a casa tem peca minha
						if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'B' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'b') {
							return false;
						}

						//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
						X = X + 1;
						Y = Y + 1;

						if (X > 7 || Y > 7) { //posicao fora do tabuleiro
							return false;
						}

						//se a proxima casa tiver peca
						if (tabuleiro.casa[X][Y].temPeca == true) {
							//ja nao pode comer
							return false;
						}
					}
				} else {
					Y = Y - 1;

					//verifica se tem peca na proxima casa
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//Verifica se a casa tem peca minha
						if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'B' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'b') {
							return false;
						}

						//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
						X = X + 1;
						Y = Y - 1;


						if (X > 7 || Y < 0) { //posicao fora do tabuleiro
							return false;
						}

						//se a proxima casa tiver peca
						if (tabuleiro.casa[X][Y].temPeca == true) {
							//nao pode comer
							return false;
						}
					}
				}
			}
		} else {
			//dama B
			if (posicao == 'F' && localMovido == 'D') { // frente e direita
				if (X >= 7 || Y >= 7) {
					return false;
				}
				
				X = X + 1;
				Y = Y + 1;
				
				//verifica se tem peca na proxima casa
				if (tabuleiro.casa[X][Y].temPeca == true) {
					//Verifica se a casa tem peca minha
					if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'B' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'b') {
						return false;
					}
				
					//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
					X = X + 1;
					Y = Y + 1;
					
					if (X > 7 || Y > 7) { //posicao fora do tabuleiro
						return false;
					}

					//se a proxima casa tiver peca
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//ja nao pode comer
						return false;
					}
				}
			} else if (posicao == 'F' && localMovido == 'E') { // frente e esquerda
			
				if (X >= 7 || Y <= 0) {
					return false;
				}
			
				X = X + 1;
				Y = Y - 1;
				//verifica se tem peca na proxima casa
				if (tabuleiro.casa[X][Y].temPeca == true) {
					//Verifica se a casa tem peca minha
					if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'B' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'b') {
						return false;
					}
					
					//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
					X = X + 1;
					Y = Y - 1;

					if (X > 7 || Y < 0) { //posicao fora do tabuleiro
						return false;
					}
					
					//se a proxima casa tiver peca
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//nao pode comer
						return false;
					}
				}
			} else if (posicao == 'T' && localMovido == 'D') { // tras e direita
			
				if (X <= 0 || Y >= 7) {
					return false;
				}
				
				X = X - 1;
				Y = Y + 1;
				//verifica se tem peca na proxima casa
				if (tabuleiro.casa[X][Y].temPeca == true) {
					//Verifica se a casa tem peca minha
					if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'B' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'b') {
						return false;
					}
				
					//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
					X = X - 1;
					Y = Y + 1;
					
					if (X < 0 || Y > 7) { //posicao fora do tabuleiro
						return false;
					}

					//se a proxima casa tiver peca
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//ja nao pode comer
						return false;
					}
				}
				
			} else if (posicao == 'T' && localMovido == 'E') { // tras e esquerda
			
				if (X <= 0 || Y <= 0) {
					return false;
				}
			
				X = X - 1;
				Y = Y - 1;
				//verifica se tem peca na proxima casa
				if (tabuleiro.casa[X][Y].temPeca == true) {
					//Verifica se a casa tem peca minha
					if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'B' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'b') {
						return false;
					}
					
					//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
					X = X - 1;
					Y = Y - 1;

					if (X < 0 || Y < 0) { //posicao fora do tabuleiro
						return false;
					}
					
					//se a proxima casa tiver peca
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//nao pode comer
						return false;
					}
				}
			}
		}
	} else {
		//jogador 2
		if (jogador.peca[numPeca].cor == 'p') {
			//peca normal
			if (X <= 0 || (localMovido == 'D' && Y >= 7) || (localMovido == 'E' && Y <= 0)) {
				return false;
			} else {
				X = X - 1;
				if (localMovido == 'D') {
					Y = Y + 1;

					//verifica se tem peca na proxima casa
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//Verifica se a casa tem peca minha
						if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'P' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'p') {
							return false;
						}

						//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
						X = X - 1;
						Y = Y + 1;

						if (X < 0 || Y > 7) { //posicao fora do tabuleiro
							return false;
						}

						//se a proxima casa tiver peca
						if (tabuleiro.casa[X][Y].temPeca == true) {
							//num pode comer
							return false;
						}
					}
				} else {
					Y = Y - 1;

					//verifica se tem peca na proxima casa
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//Verifica se a casa tem peca minha
						if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'P' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'p') {
							return false;
						}

						//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
						X = X - 1;
						Y = Y - 1;

						if (X > 7 || Y < 0) { //posicao fora do tabuleiro
							return false;
						}

						//se a proxima casa tiver peca
						if (tabuleiro.casa[X][Y].temPeca == true) {
							//num pode comer
							return false;
						}
					}
				}
			}
		} else {
			//dama P
			if (posicao == 'F' && localMovido == 'D') { // frente e direita
				if (X <= 0 || Y >= 7) {
					return false;
				}
				
				X = X - 1;
				Y = Y + 1;
				
				//verifica se tem peca na proxima casa
				if (tabuleiro.casa[X][Y].temPeca == true) {
					//Verifica se a casa tem peca minha
					if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'P' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'p') {
						return false;
					}
				
					//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
					X = X - 1;
					Y = Y + 1;
					
					if (X < 0 || Y > 7) { //posicao fora do tabuleiro
						return false;
					}

					//se a proxima casa tiver peca
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//ja nao pode comer
						return false;
					}
				}
			} else if (posicao == 'F' && localMovido == 'E') { // frente e esquerda
			
				if (X < 0 || Y <= 0) {
					return false;
				}
			
				X = X - 1;
				Y = Y - 1;
				//verifica se tem peca na proxima casa
				if (tabuleiro.casa[X][Y].temPeca == true) {
					//Verifica se a casa tem peca minha
					if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'P' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'p') {
						return false;
					}
					
					//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
					X = X - 1;
					Y = Y - 1;

					if (X < 0 || Y < 0) { //posicao fora do tabuleiro
						return false;
					}
					
					//se a proxima casa tiver peca
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//nao pode comer
						return false;
					}
				}
			} else if (posicao == 'T' && localMovido == 'D') { // tras e direita
			
				if (X >= 7 || Y >= 7) {
					return false;
				}
				
				X = X + 1;
				Y = Y + 1;
				//verifica se tem peca na proxima casa
				if (tabuleiro.casa[X][Y].temPeca == true) {
					//Verifica se a casa tem peca minha
					if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'P' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'p') {
						return false;
					}
				
					//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
					X = X + 1;
					Y = Y + 1;
					
					if (X > 7 || Y > 7) { //posicao fora do tabuleiro
						return false;
					}

					//se a proxima casa tiver peca
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//ja nao pode comer
						return false;
					}
				}
				
			} else if (posicao == 'T' && localMovido == 'E') { // tras e esquerda
			
				if (X >= 7 || Y <= 0) {
					return false;
				}
			
				X = X + 1;
				Y = Y - 1;
				//verifica se tem peca na proxima casa
				if (tabuleiro.casa[X][Y].temPeca == true) {
					//Verifica se a casa tem peca minha
					if (tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'P' || tabuleiro.casa[X][Y].pecaAtualPresente.cor == 'p') {
						return false;
					}
					
					//se não for peca minha, verifica se a proxima casa ta vazia, pra ver se pode comer.
					X = X + 1;
					Y = Y - 1;

					if (X > 7 || Y < 0) { //posicao fora do tabuleiro
						return false;
					}
					
					//se a proxima casa tiver peca
					if (tabuleiro.casa[X][Y].temPeca == true) {
						//nao pode comer
						return false;
					}
				}
			}
		}
	}

	return true;
}

void TJogador_Jogar(TTabuleiro *tabuleiro, TJogador *jogador, TJogador *outroJogador,  int numPeca, char localMovido, char posicao) {
	int X, Y;

	//buscando a casa atual que a peça atual esta
	for (int i = 0; i < MAX_CASA; ++i) {
		for (int j = 0; j < MAX_CASA; ++j) {
			if (tabuleiro->casa[i][j].temPeca == true && tabuleiro->casa[i][j].pecaAtualPresente.cor == jogador->peca[numPeca].cor && tabuleiro->casa[i][j].pecaAtualPresente.numeroPeca == numPeca) {
				X = i;
				Y = j;
			}
		}
	}

	if (jogador->peca[numPeca].cor == 'b' || jogador->peca[numPeca].cor == 'B') {
		//jogador 1
		if (jogador->peca[numPeca].cor == 'b') {
			X = X + 1;
			if (localMovido == 'D') {
				Y = Y + 1;

				if (tabuleiro->casa[X][Y].temPeca == true) { // comeu algo

					//removendo a peça que comeu
					X = X - 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X + 1;
					Y = Y + 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X + 1;
					Y = Y + 1;

					if (X == 7) {
						tabuleiro->casa[X][Y].pecaAtualPresente.cor = 'B';
						jogador->peca[numPeca].cor = 'B';
					}
					
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					
					//transforma em dama
					if (X == 7) {
						tabuleiro->casa[X][Y].pecaAtualPresente.cor = 'B';
						jogador->peca[numPeca].cor = 'B';
					}
				
					X = X - 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			} else {
				Y = Y - 1;

				if (tabuleiro->casa[X][Y].temPeca == true) {

					//removendo a peça que comeu
					X = X - 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X + 1;
					Y = Y - 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X + 1;
					Y = Y - 1;
					
					//transnforma em dama
					if (X == 7) {
						tabuleiro->casa[X][Y].pecaAtualPresente.cor = 'B';
						jogador->peca[numPeca].cor = 'B';
					}

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;

					//transformando em Dama
					if (X == 7) {
						tabuleiro->casa[X][Y].pecaAtualPresente.cor = 'B';
						jogador->peca[numPeca].cor = 'B';
					}

					X = X - 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			}
		} else {
			//dama B
			if (posicao == 'F' && localMovido == 'D') {
			
				X = X + 1;
				Y = Y + 1;
			
				if (tabuleiro->casa[X][Y].temPeca == true) { // comeu algo

					//removendo a peça que comeu
					X = X - 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X + 1;
					Y = Y + 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X + 1;
					Y = Y + 1;

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					
					X = X - 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			} else if (posicao == 'F' && localMovido == 'E') {
			
				X = X + 1;
				Y = Y - 1;
			
				if (tabuleiro->casa[X][Y].temPeca == true) {

					//removendo a peça que comeu
					X = X - 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X + 1;
					Y = Y - 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X + 1;
					Y = Y - 1;
					
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;

					X = X - 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			} else if (posicao == 'T' && localMovido == 'D') {
				
				X = X - 1;
				Y = Y + 1;
			
				if (tabuleiro->casa[X][Y].temPeca == true) { // comeu algo

					//removendo a peça que comeu
					X = X + 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X - 1;
					Y = Y + 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X - 1;
					Y = Y + 1;

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					
					X = X + 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			} else if (posicao == 'T' && localMovido == 'E') {
			
				X = X - 1;
				Y = Y - 1;
			
				if (tabuleiro->casa[X][Y].temPeca == true) { // comeu algo

					//removendo a peça que comeu
					X = X + 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X - 1;
					Y = Y - 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X - 1;
					Y = Y - 1;

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					
					X = X + 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			}
		}
	} else {
		//jogador 2
		if (jogador->peca[numPeca].cor == 'p') {

			X = X - 1;
			if (localMovido == 'D') {
				Y = Y + 1;

				if (tabuleiro->casa[X][Y].temPeca == true) {

					//removendo a peça que comeu
					X = X + 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X - 1;
					Y = Y + 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X - 1;
					Y = Y + 1;
					
					//transforma em dama
					if (X == 0) {
						tabuleiro->casa[X][Y].pecaAtualPresente.cor = 'P';
						jogador->peca[numPeca].cor = 'P';
					}

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					
					//transforma em dama
					if (X == 0) {
						tabuleiro->casa[X][Y].pecaAtualPresente.cor = 'P';
						jogador->peca[numPeca].cor = 'P';
					}

					X = X + 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			} else {
				Y = Y - 1;

				if (tabuleiro->casa[X][Y].temPeca == true) {

					//removendo a peça que comeu
					X = X + 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X - 1;
					Y = Y - 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X - 1;
					Y = Y - 1;

					//transforma em dama
					if (X == 0) {
						tabuleiro->casa[X][Y].pecaAtualPresente.cor = 'P';
						jogador->peca[numPeca].cor = 'P';
					}

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;

					//transforma em dama
					if (X == 0) {
						tabuleiro->casa[X][Y].pecaAtualPresente.cor = 'P';
						jogador->peca[numPeca].cor = 'P';
					}

					X = X + 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			}
			
		} else {
			//dama P
			if (posicao == 'F' && localMovido == 'D') {
			
				X = X - 1;
				Y = Y + 1;
			
				if (tabuleiro->casa[X][Y].temPeca == true) { // comeu algo

					//removendo a peça que comeu
					X = X + 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X - 1;
					Y = Y + 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X - 1;
					Y = Y + 1;

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					
					X = X + 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			} else if (posicao == 'F' && localMovido == 'E') {
			
				X = X - 1;
				Y = Y - 1;
			
				if (tabuleiro->casa[X][Y].temPeca == true) {

					//removendo a peça que comeu
					X = X + 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X - 1;
					Y = Y - 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X - 1;
					Y = Y - 1;
					
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;

					X = X + 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			} else if (posicao == 'T' && localMovido == 'D') {
				
				X = X + 1;
				Y = Y + 1;
			
				if (tabuleiro->casa[X][Y].temPeca == true) { // comeu algo

					//removendo a peça que comeu
					X = X - 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X + 1;
					Y = Y + 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X + 1;
					Y = Y + 1;

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					
					X = X - 1;
					Y = Y - 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			} else if (posicao == 'T' && localMovido == 'E') {
			
				X = X + 1;
				Y = Y - 1;
			
				if (tabuleiro->casa[X][Y].temPeca == true) { // comeu algo

					//removendo a peça que comeu
					X = X - 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;

					//Atribuindo os novos valores a peça comida
					X = X + 1;
					Y = Y - 1;
					outroJogador->peca[tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca].comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.comido = true;
					tabuleiro->casa[X][Y].pecaAtualPresente.numeroPeca = -1;
					tabuleiro->casa[X][Y].temPeca = false;

					//Jogando a minha peça pra nova casa dela
					X = X + 1;
					Y = Y - 1;

					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					jogador->comeuPeca = true;
				} else {
					tabuleiro->casa[X][Y].pecaAtualPresente = jogador->peca[numPeca];
					tabuleiro->casa[X][Y].temPeca = true;
					
					X = X - 1;
					Y = Y + 1;
					tabuleiro->casa[X][Y].temPeca = false;
					jogador->comeuPeca = false;
				}
			}
		}
	}
}