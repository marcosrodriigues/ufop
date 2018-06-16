/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author FAKE DOI
 */
public class Instrucao {

    public int opCode;
    public int endBloco;
    public int endPalavra;

    /*
     Instruções:
     OPCode
     0 - Ligar/Desligar o carro
     1 - Abaixar/Levantar o freio de mão
     2 - Pisar na Embreagem : quantos kg de força ?
     3 - Trocando a marcha do veículos : qual marcha ?
     4 - Acelerando o carro : quanto ?
     5 - Virar a direita : quantos graus ?
     6 - Virar a esquerda : quantos graus ?
     7 - Carro batido : quanto kg de força foi o dano ?
     8 - Diminuindo a velocidade : quanto ?
     9 - Parando o carro : conseguiu ?
     10 - Velocidade atual do carro
     11 - Marcha atual do carro
     12 - Numero de vezes que foi trocada a marcha
     13 - Quantos kg de dano o carro bateu ?
     14 - Ultimo grau virado pra direita
     15 - Ultimo grau virado pra esquerda
     */
    
    public static Instrucao[] montarInstrucoes() throws IOException {
        return montarInstrucoes("");
    }
    public static Instrucao[] montarInstrucoes(String tamFor) throws IOException {
        try {
            FileReader arq = new FileReader("instrucoes" + (tamFor.isEmpty() ? "" : "_" + tamFor) + ".txt");;
            BufferedReader lerArq = new BufferedReader(arq);

            String linha = lerArq.readLine();
            String[] inst;
            Instrucao[] memoria = new Instrucao[10000];
            Instrucao instru;

            int i = 0;
            while (linha != null) {
                instru = new Instrucao();
                inst = linha.split(":");
                instru.opCode = Integer.parseInt(inst[0]);
                instru.endBloco = Integer.parseInt(inst[1]);
                instru.endPalavra = Integer.parseInt(inst[2]);

                memoria[i] = instru;
                i++;
                linha = lerArq.readLine();
            }

            return memoria;
        } catch (FileNotFoundException e) {
            System.err.println("Arquivo não encontrado");
        } catch (Exception e) {
            System.err.println("Erro: " + e.toString());
        }

        return null;
    }
}
