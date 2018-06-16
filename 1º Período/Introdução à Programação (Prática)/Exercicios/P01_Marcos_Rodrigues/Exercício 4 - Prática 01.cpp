#include <iostream>
#include <cmath>
using namespace std;

int main(){
	//declaração de variáveis
	int Q, K, N, An;
	
	//Leitura de Dados
	cout << "Etre com a razao da P.G: ";
	cin >> Q;
	cout << "Entre com algum termo da P.G: ";
	cin >> K;
	cout << "Digite qual termo deseja saber: ";
	cin >> N;
	
	//Processamentoe
	An = K * (pow(Q, N - K)); // An = K * Qn-ĸ
	
	//Impressão de resultados.
	cout << "O termo " << N << " da PG é : " << An;
	
	return 0;
}
