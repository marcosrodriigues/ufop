package sd.broadcast.multi.client;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class MulticastClient {

    public static void main(String[] args) throws IOException {
        MulticastSocket socket = new MulticastSocket(4446);
        InetAddress address = InetAddress.getByName("230.0.0.1");
        socket.joinGroup(address);

        DatagramPacket packet;

        //get a few quotes
        byte[] buf = new byte[256];
        int count = 1;
        while ((packet = new DatagramPacket(buf, buf.length)) != null) {
            System.out.println("Escutando pela " + count + " vez");
            socket.receive(packet);
            String receveid = new String(packet.getData(), 0, packet.getLength());
            System.out.println("Quote of the moment: " + receveid);

            buf = new byte[256];
            count++;
        }

        socket.leaveGroup(address);
        socket.close();

    }
}
