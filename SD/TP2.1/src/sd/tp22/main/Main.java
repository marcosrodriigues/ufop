package sd.tp22.main;

import sd.tp22.peer.Peer;
import sd.tp22.peer.PeerClient;
import sd.tp22.peer.PeerServer;
import sd.tp22.builder.ClientBuilder;
import sd.tp22.builder.PeerBuilder;
import sd.tp22.properties.IpProperties;

import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException, InterruptedException {
        //IPs do cluster
        IpProperties ips = IpProperties.getInstance();
        ips.getListIp().forEach(ip -> System.out.println(ip.trim()));

        //Peer com valores default
        Peer peer = new PeerBuilder().build();
//        peer.initServer();
//        peer.initClient();
//
//        peer.closeClient();
//        peer.closeServer();

        //Peer especificando os parametros
        PeerServer server = new PeerServer(7090);
        PeerClient client = new ClientBuilder()
                .host("")
                .numberOfRequest(10)
                .port(7090)
                    .build();
        peer = new PeerBuilder()
                .server(server)
                .client(client)
                .build();

        peer.initServer();
        peer.initClient();

        peer.closeClient();
        peer.closeServer();
    }
}
