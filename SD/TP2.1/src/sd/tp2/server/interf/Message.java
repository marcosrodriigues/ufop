package sd.tp2.server.interf;

import java.io.Serializable;

public interface Message extends Serializable {

    Integer getType();
    void setType(Integer type);
}
