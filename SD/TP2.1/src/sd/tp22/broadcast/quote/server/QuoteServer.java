package sd.tp22.broadcast.quote.server;

import java.io.IOException;

public class QuoteServer {

    public static void main(String[] args) throws IOException {
        new QuoteServerThread().start();
    }
}