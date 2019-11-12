package sd.tp22.broadcast.quote.server;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Date;

public class QuoteServerThread extends Thread {

    protected DatagramSocket socket;
    protected BufferedReader in;
    protected boolean moreQuotes = true;

    public QuoteServerThread() throws IOException {
        this("QuoteServer");
    }

    public QuoteServerThread(String name) throws IOException {
        super(name);
        socket = new DatagramSocket(4445);
        in = new BufferedReader(new InputStreamReader(this.getClass().getResourceAsStream("/quote.txt")));
    }

    public void run() {
        DatagramPacket packet;
        while (moreQuotes) {
            try {
                byte[] buf = new byte[256];

                //recebendo pacote
                packet = new DatagramPacket(buf, buf.length);
                socket.receive(packet);

                //descobrindo resposta
                String dString = (in == null) ? new Date().toString() : getNextQuote();

                buf = dString.getBytes();

                //send response to client with "address" and "port"
                InetAddress address = packet.getAddress();
                int port = packet.getPort();
                packet = new DatagramPacket(buf, buf.length, address, port);
                socket.send(packet);
            } catch (IOException e) {
                e.printStackTrace();
                moreQuotes = false;
            }
        }

        socket.close();
    }

    protected String getNextQuote() {
        String returnValue ;
        try {
            if ((returnValue = in.readLine()) == null) {
                in.close();
                moreQuotes = false;
                returnValue  = "No more quotes. Goodbye";
            }
        } catch (IOException e) {
            returnValue = "IOException ocurred in server";
        }

        return returnValue;
    }

}
