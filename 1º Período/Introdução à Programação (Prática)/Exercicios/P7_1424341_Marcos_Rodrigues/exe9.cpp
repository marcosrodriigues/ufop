#include <iostream>
using namespace std;

int main() {

	const int MAX = 10;
	int Matriz[MAX][MAX];
	
	for (int i = 0; i < MAX; i++) 
		for (int j = 0; j < MAX; j++) 
			cin >> Matriz[i][j];
			
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < (MAX - 1 - i); j++) {
			cout << Matriz[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}