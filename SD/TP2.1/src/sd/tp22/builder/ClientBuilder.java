package sd.tp22.builder;

import sd.tp22.peer.PeerClient;

import java.io.IOException;

public class ClientBuilder {
    private String host = "";
    private int numberOfRequest = 10;
    private int port = 7090;

    public ClientBuilder host(String actualHost) {
        this.host = actualHost;
        return this;
    }

    public ClientBuilder numberOfRequest(int numberOfRequest) {
        this.numberOfRequest = numberOfRequest;
        return this;
    }

    public ClientBuilder port(int port) {
        this.port = port;
        return this;
    }

    public PeerClient build() throws IOException {
        return new PeerClient(host, port, numberOfRequest);
    }
}
