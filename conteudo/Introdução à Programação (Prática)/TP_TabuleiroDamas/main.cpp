#ifdef WIN32
#define CLEAR true
#else
#define CLEAR false
#endif

#include "tabuleiro.h"
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main () {

	TTabuleiro *tabuleiro;
	TJogador *player1, *player2, *playerAux, *otherPlayerAux;

	player1 = TJogador_Inicia(1);
	player2 = TJogador_Inicia(2);

	tabuleiro = TJogo_Inicia(*player1, *player2);

	int nextPlayer = 1;
	char nextCollor = 'b';

	int pecaMovida;
	char localMovido, posicao;
	
	bool andarNovamente = false;
	char resp = 'N';
	do {
		
		if(CLEAR == true) //limpa a tela
			system("cls");
		else
			system("clear");
			
		cout << "Jogador " << nextPlayer << " - Pecas " << nextCollor << endl;

		if(nextPlayer == 1) {
			playerAux = player1;
			otherPlayerAux = player2;
		} else {
			playerAux = player2;
			otherPlayerAux = player1;
		}

		do {
			do {

				MostrarJogo(*tabuleiro, *player1, *player2);

				if(andarNovamente == false) {
					do {
						cout << "Numero da peca que deseja mover: " << endl;
						cin >> pecaMovida;
					} while ((pecaMovida > 11 || pecaMovida < 0) && (pecaExistente(*playerAux, pecaMovida)));
				}
					
				do {
					cout << "Diagonal que deseja mover ('D' | 'E'): " << endl;
					cin >> localMovido;
				} while (localMovido != 'D' && localMovido != 'E');
				
				if (playerAux->peca[pecaMovida].cor == 'B' || playerAux->peca[pecaMovida].cor == 'P') {
					do {
						cout << "Deseja mover para frente ou para tras ('F' | 'T') ?" << endl;
						cin >> posicao;
					} while (posicao != 'F' && posicao != 'T');
				}

			} while (podeJogar(*tabuleiro, *playerAux, pecaMovida, localMovido, posicao) == false);

			TJogador_Jogar(tabuleiro, playerAux, otherPlayerAux, pecaMovida, localMovido, posicao);

			if (playerAux->comeuPeca == true) {
				playerAux->comeuPeca = false;
				
				do {
					cout << "Deseja andar novamente com a peca " << pecaMovida << " (S | N)" << endl;
					cin >> resp;
				} while (resp != 'S' && resp != 'N');
				
				if (resp == 'S') {
					if(podeJogar(*tabuleiro, *playerAux, pecaMovida, 'D', ' ') == true || podeJogar(*tabuleiro, *playerAux, pecaMovida, 'E', ' ') == true)
						andarNovamente = true;
					else {
						cout << "Peca " << pecaMovida << " nao tem movimentos validos." << endl;
						
						cin.ignore(1024, '\n');
						cout << "Digite enter para continuar" << endl;
						cin.get();
		
						andarNovamente = false;
					}
				} else
					andarNovamente = false;
					
			} else {
				andarNovamente = false;
			}
			
		} while (andarNovamente == true && TJogador_TemPeca(*tabuleiro, *otherPlayerAux, false));
	
		if (nextPlayer == 1)
			nextPlayer = 2;
		else
			nextPlayer = 1;
			
		if (nextCollor == 'b')
			nextCollor = 'p';
		else
			nextCollor = 'b';

	} while (TJogador_TemPeca(*tabuleiro, *otherPlayerAux, true));


	if (TJogador_TemPeca(*tabuleiro, *player1, true))
		cout << "Parabens Jogador 1, voce ganhou !!!" << endl;
	else if (TJogador_TemPeca(*tabuleiro, *player2, true))
		cout << "Parabens Jogador 2, voce ganhou !!!" << endl;
	else
		cout << "Game Over !!!" << endl;

	return 0;
}
