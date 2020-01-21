import java.io.Serializable;

public class Alteracao implements  Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String id;
	private int type;
	private String from;
	private int quantidade;
	private int indice;
	
	private int x;
	private int y;
	private int cor;
	private int dimensionDOT;

	
	public int getDimensionDOT() {
		return dimensionDOT;
	}
	public void setDimensionDOT(int dimensionDOT) {
		this.dimensionDOT = dimensionDOT;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
	public int getCor() {
		return cor;
	}
	public void setCor(int cor) {
		this.cor = cor;
	}
	public int getIndice() {
		return indice;
	}
	public void setIndice(int indiceRemove) {
		this.indice = indiceRemove;
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
	public int getQuantidade() {
		return quantidade;
	}
	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}
	
	
}
