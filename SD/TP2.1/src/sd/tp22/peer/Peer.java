package sd.tp22.peer;

import java.util.Scanner;

public class Peer {

    private PeerServer server;
    private PeerClient client;

    public Peer(PeerServer server, PeerClient client) {
        this.server = server;
        this.client = client;
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

    public void closeServer() throws InterruptedException {
        this.server.join();
    }

    public void initClient() {
        this.client.start();
    }

    public void closeClient() throws InterruptedException {
        this.client.join();
    }

    private void waitServer() {
        System.out.println("[SERVIDOR INICIADO. PRESSIONE QUALQUER TECLA PARA CONTINUAR]");
        Scanner in = new Scanner(System.in);
        in.nextLine();
    }
}
