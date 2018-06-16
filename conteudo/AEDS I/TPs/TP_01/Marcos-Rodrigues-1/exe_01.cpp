#include "exe_01.h"
#include <cmath>
#include <iostream>
using namespace std;

int Area (TRetangulo r) {
	return r.Altura * r.Largura;
}

float Distancia (TRetangulo r1, TRetangulo r2) {

	float dist = 0.0;
	bool ehDiagonal = false;
	
	int X_01 = r1.X;
	int Larg_01 = r1.Largura + r1.X;
	int Y_01 = r1.Y;
	int Alt_01 = r1.Altura + r1.Y;
	
	int X_02 = r2.X;
	int Larg_02 = r2.Largura + r2.X;
	int Y_02 = r2.Y;
	int Alt_02 = r2.Altura + r2.Y;
	
	/*
	cout << "X_01: " << X_01 << endl;
	cout << "Y_01: " << Y_01 << endl;
	cout << "Larg_01: " << Larg_01 << endl;
	cout << "Alt_01: " << Alt_01 << endl << endl;
	
	cout << "X_02: " << X_02 << endl;
	cout << "Y_02: " << Y_02 << endl;
	cout << "Larg_02: " << Larg_02 << endl;
	cout << "Alt_02: " << Alt_02 << endl;
	*/
	if(((X_02 > Larg_01 || X_01 > Larg_02) && (Y_02 > Alt_01 || Y_02 < Y_01))) {
		ehDiagonal = true;	
	}
	
	if (ehDiagonal) {
		bool direita = false;
		bool acima = false;
		
		direita = (Larg_02 < X_01); // Ret_01 a direita do Ret_02
		acima = (Y_01 > Alt_02); // Ret_01 acima do Ret_02
		
		if (direita && acima) {
			dist = sqrt(pow(X_01 - Larg_02, 2) + pow(Y_01 - Alt_02, 2));
		} else if (!direita && acima ) {
			dist = sqrt(pow(X_02 - Larg_01, 2) + pow(Y_01 - Alt_02, 2));
		} else if (direita && !acima) {
			dist = sqrt(pow(X_01 - Larg_02, 2) + pow(Y_02 - Alt_01, 2));
		} else {
			dist = sqrt(pow(X_02 - Larg_01, 2) + pow(Y_02 - Alt_01, 2));
		}
		
		/*
		switch(acima, direita) {
			case true & true:
				break;
			case true & false:
				break;
			default:
				break;
		}
		
		switch(acima, direita) {
			case true & true:
				//cout << "Acima e a Direita" << endl;
				break;
			case true & false:
				//cout << "Acima e a Esquerda" << endl;
				break;
			case false & true:
				//cout << "Abaixo e  Direita" << endl;
				break;
			case false & false:
				//cout << "Abaixo e a Esquerda" << endl;
				break;
			default:
				//cout << "Invalido" << endl;
				break;
		}
		*/
		
	} else {
		if (Larg_01 < X_02) { // Ret_01 a esquerda do Ret_02
			dist = X_02 - Larg_01;
		} else if (Larg_02 < X_01) { // Ret_01 a direita do Ret_02
			dist = X_01 - Larg_02;
		} else if (Y_01 > Alt_02) { // Ret_01 acima do Ret_02
			dist = Y_01 - Alt_02;
		} else if (Y_02 > Alt_01) { // Ret_01 abaixo do Ret_02
			dist = Y_02 - Alt_01;
		}
	}

	return dist;
}

int Intersecao (TRetangulo r1, TRetangulo r2) {
	
	int area = 0;
	
	int X_01 = r1.X;
	int Larg_01 = r1.Largura + r1.X;
	int Y_01 = r1.Y;
	int Alt_01 = r1.Altura + r1.Y;
	
	int X_02 = r2.X;
	int Larg_02 = r2.Largura + r2.X;
	int Y_02 = r2.Y;
	int Alt_02 = r2.Altura + r2.Y;

	TRetangulo *ret = new TRetangulo;
	
	if 	(Alt_02 > Y_01 && Alt_01 > Alt_02 && Larg_02 > X_01 && Larg_01 > Larg_02) { // esquerda e abaixo
		int x, y, X, Y, Alt, Larg;
		x = X_02;
		X = Larg_01;
		y = Y_02;
		Y = Alt_01;
		
		Alt = Y - y;
		Larg = X - x;
		
		area = Alt * Larg;
	} else if (Alt_01 > Y_02 && Alt_02 > Alt_01 &&  Larg_02 > X_01 && Larg_01 > Larg_02) { // esquerda e acima
		int x, y, X, Y, Alt, Larg;
		x = X_01;
		y = Y_01;;
		X = Larg_02;
		Y = Alt_02;
		
		Alt = Y - y;
		Larg = X - x;
		
		area = Alt * Larg;
	} else if (Larg_01 > X_02 && Larg_02 > Larg_01 && Alt_02 > Y_01 && Alt_01 > Alt_02) { //direita e abaixo
		int x, y, X, Y, Alt, Larg;
		x = Larg_02;
		X = X_01;
		y = Y_01;
		Y = Alt_02;
		
		Alt = Y - y;
		Larg = X - x;
		
		area = Alt * Larg;
	} else if (Larg_01 > X_02 && Larg_02 > Larg_01 && Alt_01 > Y_02 && Alt_02 > Alt_01) { // direita e acima
		int x, y, X, Y, Alt, Larg;
		x = X_02;
		y = Y_02;;
		X = Larg_01;
		Y = Alt_01;
		
		Alt = Y - y;
		Larg = X - x;
		
		area = Alt * Larg;
	} else if ((Alt_02 >= Alt_01 && Alt_01 >> X_02) && (X_01 <= X_02 && Larg_01 >= Larg_02) ) { // somente acima
		int x, y, X, Y, Alt, Larg;
		x = X_02;
		X = Larg_02;
		
		Alt = Alt_01 - Y_02;
		Larg = X - x;
		
		area = Alt * Larg;
	} else if ((Alt_01 >= Alt_02 && Y_01 <= Y_02) && (Larg_01 > X_02 && X_02 >= X_01 && Larg_02 > Larg_01)) { // somente a direita
		int x, y, X, Y, Alt, Larg;
		y = Y_02;
		Y = Alt_02;
		x = X_02;
		X = Larg_01;
		
		Alt = Y - y;
		Larg = X - x;
		
		area = Alt * Larg;
	} else if ((X_01 <= X_02 && Larg_01 >= Larg_02) && (Alt_02 > Y_01 && Y_01 <= Y_02)) { // somente abaixo
		int x, y, X, Y, Alt, Larg;
		x = X_02;
		X = Larg_02;
		y = Y_01;
		Y = Alt_02;
		
		Alt = Y - y;
		Larg = X - x;
		
		area = Alt * Larg;
	} else { // somente a esquerda
		int x, y, X, Y, Alt, Larg;
		x = X_01;
		X = Larg_02;
		y = Y_01;
		Y = Alt_01;
		
		Alt = Y - y;
		Larg = X - x;
		
		area = Alt * Larg;
	}
	
	if (area < 0)
		area = area * -1;
	
	return area;
}

bool haIntersecao (TRetangulo r1, TRetangulo r2) {
	return (((r1.Altura + r1.Y) >= r2.Y && r2.Y >= r1.Y) && ((r1.Largura + r1.X) >= r2.X && r2.X >= r1.X));
}