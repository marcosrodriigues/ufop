/*
	 Escreva um programa que: 
		-  leia 100 fichas, onde cada ficha contém o número de matrícula e a nota de cada aluno de um determinado curso; 
		-  determine e imprima as duas maiores notas, juntamente com o número de matrícula do aluno que obteve cada uma delas; 
		-  Suponha que não exista dois ou mais alunos com a mesma nota. 
*/

#include <iostream>
using namespace std;

int main() {
	
	double nota, notaMaior = 0.0, notaMaior2 = 0.0;
	int matricula, maiorMatricula = 0, maiorMatricula2 = 0;
	
	for (int i = 1; i <= 5; i++) {
		cout << "Digite o valor da Matricula e a nota do aluno: \n";
		cin >> matricula >> nota;
		
		if (nota > notaMaior) {
			//Atribuindo o valor da "nota/matricula maior" pra "segunda nota/matricula maior".
			notaMaior2 = notaMaior;
			maiorMatricula2 = maiorMatricula;
			
			notaMaior = nota;
			maiorMatricula = matricula;
		} else if (nota > notaMaior2) { //usou-se else-if pois não existem dois ou mais alunos com a mesma nota.
			notaMaior2 = nota;
			maiorMatricula2 = matricula;
		}
	}
	
	cout << "Maior nota: " << notaMaior << ", pertencente a matricula " << maiorMatricula << "\n";
	cout << "Segunda maior nota: " << notaMaior2 << ", pertencente a matricula " << maiorMatricula2 << "\n";
	
	return 0;
}