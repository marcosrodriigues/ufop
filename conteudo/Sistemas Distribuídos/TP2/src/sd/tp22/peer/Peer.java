package sd.tp22.peer;

import sd.tp22.peer.properties.IpProperties;

import java.io.IOException;
import java.net.InetAddress;
import java.util.Map;
import java.util.Scanner;

public class Peer {

    private PeerServer server;
    private PeerClient client;
    private static int[] virtual_clock;
    private static String me;

    private Peer(PeerBuilder builder) {
        this.server = builder.server;
        this.client = builder.client;

        this.virtual_clock = new int[IpProperties.getInstance().getSize()];
        this.me = myName();

        System.out.println("ME: " + me);
        System.out.println("CLOCK:" + getClockString());
    }

    public PeerServer getServer() {
        return server;
    }

    public PeerClient getClient() {
        return client;
    }

    public void initServer() {
        this.server.start();
        waitServer();
    }

    public void waitServer() {
        System.out.println("[### Servidor iniciado. Pressione ENTER para iniciar o cliente. ###]");
        Scanner in = new Scanner(System.in);
        in.nextLine();
    }

    public void waitEnter() {
        System.out.println("[### PAUSADO. Aperte ENTER pra continuar. ###]");
        Scanner in = new Scanner(System.in);
        in.nextLine();
    }

    public void waitClient() {
        System.out.println("[### Mensagem enviada. Pressione ENTER para enviar a próxima mensagem. ###]");
        Scanner in = new Scanner(System.in);
        in.nextLine();
    }

    public void closeServer() {
        try {
            this.server.join();
        } catch (Exception e) {
            System.out.println("Cannot did join server!");
            e.printStackTrace();;
        }
    }

    public void initClient() {
        this.client.start();
    }

    public void closeClient(){
        try {
            this.client.join();
        } catch (Exception e) {
            System.err.println("Coudln't did join client!");
            e.printStackTrace();
        }

    }


    public static void incrementIp() {
        int position = myPosition();
        if (position < 0) throw new RuntimeException("IP NAO PERTENCE A LISTA DE VETORES DO IP.PROPERTIES");
        virtual_clock[position]++;
        System.out.println("###  [PEER]: Ip Incrementado: " + getClockString());
    }

    public static int myPosition() {
        return getPositionFromHostOrIp(me);
    }

    public static void setVirtualClock(int[] vc) {
        virtual_clock = vc;
    }

    public static int getPositionFromHostOrIp(String hostOrIp) {
        int position = 0;

        for (Map.Entry<String, String> pair : IpProperties.getInstance().getHash().entrySet()) {
            if (pair.getKey().equals(hostOrIp) || pair.getValue().equals(hostOrIp)) return position;
            position++;
        }
        return -1;
    }

    public static int[] getClock() {
        return virtual_clock;
    }

    public static String getClockString() {
        String ret = "[";
        for(int i = 0; i < getClock().length; i++) {
            ret = ret.concat(String.valueOf(getClock()[i]));
            if (i + 1 < getClock().length) ret = ret.concat(",");
        }
        ret = ret.concat("]");
        return ret;
    }

    public static String myName() {
        String retorno = "";
        try {
            retorno = InetAddress.getLocalHost().getHostName();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return retorno;
    }

    public static class PeerBuilder {
        private int port = 7090;
        private PeerServer server;
        private PeerClient client;

        public PeerBuilder() {
            this.server = new PeerServer.ServerBuilder().port(port).build();
            this.client = new PeerClient.ClientBuilder().build();
        }

        public PeerBuilder(PeerServer server) {
            this.server = server;
            this.port = server.getPort();
            this.client = new PeerClient.ClientBuilder().build();
        }

        public PeerBuilder(PeerServer server, PeerClient client) {
            this.server = server;
            this.client = client;
            this.port = server.getPort();
        }

        public PeerBuilder server(PeerServer server) {
            this.server = server;
            return this;
        }

        public PeerBuilder client(PeerClient client) {
            this.client = client;
            return  this;
        }

        public PeerBuilder port(int port) {
            this.port = port;
            return this;
        }

        public Peer build() {
            Peer peer = new Peer(this);
            return peer;
        }
    }
}
