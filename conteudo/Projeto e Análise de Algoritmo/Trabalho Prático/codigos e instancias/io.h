// Escrita e leitura das instancias e solucoes

#ifndef io_h
#define io_h

#include "util.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <chrono>

using namespace std::chrono;

// Geracao de numero aleatorio entre 0 e 1
unsigned semente = system_clock::now().time_since_epoch().count();
default_random_engine gerador(semente);
uniform_real_distribution<float> distrib(0.0, 1.0);

// Cria um grafo aleatorio com n numero de vertices
// A chance de ter uma aresta entre dois vertices eh determinada pela probabilidade p (entre 0 e 1)
Grafo CriaGrafo(unsigned n, float p) {
  Grafo g(n, vector<int>(n, 0));
  
  for(unsigned i = 0; i < n - 1; i++) {
    for(unsigned j = i + 1; j < n; j++) {
      // Se o numero aleatorio for menor que p, cria adjacencia entre vertices
      float chance = distrib(gerador);
      if(chance < p) {
        g[i][j] = g[j][i] = 1;
      }
    }
  }
  
  return g;
}

// Leitura de um grafo salvo em arquivo
Grafo CarregaGrafo(const char* nomearq) {
  unsigned n; // Numero de vertices
  int valor;  // Valor 0 ou 1 lido
  
  ifstream arq(nomearq);
  if(!arq.is_open()) {
		cerr << "\nERRO: Arquivo nao encontrado\n";
		return Grafo();
	}
  
  arq >> n;
  Grafo g(n, vector<int>(n, 0));
  
  for(unsigned i = 0; i < n; i++) {
    for(unsigned j = 0; j < n; j++) {
      arq >> valor;
      g[i][j] = valor;
    }
  }
  
  arq.close();
  return g;
}

// Escrita de um grafo em arquivo
void SalvaGrafo(Grafo& g, const char* nomearq) {
  ofstream arq(nomearq);
  if(!arq.is_open()) {
		cerr << "\nERRO: Impossivel criar arquivo\n";
		return;
	}
  
  arq << g.size() << '\n';
  
  for(unsigned i = 0; i < g.size(); i++) {
    for(unsigned j = 0; j < g.size(); j++) {
      arq << g[i][j] << ' ';
    }
    arq << '\n';
  }
  
  arq.close();
}

// Imprime matriz de adjacencias do grafo g
void ImprimeGrafo(Grafo& g) {
  cout << "\nMatriz de adjacencias do grafo:\n";
  for(unsigned i = 0; i < g.size(); i++) {
    for(unsigned j = 0; j < g.size(); j++) {
      cout << g[i][j] << ' ';
    }
    cout << '\n';
  }
}

// Cria uma formula booleana com c clausulas e v variaveis,
// Com a chance p de uma variavel participar de cada clausula,
// Com 50% de chance de ter valor negado se participar
Formula CriaFormula(unsigned c, unsigned v, float p) {
  Formula f(c, vector<int>(v, 2));
  
  for(unsigned i = 0; i < c; i++) {
    for(unsigned j = 0; j < v; j++) {
      // Se o numero aleatorio for menor que p,  a variavel j participa da clausula i
      // Se o numero for menor que p/2, a  variavel tera valor negado
      float chance = distrib(gerador);
      if(chance < p / 2)
        f[i][j] = 0;
      else if(chance < p)
        f[i][j] = 1;
    }
  }
  return f;
}

// Leitura de uma formula salva em arquivo
Formula CarregaFormula(const char* nomearq) {
  unsigned v;           // Numero de variaveis
  vector<int> valores;  // Valor 0, 1 ou 2 lido
  ifstream arq(nomearq);
  if(!arq.is_open()) {
		cerr << "\nERRO: Arquivo nao encontrado\n";
		return Formula();
	}

  Formula f;
  arq >> v;
  valores.resize(v);
  unsigned i = 0;
  while(arq >> valores[i++]) {
    while(i < v) {
      arq >> valores[i++];
    }
    f.push_back(valores);
    i = 0;
  }
  
  arq.close();
  return f;
}

// Escrita de uma formula em arquivo
void SalvaFormula(Formula& f, const char* nomearq) {
  ofstream arq(nomearq);
  if(!arq.is_open()) {
		cerr << "\nERRO: Impossivel criar arquivo\n";
		return;
	}
  
  arq << f[0].size() << '\n';
  
  for(unsigned i = 0; i < f.size(); i++) {
    for(unsigned j = 0; j < f[i].size(); j++) {
      arq << f[i][j] << ' ';
    }
    arq << '\n';
  }
  
  arq.close();
}

// Imprime formula booleana
void ImprimeFormula(Formula& f) {
  cout << "\nFormula booleana na forma normal conjuntiva simplificada:\n";
  for(unsigned i = 0; i < f.size(); i++) {
    for(unsigned j = 0; j < f[i].size(); j++) {
      cout << f[i][j] << ' ';
    }
    cout << '\n';
  }
}

// Escrita de uma solucao de grafos em arquivo
void SalvaSolucaoGrafo(Solucao& s, duration<double>& tempo, const char* nomearq) {
  ofstream arq(nomearq);
  if(!arq.is_open()) {
		cerr << "\nERRO: Impossivel criar arquivo\n";
		return;
	}
  
  arq << s.size() << '\n' << tempo.count() << '\n';
  
  for(unsigned i = 0; i < s.size(); i++) {
    arq << s[i] << ' ';
  }
  
  arq.close();
}

// Escrita de uma solucao de satisfabilidade em arquivo
void SalvaSolucaoFormula(Solucao& s, duration<double>& tempo, const char* nomearq) {
  ofstream arq(nomearq);
  if(!arq.is_open()) {
		cerr << "\nERRO: Impossivel criar arquivo\n";
		return;
	}
  
  arq << tempo.count() << '\n';
  
  for(unsigned i = 0; i < s.size(); i++) {
    arq << s[i] << ' ';
  }
  
  arq.close();
}

// Imprime solucao dos problemas de grafos
void ImprimeSolucaoGrafo(Solucao& s, duration<double>& tempo) {
  cout << "\nTempo de execucao em segundos: " << tempo.count() << '\n';
  cout << "\nMelhor solucao encontrada: " << s.size() << "\nVertices:";
  
  for(unsigned i = 0; i < s.size(); i++) {
    cout << ' ' << s[i];
  }
  cout << '\n';
}

// Imprime solucao do problema de satisfabilidade
void ImprimeSolucaoFormula(Solucao& s, duration<double>& tempo) {
  cout << "\nTempo de execucao em segundos: " << tempo.count() << '\n'; 
  cout << "\nMelhor solucao encontrada: " << s.size() << "\nVertices:";
  
  for(unsigned i = 0; i < s.size(); i++) {
    cout << ' ' << s[i];
  }
  cout << '\n';
}
#endif