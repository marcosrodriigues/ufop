import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class Servidor {
	private static List<String> clientes;
	private static ServerSocket servidor;
	private static boolean serverPrincipal;
	public static List<Alteracao> filaAlteracoes;// ip da maquina que pediu para
													// mudar e quantos pontos
													// teve que mudar
	public static List<Point> listaPontos;
	public static String ipAtual;
	public static boolean desatualizado = false;

	public static void main(String[] args) throws Exception {
		filaAlteracoes = new LinkedList<Alteracao>();
		listaPontos = new LinkedList<>();
		clientes = new LinkedList<>();

		//Globals.outroServidor = "200.239.139.61";
		Globals.outroServidor = "10.128.0.3";
		serverPrincipal = true;
		new Servidor().executa();
	}

	public Servidor() {
		Servidor.clientes = new ArrayList<String>();
	}

	public void executa() throws IOException {
		Servidor.servidor = new ServerSocket(Globals.PORT);
		servidor.getInetAddress();
		ipAtual = InetAddress.getLocalHost().toString().replaceAll(".*/", "");
		System.out.println("servidor aberto");
		new Thread() {
			@Override
			public void run() {
				listenCliente();
			}
		}.start();

		new Thread() {
			@Override
			public void run() {
				changePoints();
			}
		}.start();
		new Thread() {
			@Override
			public void run() {
				checkClientes();
			}
		}.start();
	}

	public static void checkClientes() {
		while (true) {
			try {
				Thread.sleep(Globals.delay/50);
				for (int i = 0; i < clientes.size(); i++) {
					try {
						InetAddress ping = InetAddress.getByName(clientes.get(i));

						if (!ping.isReachable(Globals.delay/50) && Globals.ping()) {
							if (!ping.isReachable(Globals.delay/50)) {
								System.out.println("Cliente: " + clientes.get(i) + " caiu !!");
								clientes.remove(i);
								break;
							}
						}
					} catch (Exception e) {

					}
				}
			} catch (Exception e) {

			}

		}
	}

	public static void changePoints() {
		while (true) {
			try {
				if (serverPrincipal) {
					try {
						Thread.sleep(10 * Globals.delay);
//						System.out.println(Globals.ping());
						if (!Globals.ping()) {
							serverPrincipal = false;
							System.out.println("cai");
							continue;
						}
					} catch (Exception e) {
					}
					
					
					if (filaAlteracoes.size() > 0) {
						System.out.println("Atendendo ip: " + filaAlteracoes.get(0).getFrom());
						Random r = new Random();
						Alteracao alteracao = filaAlteracoes.remove(0);

						System.out.println("realizando altera�ao vinda do ip: " + alteracao.getFrom());
						List<Alteracao> mudancas = new LinkedList<>();
						for (int i = 0; i < alteracao.getQuantidade(); i++) {
							int random = Math.abs(r.nextInt(4));
							if (random == 3)
								random = 0;
							Alteracao a;
							int indice, x, y, cor, dimensionDots;

							switch (random) {
							case Globals.NEW:

								x = r.nextInt(Globals.dimensionX);
								y = r.nextInt(Globals.dimensionY);
								cor = r.nextInt(Globals.COR);
								dimensionDots = r.nextInt(Globals.MaxDimensionsDot);

								Point p = new Point(x, y, cor, dimensionDots);
								listaPontos.add(p);

								a = new Alteracao();
								a.setFrom(ipAtual);
								a.setType(Globals.NEW);
								a.setX(x);
								a.setY(y);
								a.setCor(cor);
								a.setDimensionDOT(dimensionDots);
								a.setId(alteracao.getId());
								mudancas.add(a);
								// envio as mudan�as
								break;
							case Globals.REMOVE:
								if (listaPontos.size() == 0)
									continue;
								indice = r.nextInt(listaPontos.size());
								if (indice >= 0 && listaPontos.size() > 0) {
									listaPontos.remove(indice);
									a = new Alteracao();
									a.setFrom(ipAtual);
									a.setType(Globals.REMOVE);
									a.setIndice(indice);
									a.setId(alteracao.getId());

									mudancas.add(a);
								}
								break;
							case Globals.ALTER:
								if (listaPontos.size() == 0)
									continue;
								indice = r.nextInt(listaPontos.size());
								if (indice >= 0 && listaPontos.size() > 0) {
									x = r.nextInt(Globals.dimensionX);
									y = r.nextInt(Globals.dimensionY);
									cor = r.nextInt(Globals.COR);
									dimensionDots = r.nextInt(Globals.MaxDimensionsDot);

									listaPontos.get(indice).setX(x);
									listaPontos.get(indice).setY(y);
									listaPontos.get(indice).setCor(cor);
									listaPontos.get(indice).setDimensionDot(dimensionDots);

									a = new Alteracao();
									a.setFrom(ipAtual);
									a.setType(Globals.ALTER);
									a.setCor(cor);
									a.setX(x);
									a.setY(y);
									a.setDimensionDOT(dimensionDots);
									a.setIndice(indice);
									a.setId(alteracao.getId());

									mudancas.add(a);
								}

								break;
							default:
								//System.out.println("nao era para cair aqui");
								System.exit(-1);
								break;
							}

						}
						try {
							Globals.sendMessage(ipAtual, Globals.outroServidor, Globals.COPY, Globals.PORT, listaPontos,
									filaAlteracoes);
						} catch (Exception e) {

						}
						for (String cliente : clientes) {
							try {
								Globals.sendMessage(ipAtual, cliente, Globals.SENDCHANGE, Globals.PORT, mudancas);
							} catch (Exception e) {

							}
						}
						System.out.println("\t" + alteracao.getQuantidade() + " altera�oes enviadas para os "
								+ clientes.size() + " clientes!");
					}
				} else {
					try {
						InetAddress ping = InetAddress.getByName(Globals.outroServidor);

						if (!ping.isReachable(Globals.delay/50) && Globals.ping()) {
							if (!ping.isReachable(Globals.delay/50)) {
								System.out.println(
										"Servidor: " + Globals.outroServidor + " caiu, assumindo servidor principal");
								desatualizado = true;
								serverPrincipal = true;
							}
						}
					} catch (Exception e) {

					}
				}
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

	public static void listenCliente() {
		while (true) {
			Socket cliente;
			try {

				cliente = servidor.accept();
				if (!clientes.contains(cliente.getInetAddress().getHostAddress())) {
					if (!cliente.getInetAddress().getHostAddress().equals(Globals.bkpServer)
							&& !cliente.getInetAddress().getHostAddress().equals(Globals.mainServer)) {
						System.out.println("Nova conex�o com o cliente " + cliente.getInetAddress().getHostAddress());
						clientes.add(cliente.getInetAddress().getHostAddress());
						try {
							Globals.sendMessageReturn(ipAtual, cliente.getInetAddress().getHostAddress(),
									Globals.RETURN, Globals.PORT, listaPontos);
							System.out.println("!!!! Enviando a lista de pontos para o novo cliente !!!!");
						} catch (Exception e) {
							// TODO Auto-generated catch block
							// e.printStackTrace();
						}
					}
				}

				ObjectInputStream in = new ObjectInputStream(cliente.getInputStream());
				try {
					Message message = (Message) in.readObject();

					if (message.getType() == Globals.CHANGE) {
						filaAlteracoes.add(message.getAlteracao());
					} else if (message.getType() == Globals.COPY) {
						System.out.println("COPIANDO BACKUP DO SERVIDOR PRINCIPAL");
						filaAlteracoes = message.getListaAlteracoes();
						listaPontos = message.getPontos();// TODO TALVEZ
					} else if (message.getType() == Globals.SENDCHANGE) {
						System.out.println("RECEBENDO ATUALIZA�OES");
						for (Alteracao alteracao : message.getListaAlteracoes()) {
							int indice = -1;
							for (int i = 0; i < listaPontos.size(); i++) {
								if (filaAlteracoes.get(i).getId().equals(alteracao.getId())) {
									indice = i;
									break;
								}
							}
							if (indice >= 0)
								filaAlteracoes.remove(indice);
							int x, y, cor, dimensionDots;
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
}
