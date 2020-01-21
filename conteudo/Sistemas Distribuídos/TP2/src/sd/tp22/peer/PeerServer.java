package sd.tp22.peer;

import sd.tp2.server.Server;
import sd.tp2.server.SocketConsumer;
import sd.tp2.server.resources.Consumer;
import sd.tp2.server.resources.Resource;

import java.net.Socket;

public class PeerServer extends Server  {

    private PeerServer(ServerBuilder builder) {
        super(builder.port);
        System.out.println("### CONFIGURACAO ### - Servidor configurado na porta " + this.port);
    }

    @Override
    protected Consumer<Socket> createSocketConsumer(Resource<Socket> r) {
        return new SocketConsumer<>(r);
    }

    public static class ServerBuilder {
        private int port = 7090;

        public ServerBuilder port(int port) {
            this.port = port;
            return this;
        }

        public PeerServer build() {
            PeerServer server = new PeerServer(this);
            return server;
        }
    }

}
