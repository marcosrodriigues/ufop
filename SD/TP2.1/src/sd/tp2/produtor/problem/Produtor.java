package sd.tp2.produtor.problem;

import java.io.BufferedReader;
import java.io.FileReader;

public class Produtor<S> extends Thread {

    private String fileName;
    private Resource<S> re;


    public Produtor(String fileName, Resource<S> re) {
        this.fileName = fileName;
        this.re = re;
    }

    public void run() {
        //cria um stream pra ler o arquivo
        try {
            BufferedReader in = new BufferedReader(new FileReader(fileName + ".txt"));
            String str = null;

            int i = 0;
            //ler o arquivo
            while ((str = in.readLine()) != null) {
                i = i + 1;
                System.out.println("Lendo a linha " + i + " de 9699 linhas");
                re.putRegister((S) str);
            }

            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("No connection");
        }
    }
}
