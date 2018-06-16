package appl.simpleAppl;

import implementations.dm_kernel.user.JCL_FacadeImpl;
import interfaces.kernel.JCL_facade;
import interfaces.kernel.JCL_result;

import java.io.File;
import java.util.LinkedList;
import java.util.List;

public class appl3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		appl3 appl = new appl3();
	}
	
	public appl3(){
		JCL_facade jcl = JCL_FacadeImpl.getInstance();
						
		//creating a simple variable
		
		System.err.println(jcl.instantiateGlobalVar("firstVar", new String("nada")));
		jcl.setValueUnlocking("firstVar", "hello world");
		JCL_result result = jcl.getValue("firstVar");
		System.err.println(result.getCorrectResult().toString());
		
		//creating a matrix of integers called matrix_i:j
		long time = System.currentTimeMillis();
		
		time = System.currentTimeMillis();
		
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				Integer aux = new Integer (String.valueOf(i)+String.valueOf(j));
				jcl.instantiateGlobalVar("Matrix_"+String.valueOf(i) + ":" + String.valueOf(j), aux);
			}
		}
		
		System.err.println("created 100 cells in " + (System.currentTimeMillis()-time));
		
		
		//done!!
		//printing it
		for(int i=0; i<10; i++)
			for(int j=0; j<10; j++)
				System.err.println("cell: " + i + j + " :" + jcl.getValue("Matrix_"+i + ":" + j).getCorrectResult().toString());
		
					
		//writing useful GVs		
		Object[] args = {"eric gamma", "bookman", new Integer("287"), new Integer("2002")};
		File f = new File("../jcl_useful_jars/book.jar");
		File[] jars = {f};
		jcl.instantiateGlobalVar("myBook", "appl.simpleAppl.Book", jars, args);
		Object[] args1 = {"ullman and aho", "bookman", new Integer("587"), new Integer("2009")};
		jcl.instantiateGlobalVar("myBook1", "appl.simpleAppl.Book", jars, args1);
				
		//do something...		
		//get a book!
		Book b = (Book)jcl.getValue("myBook").getCorrectResult();
		b.print();		
		jcl.destroyGlobalVar("myBook");
		jcl.destroy();
	}	
	

}
