package sd.tp2.client.app;

import sd.tp2.client.message.MyMessage;
import sd.tp2.server.interf.Message;
import sd.tp2.server.interf.ServerCommand;

public class CountLetter implements ServerCommand {

    @Override
    public Object execute(Message m) {
        long count = 0;
        String msg = ((MyMessage)m).getMyData();

        for (long i = 0; i < msg.length(); i++)
            count++;

        return String.valueOf(count);
    }
}
