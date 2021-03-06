#include "io.h"

#include<algorithm>
#include<cmath>

Grafo g;

// Limite inferior, 0 caso seja um grafo vazio, 1 caso contrario
inline unsigned LimiteInferior() {
  return (g.size() > 0 );
}

// Tamanho maximo possivel de um conjunto independente em um grafo
// eh dado pela formula a seguir, vide https://www8.cs.umu.se/kurser/5DA001/HT08/lab2.pdf
inline unsigned LimiteSuperior() {
  unsigned n = g.size();
  unsigned m = NumeroArestas(g);
  return floor((1 + (sqrt(1 - 8 * m - 4 * n + 4 * n * n))) / 2.0);
}

// Quantidade de vertices que podem ser ainda explorados
unsigned NumeroExploraveis(vector<bool>& exploraveis) {
  unsigned e = 0;
  for(unsigned i = 0; i < exploraveis.size(); i++) {
    e += exploraveis[i];
  }
  
  return e;
}

// Indice dos vertices vizinhos do vertice atual que ja nao foram considerados
vector<int> Vizinhos(vector<bool>& exploraveis, unsigned v) {
  vector<int> vizinhos;
  
  for(unsigned j = 0; j < g.size(); j++) {
    if(g[v][j] && exploraveis[j]) {
      vizinhos.push_back(j);
    }
  }
  
  return vizinhos;
}

// BranchAndBound, algoritmo que percorre a arvore de solucoes
// de forma a percorrer apenas ramos promissores para melhorar
// a solucao corrente
Solucao BranchAndBound(Solucao& best, Solucao& s, vector<bool>& exploraveis, 
  unsigned& liminf, unsigned limsup) {
  
  if(s.size() == limsup) return s; // 1: Solucao confirmadamente otima encontrada
  // 2: Quantidade de vertices que faltam explorar nao sao suficientes para melhorar solucao
  if(s.size() + NumeroExploraveis(exploraveis) <= liminf) return s;
  
  // Verifica se encontrou nova melhor solucao (novo limite inferior)
  if(s.size() > liminf) {
    liminf = s.size();
    best = s;
    return s;
  }
  
  // 3: Conjunto independente maximal atingido
  if(find(exploraveis.begin(), exploraveis.end(), true) == exploraveis.end()) return s;
  
  // Percorrendo os vertices nao visitados. Adiciona na solucao atual o próximo
  // Vertice que puder participar e marca os seus vizinhos como nao exploraveis
  for(unsigned i = 0; i < exploraveis.size(); i++) {
    if(exploraveis[i]) {
      s.push_back(i);
      vector<int> vizinhos = Vizinhos(exploraveis, i);
      
      for(unsigned j = 0; j < vizinhos.size(); j++) exploraveis[vizinhos[j]] = false;
      exploraveis[i] = false;
      
      // Explora esse ramo da arvore de decisoes
      BranchAndBound(best, s, exploraveis, liminf, limsup); 
      
      s.pop_back(); // Desfaz a acao deste ramo

      for(unsigned j = 0; j < vizinhos.size(); j++) exploraveis[vizinhos[j]] = true;
      exploraveis[i] = true;
    }
  }
  // Ja percorreu todos os ramos da arvore
  return best;
}


// Funcao preparatoria para o BranchAndBound
Solucao BnB() {
  unsigned liminf = LimiteInferior();
  unsigned limsup = LimiteSuperior();
  
  Solucao best; // Melhor solucao encontrada
  Solucao s; // Solucao atual
  vector<bool> exploraveis(g.size(), true); // Vertices que podem participar
                                           // do conjunto independente atual
  
  return BranchAndBound(best, s, exploraveis, liminf, limsup);
}

int main() {
  ios_base::sync_with_stdio(false);
  // Abrindo as instancias
  
  const int n_tamanhos = 4; // 4 * 4 = 16 tamanhos e densidades diferentes de grafo
  
  int tamanhos[n_tamanhos] = {10, 20, 30, 40}; // Numero de vertices das instancias
  float densidades[n_tamanhos] = {0.2, 0.4, 0.6, 0.8}; // Densidades das instancias
  
  string nomearq;

  for(int i = 0; i < n_tamanhos; i++) {
    for(int j = 0; j < n_tamanhos; j++) {
      cout << endl;
      nomearq = "instancias_grafos/grafo_" + to_string(tamanhos[i]) + "_" + to_string(densidades[j])[2] + ".txt";
      g = CarregaGrafo(nomearq.c_str());

      high_resolution_clock::time_point tempo_inicio = high_resolution_clock::now();
      
      Solucao s = BnB();
      
      high_resolution_clock::time_point tempo_agora = high_resolution_clock::now();
      duration<double> tempo_total = duration_cast<duration <double> > (tempo_agora - tempo_inicio);
      
      cout << "\n-#-#-#-#-#-#-#-\n\n" << nomearq << '\n';
      
      ImprimeSolucaoGrafo(s, tempo_total);
      
      nomearq = "result_indep/grafo_" + to_string(tamanhos[i]) + "_" + to_string(densidades[j])[2] + "_result.txt";
      SalvaSolucaoGrafo(s, tempo_total, nomearq.c_str());
    }
  }
  
  return 0;
}
