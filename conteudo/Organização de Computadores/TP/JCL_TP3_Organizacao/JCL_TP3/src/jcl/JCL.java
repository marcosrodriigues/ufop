package jcl;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

import implementations.sm_kernel.JCL_FacadeImpl;
import interfaces.kernel.JCL_facade;
import interfaces.kernel.JCL_result;

public class JCL {

	public JCL() {
		//Instanciando o Java CaeLa
		JCL_facade jcl = JCL_FacadeImpl.getInstance();

		//Registando o JAR que irei usar as minhas funções
		File file = new File("lib/SimuladorCarro.jar");
		File[] arg = {file};
		System.err.println(jcl.register(arg, "SimuladorCarro"));

		//Declarando minhas variáveis
		for(int i = 0; i < 17; i++ )
			jcl.instantiateGlobalVar("dataMemory_" + i, new Integer(0));
		jcl.instantiateGlobalVar("actionsOpCode", new ArrayList<String>());
		jcl.instantiateGlobalVar("nextOpCode", new String());
		jcl.instantiateGlobalVar("currentOpCode", new String());
		jcl.instantiateGlobalVar("currentAction", new Integer(0));

		int[] retMemory = new int[4];

		//Declarando o argumento da funcao a ser chamada
		Object[] args = null;
		String ticket = jcl.execute("SimuladorCarro", "generateOpCodes", args);

		JCL_result result = jcl.getResultBlocking(ticket);
		JCL_result result1 = null;
		
		int varAux = 0;

		if (result.getCorrectResult() != null) {
			jcl.setValueUnlocking("actionsOpCode", result.getCorrectResult());
			result = jcl.getValue("actionsOpCode");
			if (result.getCorrectResult() != null) {
				ListIterator<String> arrayOpCodes = ((List<String>)result.getCorrectResult()).listIterator();

				//Pipeline
				if (arrayOpCodes.hasNext()) {
					jcl.setValueUnlocking("nextOpCode", arrayOpCodes.next());
					result = jcl.getValue("nextOpCode");
					
					if (arrayOpCodes.hasNext()) {
						jcl.setValueUnlocking("nextOpCode", arrayOpCodes.next());
						result1 = jcl.getValue("nextOpCode");
						
					}
				}
				
				while(arrayOpCodes.hasNext()) {
					
					if(result.getCorrectResult() != null) {
						//Salvando meu opCode:
						jcl.setValueUnlocking("currentOpCode", result.getCorrectResult().toString());
						
						//Executando o meu opCode;
						ticket = jcl.execute("SimuladorCarro", "executeOpCode", result.getCorrectResult().toString());

						//Pego o resultado do meu executeOpCode
						result = jcl.getResultBlocking(ticket);
						if(result.getCorrectResult() != null) {
							/*
							 * Retorno
							 * Primeiro: Posicao da Memoria onde irei salvar o dado
							 * Segundo: O dado a ser salvo
							 * Terceiro: Posicao da memoria para o incremento +1
							 * Quarto: Posicao da memoria para incremento +x
							 */
							retMemory = (int[])result.getCorrectResult();
							
							if(retMemory[1] != -1) {
								jcl.setValueUnlocking("dataMemory_" + retMemory[0], retMemory[1]);
								
								//Quarto retorno (posicao 3) é dependente do primeiro, por isso o IF aqui dentro 
								if (retMemory[3] != -1) {
									result1 = jcl.getValue("dataMemory_" + retMemory[3]);
									
									if(result1.getCorrectResult() != null) {
										varAux = Integer.parseInt(result1.getCorrectResult().toString());
										
										jcl.setValueUnlocking("dataMemory_" + retMemory[3], varAux + retMemory[1]);
									} else result1.getErrorResult().printStackTrace();
								}
							}

							if(retMemory[2] != -1) {
								result1 = jcl.getValue("dataMemory_" + retMemory[2]);
								
								if(result1.getCorrectResult() != null) {
									varAux = Integer.parseInt(result1.getCorrectResult().toString());
									
									jcl.setValueUnlocking("dataMemory_" + retMemory[2], varAux + 1);
								} else result1.getErrorResult().printStackTrace();
							}
							
							jcl.setValueUnlocking("currentAction", Integer.parseInt(jcl.getValue("currentOpCode").getCorrectResult().toString().split(":")[0]));
							
							//Busco dados da memoria
							switch(Integer.parseInt(jcl.getValue("currentAction").getCorrectResult().toString())) {
							case 10://status do carro (ligado|desligado)
								System.err.println("O carro esta atualmente " + 
											(jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString() == "1" ? 
													"ligado" : "desligado"));
								break;
							case 11: //marcha atual do carro
								System.err.println("Marcha atual do veículo: " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString());
								break;
							case 12: //velocidade atual do carro
								System.err.println("Velocidade atual do veículo: " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString());
								break;
							case 13: //soma de quantas vezes o carro bateu
								System.err.println("O veículo bateu " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " vezes");
								break;
							case 14: //número de vezes que o carro ligou
								System.err.println("O veículo ligou " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " vezes");
								break;
							case 15: //numero de vezes que o carro desligou
								System.err.println("O veículo desligou " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " vezes");
								break;
							case 16: //soma de quantas vezes o carro pisou na embreagem
								System.err.println("O carro foi pisado na embreagem " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " vezes");
								break;
							case 17: //soma dos kilos pisados na embreagem
								System.err.println("O carro sofreu pisagem de " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " kg na embreagem");
								break;
							case 18: //soma do valor das marchas trocadas
								System.err.println("O veículo somou o valor total de " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " marchas trocadas");
								break;
							case 19: //soma da quantidade de marchas trocadas
								System.err.println("O veículo trocou de marcha " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " vezes");
								break;
							case 20: //soma dos valores das velocidades que o carro alterou
								System.err.println("O veículo somou o valor total de " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " de velocidades alteradas");
								break;
							case 21: //soma de quantas vezes a velocidade do carro alterou
								System.err.println("O veículo alterou sua velocidade " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " vezes");
								break;
							case 22: //soma dos graus virados à esquerda
								System.err.println("O veículo somou o valor total de " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " graus virados à esquerda");
								break;
							case 23: //soma dos graus virados à direita
								System.err.println("O veículo somou o valor total de " 
										+ jcl.getValue("dataMemory_" + retMemory[0]).getCorrectResult().toString()
										+ " graus virados à direita");
								break;
							}
							

						} else result.getErrorResult().printStackTrace();
					} else result.getErrorResult().printStackTrace();
					
					result = result1;
					result1 = null;
					try {
						jcl.setValueUnlocking("nextOpCode", arrayOpCodes.next());
						result1 = jcl.getValue("nextOpCode");
					} catch (Exception e) {
						
					}
					
				}
			}
		} else result.getErrorResult().printStackTrace();

		jcl.removeResult(ticket);
		jcl.destroy();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new JCL();
	}

}
