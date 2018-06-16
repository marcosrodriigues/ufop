package appl.simpleAppl;

import java.io.File;
import java.util.Map;

import implementations.collections.JCLHashMap;
import implementations.dm_kernel.user.JCL_FacadeImpl;
import interfaces.kernel.JCLMap;
import interfaces.kernel.JCL_facade;

public class appl7 {

	public static void main(String[] args) {
		appl7 app = new appl7();
	}
	
	public appl7() {
		
		// TODO Auto-generated constructor stub
		Map<String, String> m = JCL_FacadeImpl.GetHashMap("mymap");
		Map<String, String> m1 = new JCLHashMap<String, String>("mymap1");
		
		File[] book = {new File("../jcl_useful_jars/book.jar")};
		Map<String, Book> b = new JCLHashMap<String, Book>("usertypemap", "book", book);
		Map<String, Book> b1 = JCL_FacadeImpl.GetHashMap("usertypemap1", "book", book);
		Book myBook = new Book("author", "editor", 1024, 2015);
		b.put("1", myBook);
		b1.put("1", myBook);
		myBook = b.get("1");
		//any other Java map interface method can be invoked!!
		myBook.print();
		
	}
}
