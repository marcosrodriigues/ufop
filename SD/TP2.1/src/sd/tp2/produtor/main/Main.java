package sd.tp2.produtor.main;

import sd.tp2.produtor.problem.Consumer;
import sd.tp2.produtor.problem.Produtor;
import sd.tp2.produtor.problem.Resource;

public class Main {

    public static void main(String[] args) {
        int pumProdutores = 2;
        int numConsumidores = 5;

        for (int i = 0; i < args.length; i++) {
            if (args[i].startsWith("-p")) pumProdutores = Integer.parseInt(args[i].split("=")[1]);
            else if (args[i].startsWith("-c")) numConsumidores = Integer.parseInt(args[i].split("=")[1]);
        }

        new Main(pumProdutores, numConsumidores);
    }

    public Main(int numProd,int numCons) {
        long inicio = System.nanoTime();
        final int numProdutores = numProd;
        final int numConsumidores = numCons;

        Resource<String> recurso = new Resource<>();

        String[] arquivos = {"matriz", "matriz2"};

        Produtor<String>[] produtores = new Produtor[numProdutores];
        for (int i = 0; i < produtores.length; i++) {
            produtores[i] = new Produtor<>(arquivos[i], recurso);
        }

        Consumer<String>[] consumidores = new Consumer[numConsumidores];
        for (int i = 0; i < consumidores.length; i++) {
            consumidores[i] = new Consumer<>(recurso);
        }

        for (int i = 0; i < produtores.length; i++) produtores[i].start();
        for (int i = 0; i < consumidores.length; i++) consumidores[i].start();

        try {
            for (int i = 0; i < produtores.length; i++) produtores[i].join();

            recurso.setFinished();

            for (int i = 0; i < consumidores.length; i++) consumidores[i].join();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.err.println("tempo de execução: " + ((System.nanoTime()) - inicio));
    }
}
