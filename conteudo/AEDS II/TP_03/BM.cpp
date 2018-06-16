#include "BM.h"

void Sufixo(TipoPadrao Padrao, long m, int *sufixo) {
	int f,              
        g = m - 1,      
        i;              

    sufixo[m - 1] = m;

    for (i = m - 2; i >= 0; i--) {
        if (i > g && sufixo[i + m - 1 - f] < i - g) {
            sufixo[i] = sufixo[i + m - 1 - f];
        } else {

            if (i < g)  g = i;

            f = i;

            while (g >= 0 && Padrao[g] == Padrao[g + m - 1 - f])    g--;
            sufixo[i] = f - g;
        }
    }
}

void Pre_Processamento(TipoPadrao Padrao, int m, int *ocorrencias) {
	int i, j, *sufixo = new int[MAX_TAM_PADRAO_MEDIO];
    Sufixo(Padrao, m, sufixo);

    for (i = 0; i < m; i++) ocorrencias[i] = m;

    j = 0;

    for (i = m - 1; i >= 0; i--) {
        if (sufixo[i] == i + 1) {
            for (; j < m - 1 - i; j++) {
                if (ocorrencias[j] == m) {
                    ocorrencias[j] = m - 1 - i;
                }
            }
        }
    }

    for (i = 0; i <= m - 2; i++)    ocorrencias[m - 1 - sufixo[i]] = m - 1 - i;
}

/*  Boyer_Moore pela heurística Ocorrência  */
void Boyer_Moore(TipoTexto Texto, int n, TipoPadrao Padrao, int m, int *numComparacoes, int *numDeslocamentos) {
	int i, 
        j, 
        *ocorrencias = new int[MAX_TAM_PADRAO_MEDIO];

    Pre_Processamento(Padrao, m, ocorrencias);

    j = 0;

    int MAX = 0;
    while (j <= n - m) {
        for (i = m - 1; i >= 0 && Padrao[i] == Texto[i + j]; i--)   (*numComparacoes)++;

        if (i < 0) {
            cout << "Casamento na posicao: " << j+1 << endl;
            j += m;
            MAX++;
        } else {
            j += ocorrencias[i];
            (*numDeslocamentos)++;
        }
    }

    cout << "MAX: " << MAX << endl;
}