package sd.tp2.server;

import sd.tp2.server.interf.Message;
import sd.tp2.server.resources.Consumer;
import sd.tp2.server.resources.Resource;

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

            Object response = commands.get(msg.getType()).execute(msg);

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
}
