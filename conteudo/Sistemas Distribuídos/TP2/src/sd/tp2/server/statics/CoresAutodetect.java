package sd.tp2.server.statics;

public class CoresAutodetect {

    public static int detect() {
        Runtime run = Runtime.getRuntime();
        return run.availableProcessors();
    }
}
