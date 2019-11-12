package sd.tp2.client.app;

import sd.tp2.client.message.MyIntMessage;
import sd.tp2.server.interf.Message;
import sd.tp2.server.interf.ServerCommand;

public class Fibonacci implements ServerCommand {

    @Override
    public Object execute(Message m) {
        int n = ((MyIntMessage)m).getNum();
        int proximo = 0, atual = 0, anterior = 1;
        int i = 0;

        String msg = "";

        while (i <= n) {
            proximo = atual + anterior;
            msg = msg.concat(String.valueOf(proximo));
            anterior = atual;
            atual = proximo;
            i++;
            if (i < n) msg = msg.concat(",");
        }

        return msg;
    }
}
