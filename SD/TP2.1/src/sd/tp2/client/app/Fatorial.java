package sd.tp2.client.app;

import sd.tp2.client.message.MyIntMessage;
import sd.tp2.server.interf.Message;
import sd.tp2.server.interf.ServerCommand;

public class Fatorial implements ServerCommand {

    @Override
    public Object execute(Message m) {
        long fat = 1;
        int n = ((MyIntMessage)m).getNum();
        int i = 1;
        while (i <= n) {
            fat = fat * i;
            i++;
        }
        return String.valueOf(fat);
    }
}
