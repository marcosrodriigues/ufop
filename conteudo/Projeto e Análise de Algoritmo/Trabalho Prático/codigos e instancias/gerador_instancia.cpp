// Gerador de instancias para os 3 problemas

#include "io.h"
#include <string>

int main() {
  // Instancias de grafo
  
  const int n_tamanhos = 4; // 4 * 4 = 16 tamanhos e densidades diferentes de grafo
  
  int tamanhos[n_tamanhos] = {10, 20, 30, 40}; // Numero de vertices das instancias
  float densidades[n_tamanhos] = {0.2, 0.4, 0.6, 0.8}; // Densidades das instancias
  
  string dir = "instancias_grafos/";
  
  for(int i = 0; i < n_tamanhos; i++) {
    for(int j = 0; j < n_tamanhos; j++) {
      Grafo g = CriaGrafo(tamanhos[i], densidades[j]);
      
      string nomearq = dir + "grafo_" + to_string(tamanhos[i]) + "_" + to_string(densidades[j])[2] + ".txt";
      SalvaGrafo(g, nomearq.c_str());
    }
  }
  
  // Instancias de formula
  
  const int n_clausulas = 4; // 4 numero de clausulas diferentes
  const int n_variaveis = 4; // 4 numero de variaveis diferentes
  
  int clausulas[n_clausulas] = {2, 4, 6, 8};
  int variaveis[n_variaveis] = {3, 5, 7, 9};
  float probabilidade = 0.5; // Probabilidade unica
  
  dir = "instancias_formulas/";
  
  for(int i = 0; i < n_clausulas; i++) {
    for(int j = 0; j < n_variaveis; j++) {
      Formula f = CriaFormula(clausulas[i], variaveis[j], probabilidade);
      
      string nomearq = dir + "formula_" + to_string(clausulas[i]) + "_" + to_string(variaveis[j]) + ".txt";
      SalvaFormula(f, nomearq.c_str());
    }
  }
  
  return 0;
}
