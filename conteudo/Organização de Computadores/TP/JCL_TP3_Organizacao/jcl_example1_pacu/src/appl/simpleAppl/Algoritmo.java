package appl.simpleAppl;

public class Algoritmo {

	//Fib
	 public long execute(int n) {
	        if (n < 2) {
	            return n;
	        } else {
	            return execute(n - 1) + execute(n - 2);
	        }
	    }
}
