/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;

import java.io.IOException;
import java.util.Date;
import java.util.Random;

/**
 *
 * @author FAKE DOI
 */
public class Carro {

    static final int totalLinhas = 5;
    static final int totalPalavras = 4;

    static final int tamCache_1 = 1;
    static final int tamCache_2 = 10;
    static final int tamCache_3 = 100;

    public Instrucao[] memInstrucao;
    public Blocos[] memDados;

    private Cache cache_L1;
    private Cache cache_L2;
    private Cache cache_L3;

    public int hit_L1 = 0, hit_L2 = 0, hit_L3 = 0, hit_ram = 0;
    public int miss_L1 = 0, miss_L2 = 0, miss_L3 = 0, miss_ram = 0;

    public Carro() throws IOException {

        memInstrucao = Instrucao.montarInstrucoes("802");
        memDados = Blocos.montarMemoria();

        cache_L1 = new Cache(tamCache_1);
        cache_L2 = new Cache(tamCache_2);
        cache_L3 = new Cache(tamCache_3);
    }

    class Cache {

        Conjunto[] conjunto;

        public Cache(int tamanho) {
            conjunto = new Conjunto[tamanho];
        }
    }

    class Conjunto {

        Linha[] linhas = new Linha[totalLinhas];
        int posicaoPior;

        public Conjunto() {
            posicaoPior = -1;

            for (int i = 0; i < totalLinhas; i++) {
                linhas[i] = new Linha();
            }
        }

    }

    class Linha {

        int[] dados;
        Instrucao inst;
        Date d;
        int numAcessos;
        boolean valorAlterado;

        public Linha() {
            dados = new int[totalPalavras];
            d = new Date();
            numAcessos = 0;
            valorAlterado = false;
        }
    }

    public int getRandomNumber(int range) {
        Random rand = new Random();
        return (range == 0) ? rand.nextInt() : rand.nextInt(range);
    }

    // FUNÇÃO DO MMU
    /*
     Função Recursiva
     Se achar o dado em qualquer cache que não seja a 1,
     a função automaticamente passa o dado da cache atual
     para todas abaixo dela, até chegar na cache 1
     */
    public int procurarInstrucaoCache(int cacheInicial, Instrucao inst, int valor, boolean somar) {
        int endBloco = inst.endBloco;
        int endPalavra = inst.endPalavra;

        //posicao do conjunto dentro da cache
        int posConjunto;

        switch (cacheInicial) {
            case 1:
                posConjunto = ((endBloco + endPalavra) % tamCache_1);

                if (cache_L1.conjunto[posConjunto] != null) {
                    for (Linha lin : cache_L1.conjunto[posConjunto].linhas) {
                        if (lin.inst != null) {
                            if (lin.inst.equals(inst)) {
                                if (somar) {
                                    hit_L1++;
                                }
                                return lin.dados[endPalavra];
                            }
                        }
                    }
                }
                if (somar) {
                    miss_L1++;
                }
                return procurarInstrucaoCache(2, inst, valor, true);
            case 2:
                posConjunto = ((endBloco + endPalavra) % tamCache_2);

                if (cache_L2.conjunto[posConjunto] != null) {
                    for (Linha lin : cache_L2.conjunto[posConjunto].linhas) {
                        if (lin.inst != null) {
                            if (lin.inst.equals(inst)) {
                                if (somar) {
                                    hit_L2++;
                                }
                                jogarInstrucaoNaCache(1, inst, valor);
                                return procurarInstrucaoCache(1, inst, valor, false);
                            }
                        }
                    }
                }
                if (somar) {
                    miss_L2++;
                }
                return procurarInstrucaoCache(3, inst, valor, true);
            case 3:
                posConjunto = ((endBloco + endPalavra) % tamCache_3);

                if (cache_L3.conjunto[posConjunto] != null) {
                    for (Linha lin : cache_L3.conjunto[posConjunto].linhas) {
                        if (lin.inst != null) {
                            if (lin.inst.equals(inst)) {
                                if (somar) {
                                    hit_L3++;
                                }
                                jogarInstrucaoNaCache(2, inst, valor);
                                return procurarInstrucaoCache(2, inst, valor, false);
                            }
                        }
                    }
                }
                if (somar) {
                    miss_L3++;
                }

                return procurarInstrucaoCache(4, inst, valor, true);
            case 4: // O Case 4 eh a MEMÓRIA PRINCIPAL

                /*
                 Como a minha instrução possui o endereco do Bloco e da Palavra,
                 não preciso percorrer toda a memoria para achá-lo, posso ir di-
                 reto para o bloco e palavra, por isso, eu jogo a instru		ção dire-
                 to na cache L3
                 */
                hit_ram++;
                jogarInstrucaoNaCache(3, inst, valor);
                return procurarInstrucaoCache(3, inst, valor, false);
        }

        return -1;
    }

    public void jogarInstrucaoNaCache(int cacheDestino, Instrucao instru, int valor) {
        int endBloco = instru.endBloco;
        int endPalavra = instru.endPalavra;
        int posConjunto;
        int i = 0;
        Date date = new Date();

        Linha linAux;
        Conjunto conjunto;
        Conjunto conAux;
        //Funcao recursiva com base em CacheDestino < 1
        if (cacheDestino >= 1) {
            switch (cacheDestino) {
                case 1: //Jogando na Cache 1
                    posConjunto = ((endBloco + endPalavra) % tamCache_1);

                    conjunto = cache_L1.conjunto[posConjunto];
                    conAux = new Conjunto();
                    if (conjunto != null) {
                        linAux = conjunto.linhas[i];

                        if (linAux == null) {
                            cache_L1.conjunto[posConjunto].linhas[i].inst = instru;
                            cache_L1.conjunto[posConjunto].linhas[i].d = date;
                            cache_L1.conjunto[posConjunto].linhas[i].valorAlterado = false;
                            cache_L1.conjunto[posConjunto].linhas[i].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                            return;
                        }

                        for (Linha lin : conjunto.linhas) {
                            if (lin == null) {
                                cache_L1.conjunto[posConjunto].linhas[i].inst = instru;
                                cache_L1.conjunto[posConjunto].linhas[i].d = date;
                                cache_L1.conjunto[posConjunto].linhas[i].valorAlterado = false;
                                cache_L1.conjunto[posConjunto].linhas[i].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                                return;
                            } else {
                                if (lin.d.after(linAux.d)) {
                                    linAux = conjunto.linhas[i];
                                    conjunto.posicaoPior = i;
                                }
                            }
                            i++;
                        }
                        if (conjunto.linhas[conjunto.posicaoPior].valorAlterado && valor != -1) {
                            memDados[endBloco].palavras[endPalavra] = valor;
                        }

                        cache_L1.conjunto[posConjunto].linhas[conjunto.posicaoPior].inst = instru;
                        cache_L1.conjunto[posConjunto].linhas[conjunto.posicaoPior].d = date;
                        cache_L1.conjunto[posConjunto].linhas[conjunto.posicaoPior].valorAlterado = true;
                        cache_L1.conjunto[posConjunto].linhas[conjunto.posicaoPior].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                    } else {
                        linAux = new Linha();

                        linAux.d = new Date();
                        linAux.inst = instru;
                        linAux.numAcessos = 0;
                        linAux.valorAlterado = false;
                        linAux.dados[0] = valor;

                        conAux.linhas[0] = linAux;
                        conAux.posicaoPior = 0;

                        cache_L1.conjunto[posConjunto] = conAux;
                    }
                    break;
                case 2: //Jogando na Cache 2
                    posConjunto = ((endBloco + endPalavra) % tamCache_2);

                    conjunto = cache_L2.conjunto[posConjunto];
                    conAux = new Conjunto();
                    if (conjunto != null) {
                        linAux = conjunto.linhas[i];

                        if (linAux == null) {
                            cache_L2.conjunto[posConjunto].linhas[i].inst = instru;
                            cache_L2.conjunto[posConjunto].linhas[i].d = date;
                            cache_L2.conjunto[posConjunto].linhas[i].valorAlterado = false;
                            cache_L2.conjunto[posConjunto].linhas[i].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                            return;
                        }

                        for (Linha lin : conjunto.linhas) {
                            if (lin == null) {
                                cache_L2.conjunto[posConjunto].linhas[i].inst = instru;
                                cache_L2.conjunto[posConjunto].linhas[i].d = date;
                                cache_L2.conjunto[posConjunto].linhas[i].valorAlterado = false;
                                cache_L2.conjunto[posConjunto].linhas[i].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                                return;
                            } else {
                                if (lin.d.after(linAux.d)) {
                                    linAux = conjunto.linhas[i];
                                    conjunto.posicaoPior = i;
                                }
                            }
                            i++;
                        }
                        if (conjunto.linhas[conjunto.posicaoPior].valorAlterado && valor != -1) {
                            memDados[endBloco].palavras[endPalavra] = valor;
                        }

                        cache_L2.conjunto[posConjunto].linhas[conjunto.posicaoPior].inst = instru;
                        cache_L2.conjunto[posConjunto].linhas[conjunto.posicaoPior].d = date;
                        cache_L2.conjunto[posConjunto].linhas[conjunto.posicaoPior].valorAlterado = true;
                        cache_L2.conjunto[posConjunto].linhas[conjunto.posicaoPior].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                    } else {
                        linAux = new Linha();

                        linAux.d = new Date();
                        linAux.inst = instru;
                        linAux.numAcessos = 0;
                        linAux.valorAlterado = false;
                        linAux.dados[0] = valor;

                        conAux.linhas[0] = linAux;
                        conAux.posicaoPior = 0;

                        cache_L2.conjunto[posConjunto] = conAux;
                    }
                    break;
                case 3: //Jogando na Cache 3

                    posConjunto = ((endBloco + endPalavra) % tamCache_3);

                    conjunto = cache_L3.conjunto[posConjunto];
                    conAux = new Conjunto();
                    if (conjunto != null) {
                        linAux = conjunto.linhas[i];

                        if (linAux == null) {
                            cache_L3.conjunto[posConjunto].linhas[i].inst = instru;
                            cache_L3.conjunto[posConjunto].linhas[i].d = date;
                            cache_L3.conjunto[posConjunto].linhas[i].valorAlterado = false;
                            cache_L3.conjunto[posConjunto].linhas[i].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                            return;
                        }

                        for (Linha lin : conjunto.linhas) {
                            if (lin == null) {
                                cache_L3.conjunto[posConjunto].linhas[i].inst = instru;
                                cache_L3.conjunto[posConjunto].linhas[i].d = date;
                                cache_L3.conjunto[posConjunto].linhas[i].valorAlterado = false;
                                cache_L3.conjunto[posConjunto].linhas[i].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                                return;
                            } else {
                                if (lin.d.after(linAux.d)) {
                                    linAux = conjunto.linhas[i];
                                    conjunto.posicaoPior = i;
                                }
                            }
                            i++;
                        }
                        if (conjunto.linhas[conjunto.posicaoPior].valorAlterado && valor != -1) {
                            memDados[endBloco].palavras[endPalavra] = valor;
                        }

                        cache_L3.conjunto[posConjunto].linhas[conjunto.posicaoPior].inst = instru;
                        cache_L3.conjunto[posConjunto].linhas[conjunto.posicaoPior].d = date;
                        cache_L3.conjunto[posConjunto].linhas[conjunto.posicaoPior].valorAlterado = true;
                        cache_L3.conjunto[posConjunto].linhas[conjunto.posicaoPior].dados[endPalavra] = memInstrucao[endBloco].endPalavra;
                    } else {
                        linAux = new Linha();

                        linAux.d = new Date();
                        linAux.inst = instru;
                        linAux.numAcessos = 0;
                        linAux.valorAlterado = false;
                        linAux.dados[0] = valor;

                        conAux.linhas[0] = linAux;
                        conAux.posicaoPior = 0;

                        cache_L3.conjunto[posConjunto] = conAux;
                    }
                    break;
            }
        }
    }
    //FIM DO MMU
}
