package sd.tp22.properties;

import java.io.IOException;
import java.io.InputStream;
import java.util.Collection;
import java.util.HashMap;
import java.util.Properties;

public class IpProperties {

    private final String FILENAME = "ip.properties";
    private static HashMap<Integer, String> hashIp;

    private IpProperties() {

    }

    public static IpProperties getInstance() throws IOException {
        IpProperties prop = new IpProperties();
        hashIp = prop.loadPropValues();
        return prop;
    }


    private HashMap<Integer, String> loadPropValues() throws IOException {
        InputStream input = null;
        HashMap<Integer, String> hash = new HashMap<>();

        Properties prop = new Properties();
        try {
            input = getClass().getClassLoader().getResourceAsStream(FILENAME);
            prop.load(input);

            for (int i = 0; i < prop.values().size(); i++)
                hash.put(i, prop.getProperty(String.valueOf(i)));
        } catch (Exception e) {
            System.err.println(e);
        } finally {
            input.close();
        }

        return hash;
    }

    public Collection<String> getListIp() {
        return hashIp.values();
    }
}
