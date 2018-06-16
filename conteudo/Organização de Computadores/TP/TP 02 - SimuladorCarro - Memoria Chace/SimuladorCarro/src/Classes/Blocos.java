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
public class Blocos {

    public static final int totalBlocos = 5;
    int palavras[] = new int[4];

    /*
        Posições da Memória de Dados
            0 - Status do carro [ligado/desligado]
            1 - Status do freio de mão [abaixado/levantado]
            2 - Força que pisou na embreagem [em kilos]
            3 - Marcha trocada do veículo [qual]
            4 - Aceleração do carro [quanto]
            5 - Quanto virou a direita [graus]
            6 - Quanto virou a esquerda [graus]
            7 - Kgs de força da batida do carro
            8 - Diminuindo velocidade do carro [quanto]
            9 - Parando o carro [conseguiu/não conseguiu]
            10 - Velocidade do carro [atual]
            11 - Batida do carro [soma da qtde]
            12 - Troca de marcha do carro [quanto] 
            13 - Batida do carro [soma das forças]
            14 - Graus virados pra direita [soma]
            15 - Graus virados pra esquerda [soma]
    */
    
    public static Blocos[] montarMemoria() {
        int[][] memoriaDados
                = {
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                };

        Blocos[] todosBlocos = new Blocos[memoriaDados.length];
        int i = 0;
        for (int[] bloco : memoriaDados) {
            Blocos bloc = new Blocos();
            for (int j = 0; j < memoriaDados.length; j++) 
                bloc.palavras[i] = memoriaDados[i][j];
            
            todosBlocos[i] = bloc;
            i++;
        }

        return todosBlocos;
    }
}
