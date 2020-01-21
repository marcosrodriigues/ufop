import java.io.Serializable;

public class Point implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int cor;
	private int x;
	private int y;
	private int DimensionDot;

	public Point(int x,int y,int cor, int DimensionDot){
		this.cor = cor;
		this.x = x;
		this.y = y+20;
		this.DimensionDot = DimensionDot+10;
	}
	
	public int getDimensionDot() {
		return DimensionDot;
	}

	public void setDimensionDot(int dimensionDot) {
		DimensionDot = dimensionDot;
	}

	public int getCor() {
		return cor;
	}
	public void setCor(int cor) {
		this.cor = cor;
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
		this.y = y+20;
	}
	
	public void imprime_ponto(){
		System.out.println("pontoX: "+ getX()+" PontoY: "+ getY()+ " Cor: "+getCor());
	}
	
	
}