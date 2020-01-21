package sd.tp2.server;

import sd.tp2.server.interf.Message;
import sd.tp2.server.resources.Consumer;
import sd.tp2.server.resources.Resource;
import sd.tp22.peer.Peer;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class SocketConsumer<S extends Socket> extends Consumer<S> {

    public SocketConsumer(Resource<S> res) {
        super(res);
    }

    @Override
    protected void doSomething(S str) {
        try {
            ObjectInputStream in = new ObjectInputStream(str.getInputStream());
            Message msg = (Message) in.readObject();

            String host_from = str.getInetAddress().getHostName();

            Object response;

            System.out.println("[SocketConsumer]: VALIDANDO CLOCK LOCAL " + Peer.getClockString() + " E CLOCK EXTERNO " + msg.getClockToString());

            if(ehConcorrente(msg, host_from)) {
                System.out.println(" ======= DOIS EVENTOS CONCORRENTES IDENTIFICADOS NO SOCKET_CONSUMER =======");
                System.out.println("[SocketConsumer]: CLOCK NO SERVIDOR: " + Peer.getClockString() + " - CLOCK RECEBIDO DO CLIENTE: " + msg.getClockToString());
                //response = "##DENIED##" + msg.getClockToString();
            }

            Peer.setVirtualClock(updateVirtualClock(msg, host_from));
            System.out.println("[SocketConsumer]: Executando mensagem " + msg.toString());
            response = commands.get(msg.getType()).execute(msg);

            ObjectOutputStream out = new ObjectOutputStream(str.getOutputStream());
            out.writeObject(response);
            out.flush();
            out.close();
            in.close();

            str.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private boolean ehConcorrente(Message msg, String host) {
        int[] clock = Peer.getClock();
        int[] other_clock = extractClock(msg);

        boolean paraTodoI = true;
        boolean existeI = false;
        boolean ehIgual = true;

        for (int i = 0; i < clock.length; i++) {
            if (!(clock[i] <= other_clock[i])) paraTodoI = false;
        }

        return !paraTodoI;
    }

    private int[] updateVirtualClock(Message msg, String host) {
        int[] clock = Peer.getClock();
        int[] other_clock = extractClock(msg);

        clock[Peer.myPosition()] = clock[Peer.myPosition()] + 1;

        for (int i = 0; i < clock.length; i++)
            clock[i] = Math.max(clock[i], other_clock[i]);

        return clock;
    }

    private int[] extractClock(Message msg) {
        return msg.getClock();
    }
}
