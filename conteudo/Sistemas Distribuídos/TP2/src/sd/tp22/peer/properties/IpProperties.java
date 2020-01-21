package sd.tp22.peer.properties;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Collection;
import java.util.HashMap;
import java.util.Properties;

public class IpProperties {

    private final String FILENAME = "resource/ip.properties";
    private static HashMap<String, String> hashIp;

    private IpProperties() {

    }

    public static IpProperties getInstance(){
        IpProperties prop = new IpProperties();
        hashIp = prop.loadPropValues();
        return prop;
    }


    private HashMap<String, String> loadPropValues() {
        HashMap<String, String> hash = new HashMap<>();

        Properties prop = new Properties();
        try {
            InputStream  input = new FileInputStream(FILENAME);//getClass().getClassLoader().getResourceAsStream(FILENAME);
            prop.load(input);

            prop.stringPropertyNames().forEach(s -> {
                hash.put(String.valueOf(s), prop.getProperty(s));
            });

            input.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return hash;
    }

    public Collection<String> getListIp() {
        return hashIp.values();
    }

    public HashMap<String, String> getHash() { return hashIp; }

    public int getSize() { return hashIp.size(); }
}
