typedef struct Retangulo{
	int Altura, Largura, X, Y;
}TRetangulo;

int Area (TRetangulo r);
float Distancia (TRetangulo r1, TRetangulo r2);
int Intersecao (TRetangulo r1, TRetangulo r2);
bool haIntersecao (TRetangulo r1, TRetangulo r2);