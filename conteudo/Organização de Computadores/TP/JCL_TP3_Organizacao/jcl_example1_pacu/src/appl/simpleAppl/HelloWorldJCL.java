package appl.simpleAppl;
import java.io.File;

import implementations.dm_kernel.user.JCL_FacadeImpl;
import interfaces.kernel.JCL_facade;


public class HelloWorldJCL {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new HelloWorldJCL();
	}
	
	public HelloWorldJCL(){
		JCL_facade meuJCL = JCL_FacadeImpl.getInstance();
		File f = new File("../jcl_useful_jars/alg.jar");
		File[] args ={f};
		boolean b = meuJCL.register(args, "Algoritmo");
		System.out.println(b);
		
		long tempoIni = System.nanoTime();
		Integer i = new Integer(40);
		Object[] param = {i};
		String t = meuJCL.execute("Algoritmo", param);
		String r = meuJCL.getResultBlocking(t).getCorrectResult().toString();
		System.out.println(r);
		
		Object[] param1 = {i+1};
		String t1 = meuJCL.execute("Algoritmo", param1);
		String r1 = meuJCL.getResultBlocking(t1).getCorrectResult().toString();
		System.out.println(r1);
		
		Object[] param2 = {i+2};
		String t2 = meuJCL.execute("Algoritmo", param2);
		String r2 = meuJCL.getResultBlocking(t2).getCorrectResult().toString();
		System.out.println(r2);
		
		Object[] param3 = {i+3};
		String t3 = meuJCL.execute("Algoritmo", param3);
		String r3 = meuJCL.getResultBlocking(t3).getCorrectResult().toString();
		System.out.println(r3);
		
		System.out.println("tempo: " + (System.nanoTime()-tempoIni));

		//usando paralelismo nivel 2
		tempoIni = System.nanoTime();
		t = meuJCL.execute("Algoritmo", param);
		t1 = meuJCL.execute("Algoritmo", param1);
		r = meuJCL.getResultBlocking(t).getCorrectResult().toString();
		System.out.println(r);
		r1 = meuJCL.getResultBlocking(t1).getCorrectResult().toString();
		System.out.println(r1);
		
		t2 = meuJCL.execute("Algoritmo", param2);
		t3 = meuJCL.execute("Algoritmo", param3);
		r2 = meuJCL.getResultBlocking(t2).getCorrectResult().toString();
		System.out.println(r2);
		r3 = meuJCL.getResultBlocking(t3).getCorrectResult().toString();
		System.out.println(r3);
		
		System.out.println("tempo: " + (System.nanoTime()-tempoIni));
		
		//usando paralelismo nivel 4
		tempoIni = System.nanoTime();
		t = meuJCL.execute("Algoritmo", param);
		t1 = meuJCL.execute("Algoritmo", param1);
		t2 = meuJCL.execute("Algoritmo", param2);
		t3 = meuJCL.execute("Algoritmo", param3);
		
		r = meuJCL.getResultBlocking(t).getCorrectResult().toString();
		System.out.println(r);
		r1 = meuJCL.getResultBlocking(t1).getCorrectResult().toString();
		System.out.println(r1);
		r2 = meuJCL.getResultBlocking(t2).getCorrectResult().toString();
		System.out.println(r2);
		r3 = meuJCL.getResultBlocking(t3).getCorrectResult().toString();
		System.out.println(r3);
		
		System.out.println("tempo: " + (System.nanoTime()-tempoIni));

		
		meuJCL.destroy();
		
	}

}
