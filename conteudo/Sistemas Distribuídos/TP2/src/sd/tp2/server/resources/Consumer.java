package sd.tp2.server.resources;

import sd.tp2.server.interf.ServerCommand;

import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;
import java.util.Set;

public abstract class Consumer<S> extends Thread {

    private final String FILENAME = "resource/config.properties";
    protected Resource<S> resource;
    protected Map<Integer, ServerCommand> commands;

    public Consumer(Resource<S> res) {
        this.resource = res;
        commands = new HashMap<>();
        loadCommandProperties();
    }

    protected void loadCommandProperties() {
        Properties properties = new Properties();

        try {
            InputStream input = new FileInputStream(FILENAME);
            properties.load(input);
            Set<String> ids = properties.stringPropertyNames();
            for (String id : ids) {
                Class c = Class.forName(properties.getProperty(id));
                commands.put(Integer.parseInt(id), (ServerCommand) c.newInstance());
            }
        } catch (Exception e) {
            e.printStackTrace();;
        }
    }

    public void run() {
        try {
            S str = null;
            while (!resource.isFinished() || resource.getNumOfRegister() != 0) {
                if ((str = resource.getRegister()) != null) {
                    //Função doSomething faz algo com o recurso.
                    doSomething(str);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void setFinish() {
        resource.setFinished();
    }

    public void stopServer() {
        resource.stopServer();
    }

    protected abstract void doSomething(S str);
}
