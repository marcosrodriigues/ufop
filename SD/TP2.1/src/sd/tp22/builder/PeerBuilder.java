package sd.tp22.builder;

import sd.tp22.peer.Peer;
import sd.tp22.peer.PeerClient;
import sd.tp22.peer.PeerServer;

public class PeerBuilder {

    private final int SOCKET_PORT = 7090;

    private PeerServer server;
    private PeerClient client;

    public PeerBuilder() {
        this.server = new PeerServer(SOCKET_PORT);

        try {
            this.client = new ClientBuilder().build();
        } catch (Exception e) {
            System.err.println("Erro ao iniciar PeerClient: " + e);
        }
    }

    public PeerBuilder server(PeerServer server) {
        this.server = server;
        return this;
    }

    public PeerBuilder client(PeerClient client) {
        this.client = client;
        return this;
    }

    public Peer build() {
        return new Peer(server, client);
    }


}
