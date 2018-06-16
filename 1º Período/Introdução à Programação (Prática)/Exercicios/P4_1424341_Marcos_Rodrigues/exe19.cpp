#include <iostream>
using namespace std;

int main() {
	
	const int MAX = 50;
	
	double vetAltura[MAX], maiorH = 0.00, menorH = 100.00, medAltMulher = 0.0, medAlturaTurma = 0.0;
	int	vetSexo[MAX], totMulher = 0;
	
	for(int i = 0; i < MAX; i++) {
		cin >> vetAltura[i] >> vetSexo[i];
		
		if (vetSexo[i] != 1 && vetSexo[i] != 2) {
			cout << "Sexo invalido.";
			return 1;
		}
		
		if (vetAltura[i] < menorH)
			menorH = vetAltura[i];
			
		if (vetAltura[i] > maiorH)
			maiorH = vetAltura[i];
			
		if (vetSexo[i] == 2) {
			totMulher++;
			medAltMulher = medAltMulher + vetAltura[i];
		}		
		
		medAlturaTurma = medAlturaTurma + vetAltura[i];
	}
	
	medAltMulher = medAltMulher / totMulher;
	medAlturaTurma = medAlturaTurma / MAX;
	
	cout << "Maior Altura: " << maiorH << endl;
	cout << "Menor Altura: " << menorH << endl;
	
	cout << "Mulheres acima da media feminina: " << endl;
	for (int i = 0; i < MAX; i++) {
		if (vetSexo[i] == 2 && vetAltura[i] > medAltMulher) {
			cout << vetAltura[i] << " " << vetSexo[i] << endl;
		}
	}
	
	cout << "Pessoas abaixo da media da turma: " << endl;
	for(int i =0; i < MAX; i++) {
		if (vetAltura[i] < medAlturaTurma)
			cout << vetAltura[i] << vetSexo[i] << endl;
	}
	
	return 0;
}