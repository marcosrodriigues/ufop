package sd.tp22.broadcast.multi.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Date;

public class MulticastServerThread extends Thread {

    protected DatagramSocket socket;
    protected BufferedReader in;
    protected boolean moreQuotes = true;

    private long FIVE_SECONDS = 5000;

    public MulticastServerThread() throws IOException {
        this("MulticastServerThread");
    }

    public MulticastServerThread(String name) throws IOException {
        super(name);
        socket = new DatagramSocket();
        in = new BufferedReader(new InputStreamReader(this.getClass().getResourceAsStream("/quote.txt")));
    }

    public void run() {
        while(moreQuotes) {
            try {
                byte[] buf = new byte[256];

                //construct quote
                String dString;
                if (in == null) dString = new Date().toString();
                else dString = getNextQuote();

                buf = dString.getBytes();

                //send it
                InetAddress group = InetAddress.getByName("230.0.0.1");
                DatagramPacket packet = new DatagramPacket(buf, buf.length, group, 4446);
                socket.send(packet);

                //sleep for a while
                try {
                    sleep((long) Math.random() * FIVE_SECONDS);
                } catch (InterruptedException e) { }
            } catch (IOException e ){
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
