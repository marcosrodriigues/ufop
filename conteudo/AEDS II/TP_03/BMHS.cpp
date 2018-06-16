#include "BMHS.h"


void _BMHS_(TipoTexto Texto, long n, TipoPadrao Padrao, long m, int *numComparacoes, int *numDeslocamentos){
    long    i, 
            j, 
            k, 
            d[MAX_CHAR+1];

    //Pre Processamento para obter a tabela de deslocamento
    for(j = 0; j <= MAX_CHAR; j++)  d[j] = m + 1;
    for(j = 1; j <= m; j++)         d[Padrao[j - 1]] = m - j + 1;

    i = m;
    int MAX = 0;
    while(i <= n){
        (*numComparacoes)++;
        k = i;
        j = m;

        //Pesquisa por um sufixo do texto que casa com um sufixo do padrao
        while(Texto[k - 1] == Padrao[j - 1] && j > 0){
            (*numComparacoes)++;
            k--;
            j--;
        }
        (*numComparacoes)++;   
        

        if(j == 0) {
            cout << "Casamento na posicao: " << k + 1 << endl;
            MAX++;
        }

        //Desloca de acordo com o valor da tabela de deslocamentos de acordo com a posicao seguinte ao ultimo caractere do padrao
        i += d[Texto[i]];
        (*numDeslocamentos)++;
    }
    (*numComparacoes)++;   //Quando ele não entrar no while, significa que ele comparou e foi false, por isso eu atribuo novamente o comparacoes++
    cout << "MAX: " << MAX << endl;
}