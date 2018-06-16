package appl.simpleAppl;

import java.io.File;
import java.util.List;
import java.util.Random;

import implementations.dm_kernel.user.JCL_FacadeImpl;
import interfaces.kernel.JCL_facade;
import interfaces.kernel.JCL_result;

public class appl6 {
	public static void main(String[] args) {
		appl6 app = new appl6();
	}
	
	public appl6() {
		
		// TODO Auto-generated constructor stub
		JCL_facade javaCaLa = JCL_FacadeImpl.getInstance();
		
		// Load jar file
		File[] applJars = {new File("../jcl_useful_jars/manipulateFile.jar")};
		
		//the name of the class to be executed in the Jar file		
		javaCaLa.register(applJars, "manipulateFile");
		
		// Get all hosts
		List<String> hosts = javaCaLa.getHosts();
		
		// random choice one host
		Random gerador = new Random();
        int number = gerador.nextInt(hosts.size());        
        String host = hosts.get(number);
		
		//no args execute in choice host (Create file on host)
		String ticket = javaCaLa.executeOnHost(host,"manipulateFile", "create");
		
		//wait 
		javaCaLa.getResultBlocking(ticket);
		
		//no args execute in chosen host (Print file content on host)
		String ticketPrint = javaCaLa.executeOnHost(host,"manipulateFile", "printOnHost");
		
		//wait
		javaCaLa.getResultBlocking(ticketPrint);
		
		//Print chosen host
		System.out.println("Host: "+host);
		
		//close JCL
		javaCaLa.destroy();
		
	}

}
