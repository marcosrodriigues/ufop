/*
	Marcos Rodrigues - 14.2.4341
	Arquivos I - Exercício 01
*/

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
	//Input File Stream
	ifstream file;
	
	//Output File Stream
	ofstream otherFile;
	double x, y, z;
	
	file.open("ReadFile.txt");
	otherFile.open("WriteFile.txt");
	
	while(!file.eof()) {
		file >> x >> y;
		z = pow(x, 2) + pow(y, 2);
		otherFile << x << "\t" << y << "\t" << z << endl;
	}
	
	file.close();
	otherFile.close();

	return 0;
}