package sd.tp2.client.message;

import sd.tp2.server.interf.impl.MessageImpl;

public class MyIntMessage extends MessageImpl {

    private Integer num;

    public Integer getNum() {
        return num;
    }

    public void setNum(Integer num) {
        this.num = num;
    }

    @Override
    public String toString() {
        return "[" + this.getType() + " - " + this.getNum() + "]";
    }
}
