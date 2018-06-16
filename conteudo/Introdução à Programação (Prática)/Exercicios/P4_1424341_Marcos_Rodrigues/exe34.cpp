#include <iostream>
using namespace std;

int main() {

	const int MAX = 10;

	int vInscricao[MAX + 1] = { }, vResultInsc[MAX + 1] = { }, iAux;
	double vTempo[MAX + 1] = { }, vResultTempo[MAX + 1] = { }, dAux;
	
	int iMaiorTempo = 0, primeiraPosicao = 0, ultimaPosicao = (MAX - 1);
	
	for (int i = 0; i < MAX; i++) {
		do {
			cout << "Digite o numero da inscricao e o tempo de corrida do " << i + 1 << ". corredor: ";
			cin >> vInscricao[i] >> vTempo[i];
		} while (vInscricao[i] <= 0 || vInscricao[i] > MAX);
	}
	
	for (int i = 0; i < MAX; i++) {
		for (int j = i; j < MAX; j++) {
			if (j < (MAX - 1) && vTempo[j] > vTempo[j + 1]) {
				dAux = vTempo[j];
				iAux = vInscricao[j];
				
				vTempo[j] = vTempo[j + 1];
				vInscricao[j] = vInscricao[j+1];
				
				vTempo[j+1] = dAux;
				vInscricao[j+1] = iAux;
			}
		}
	}
	
	for (int i = (MAX - 1); i >= 0; i--) {
		cout << (i + 1) << ". lugar: Inscricao " << vInscricao[i] << " com o tempo " << vTempo[i] << endl;
	}

	return 0;
}
