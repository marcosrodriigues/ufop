package sd.tp22.main;

import sd.tp22.peer.Peer;
import sd.tp22.peer.PeerClient;
import sd.tp22.peer.PeerServer;
import sd.tp22.peer.properties.IpProperties;

import java.net.InetAddress;

public class Main {

    //private static final String MASTER = "127.0.1.1";
    private static final String MASTER = "10.128.0.2";
    private static final String WORKER_1 = "10.128.0.3";
    private static final String WORKER_2 = "10.128.0.4";

    private static final IpProperties ips = IpProperties.getInstance();

    public static void main(String[] args) {
        ips.getListIp().forEach(ip -> System.out.println(ip.trim()));

        System.out.println("=====  EXECUTANDO SCENARIO #1  =====");
        scenarioOne(7090);
        System.out.println("=====  FINALIZOU SCENARIO #1  =====");

        
        System.out.println("=====  EXECUTANDO SCENARIO #2  =====");
        scenarioTwo(5151);
        System.out.println("=====  FINALIZOU SCENARIO #2  =====");
//
//
//        System.out.println("=====  EXECUTANDO SCENARIO #3  =====");
//        scenarioRandom();
//        System.out.println("=====  FINALIZOU SCENARIO #3  =====");
    }

    private static void scenarioOne(int port) {
        String address = getAddress();
        System.out.println("Address: " + address);

        PeerServer server = new PeerServer.ServerBuilder().port(port).build();

        if (address.equals(MASTER)) {
            incrementAndSend(server, WORKER_1, 1);
        } else if (address.equals(WORKER_1)) {
            receiveAndSend(server, WORKER_2, 1, false);
        } else if (address.equals(WORKER_2)) {
            incrementAndReceive(server);
        }
    }

    private static void scenarioTwo(int port) {
        try {
            String address = getAddress();
            System.out.println("Address: " + address);

            PeerServer server = new PeerServer.ServerBuilder().port(port).build();

            if (address.equals(MASTER)) {
                receiveAndSend(server, WORKER_2, 1, false);
            } else if (address.equals(WORKER_1)) {
                receiveAndSend(server, MASTER, 1, true);
            } else if (address.equals(WORKER_2)) {
                incrementTwiceReceiveAndSend(server, WORKER_1, 1);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void scenarioRandom() {

    }

    private static void incrementAndSend(PeerServer server, String dest, int numberOfRequest) {
        PeerClient client = createClient(dest, numberOfRequest);

        Peer peer = new Peer.PeerBuilder(server, client)
                .port(server.getPort())
                .build();
        peer.initServer();

        Peer.incrementIp();

        peer.initClient();
        peer.waitClient();
    }

    private static void receiveAndSend(PeerServer server, String dest, int numberOfRequest, boolean show) {
        PeerClient client = createClient(dest, numberOfRequest);

        Peer peer = new Peer.PeerBuilder(server, client)
                .port(server.getPort())
                .build();
        peer.initServer();

        peer.initClient();
        peer.waitClient();

        if (show) {
            System.out.println("[MAIN:] CLOCK FINAL " + Peer.getClockString());
        }
    }

    private static void incrementAndReceive(PeerServer server) {
        Peer peer = new Peer.PeerBuilder(server)
                .build();

        Peer.incrementIp();
        peer.initServer();

        System.out.println("[MAIN:] CLOCK FINAL " + Peer.getClockString());
    }

    private static void incrementTwiceReceiveAndSend(PeerServer server, String dest, int numberOfRequest) {
        PeerClient client = createClient(dest, numberOfRequest);

        Peer peer = new Peer.PeerBuilder(server, client)
                .port(server.getPort())
                .build();
        peer.initServer();

        Peer.incrementIp();
        Peer.incrementIp();

        peer.waitEnter();

        client.start();
    }

    private static PeerClient createClient(String host, int numberRequest) {
        return new PeerClient.ClientBuilder()
                .host(host)
                .numberOfRequest(numberRequest)
                .build();
    }

    private static String getAddress() {
        String address = "";
        try {

            String name = InetAddress.getLocalHost().getHostName();

            if (name.equals("instance-1")) address = MASTER;
            else if (name.equals("instance-2")) address = WORKER_1;
            else if (name.equals("instance-3")) address = WORKER_2;

        } catch (Exception e) {
            e.printStackTrace();
        }

        return address;

    }
}
