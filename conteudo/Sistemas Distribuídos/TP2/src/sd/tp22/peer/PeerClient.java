package sd.tp22.peer;

import sd.tp2.client.message.MyMessage;
import sd.tp2.server.interf.Message;
import sd.tp22.peer.properties.IpProperties;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Map;
import java.util.Random;

public class PeerClient  extends Thread {

    private Collection<String> KNOWN_HOSTS;

    private int port;
    private int numberOfRequest;
    private String host;

    private PeerClient(ClientBuilder builder) {
        this.configure(builder.host, builder.port, builder.numberOfRequest);
    }

    private void configure(String host, int port, int n) {
        this.host = host;
        this.port = port;
        numberOfRequest = n;

        Collection<String> knows = new ArrayList<>();

        for (Map.Entry<String, String> pair : IpProperties.getInstance().getHash().entrySet()) {
            if (Peer.myName().equals(pair.getKey())) continue;
            knows.add(pair.getValue());
        }

        KNOWN_HOSTS = knows;
    }

    public void run() {
        Random rand = new Random();
        String actualHost;
        int chance = 0;
        int count = 0;
        while (count < numberOfRequest) {
            chance = rand.nextInt(100);
            actualHost = host.isEmpty() ? getIpRandom() : host;
            initClient(actualHost);
            count++;
        }
    }

    public String getIpRandom() {
        Random rand = new Random();
        int size = KNOWN_HOSTS.size();
        int next = rand.nextInt(size);
        return KNOWN_HOSTS.toArray()[next].toString();
    }

    private void initClient(String host) {
        try {
            String response = "";
            Peer.incrementIp();

            //do {
                Socket socket = new Socket(host, port);
                System.out.println("[CLIENT]: #### INICICOU COMUNICACAO COM O SERVIDOR " + host + " ####");

                Message msg = new MyMessage();
                ((MyMessage) msg).setMyData(Peer.getClockString());
                msg.setType(4);
                msg.setClock(Peer.getClock());

                System.out.println("[CLIENT]: Enviando mensagem " + msg.toString() + " para o servidor");
                if (response.contains("##DENIED##")) {
                    System.out.println("[CLIENT]: CONEXAO RECUSADA PELO SERVIDOR. TENTANDO NOVAMENTE EM 2 SEGUNDOS");
                    Thread.sleep(2000);
                }

                ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());

                out.writeObject(msg);
                out.flush();

                ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
                response = (String) in.readObject();
                System.out.println("[CLIENT]: Recebeu a mensagem: '" + response + "' do " + host);

                in.close();
                out.close();
                socket.close();
                System.out.println("[CLIENT]: #### ENCERROU COMUNICACAO COM O SERVIDOR " + host + " ####");
            //} while (response.contains("##DENIED##"));


        } catch (Exception e) {
            e.printStackTrace();
        }

    }


    public static class ClientBuilder {
        private String host = "";
        private int numberOfRequest = 100;
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

        public PeerClient build() {
            PeerClient client = new PeerClient(this);
            return client;
        }
    }

}
