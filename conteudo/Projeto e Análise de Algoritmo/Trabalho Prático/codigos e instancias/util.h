// Varios utilitarios para o programa

#ifndef util_h
#define util_h

#include <vector>
using namespace std;

typedef vector<vector<int> > Grafo;    // Matriz de adjacencias de um grafo
typedef vector<vector<int> > Formula;  // Matriz de clausulas e variaveis

typedef vector<int> Solucao;          // Solucao para os 3 problemas
                                      // Para o clique, a solucao eh uma
                                      // lista contendo o indice dos vertices
                                      // que fazem parte do clique
                                      // Para o conjunto independente, idem
                                      // Para a satisfabilidade, a solucao eh
                                      // uma lista das variaveis e o valor
                                      // 1 ou 0 indica atribuicao V ou F na
                                      // formula

// Computa numero de arestas do grafo
unsigned NumeroArestas(Grafo& g) {
  unsigned n = 0;
  
  for(unsigned i = 0; i < g.size() - 1; i++)
    for(unsigned j = i + 1; j < g.size(); j++)
      n += g[i][j];
  
  return n;
}

// Gera complemento h do grafo g
Grafo Complemento(Grafo& g) {
  Grafo h(g);
  
  for(unsigned i = 0; i < h.size() - 1; i++)
    for(unsigned j = i + 1; j < h.size(); j++)
      h[i][j] = h[j][i] = !h[i][j];
  
  return h;
}

// Reduz uma fórmula para um grafo
Grafo ReducaoSatGrafo(Formula& f) {
  vector<int> indice_i; // Indice i da variavel na matriz f
  vector<int> indice_j; // Indice j da variavel na matriz f
  vector<int> sinal;    // Se variavel esta sem not ou com not
  
  unsigned lin = f.size();
  unsigned col = f[0].size();
  
  // Anota as variaveis que vao virar vertices
  for(unsigned i = 0; i < lin; i++) {
    for(unsigned j = 0; j < col; j++) {
      if(f[i][j] != 2) {
        indice_i.push_back(i);
        indice_j.push_back(j);
        sinal.push_back(f[i][j] == 1);
      }
    }
  }
  
  // Numero de vertices do grafo
  unsigned quant = indice_i.size();
  
  // Cria um grafo sem arestas
  Grafo g;
  if(quant > 0) { // Para evitar criar um grafo nulo
    g.resize(quant, vector<int>(quant, 0));
  }
  
  // Conecta todos as variaveis da mesma clausula
  for(unsigned i = 0; i < quant - 1; i++) {
    for(unsigned j = i + 1; j < quant; j++) {
      if(indice_i[i] == indice_i[j]) {
        g[i][j] = g[j][i] = 1;
      }
    }
  }
  
  // Conecta todas as variaveis com sinal diferente em clausulas diferentes
  for(unsigned i = 0; i < quant - 1; i++) {
    for(unsigned j = i + 1; j < quant; j++) {
      if(indice_j[i] == indice_j[j] && sinal[i] != sinal[j]) {
        g[i][j] = g[j][i] = 1;
      }
    }
  }
  
  return g;  
}

#endif
