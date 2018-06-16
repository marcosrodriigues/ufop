package simuladorcarro;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

/**
 *
 * @author MARCOS
 */
public class SimuladorCarro {

    static int countAction = 1000, totalActions = 10;
    static int valMemory = 0, totalMemory = 10;
    static String delimit = ":";
    static HashMap<String, String> hashCode = new HashMap<>();
    
    public static void main(String[] args) {
        SimuladorCarro simulador = new SimuladorCarro();
    }

    public SimuladorCarro() {
    	ArrayList<String> array = generateActions();
    	
        int[] memory = new int[]{0, 1, 0, 0, 0, 2, 0, 0, 0, 0};
        int aux;
        String[] code;
        String allMemory = "";
        int mainAcion, mainParameter;

        /*      Posicoes da memoria
        
         1  - Embreagem (1 -> Retrocede / 0 -> Acelera)
         2  - Trocando Marcha 
         3  - Acelerando o carro
         4  - Diminuindo a Velocidade
         5  - Velocidade Atual do Carro
         6  - Marcha Atual do Carro
         7  - Contagem de vezes que a marcha foi trocada
         */
        /*
         OPCode das Ações
         */
        hashCode.put("-1", "Ligando o carro");
        hashCode.put("0", "Abaixando o Freio de Mão");
        hashCode.put("1:0", "Pisando na Embreagem");
        hashCode.put("2:1", "Trocando a Marcha do Veículo");
        hashCode.put("3:2", "Acelerando o carro");
        hashCode.put("4", "Virar à Direita");
        hashCode.put("5", "Virar à Esquerda");
        hashCode.put("6", "Carro Batido");
        hashCode.put("7:3", "Diminuindo a Velocidade");
        hashCode.put("8", "Parando o carro");
        hashCode.put("9:4", "Velocidade do Carro");
        hashCode.put("10:5", "Marcha do Carro");
        hashCode.put("11:6", "Numero de vezes que a marcha foi trocada");
        hashCode.put("12", "Mostrar Dados na Memória");
        hashCode.put("13", "Limpar Dados da Memória");
        hashCode.put("14", "Levantando o freio de mão");
        hashCode.put("15", "Desligando o carro");

        for (String s : array) {
            if (s.equals("12")) {
                System.out.println("Dados da Memória: " + allMemory);
            } else if (s.equals("13")) {
                System.out.println("Memória Limpa");
                allMemory = "";
            } else if (!s.contains(delimit)) {
                System.out.println(hashCode.get(s));
                allMemory = allMemory.concat(hashCode.get(s) + "; ");
            } else {
                code = s.split(delimit);
                mainAcion = Integer.parseInt(code[0]);
                mainParameter = Integer.parseInt(code[1]);
                allMemory = allMemory.concat(hashCode.get(s) + "; ");

                switch (mainParameter) {
                    case 0: // Embreagem -> 1 Retrocede e 0 Acelera
                        memory[0] = getRandomNumber(2);
                        System.out.println("Preparando o carro para "
                                + ((memory[0] == 0) ? "acelerar" : "retroceder")
                                + " a velocidade");
                        break;
                    case 1: // Trocando Marchas
                        System.out.println(hashCode.get(s));

                        aux = memory[5];
                        if (aux == 0) {
                            aux = 1;
                        }

                        if (memory[0] == 0) {
                            if (aux == 6) {
                                System.out.println("Impossível avançar a marcha. Marcha máxima");
                            } else {
                                do {
                                    memory[1] = getRandomNumber(6) + 1;
                                } while (memory[1] <= aux);
                                if (aux != 1) {
                                    System.out.println("Marcha avançada da " + (aux - 1) + "ª para a " + memory[1] + "ª.");
                                } else {
                                    System.out.println("Marcha avançada da marcha a ré para a " + memory[1] + "ª.");
                                }
                            }
                        } else {
                            if (aux == 1) {
                                System.out.println("Impossível diminuir a marcha. Marcha mínima");
                            } else {
                                do {
                                    memory[1] = getRandomNumber(6) + 1;
                                } while (memory[1] > aux);

                                if (memory[1] != 1) {
                                    System.out.println("Marcha diminuida da " + aux + "ª para a " + memory[1] + "ª.");
                                } else {
                                    System.out.println("Marcha diminuida da " + (aux - 1) + "ª para a da marcha a ré.");
                                }
                            }

                        }
                        memory[5] = memory[1];
                        memory[6]++;
                        break;
                    case 2: // Acelerando o carro
                        System.out.println(hashCode.get(s));

                        if (memory[4] < 220) {
                            aux = memory[4];
                            do {
                                memory[2] = getRandomNumber(260) + 1;
                            } while (memory[2] <= aux);
                            memory[4] = memory[2];
                            System.out.println("Carro acelerando de " + aux + " km/h para " + memory[2] + " km/h");
                        } else {
                            System.out.println("Carro na velocidade máxima.");
                        }

                        break;
                    case 3: // Diminuindo a velocidade
                        if (memory[4] > 30) {
                            aux = memory[4];
                            do {
                                memory[3] = getRandomNumber(260) + 1;
                            } while (memory[3] >= aux);
                            memory[4] = memory[3];
                            System.out.println("Carro diminuindo a velocidade de " + aux + " km/h para " + memory[3] + " km/h");
                        }
                        break;
                    case 4: // Velocidade atual do carro
                        System.out.println("Velocidade atual do carro: " + memory[4] + " km/h");
                        break;
                    case 5: // Marcha atual do carro
                        switch (memory[5]) {
                            case 1:
                                System.out.println("Carro está engatado na marcha a ré");
                                break;
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                                System.out.println("Carro está engatado na " + memory[5] + "ª marcha");
                                break;
                        }
                    case 6:
                        System.out.println("A marcha foi trocada " + memory[6] + " vezes na corrida");
                        break;
                }
            }
        }
        System.out.println("Ultima velocidade registrada: " + memory[4] + " km/h");
        System.out.println("Ultima marcha engatada registrada: " + (memory[5] == 1 ? "Marcha a Ré" : memory[5] + "ª marcha"));
        System.out.println("A marcha foi alterada " + memory[6] + " durante a corrida.");
    }

    private ArrayList<String> generateActions() {
        ArrayList<String> actions = new ArrayList<>();
        int action, parameter;

        actions.add("-1");
        actions.add("0");
        for (int i = 0; i < countAction; i++) {

            action = getRandomNumber(totalActions) + 1;
            parameter = -1;
            switch (action) {
                case 1:
                case 2:
                case 3:
                    parameter = action - 1;
                    break;
                case 7:
                    parameter = 3;
                    break;
                case 9:
                    parameter = 4;
                case 10:
                    parameter = 5;
                case 11:
                    parameter = 6;
                    break;
            }
            if (parameter != -1) {
                actions.add(String.valueOf(action + delimit + parameter));
            } else {
                actions.add(String.valueOf(action));
            }
        }
        actions.add("14");
        actions.add("15");
        actions.add("12");
        actions.add("13");

        return actions;
    }

    private int getRandomNumber(int range) {
        Random rand = new Random();
        return (range == 0) ? rand.nextInt() : rand.nextInt(range);
    }
}
