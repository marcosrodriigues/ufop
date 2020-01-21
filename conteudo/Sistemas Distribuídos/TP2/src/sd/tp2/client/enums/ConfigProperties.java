package sd.tp2.client.enums;

public enum ConfigProperties {
    FIBONACCI ("sd.tp2.client.app.Fibonacci"),
    FATORIAL ("sd.tp2.client.app.Fatorial"),
    COUNT_LETTER ("sd.tp2.client.app.CountLetter");

    private String desc;

    ConfigProperties(String desc) {
        this.desc = desc;
    }

    public String getDesc() {
        return desc;
    }
}
