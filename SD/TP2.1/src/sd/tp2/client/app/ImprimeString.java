package sd.tp2.client.app;

import sd.tp2.client.message.MyMessage;
import sd.tp2.server.interf.Message;
import sd.tp2.server.interf.ServerCommand;

public class ImprimeString implements ServerCommand {

    @Override
    public Object execute(Message m) {
        String msg = ((MyMessage) m).getMyData();
        String ret = "";
        for (char c : msg.toCharArray())
            ret = ret.concat(String.valueOf(c));
        return ret;
    }
}
