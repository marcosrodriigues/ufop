package jcl;

import java.util.ArrayList;
import java.util.Random;

public class SimuladorCarro {
    
	/*      Posicoes da memoria de dados
    
    00	- Situação do Carro (1 - Ligado | 0 - Desligado)
    01	- Kilos de força pisado na embreagem pela última vez
    02	- Marcha Atual do veículo
    03	- Velocidade atual do carro
    04	- Ultima virada à Direita (em graus)
    05	- Ultima virada à Esquerda (em graus)
    06	- Soma de quantas vezes o carro foi ligado
    07	- Soma de quantas vezes o carro foi desligado
    08	- Soma de quantos kilos foram pisados na embreagem
    09	- Soma de quantas vezes a embreagem foi pisada
    10  - Soma de todas as marchas trocadas do veículo
    11	- Soma de quantas vezes a marcha foi trocada
    12  - Soma de todas as velocidades que o carro alterou
    13	- Soma de quantas vezes a velocidade do carro alterou
    14  - Soma de quantos graus o carro ficou à esquerda
    15  - Soma de quantos graus o carro ficou à direita
    16	- Soma de quantas vezes o carro bateu
    */
	
	/*      Posicoes do Hash dos OpCodes
    
    1:1		- Ligando o carro
    2:1		- Desligando o carro
    3:2		- Pisando na embreagem
    4:3		- Trocando a marcha
    5:4		- Acelerando o carro
    6:5		- Virando à direita
    7:6		- Virando à esquerda
    8:17	- Carro batido
    9:4		- Diminuindo a velocidade
    10:1	- Status do carro (ligado/desligado)
    11:3	- Marcha atual do carro
    12:4	- Velocidade atual do carro
    13:17	- Soma de quantas vezes o carro bateu
    14:7	- Numero de vezes que o carro ligou
    15:8	- Numero de vezes que o carro desligou
    16:10	- Soma de quantas vezes o carro pisou na embreagem
    17:9	- Soma de kilos pisados na embreagem
    18:11	- Soma do valor das marchas trocadas
    19:12	- Soma da quantidade das marchas trocadas
    20:13	- Soma dos valores das velocidades que o carro alterou
    21:14	- Soma de quantas vezes a velocidade do carro alterou
    22:15	- Soma dos graus virados à esquerda
    23:16	- Soma dos graus virados à direita
    */
	
	private static final int sizeDataMemory = 17;
	private static final int sizeOpCodeHash = 23;
	private static final int sizeOpCodeMemory = 1000;
	private static final char delimit = ':';
	
	public int[] initializeDataMemory() {
		//Memoria com 17 posicoes:
		int[] memoryData = {0, 0, 0, 0, 
							0, 0, 0, 0, 
							0, 0, 0, 0, 
							0, 0, 0, 0,
							0 };
		return memoryData;
	}
	
	public ArrayList<String> generateOpCodes() {
		ArrayList<String> actions = new ArrayList<String>();
		int randomNumber = 0;
		for (int i = 0; i < sizeOpCodeMemory; i++) {
			randomNumber = getRandomNumber(sizeOpCodeHash) + 1;
			actions.add(getOpCodes(randomNumber));
		}

		return actions;
	}
	
	private String getOpCodes(int action) {
		String opCode = String.valueOf(action);
		switch(action) {
			case 1:
			case 2:
			case 10:
				opCode = opCode.concat(delimit + "1");
				break;
			case 3:
				opCode = opCode.concat(delimit + "2");
				break;
			case 4:
			case 11:
				opCode = opCode.concat(delimit + "3");
				break;
			case 5:
			case 9:
			case 12:
				opCode = opCode.concat(delimit + "4");
				break;
			case 6:
				opCode = opCode.concat(delimit + "5");
				break;
			case 7:
				opCode = opCode.concat(delimit + "6");
				break;
			case 8:
			case 13:
				opCode = opCode.concat(delimit + "17");
				break;
			case 14:
				opCode = opCode.concat(delimit + "7");
				break;
			case 15:
				opCode = opCode.concat(delimit + "8");
				break;
			case 16:
				opCode = opCode.concat(delimit + "10");
				break;
			case 17:
				opCode = opCode.concat(delimit + "9");
				break;
			case 18:
				opCode = opCode.concat(delimit + "11");
				break;
			case 19:
				opCode = opCode.concat(delimit + "12");
				break;
			case 20:
				opCode = opCode.concat(delimit + "13");
				break;
			case 21:
				opCode = opCode.concat(delimit + "14");
				break;
			case 22:
				opCode = opCode.concat(delimit + "15");
				break;
			case 23:
				opCode = opCode.concat(delimit + "16");
				break;
		}
		return opCode;
	}
	
	private int getRandomNumber(int range) {
		Random rand = new Random();
        return (range == 0) ? rand.nextInt() : rand.nextInt(range);
	}
	
	public int[] executeOpCode(String opCode) {
		/*
		 * Retorno
		 * Primeiro: Posicao da Memoria onde irei salvar o dado
		 * Segundo: O dado a ser salvo
		 * Terceiro: Posicao da memoria para o incremento +1
		 * Quarto: Posicao da memoria para incremento +x
		 */
		int[] x = {-1, -1, -1, -1};
		
		int action = Integer.parseInt(opCode.split(":")[0]);
		
		switch(action) {
		case 1: //ligando o carro
				x[0] = 0;
				x[1] = 1;
				x[2] = 6;
				
				System.out.println("O carro foi ligado");
			break;
		case 2: //desligando o carro
				x[0] = 0;
				x[1] = 0;
				x[2] = 7;
				System.out.println("O carro foi desligado");
			break;
		case 3: //pisando na embreagem 
				x[0] = 1;
				x[1] = getRandomNumber(100) + 1;
				x[2] = 9;
				x[3] = 8;
				System.out.println("A embreagem foi pisada com uma força de " + x[1] + " kgs");
			break;
		case 4: //trocando a marcha
				x[0] = 2;
				x[1] = getRandomNumber(6) + 1; 
				x[2] = 11;
				x[3] = 10;
				
				if(x[1] == 6) 
					System.out.println("Marcha trocada para a marcha à ré ");
				else 
					System.out.println("Marcha trocada para a " + x[1] + "ª marcha");
				
			break;
		case 5: //acelerando o carro
			x[0] = 3;
			x[1] = getRandomNumber(250) + 1;
			x[2] = 13;
			x[3] = 12;
			System.out.println("Acelerando o carro para " + x[1] + " hm/h");
			break;
		case 6: //virando à direita
			x[0] = 4;
			x[1] = getRandomNumber(360) + 1;
			x[3] = 15;
			
			System.out.println("O carro virou " + x[1] + " graus à direita");
			break;
		case 7: //virando à esquerda
			x[0] = 5;
			x[1] = getRandomNumber(360) + 1;
			x[3] = 14;
			
			System.out.println("O carro virou " + x[1] + " graus à esquerda");
			break;
		case 8: //carro batido
			x[0] = 16;
			x[2] = 16;
			
			System.out.println("Carro batido");
			break;
		case 9: //diminuindo a velocidade do carro
			x[0] = 3;
			x[1] = getRandomNumber(50) + 1;
			x[2] = 13;
			x[3] = 12;
			System.out.println("Desacelerando o carro para " + x[1] + " hm/h");
			break;
		case 10://status do carro (ligado|desligado)
			x[0] = 0;
			break;
		case 11: //marcha atual do carro
			x[0] = 2;
			break;
		case 12: //velocidade atual do carro
			x[0] = 3;
			break;
		case 13: //soma de quantas vezes o carro bateu
			x[0] = 16;
			break;
		case 14: //numero de vezes que o carro ligou
			x[0] = 6;
			break;
		case 15: //numero de vezes que o carro desligou
			x[0] = 7;
			break;
		case 16: //soma de quantas vezes o carro pisou na embreagem
			x[0] = 9;
			break;
		case 17: //soma dos kilos pisados na embreagem
			x[0] = 8;
			break;
		case 18: //soma do valor das marchas trocadas
			x[0] = 10;
			break;
		case 19: //soma da quantidade de marchas trocadas
			x[0] = 11;
			break;
		case 20: //soma dos valores das velocidades que o carro alterou
			x[0] = 12;
			break;
		case 21: //soma de quantas vezes a velocidade do carro alterou
			x[0] = 13;
			break;
		case 22: //soma dos graus virados à esquerda
			x[0] = 14;
			break;
		case 23: //soma dos graus virados à direita
			x[0] = 15;
			break;
		}
		
		return x;
	}
	
}
