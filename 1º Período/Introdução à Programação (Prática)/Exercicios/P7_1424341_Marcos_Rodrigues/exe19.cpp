#include <iostream>
#define LIN 5
#define COL 10
using namespace std;

int main() {
	
	double Matriz[LIN][COL], maiorAlt = -1;
	
	for (int i = 0; i < LIN; i++)
		for (int j = 0; j < COL; j++)
			cin >> Matriz[i][j];
			
	for (int i = 0; i < LIN; i++) {
		maiorAlt = -1;
		for (int j = 0; j < COL; j++) {
			if (Matriz[i][j] >= maiorAlt)	maiorAlt = Matriz[i][j];
		}
		cout << maiorAlt << endl;
	}
	
	return 0;
}