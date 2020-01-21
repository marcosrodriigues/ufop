package sd.tp2.client.resource;

import sd.tp2.client.message.MyIntMessage;
import sd.tp2.client.message.MyMessage;
import sd.tp2.server.interf.Message;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class Client {

    private final int PORT = 7020;
    private final String HOST = "10.8.40.216";

    private final int N = 20;
    private final String STR = "My beautiful world!";

    public Client(int type) {

        try {
            Socket s = new Socket(HOST, PORT);

            Message msg;
            String resposta;

            switch (type) {
                case 1:
                    msg = new MyIntMessage();
                    resposta = "Fibonacci de " + N + ": ";
                    ((MyIntMessage) msg).setNum(new Integer(N));
                    break;
                case 2:
                    msg = new MyIntMessage();
                    resposta = "Fatorial de " + N + ": ";
                    ((MyIntMessage) msg).setNum(new Integer(N));
                    break;
                case 3:
                    msg = new MyMessage();
                    resposta = "CountLetter da String: " + STR + ": ";
                    ((MyMessage) msg).setMyData(STR);
                    break;
                default:
                    throw new RuntimeException("TYPE NOT FOUND");
            }
            msg.setType(type);

            ObjectOutputStream out = new ObjectOutputStream(s.getOutputStream());

            out.writeObject(msg);
            out.flush();

            ObjectInputStream in = new ObjectInputStream(s.getInputStream());
            String response = (String) in.readObject();

            System.out.println(resposta + response);

            in.close();
            out.close();
            s.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
