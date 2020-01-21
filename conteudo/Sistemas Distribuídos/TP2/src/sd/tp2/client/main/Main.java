package sd.tp2.client.main;

import sd.tp2.client.enums.ConfigProperties;
import sd.tp2.client.resource.Client;

import java.util.Random;

public class Main {

    public static void main (String args[]) {
        int numberOfRequest = 100000;

        for (int i = 0; i < args.length; i++) {
            if (args[i].startsWith("-n")) numberOfRequest= Integer.parseInt(args[i].split("=")[1]);
        }

        long inicio = System.nanoTime();

        ConfigProperties[] tipos = ConfigProperties.values();
        Random rand = new Random();

        int next = 0;
        for (int i = 0; i < numberOfRequest; i++) {
            next = rand.nextInt(tipos.length) + 1;
            new Client(next);
            System.out.println(i);
        }

        System.out.println("tempo de execução: " + (System.nanoTime() - inicio));

    }
}
