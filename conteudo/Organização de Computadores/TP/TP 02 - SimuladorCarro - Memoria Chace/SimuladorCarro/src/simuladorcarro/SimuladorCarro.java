package simuladorcarro;

import Classes.Carro;
import Classes.Instrucao;
import java.io.IOException;

/**
 *
 * @author MARCOS
 */
public class SimuladorCarro {

    Carro carro;

    public static void main(String[] args) throws IOException {
        SimuladorCarro simulador = new SimuladorCarro();
    }

    public SimuladorCarro() throws IOException {
        carro = new Carro();
        int valorNovo, valorAntigo;
        Instrucao instru = new Instrucao();
        for (Instrucao inst : carro.memInstrucao) {
            //System.err.println(inst.opCode + ":" + inst.endBloco + ":" + instru.endPalavra);
            switch (inst.opCode) {
                case 0:
                    valorNovo = carro.getRandomNumber(2);
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    if (valorNovo != valorAntigo) {
                        System.out.println("Carro mudou para " + ((valorNovo == 0) ? "desligado" : "ligado"));
                    } else {
                        System.out.println("Carro continua " + ((valorNovo == 0) ? "desligado" : "ligado"));
                    }
                    break;
                case 1:
                    valorNovo = carro.getRandomNumber(2);
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    if (valorNovo != valorAntigo) {
                        System.out.println("Freio de mão mudou para " + ((valorNovo == 0) ? "desligado" : "ligado"));
                    } else {
                        System.out.println("Freio de mão continua " + ((valorNovo == 0) ? "desligado" : "ligado"));
                    }
                    break;
                case 2:
                    valorNovo = carro.getRandomNumber(101);
                    carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    System.out.println("Pisou na embreagem com " + valorNovo + " kgs de força");
                    break;
                case 3:
                    valorNovo = carro.getRandomNumber(7);
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    if (valorNovo != valorAntigo) {
                        if (valorNovo == 1) {
                            System.out.println("Trocou a marcha do veículo da " + valorAntigo + " para ré");
                        } else if (valorAntigo == 1) {
                            System.out.println("Trocou a marcha do veículo da ré para " + valorNovo);
                        } else {
                            System.out.println("Trocou a marcha do veículo da " + valorAntigo + " para " + valorNovo);
                        }

                        //Instrucao para atualizar o valor da velocidade
                        instru.opCode = 3;
                        instru.endBloco = 0;
                        instru.endPalavra = 3;
                        valorAntigo = carro.procurarInstrucaoCache(1, instru, -1, true);
                        carro.jogarInstrucaoNaCache(1, instru, valorAntigo + 1);
                    } else {
                        System.out.println("Freio de mão continua na marcha " + valorNovo);
                    }
                    break;
                case 4:
                    valorNovo = carro.getRandomNumber(350);
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    if (valorNovo != valorAntigo && valorNovo > valorAntigo) {
                        System.out.println("Acelerou o carro de " + valorAntigo + " para " + valorNovo);
                    } else {
                        System.out.println("Desaceledou o carro de " + valorAntigo + " para " + valorNovo);
                    }
                    
                    //Instrucao para atualizar o valor da velocidade
                    instru.opCode = 10;
                    instru.endBloco = 2;
                    instru.endPalavra = 3;
                    carro.jogarInstrucaoNaCache(1, instru, valorNovo);
                    
                    break;
                case 5:
                    valorNovo = carro.getRandomNumber(360);
                    carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    System.out.println("Virou o carro pra direita em " + valorNovo + " graus");
                    
                    //Instrucao para atualizar o valor da cache
                    instru.opCode = 5;
                    instru.endBloco = 1;
                    instru.endPalavra = 2;
                    carro.jogarInstrucaoNaCache(1, instru, valorNovo);
                case 6:
                    valorNovo = carro.getRandomNumber(360);
                    carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    System.out.println("Virou o carro pra esquerda em " + valorNovo + " graus");
                    
                    //Instrucao para atualizar o valor da cache
                    instru.opCode = 5;
                    instru.endBloco = 1;
                    instru.endPalavra = 3;
                    carro.jogarInstrucaoNaCache(1, instru, valorNovo);
                    break;
                case 7:
                    valorNovo = carro.getRandomNumber(1000);
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    System.out.println("Carro bateu e sofreu uma pancada de " + valorNovo + " kgs");
                    
                    //Instrucao para atualizar o valor da cache
                    instru.opCode = 13;
                    instru.endBloco = 3;
                    instru.endPalavra = 2;
                    carro.jogarInstrucaoNaCache(1, instru, valorNovo + valorAntigo);
                    
                    instru.opCode = 11;
                    instru.endBloco = 2;
                    instru.endPalavra = 3;
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, -1, true);
                    carro.procurarInstrucaoCache(1, inst, valorAntigo + 1, true);
                    break;
                case 8:
                    valorNovo = carro.getRandomNumber(350);
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    if (valorNovo != valorAntigo && valorAntigo > valorNovo) {
                        System.out.println("Desaceledou o carro de " + valorAntigo + " para " + valorNovo);
                    } else {
                        System.out.println("Acelerou o carro de " + valorAntigo + " para " + valorNovo);
                    }
                    
                    //Instrucao para atualizar o valor da cache
                    instru.opCode = 10;
                    instru.endBloco = 2;
                    instru.endPalavra = 3;
                    carro.jogarInstrucaoNaCache(1, instru, valorNovo);
                    break;
                case 9:
                    valorNovo = carro.getRandomNumber(2);
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, valorNovo, true);

                    if (valorNovo != valorAntigo && valorAntigo != -1) {
                        System.out.println("Carro parou");
                    } else {
                        System.out.println("Carro continua em movimento");
                    }
                    break;
                case 10:
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, -1, true);
                    if (valorAntigo != -1) {
                        System.out.println("Velocidade atual do carro: " + valorAntigo);
                    }
                    break;
                case 11:
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, -1, true);
                    if (valorAntigo != -1) {
                        System.out.println("Carro bateu " + valorAntigo + " vezes");
                    }
                    break;
                case 12:
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, -1, true);
                    if (valorAntigo != -1) {
                        System.out.println("Marcha foi trocada " + valorAntigo + " vezes");
                    }
                    break;
                case 13:
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, -1, true);
                    if (valorAntigo != -1) {
                        System.out.println("Carro sofreu batidas totais em " + valorAntigo + " kilos");
                    }
                    break;
                case 14:
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, -1, true);
                    if (valorAntigo != -1) {
                        System.out.println("Ultimo grau virado pra direita: " + valorAntigo + " graus");
                    }
                    break;
                case 15:
                    valorAntigo = carro.procurarInstrucaoCache(1, inst, -1, true);
                    System.out.println("Ultimo grau virado pra esquerda: " + valorAntigo + " graus");
                    break;

            }
        }
        
        //Miss e Hit das Caches
        System.out.println("\n\nCache 01:\nHIT: " + carro.hit_L1 + " - MISS:" + carro.miss_L1);
        System.out.println("Cache 02:\nHIT: " + carro.hit_L2 + " - MISS:" + carro.miss_L2);
        System.out.println("Cache 03:\nHIT: " + carro.hit_L3 + " - MISS:" + carro.miss_L3);
//        System.out.println("Memória RAM:\nHIT: " + carro.hit_ram);
    }
}
