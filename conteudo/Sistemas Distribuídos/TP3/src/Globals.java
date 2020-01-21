import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.List;

public class Globals {
	public static String mainServer = "10.128.0.2";
	public static String bkpServer = "10.128.0.3";
	
	public static final int delay = 500;
	public static final int MaxDimensionsDot = 40;
	
	public static String outroServidor;

	public static final int RangeAlteracoes = 30;
	public static final int PORT = 8080;

	public static final int CHANGE = 10;
	public static final int RETURN = 20;
	public static final int COPY = 30;
	public static final int SENDCHANGE = 40;

	public static final int dimensionX = 1000;
	public static final int dimensionY = 1000;
	public static final int COR = 5;

	public static final int NEW = 0;
	public static final int REMOVE = 1;
	public static final int ALTER = 2;

	public static boolean ping() {

		try {
			InetAddress ping = InetAddress.getByName(bkpServer);
			return ping.isReachable(10);
		} catch (IOException e) {
//			e.printStackTrace();
			return false;
		}
	}

	public static void sendMessage(String from, String to, int type, int port, List<Point> pontos,
			List<Alteracao> filaAlteracoes, Alteracao alteracao){
		try {
			Socket destinatario = new Socket(to, port);

			Message message = new Message();
			message.setType(type);
			message.setFrom(from);
			message.setTo(to);
			message.setPontos(pontos);
			message.setListaAlteracoes(filaAlteracoes);
			message.setAlteracao(alteracao);
			ObjectOutputStream out = new ObjectOutputStream(destinatario.getOutputStream());
			out.writeObject(message);
			out.flush();
			out.close();

			destinatario.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void sendMessageReturn(String from, String to, int type, int port, List<Point> pontos) {
		sendMessage(from, to, type, port, pontos, null, null);
	}

	public static void sendMessage(String from, String to, int type, int port, List<Point> pontos,
			List<Alteracao> filaAlteracoes) {
		sendMessage(from, to, type, port, pontos, filaAlteracoes, null);
	}

	public static void sendMessage(String from, String to, int type, int port, List<Alteracao> alteracoes){
		sendMessage(from, to, type, port, null, alteracoes, null);
	}

	// alteracao
	public static void sendMessage(String from, String to, int type, int port, Alteracao alteracao) {
		sendMessage(from, to, type, port, null, null, alteracao);
	}
}
