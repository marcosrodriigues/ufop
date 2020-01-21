package sd.tp2.server;

import sd.tp2.server.resources.Consumer;
import sd.tp2.server.resources.Resource;
import sd.tp2.server.statics.CoresAutodetect;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public abstract class Server extends Thread {

    protected Consumer<Socket>[] serverThreads;
    protected Resource<Socket> serverR;
    protected int port;
    protected ServerSocket serverSocket;
    protected long initialTime;

    private int numOfThreads;

    public Server(int port) {
        this.initialTime = System.nanoTime();
        this.port = port;
        numOfThreads = CoresAutodetect.detect();
        serverThreads = new Consumer[numOfThreads];
        serverR = new Resource<>();
    }

    public void run() {
        try {
            for (int i = 0; i < numOfThreads; i++) {
                serverThreads[i] = createSocketConsumer(serverR);
                serverThreads[i].start();
            }

            listen();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    protected void listen() {
        openServerSocket();

        while (!serverR.isStopped()) {
            try {
                Socket client = this.serverSocket.accept();
                System.out.println("[SERVER]: Aceitou conexao do IP " + client.getInetAddress().getHostAddress());
                serverR.putRegister(client);
            } catch (IOException e) {
                if (serverR.isStopped()) {
                    System.out.println("[SERVER]: Server stopped!");
                    return;
                }

                throw new RuntimeException("[SERVER]: Error accepting client connection: ", e);
            }
        }
    }

    private void openServerSocket() {
        try {
            this.serverSocket = new ServerSocket(this.port);
        } catch (IOException e) {
            throw new RuntimeException("[SERVER]: Cannot open port " + this.port + " - " + e);
        }
    }

    protected abstract Consumer<Socket> createSocketConsumer(Resource<Socket> r);

    public int getPort() {
        return this.port;
    }
}
