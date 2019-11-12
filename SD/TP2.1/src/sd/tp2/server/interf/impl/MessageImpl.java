package sd.tp2.server.interf.impl;

import sd.tp2.server.interf.Message;

public class MessageImpl implements Message {

    private Integer type;

    @Override
    public Integer getType() {
        return type;
    }

    @Override
    public void setType(Integer type) {
        this.type = type;
    }
}
