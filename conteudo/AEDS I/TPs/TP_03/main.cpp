#include "THash.h"
#include <assert.h>
#include <stdlib.h>

using namespace std;


int main() {
	
	string a;
	int o;
	float x;
int i = 0;

	do {
		cin >> o;

		cin.ignore();
		cin.clear();
		getline(cin, a);
		cout << a << endl;

		getline(cin, a);
		cout << a << endl;

		cin >> o;
		cout << o << endl;

		cin >> x;
		cout << x << endl;

		cin >> o;
		cout <<"proximo: " << o << endl;
		i++;

		//if (i == 10) return 0;
		//return 0;

	}while(o != 6);

	/*	Declaração de Variáveis	*/
	int opMenu;
	THash *hash = THash_Inicia();
	TCidade *cidade = new TCidade;

	/*	Hash instanciado ? */
	if(hash == NULL || cidade == NULL) {
		cout << "Insuficient Memory !!!" << endl;
		return 1;
	}

	/*	Programa principal	*/
	do {
		cOut("DIGITE O QUE DESEJA FAZER");
		cout << "	1 - Inserir nova cidade: "				<< endl;
		cout << "	2 - Editar cidade por nome: "			<< endl;
		cout << "	3 - Excluir cidade por nome: " 			<< endl;
		cout << "	4 - Pesquisar dados de alguma cidade: " << endl;
		cout << "	5 - Exibir todos os registros: "		<< endl;
		cout << "	6 - Encerrar programa: " 				<< endl;
		
		cin >> opMenu;
		
		switch(opMenu) {
			case 1: //Inserir nova cidade;
				cout << "Insira a UF da cidade: " 			<< endl;
				getline(cin, cidade->uf);
				cidade->uf = strToUpper(cidade->uf);

				cout << "Insira o nome da cidade: " 		<< endl;
				getline(cin, cidade->nome);

				do {
					cout << "Insira a populacao da cidade: "	<< endl;
					cin >> cidade->populacao;
				} while (cidade->populacao < 0);

				do {
					cout << "Insira o IDH da cidade (Entre 0 e 1): " << endl;
					cin >> cidade->IDH;
				} while (cidade->IDH < 0 || cidade->IDH > 1);
				
				cout << ((THash_Insere(hash, *cidade) == 1) ? "Cidade inserida com sucesso." :  "Cidade ja cadastrada") << endl;
				break;
			case 2: //Editar cidade
				cout << "Insira a UF da cidade: " 			<< endl;
				getline(cin, cidade->uf);
				cidade->uf = strToUpper(cidade->uf);

				cout << "Insira o nome da cidade: " 		<< endl;
				getline(cin, cidade->nome);

				if(THash_Pesquisa(hash, cidade) == 0)
					cOut("BUSCA NAO REALIZADA - REGISTRO NAO ENCONTRADO");
				else {
					cOut("BUSCA REALIZADA COM SUCESSO");
					TCidade_MostrarDados(*cidade, true);

					do {
						cOut("DIGITE O QUE DESEJA EDITAR");
						cout << "	1 - Populacao" 			<< endl;
						cout << "	2 - IDH" 				<< endl;
						cout << "	3 - Populacao e IDH"	<< endl;
						cout << "	4 - Cancelar" 		<< endl;
						cin >> opMenu;
					} while (opMenu < 1 || opMenu > 4);
					
					switch(opMenu) {
						case 1:
							do {
								cout << "Insira a populacao da cidade: "	<< endl;
								cin >> cidade->populacao;	
							} while (cidade->populacao < 0);
							break;
						case 2:
							do {
								cout << "Insira o novo IDH da cidade (Entre 0 e 1): " << endl;
								cin >> cidade->IDH;
							} while (cidade->IDH < 0 || cidade->IDH > 1);
							break;
						case 3:
							do {
								cout << "Insira a populacao da cidade: "	<< endl;
								cin >> cidade->populacao;	
							} while (cidade->populacao < 0);

							do {
								cout << "Insira o novo IDH da cidade (Entre 0 e 1): " << endl;
								cin >> cidade->IDH;
							} while (cidade->IDH < 0 || cidade->IDH > 1);

							break;
						case 4:
							continue;
							break;
					}



					cout << ((THash_Edita(hash, *cidade) == 1) ? "Cidade alterada com sucesso." :  "Cidade nao alterada, elemento nao encontrado") << endl;
				}
				break;
			case 3:	// Excluir cidade

				cout << "Insira a UF da cidade: " 			<< endl;
				getline(cin, cidade->uf);
				cidade->uf = strToUpper(cidade->uf);

				cout << "Insira o nome da cidade: " 		<< endl;
				getline(cin, cidade->nome);

				if(THash_Pesquisa(hash, cidade) == 0)
					cOut("BUSCA NAO REALIZADA - REGISTRO NAO ENCONTRADO");
				else {
					cOut("BUSCA REALIZADA COM SUCESSO");
					TCidade_MostrarDados(*cidade, true);
					do {
						cout << "Deseja realmente excluir esta cidade? (1 -> Sim | 0 -> Nao)"<< endl;
						cin >> opMenu;
					} while (opMenu < 0 || opMenu > 1);

					if (opMenu == 1)
						cout << ((THash_Excluir(hash, *cidade) == 1) ? "Cidade excluida com sucesso !!!" : "Erro ao excluir cidade")  << endl;
				}
				break;
			case 4:	//Buscar cidade
				cout << "Digite a UF da cidade que deseja buscar: " 	<< endl;
				getline(cin, cidade->uf);
				cidade->uf = strToUpper(cidade->uf);

				cout << "Insira o nome da cidade que deseja buscar: " 	<< endl;
				getline(cin, cidade->nome);

				if(THash_Pesquisa(hash, cidade) == 0)
					cOut("BUSCA NAO REALIZADA - REGISTRO NAO ENCONTRADO");
				else {
					cOut("BUSCA REALIZADA COM SUCESSO");
					TCidade_MostrarDados(*cidade, true);
				}

				break;
			case 5: // Exibir todos os registros
					if(THash_PesquisarTodos(*hash) == 0)
						cOut("NENHUM REGISTRO ENCONTRADO");
					
				break;
			case 6: // Encerrar programa
				cOut("Obrigado por usar o programa.");
				return 0;
				break;
			default:
				cOut("Opcao Invalida. Tente novamente");
				break;
		}

	} while (opMenu != 6);


	return 0;
}

