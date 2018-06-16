/*
	Marcos Rodrigues - 14.2.4341
	Arquivos I - Exercício 02
*/

#include <iostream>
#include <string>
#include <fstream>
#define MAX 100
using namespace std;

int main() {
	//Input File Stream
	ifstream file;
	//Output File Stream
	ofstream otherFile;

	string line[MAX];
	int countLine = 0;
	
	file.open("ReadFile.txt");
	while (!file.eof()) {
		if (countLine >= MAX)
			break;
		
		getline(file, line[countLine]);
		countLine++;
	}
	
	otherFile.open("WriteFile.txt");
	for (int i = countLine - 1; i >= 0; i--) {
		otherFile << line[i] << endl;
	}
	
	file.close();
	otherFile.close();
	
	return 0;
}