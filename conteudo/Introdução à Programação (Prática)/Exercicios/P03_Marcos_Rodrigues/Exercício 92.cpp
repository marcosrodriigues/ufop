/*
	Numa universidade cada aluno possui os seguintes dados: 
		-  Renda pessoal; 
		-  Renda familiar; 
		-  Total gasto com alimentação; 
		-  Total gasto com outras despesas; 
	Criar  um  programa  que  imprima  a  porcentagem  dos  alunos  que  gasta  acima  de  R$ 200,00 com outras despesas, 
	o número de alunos com  renda pessoal maior que renda familiar  e  a  porcentagem  gasta  com  alimentação  e  
	outras  despesas  em  relação  às rendas pessoal e familiar. 
	O programa acaba quando se digita 0 para a renda pessoal.
*/
#include <iostream>
using namespace std;

int main() {
	
	double rendaPessoal, rendaFamilia, gastoAlimentacao, gastoDespesas, porcentagem200 = 0.0, porcentagem = 0.0;
	int numAlunos, count = 0, count200 = 0, countRenda = 0;
	
	cout << "Digite a renda pessoal do aluno: \n";
	cin >> rendaPessoal;
	
	while (rendaPessoal != 0.0) {
		count++;
		
		cout << "Digite a renda familiar do aluno: \n";
		cin >> rendaFamilia;
		cout << "Digite o total de gasto com a alimentacao: \n";
		cin >> gastoAlimentacao;
		cout << "Digite o total de gasto com a outras despesas: \n";
		cin >> gastoDespesas;
		
		if (gastoDespesas > 200.00) count200++;
		if (rendaPessoal > rendaFamilia) countRenda++;
		porcentagem = ((gastoDespesas + gastoAlimentacao) / (rendaFamilia + rendaPessoal)) * 100;
		
		cout << "A porcentagem gasta com alimentacao e outras despesas em relacao as rendas pessoal e familiar eh " << porcentagem << "%\n\n";
		
		cout << "Digite a renda pessoal do aluno: \n";
		cin >> rendaPessoal;
	}
	
	porcentagem200 = ((double)count200 / count) * 100;
	
	cout << "A porcentagem dos alunos que possuem gasto acima de R$ 200,00 com outras despesas eh: " << porcentagem200 << "%\n";
	cout << "O numero de alunos que posusem a renda pessoal superior a renda familiar eh: " << countRenda << "\n";
	
	return 0;
}