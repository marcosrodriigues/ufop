import java.io.Serializable;
import java.util.List;

public class Message implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int type;
	private String from;
	private String to;
	private List<Point> pontos;
	private List<Alteracao> listaAlteracoes;
	private Alteracao alteracao;
	
	
	
	
	
	public List<Alteracao> getListaAlteracoes() {
		return listaAlteracoes;
	}

	public void setListaAlteracoes(List<Alteracao> filaAlteracoes) {
		this.listaAlteracoes = filaAlteracoes;
	}

	public Alteracao getAlteracao() {
		return alteracao;
	}

	public void setAlteracao(Alteracao alteracao) {
		this.alteracao = alteracao;
	}

	public List<Point> getPontos() {
		return pontos;
	}

	public void setPontos(List<Point> pontos) {
		this.pontos = pontos;
	}

	
	public Message() {
	}

	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public String getFrom() {
		return from;
	}

	public void setFrom(String from) {
		this.from = from;
	}
	public String getTo() {
		return to;
	}

	public void setTo(String to) {
		this.to = to;
	}
	
}
