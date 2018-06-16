#include <iostream>
#include <cmath>
#define M 2
#define N 6
using namespace std;

double media (double matriz[M][N]);
double desvio (double matriz[M][N]);

int main() {

	double mat[M][N], valMedia, valDesvio;
	
	cout << "Digite " << (M * N) << " valores para comporem a matriz: \n";
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}
	
	valMedia = media(mat);
	valDesvio = desvio(mat);

	cout << "Media: " << valMedia	<< endl;
	cout << "Desvio: " << valDesvio	<< endl;

	return 0;
}

double media (double matriz[M][N]) {

	double somatorio = 0.0;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			somatorio += matriz[i][j];
		}
	}
	
	return somatorio / (M * N);
}

//Base: https://br.answers.yahoo.com/question/index?qid=20071211082353AAvywRV
double desvio (double matriz[M][N]) {

	double desvioMedio = 0.0, desvioQuadrado = 0.0;;
	int divisor = (M * N);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			desvioMedio = matriz[i][j] - media(matriz);
			desvioQuadrado += pow(desvioMedio, 2);
		}
	}
	
	desvioQuadrado = desvioQuadrado / divisor;
	
	return sqrt(desvioQuadrado);
}