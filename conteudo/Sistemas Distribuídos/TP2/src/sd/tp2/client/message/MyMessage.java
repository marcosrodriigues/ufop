package sd.tp2.client.message;

import sd.tp2.server.interf.impl.MessageImpl;

public class MyMessage extends MessageImpl {

    private String myData;

    public String getMyData() {
        return myData;
    }

    public void setMyData(String myData) {
        this.myData = myData;
    }

    @Override
    public String toString() {
        return "[" + this.getType() + " - " + this.getMyData() + "]";
    }
}
