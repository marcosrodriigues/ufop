package sd.tp22.peer;

import sd.tp2.client.message.MyMessage;
import sd.tp2.server.interf.Message;
import sd.tp22.properties.IpProperties;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Collection;
import java.util.Random;

public class PeerClient  extends Thread {

    private final Collection<String> KNOWN_HOSTS;

    private int port;
    private int numberOfRequest;
    private String host;

    public PeerClient(String host, int port, int n) throws IOException {
        this.host = host;
        this.port = port;
        numberOfRequest = n;
        KNOWN_HOSTS = IpProperties.getInstance().getListIp();
    }

    public void run() {
        int count = 0;
        while (count < numberOfRequest) {
            initClient(host.isEmpty() ? getIpRandom() : host);
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
            System.out.println("[CLIENT]: Enviando requisição para " + host);
            Socket socket = new Socket(host, port);

            Message msg = new MyMessage();
            ((MyMessage) msg).setMyData("Mensagem a ser enviada ao cliente");
            msg.setType(4);

            System.out.println("[CLIENT]: Executando " + msg.toString());

            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            out.writeObject(msg);
            out.flush();

            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
            String response = (String) in.readObject();
            System.out.println("[CLIENT]: Resposta depois de executar: " + response);

            in.close();
            out.close();
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}
