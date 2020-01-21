import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class Cliente {

	private static ServerSocket servidor;
	public static List<Point> listaPontos;
	public static Frame frame;
	public static int id = 0;
	public static String ipAtual = "";

	public static void main(String[] args) throws Exception {

		frame = new Frame();

		listaPontos = new LinkedList<Point>();
		new Cliente().executa();
	}

	public void executa() throws IOException {
		Cliente.servidor = new ServerSocket(Globals.PORT);
		servidor.getInetAddress();
		ipAtual = InetAddress.getLocalHost().toString().replaceAll(".*/", "");
		System.out.println("cliente aberto");
		new Thread() {
			@Override
			public void run() {
				listenServidor();
			}
		}.start();
		new Thread() {
			@Override
			public void run() {
				requesitarAlteracoes();
			}
		}.start();

		new Thread() {
			@Override
			public void run() {
				repintar();
			}
		}.start();
	}

	public static void requesitarAlteracoes() {
		while (true) {
			Random r = new Random();
			int alteracoes = r.nextInt(Globals.RangeAlteracoes);
			Alteracao a = new Alteracao();
			a.setQuantidade(alteracoes);
			a.setFrom(ipAtual);
			a.setId(ipAtual + "_" + id);
			boolean passou = false;
			try {
				Thread.sleep(5* Globals.delay);
			} catch (Exception e) {
			}
			try {
				Globals.sendMessage(ipAtual, Globals.mainServer, Globals.CHANGE, Globals.PORT, a);
				passou = true;
			} catch (Exception e) {
				continue;
			}
			try {
				Globals.sendMessage(ipAtual, Globals.bkpServer, Globals.CHANGE, Globals.PORT, a);
				passou = true;
			} catch (Exception e) {
				continue;
			}
			if(passou)
				id++;
		}
	}

	public static void listenServidor() {
		while (true) {
			Socket cliente;
			try {
				cliente = servidor.accept();

				ObjectInputStream in = new ObjectInputStream(cliente.getInputStream());
				try {
					Message message = (Message) in.readObject();
					System.out.println("Tipo: " + message.getType() + " tipo do Return" + Globals.RETURN);
					if (message.getType() == Globals.RETURN) {
						System.out.println("CARREGANDO DADOS");
						System.out.println("" + message.getPontos().size());
						listaPontos = new LinkedList<>();
						for(Point p : message.getPontos()){
							listaPontos.add(p);
							System.out.println("x: "+p.getX()+" y: "+p.getY());
						}
						frame.setPoints(listaPontos);
						frame.repaint();
						Thread.sleep(Globals.delay);
					} else if (message.getType() == Globals.SENDCHANGE) {
						for (Alteracao alteracao : message.getListaAlteracoes()) {
							int x, y, cor, indice, dimensionDots;
							switch (alteracao.getType()) {
							case Globals.NEW:
								x = alteracao.getX();
								y = alteracao.getY();
								cor = alteracao.getCor();
								dimensionDots = alteracao.getDimensionDOT();
								Point p = new Point(x, y, cor, dimensionDots);
								listaPontos.add(p);
								break;
							case Globals.REMOVE:
								indice = alteracao.getIndice();
								if (indice >= 0 && listaPontos.size() > 0) {
									listaPontos.remove(indice);
								}
								break;
							case Globals.ALTER:
								indice = alteracao.getIndice();
								if (indice >= 0 && listaPontos.size() > 0) {
									x = alteracao.getX();
									y = alteracao.getY();
									cor = alteracao.getCor();
									dimensionDots = alteracao.getDimensionDOT();
									listaPontos.get(indice).setX(x);
									listaPontos.get(indice).setY(y);
									listaPontos.get(indice).setCor(cor);
									listaPontos.get(indice).setDimensionDot(dimensionDots);
								}

								break;
							default:
								System.out.println("nao era para cair aqui");
								System.exit(-1);
								break;
							}

						}
					}

				} catch (Exception e) {
					// e.printStackTrace();

				}
				cliente.close();
			} catch (IOException e) {
				// e.printStackTrace();
			}
		}
	}

	public static boolean pintar(List<Point> a, List<Point> b) {
		if (a.size() != b.size())
			return false;
		else
			return true;
	}

	public static void repintar() {
		while (true) {
			if (!pintar(frame.getPoints(), listaPontos))
				continue;
			frame.setPoints(listaPontos);
			frame.repaint();
			try {
				Thread.sleep(2* Globals.delay);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
