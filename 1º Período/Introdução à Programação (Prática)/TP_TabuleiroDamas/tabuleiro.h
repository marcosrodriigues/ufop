#include <iostream>

#define MAX_CASA 8
#define MAX_PECA 12

typedef struct Pecas {
	int numeroPeca;
	bool comido;
	char cor;
}TPecas;

typedef struct Casa {
	bool caminhavel;
	TPecas pecaAtualPresente;
	bool temPeca;
}TCasa;

typedef struct Jogador {
	TPecas peca[MAX_PECA];
	bool comeuPeca;
}TJogador;

typedef struct Tabuleiro {
	TCasa casa[MAX_CASA][MAX_CASA];
}TTabuleiro;

TTabuleiro* TJogo_Inicia (TJogador player1, TJogador player2); //inicia as casas do tabuleiro
TJogador* TJogador_Inicia(int numJogador);//inicia as pecas do jogador
void MostrarJogo (TTabuleiro tabuleiro, TJogador player1, TJogador player2); //mostra o tabuleiro com as pecas
bool TJogador_TemPeca(TTabuleiro tabuleiro, TJogador player, bool terminouJogada); //verifica se o jogador ainda tem alguma peca no jogo
bool pecaExistente(TJogador player, int peca);//verifica se a peca do jogador existe
bool podeJogar(TTabuleiro tabuleiro, TJogador jogador, int numPeca, char localMovido, char posicao);//verifica se o movimento eh valido
void TJogador_Jogar(TTabuleiro *tabuleiro, TJogador *jogador, TJogador *outroJogador, int numPeca, char localMovido, char posicao); //faz o movimento