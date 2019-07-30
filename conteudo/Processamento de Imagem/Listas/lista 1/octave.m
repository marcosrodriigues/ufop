% Aluno: Marcos Rodrigues
% Matrícula: 14.2.4341

% Número 1: Defina uma matriz
A = [2, 10, 7, 6; 3, 12, 25, 9];  

% Número 1, letra A: Acrescente os dados na matriz
A = [A; 30, 21, 19, 1];

% Número 1, letra B: Crie uma matriz B que exclua a primeira coluna da matriz A
B = A(1:3, 2:4); 

% Número 2: Crie um vetor de 31 até 75 que mostre os numeros impares
V = [31:2:75];

% Número 3:
X = [3;2;6;8];
Y = [4;1;3;5];

% Número 3, letra A: Somar X e Y
X + Y;

% Número 3, letra B: Eleve cada elemento de X a potência dada pelo elemento de Y
X .^ Y;

% Número 4: Crie um vetor W com componentes:  Wn = (-1)n + 1/(2n + 1)
W = [1:100];
Wn = -1.*W +1./(2.*W + 1);
Wn = arrayfun(@(x) (-1)*x + 1/(2*x + 1), W);

% Número 5: Crie um vetor com Randi, veja o maior valor, seu index e eleve-o ao quadrado
M = randi(100, 1, 10);
[value, index] = max(M);
M(index) = value .^ 2;

% Número 6: Considere a Matriz. Substitua os valores da primeira coluna e da última linha por 1.
N = [10 2 10 5; 2 5 1 6; 2 4 8 10;4 10 3 5]
N(1:4, 1:1) = 1 % transforma a primeira coluna em 1
N(4:4, 1:4) = 1 % transforma a ultima linha em 1
indexs = find(N(3,:) > 5) % encontra os indexs das posições que tem >5 na linha 3
N(3:3, indexs) = 5 #substitui por 5

% Número 7: Chamando o harmônico de um número n de [SOMATÓRIO k=1 até n de (1/k)]. Encontrar o harmonico de 255
H = [1:255]
H = 1 ./ H
H = sum(H)

% Número 8: Escreva uma expressão curta que consiga gerar a seguinte matriz seguinte
Q = [1:7; 9:-2:-3; 2.^[2:8]]

% Número 9: Escreva a expressão em Matlab que multiplique dois vetores para gerar as seguintes matrizes
% Letra A:
Vr = [1:5]
Vc = [1;1;1]
V = Vc * Vr

% Letra B:
Vr = [0;1;2;3;4]
Vc = [1,1,1]
V = Vr * Vc

% Número 10: Gere o gráfico de f(x) = sin(1/x) para 0.01 < x < 0.1.
S = [0.01: 0.0001: 0.1]
S = sin(1 ./ S)
plot(S)