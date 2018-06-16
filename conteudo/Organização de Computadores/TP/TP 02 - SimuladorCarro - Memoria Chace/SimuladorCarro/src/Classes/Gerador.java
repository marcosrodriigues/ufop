/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;

/**
 *
 * @author FAKE DOI
 */
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Random;

public class Gerador {

    static int QTD_INS = 10000; // Quantidade de instruções geradas
    static int TAM_FOR = 100; // Tamanho do For
    static int TAM_MEM = 4; // Tamanho da Memoria (Quantidade de Endereços
    // Possiveis)
    static int PROB_FOR = 80; // Probabilidade de Ocorrencia do For (%)

    public static void main(String args[]) throws IOException {
        int aleatorio;
        // Define seu separador (entre os parametros da sua instrução
        String separador = ":";
        Random r = new Random();
        ArrayList<String> ins = new ArrayList<>();

        // N é a quantidade de Opcodes disponiveis
        int N = 15;
        // instruc é o vetor que conta quantos endereços tem cada Opcode
        int instruc[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};// Instruções numeradas de 0
        // a N-1

        // Gerando o for (laço de repetição) do programa;
        ArrayList<String> repeticao = new ArrayList<>();
        for (int i = 0; i < TAM_FOR; i++) {
            aleatorio = r.nextInt(N) + 1;
            String s = "";
            for (int j = 0; j < instruc[aleatorio - 1]; j++) {
                s += separador + r.nextInt(TAM_MEM);
            }
            repeticao.add(aleatorio + s);
        }

        for (int i = 0; i < QTD_INS;) {
            aleatorio = r.nextInt(100) + 1;
            if (aleatorio <= PROB_FOR && i + TAM_FOR < QTD_INS) {
                i = i + TAM_FOR;
                ins.addAll(repeticao);
            } else {
                i++;
                aleatorio = r.nextInt(N) + 1;
                String s = "";
                for (int j = 0; j < instruc[aleatorio - 1]; j++) {
                    s += separador + r.nextInt(TAM_MEM);
                }
                ins.add(aleatorio + s);
            }
        }
        OutputStream os = new FileOutputStream("instrucoes_802.txt");
        OutputStreamWriter osw = new OutputStreamWriter(os);
        BufferedWriter bw = new BufferedWriter(osw);
        for (int i = 0; i < ins.size(); i++) {
            bw.write(ins.get(i));
            bw.newLine();   
        }
        bw.close();
    }
}
