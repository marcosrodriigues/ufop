#include <iostream>
using namespace std;

int main() {

	double A, B, C, D;
	
	cout << "Digite quatro valores: \n";
	cin >> A >> B >> C >> D;
	
	//Verificando o maior numero
	cout << "O maior numero eh: ";
	if(A >= B && A >= C && A >= D)
		cout << A;
	else if (B >= C && B >= D)
		cout << B;
	else if (C >= D)
		cout << C;
	else 
		cout << D;
	
	cout << "\n";
	
	//Verificando o menor numero
	cout << "O menor numero eh: ";
	if(A <= B && A <= C && A <= D)
		cout << A;
	else if(B <= C && B <= D)
		cout << B;
	else if(C <= D)
		cout << C;
	else 
		cout << D;
	cout << "\n";

	return 0;
}