
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JFrame;

public class Frame extends JFrame {
	private static final long serialVersionUID = 1L;
	private List<Point> points;

	public Frame() {
		points = new LinkedList<>();
		this.setPreferredSize(new Dimension(Globals.dimensionX, Globals.dimensionY));
		this.pack();
		this.setBackground(Color.WHITE);
		this.setVisible(true);
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public void setPoints(List<Point> points) {
		this.points = points;
	}
	public List<Point> getPoints() {
		return this.points;
	}
	@Override
	public void paint(Graphics g) {
		super.paint(g);
		if (points != null)
			for (int i = 0; i < points.size(); i++) {
				// define the position
				int locX = points.get(i).getX();
				int locY = points.get(i).getY();
				int dimensionDots = points.get(i).getDimensionDot();
				switch (points.get(i).getCor()) {
				case 0:
					g.setColor(Color.BLACK);
					break;
				case 1:
					g.setColor(Color.PINK);
					break;
				case 2:
					g.setColor(Color.RED);
					break;
				case 3:
					g.setColor(Color.BLUE);
					break;
				case 4:
					g.setColor(Color.GREEN);
					break;
				}

//				System.out.println("aqui"+locX+":"+locY);
//				g.drawLine(locX, locY, locX+1, locY+1);
				g.fillOval(locX, locY, dimensionDots, dimensionDots);
			}
	}
}
