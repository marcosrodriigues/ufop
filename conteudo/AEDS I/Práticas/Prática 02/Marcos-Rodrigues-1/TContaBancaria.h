#include <string>
using namespace std;
typedef struct ContaBancaria (
	int numeroConta;
	double saldo;
)TContaBancaria;

void setContaBancaria (TContaBancaria *conta, int numConta, double saldoInicial);
void imprimirSaldo (TContaBancaria conta, int numConta, int qtdContasAbertas);
void sacarValor (TContaBancaria *conta, int numConta, double qtd, int qtdContasAbertas);
void depositarValor (TContaBancaria *conta, int numConta, double qtd, int qtdContasAbertas);
int procurarConta (TContaBancaria conta, int numContam, int totalContas);
void toWrite(string message);