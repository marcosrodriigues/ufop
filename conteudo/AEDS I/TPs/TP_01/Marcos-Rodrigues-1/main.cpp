#include "exe_01.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	TRetangulo *ret;
	int qtd;
	
	cin >> qtd;
	
	ret = new TRetangulo[qtd];
	
	for (int i = 0; i < qtd; i++) {
		cin >> ret[i].Altura;
		cin >> ret[i].Largura;
		cin >> ret[i].X;
		cin >> ret[i].Y;
	}
	
	for (int i = 0; i < qtd; i++) {
		cout << "Area retangulo " << i << ": " << Area(ret[i]) << endl;		
	}
	
	cout << endl;
	
	for (int i = 0; i < qtd - 1; i++) {
		for(int j = i; j < qtd - 1; j++) {
			if(!haIntersecao(ret[i], ret[j + 1])) {
				cout << "d(" << i << "," << j + 1 << "): " << fixed << setprecision(2) << Distancia(ret[i], ret[j + 1]) << endl;	
			} else {
				cout << "I(" << i << "," << j + 1 << "): " << Intersecao(ret[i], ret[j + 1]) << endl;
			}
		}
	}
		
	return 0;
}