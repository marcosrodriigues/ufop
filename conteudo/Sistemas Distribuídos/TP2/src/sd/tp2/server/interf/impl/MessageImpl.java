package sd.tp2.server.interf.impl;

import sd.tp2.server.interf.Message;

public class MessageImpl implements Message {

    private Integer type;
    private int[] clock;

    @Override
    public Integer getType() {
        return type;
    }

    @Override
    public void setType(Integer type) {
        this.type = type;
    }

    @Override
    public int[] getClock() {
        return clock;
    }

    @Override
    public void setClock(int[] clock) { this.clock = clock; }

    @Override
    public String getClockToString() {
        String clockString = "[";

        for (int i = 0; i < clock.length; i++) {
            clockString = clockString.concat(String.valueOf(clock[i]));
            clockString = clockString.concat(clock.length-1 != i ? "," : "");
        }
        clockString = clockString.concat("]");
        return clockString;

    }
}
