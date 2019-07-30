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

  for(unsigned j = 0; j < g.size(); j++)
    if(g[v][j] && exploraveis[j]) 
      vizinhos.push_back(j);

  return vizinhos;
}

// BranchAndBound, algoritmo que percorre a arvore de solucoes
// de forma a percorrer apenas ramos promissores para melhorar
// a solucao corrente
Solucao BranchAndBound(Solucao& best, Solucao& s, vector<bool>& exploraveis, unsigned& liminf, unsigned limsup) {
  // Casos base, 3 ao todo
  if(s.size() == limsup) return s; // 1: Solucao confirmadamente otima encontrada
  
  if(s.size() + NumeroExploraveis(exploraveis) <= liminf) return s;
                                   // 2: Quantidade de vertices que faltam explorar
                                   // nao sao suficientes para melhorar solucao
  
  // Verifica se encontrou nova melhor solucao (novo limite inferior)
  if(s.size() > liminf) {
    liminf = s.size();
    best = s;
    return s;
  }
  
  if(find(exploraveis.begin(), exploraveis.end(), true) == exploraveis.end()) return s;
                                   // 3: Conjunto independente maximal atingido
  
  // Percorrendo os vertices nao visitados
  // Adiciona na solucao atual o proximo vertice que puder participar
  // e marca os seus vizinhos como nao exploraveis
  for(unsigned i = 0; i < exploraveis.size(); i++) {
    if(exploraveis[i]) {
      s.push_back(i);
      vector<int> vizinhos = Vizinhos(exploraveis, i);
      
      for(unsigned j = 0; j < vizinhos.size(); j++) {
        exploraveis[vizinhos[j]] = false;
      }
      exploraveis[i] = false;
      
      // Explora esse ramo da arvore de decisoes
      BranchAndBound(best, s, exploraveis, liminf, limsup);
      
      // Desfaz a acao deste ramo
      s.pop_back();
      for(unsigned j = 0; j < vizinhos.size(); j++) {
        exploraveis[vizinhos[j]] = true;
      }
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

  // Vertices que podem participar do conjunto independente atual
  vector<bool> exploraveis(g.size(), true); 
  return BranchAndBound(best, s, exploraveis, liminf, limsup);
}

int main() {
  ios_base::sync_with_stdio(true);
  // Abrindo as instancias

  const int n_clausulas = 4; // 4 numero de clausulas diferentes
  const int n_variaveis = 4; // 4 numero de variaveis diferentes
  
  int clausulas[n_clausulas] = {2, 4, 6, 8};
  int variaveis[n_variaveis] = {3, 5, 7, 9};

  string nomearq;

  for(int i = 0; i < n_clausulas; i++) {
    for(int j = 0; j < n_variaveis; j++) {

      nomearq = "instancias_formulas/formula_" + to_string(clausulas[i]) + "_" + to_string(variaveis[j]) + ".txt";

      Formula f = CarregaFormula(nomearq.c_str());
      high_resolution_clock::time_point tempo_inicio = high_resolution_clock::now();

      g = ReducaoSatGrafo(f);

      g = Complemento(g);

      Solucao s = BnB();
      
      high_resolution_clock::time_point tempo_agora = high_resolution_clock::now();
      duration<double> tempo_total = duration_cast<duration <double> > (tempo_agora - tempo_inicio);
      cout << "\n-#-#-#-#-#-#-#-\n\n" << nomearq << '\n';
      
      if (f.size() == s.size()) {
        ImprimeSolucaoFormula(s, tempo_total);
      } else {
        cout << "SOLUÇÃO INSATISFAZÍVEL" << endl;
      }

      nomearq = "result_satisf/formula_" + to_string(clausulas[i]) + "_" + to_string(variaveis[j]) + "_result.txt";
      SalvaSolucaoFormula(s, tempo_total, nomearq.c_str());
    }
  }
  
  return 0;
}