package sd.tp22.peer;

import sd.tp2.server.Server;
import sd.tp2.server.SocketConsumer;
import sd.tp2.server.resources.Consumer;
import sd.tp2.server.resources.Resource;

import java.net.Socket;

public class PeerServer extends Server  {

    public PeerServer(int port) {
        super(port);
        System.out.println("Server OK!");
    }

    @Override
    protected Consumer<Socket> createSocketConsumer(Resource<Socket> r) {
        return new SocketConsumer<>(r);
    }
}
