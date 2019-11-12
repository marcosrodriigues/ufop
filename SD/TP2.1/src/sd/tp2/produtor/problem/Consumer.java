package sd.tp2.produtor.problem;

public class Consumer<S> extends Thread {

    private Resource<S> re;

    public Consumer (Resource<S> re) {
        this.re = re;
    }

    public void run() {
        try {
            S str = null;

            int i = 0;
            while (!re.isFinished() || re.getNumOfRegisters() != 0) {
                if ((str = re.getRegister()) != null) {
                    System.out.println("Consumidor lendo recurso " + i++ + ". Conteúdo: " + str);

                    //faz algo com o recurso.
                    if (((String) str).endsWith("100 "))
                        System.out.println(str);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
