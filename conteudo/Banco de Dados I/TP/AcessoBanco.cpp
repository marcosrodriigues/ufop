#include <iostream>
#include "libpq-fe.h"
using namespace std;

int main(int argc, char const *argv[]) {
	
	int nTuplas, nAtributos;

	//Declara uma variável lógica que representará o banco de dados
	PGconn *conn = NULL;

	//Cria uma conexao com um banco de dados
	conn = Pqconnectdb ("host=localhost port=5432 dbname=Empresa user=postgres password=postgres");

	//Verifica a conexão feita
	if (PQstatus(conn) != CONNECTION_OK) {

		//Retorna uma mensagem de erro do PostgreSQL
		cout << PQerrorMessage(conn);

		//Encera a conexão com o banco de dados, liberando a memoria
		PQfinish(conn);
		return 1;
	}

	cout << "Conexao executada com sucesso!" << endl;

	//Declara um pontiero para resultado de uma consulta
	PGresult *res;

	//Faz uma consulta ao banco de dados
	res = PGexec(conn, "SELECT * FROM Funcionario;");

	//Verifica a validade da consulta
	if (PGresultStatus(res) != PGRES_TUPLES_OK) {
		cout << PQerrorMessage(conn);
		PQclear(res);
		PQfinish(conn);
		return 2;
	}

	//Obtem o numero de tuplas
	nTuplas = PQntuples(res);
	//Obtem o numero de atributos
	nAtributos = PQnfields(res);

	//Percorre todas as tuplas
	for (int i = 0; i < nTuplas; ++i) {
		//Percorre todos os atributos
		for (int i = 0; i < nAtributos; ++i) {
			//Imprime o valor do atributo J da tupla I
			cout << PQgetvalue(res, i, j) << "\t";
		}
		cout << endl;
	}

	//Fecha o acesso ao resultado da consulta
	PQclear(res);

	//Fecha a conexao com o banco de dados
	PQfinish(conn);

	return 0;
}