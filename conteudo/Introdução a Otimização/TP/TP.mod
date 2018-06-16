### Declaração dos parâmetros ###

param N, integer, >= 4; #Número de vértices (2*turbinas + 2 bases)

check: N mod 2 == 0; #Para verificar se nao tem entrada errada: N deve ser par

set Jminus := {2..(N/2)}; #Conjunto de entrega

set Jplus := {(N/2)+1..N-1}; #Conjunto de devolução

set Jstar := {Jminus union Jplus union {1, N}}; #Conjunto total

set Jv within Jminus := {2}; #Subconjunto das turbinas com manutenção especial

set A, within Jstar cross Jstar; #Matriz de arestas

param C{(i,j) in A}; #Peso das arestas

param Ta{(i,j) in A}; #Custo de tempo da aresta

param Tm, integer, >= 0; #Tempo de manutenção

param Tfinal, integer, >= 0; #Tempo total disponível de manutenção

### Declaração das variáveis de decisão ###

var Y{(i,j) in A}, binary; #1 caso a aresta for visitada, 0 caso contrário

var Tt{i in Jstar}, >= 0; #Tempo quando a vértice i é visitado

### Restrições ###

s.t. r1{i in Jstar}: sum{(i,j) in A} Y[i,j] = 1; #Entra no vértice uma única vez

s.t. r2{j in Jstar}: sum{(i,j) in A} Y[i,j] = 1; #Sai do vértice uma única vez

var X{(i,j) in A}, >= 0; #Variável auxiliar, funciona como um fluxo, impede criação de subrotas

s.t. r3{(i,j) in A}: X[i,j] <= (N - 1) * Y[i,j]; #Fluxo X rodando caso selecionar aresta Y

s.t. r4{i in Jstar}: sum{(j,i) in A} X[j,i] + (if i = 1 then N) = sum{(i,j) in A} X[i,j] + 1; #Fluxo diminui em uma unidade por vértice

s.t. r5{i in Jminus}: sum{(i,j) in A} Y[i,j] = sum{(i,j) in A} Y[i + (N/2) - 1,j]; #Entrega na turbina se realiza sempre antes da devolução

s.t. r6{i in Jv}: Y[i, i + (N/2) - 1] = 1; #Barco precisa fazer entrega e devolução na turbina imediatamente

s.t. r7{i in Jminus}: Tt[i + (N/2) - 1] - Tt[i] >= Tm; #Tempo de manutenção em cada turbina deve ser viável

s.t. r8: Tt[N] <= Tfinal;

s.t. r9: Tt[1] = 0;

#s.t. r10{i in Jstar, j in Jstar}: -9999*(1 - Y[i,j]) + (Tt[i] + Ta[i,j] + Tm) <=  Tt[j];

### Função objetivo ###

minimize Z: sum{(i,j) in A} C[i,j] * Y[i,j];

solve;

### Impressão da resposta ###

printf "\n==============Resposta==============\n\n";
printf {(i,j) in A: Y[i,j]} "%3d  ->%3d = %4d\n", i, j, C[i,j];
printf "\nCusto total = %d\n", Z;
printf "\n====================================\n\n";

### Entrada de dados ###

data;

### Exemplo de entrada N := 8 ###

#      / - - - - - - - - - - - - - - - - - \
#    /                                           \
#   |        /- - - 2 - - - - 5 - - -\        |  1 e 8 são vértices que representam a base (início e fim da rota)
#   |      /         |          |         \      |  Arestas de peso 999 são "artificiais", servem apenas para completar o modelo
#    \ - 1 - - - - 3 - - - - 6 - - - - 8 - /   Vértices de 2 a 4 são as turbinas, 5 a 7 suas "cópias"
#          \         |          |          /         Na verdade os vértices de 2 a 7 são todos conectados um ao outro
#           \ - - - 4 - - - - 7 - - - /

param N := 8;

param Tm := 62;

param Tfinal := 9999;

param : A :   C   Ta :=
	   1 1  999  999
	   1 2   16   32
	   1 3   10   20
	   1 4   28   56
	   1 5  999  999
	   1 6  999  999
	   1 7  999  999
	   1 8  999  999
	   2 1  999  999
	   2 2  999  999
	   2 3    6   12
	   2 4   23   46
	   2 5    1    1
	   2 6    6   12
	   2 7   23   46
	   2 8  999  999
	   3 1  999  999
	   3 2    6   12
	   3 3  999  999
	   3 4   19   38
	   3 5    6   12
	   3 6    1    1
	   3 7   19   38
	   3 8  999  999
	   4 1  999  999
	   4 2   23   46
	   4 3   19   38
	   4 4  999  999
	   4 5   23   46
	   4 6   19   38
	   4 7    1    1
	   4 8  999  999
	   5 1  999  999
	   5 2  999  999
	   5 3    6   12
	   5 4   23   46
	   5 5  999  999
	   5 6    6   12
	   5 7   23   46
	   5 8   16   32
	   6 1  999  999
	   6 2    6   12
	   6 3  999  999
	   6 4   19   38
	   6 5    6   12
	   6 6  999  999
	   6 7   19   38
	   6 8   10   20
	   7 1  999  999
	   7 2   23   46
	   7 3   19   38
	   7 4  999  999
	   7 5   23   46
	   7 6   19   38
	   7 7  999  999
	   7 8   28   56
	   8 1    0    0
	   8 2  999  999
	   8 3  999  999
	   8 4  999  999
	   8 5  999  999
	   8 6  999  999
	   8 7  999  999
	   8 8  999  999
;

end;
