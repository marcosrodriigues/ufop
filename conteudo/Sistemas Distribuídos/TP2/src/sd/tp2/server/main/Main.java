package sd.tp2.server.main;

import sd.tp2.server.Server;
import sd.tp2.server.SocketConsumer;
import sd.tp2.server.resources.Consumer;
import sd.tp2.server.resources.Resource;

import java.net.Socket;

public class Main extends Server  {

    public static void main(String args[] ) {
        int serverPort = 7020;
        new Main(serverPort);
    }

    public Main(int port) {
        super(port);
        System.out.println("Server ok!");
        this.start();
    }

    @Override
    protected Consumer<Socket> createSocketConsumer(Resource<Socket> r) {
        return new SocketConsumer<>(r);
    }

}
