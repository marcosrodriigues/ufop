package appl.simpleAppl;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class manipulateFile {
	
	public boolean create(){
		try {
			FileWriter writer = new FileWriter(new File("../jcl_temp/saida.txt"));
			PrintWriter saida = new PrintWriter(writer); 
			for (int cont = 0 ; cont < 100; cont++){
				saida.println("Saida: "+cont);
			}
			saida.close();
			writer.close();
			return true;
		} catch (IOException e){
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}  				
	}
	
	
	public void printOnHost(){
		
		try {
			FileReader reader = new FileReader("../jcl_temp/saida.txt");
			BufferedReader leitor = new BufferedReader(reader); 
			String linha = null;  
			while((linha = leitor.readLine()) != null) {  
			    System.out.println("Line: " + linha);  
			}
			
			leitor.close();  
			reader.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
	
	}
}
