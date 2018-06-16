package appl.simpleAppl;

import implementations.dm_kernel.user.JCL_FacadeImpl;
import interfaces.kernel.JCL_facade;
import interfaces.kernel.JCL_result;

import java.io.File;

public class appl4ExecutingJars {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		appl4ExecutingJars appl1 = new appl4ExecutingJars();
	}
	
	@SuppressWarnings("unchecked")
	public appl4ExecutingJars(){
		try {
						
			//application with two dependencies
			File[] complexApplJars = {new File("../jcl_useful_jars/myChartAppl.jar"), new File("../jcl_useful_jars/jcommon-1.0.17.jar"), new File("../jcl_useful_jars/jfreechart-1.0.14.jar")};
						
			JCL_facade javaCaLa = JCL_FacadeImpl.getInstance();
			
			//the name of the class to be executed in the Jar file
			javaCaLa.register(complexApplJars, "BarExample2");
			
			
			//no args
			String ticket3 = javaCaLa.execute("BarExample2", null);
			String ticket4 = javaCaLa.execute("BarExample2", null);
			
			
			JCL_result jclr = null;
			jclr = javaCaLa.getResultBlocking(ticket4);
			if(jclr.getErrorResult()!=null)
				jclr.getErrorResult().printStackTrace();
			else System.err.println(jclr.getCorrectResult().toString());
			
			javaCaLa.removeResult(ticket4);
			
						
			jclr = null;
			jclr = javaCaLa.getResultBlocking(ticket3);
			if(jclr.getErrorResult()!=null)
				jclr.getErrorResult().printStackTrace();
			else System.err.println(jclr.getCorrectResult().toString());
			
			javaCaLa.removeResult(ticket3);
			javaCaLa.destroy();
			
						
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}

}
