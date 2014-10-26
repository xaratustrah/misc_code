import javax.swing.*;

import java.awt.*;

public class old_FOApplet extends JApplet {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private JPanel jContentPane = null;

	private JPanel middlePanel = null;

	private JLabel s22Label = null;

	private JTextField s11MagTextField = null;

	private JLabel s21Label = null;

	private JTextField s12MagTextField = null;

	private JLabel s12Label = null;

	private JTextField s21MagTextField = null;

	private JLabel s11Label = null;

	private JTextField s22MagTextField = null;

	private JTextField s11PhaseTextField = null;

	private JTextField s12PhaseTextField = null;

	private JTextField s21PhaseTextField = null;

	private int horizGridGap;

	private int vertGridGap;

	private JTextField s22PhaseTextField = null;

	private JButton calculateButton = null; // @jve:decl-index=0:visual-constraint="741,-6"

	int xmax, ymax;

	Canvas c;

	public void init() {

		setLayout(new GridLayout(3, 1, 15, 15));
		ymax = getHeight();
		xmax = getWidth();
		c = new Canvas();
		c.setBounds(20, 20, xmax - 30, ymax - 30);
		c.setBackground(Color.yellow);
		add(c);
		add(getMiddlePanel());
		add(getCalculateButton());
		this.drawOnCanvas(c);

	}

	public void drawOnCanvas(Canvas c) {
		Graphics g = c.getGraphics();
		g.setColor(Color.black);
		g.drawString("Hello", 40, 40);
	}

	// public void paint(Graphics g) {
	// g.drawRect(10, 10, xmax - 20, ymax - 20);
	// }
	
	private JPanel getMiddlePanel() {
		if (middlePanel == null) {
			s11Label = new JLabel();
			s11Label.setText("S11");
			s12Label = new JLabel();
			s12Label.setText("S12");
			s21Label = new JLabel();
			s21Label.setText("S21");
			s22Label = new JLabel();
			s22Label.setText("S22");
			middlePanel = new JPanel();
			middlePanel.setLayout(new GridLayout(4, 2, 15, 15));

			middlePanel.add(s11Label, null);
			middlePanel.add(getS11MagTextField(), null);
			middlePanel.add(getS11PhaseTextField(), null);

			middlePanel.add(s12Label, null);
			middlePanel.add(getS12MagTextField(), null);
			middlePanel.add(getS12PhaseTextField(), null);

			middlePanel.add(s21Label, null);
			middlePanel.add(getS21MagTextField(), null);
			middlePanel.add(getS21PhaseTextField(), null);

			middlePanel.add(s22Label, null);
			middlePanel.add(getS22MagTextField(), null);
			middlePanel.add(getS22PhaseTextField(), null);

		}
		return middlePanel;
	}

	/**
	 * This method initializes jTextField
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS11MagTextField() {
		if (s11MagTextField == null) {
			s11MagTextField = new JTextField();
		}
		return s11MagTextField;
	}

	/**
	 * This method initializes jTextField1
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS12MagTextField() {
		if (s12MagTextField == null) {
			s12MagTextField = new JTextField();
		}
		return s12MagTextField;
	}

	/**
	 * This method initializes jTextField2
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS21MagTextField() {
		if (s21MagTextField == null) {
			s21MagTextField = new JTextField();
		}
		return s21MagTextField;
	}

	/**
	 * This method initializes jTextField3
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS22MagTextField() {
		if (s22MagTextField == null) {
			s22MagTextField = new JTextField();
		}
		return s22MagTextField;
	}

	/**
	 * This method initializes jTextField4
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS11PhaseTextField() {
		if (s11PhaseTextField == null) {
			s11PhaseTextField = new JTextField();
		}
		return s11PhaseTextField;
	}

	/**
	 * This method initializes jTextField5
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS12PhaseTextField() {
		if (s12PhaseTextField == null) {
			s12PhaseTextField = new JTextField();
		}
		return s12PhaseTextField;
	}

	/**
	 * This method initializes jTextField6
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS21PhaseTextField() {
		if (s21PhaseTextField == null) {
			s21PhaseTextField = new JTextField();
		}
		return s21PhaseTextField;
	}

	/**
	 * This method initializes jTextField
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS22PhaseTextField() {
		if (s22PhaseTextField == null) {
			s22PhaseTextField = new JTextField();
		}
		return s22PhaseTextField;
	}

	/**
	 * This method initializes jButton
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getCalculateButton() {
		if (calculateButton == null) {
			calculateButton = new JButton();
			calculateButton.setSize(new Dimension(131, 132));
		}
		return calculateButton;
	}

} // @jve:de	// public void paint(Graphics g) {
// Complex S11 = new Complex(0.4, 170.0, false); // degrees
// Complex S12 = new Complex(0.07, 70.0, false); // degrees
// Complex S21 = new Complex(4.0, 50.0, false); // degrees
// Complex S22 = new Complex(0.5, -40.0, false); // degrees
// RFTransistor rft = new RFTransistor(S11, S12, S21, S22);
//
// g.drawRect(leftBound, leftBound, xmax - 2 * topBound, ymax - 2
// * topBound);
//
// System.out.println("Fifty Ohm RF Transistor Calculator");
// g.drawString("Fifty Ohm RF Transistor Calculator", 2 * leftBound,
// 3 * topBound);
//
// System.out.println(FOModel.makeString("S11", S11));
// g.drawString(FOModel.makeString("S11", S11), 2 * leftBound,
// 5 * topBound);
// System.out.println(FOModel.makeString("S12", S12));
// g.drawString(FOModel.makeString("S12", S12), 2 * leftBound,
// 7 * topBound);
//
// System.out.println(FOModel.makeString("S21", S21));
// g.drawString(FOModel.makeString("S21", S21), 2 * leftBound,
// 9 * topBound);
// System.out.println(FOModel.makeString("S22", S22));
// g.drawString(FOModel.makeString("S22", S22), 2 * leftBound,
// 11 * topBound);
//
// System.out.println("B1= " + new Double(rft.getB1()).toString());
// g.drawString("B1= " + new Double(rft.getB1()).toString(),
// 2 * leftBound, 13 * topBound);
// System.out.println("B2= " + new Double(rft.getB2()).toString());
// g.drawString("B2= " + new Double(rft.getB2()).toString(),
// 2 * leftBound, 15 * topBound);
//
// System.out.println(FOModel.makeString("C1", rft.getC1()));
// g.drawString(FOModel.makeString("C1", rft.getC1()), 2 * leftBound,
// 17 * topBound);
// System.out.println(FOModel.makeString("C2", rft.getC2()));
// g.drawString(FOModel.makeString("C2", rft.getC2()), 2 * leftBound,
// 19 * topBound);
//
// System.out.println("K= " + new Double(rft.getK()).toString());
// g.drawString("K= " + new Double(rft.getK()).toString(), 2 *
// leftBound,
// 21 * topBound);
//
// System.out.println(FOModel.makeString("Delta", rft.getDelta()));
// g.drawString(FOModel.makeString("Delta", rft.getDelta()),
// 2 * leftBound, 23 * topBound);
//
// System.out.println(FOModel.makeString("GammaMS", rft.getGammaMS()));
// g.drawString(FOModel.makeString("GammaMS", rft.getGammaMS()),
// 2 * leftBound, 25 * topBound);
// System.out.println(FOModel.makeString("GammaML", rft.getGammaML()));
//
// System.out.println("GTMax= " + new Double(rft.getGTMax()).toString()
// + " or " + new Double(rft.getGTMaxDB()).toString() + "dB");
// g.drawString("GTMax= " + new Double(rft.getGTMax()).toString() + " or
// "
// + new Double(rft.getGTMaxDB()).toString() + "dB",
// 2 * leftBound, 27 * topBound);
//
// System.out.println("MSG= " + new Double(rft.getMSG()).toString()
// + " at K = 1");
// g.drawString("MSG= " + new Double(rft.getMSG()).toString()
// + " at K = 1", 2 * leftBound, 29 * topBound);
//
// System.out.println(FOModel.makeString("Cs", rft.getCS()));
// g.drawString(FOModel.makeString("Cs", rft.getCS()), 2 * leftBound,
// 31 * topBound);
//
// System.out.println("Rs= " + new Double(rft.getRS()).toString());
// g.drawString("Rs= " + new Double(rft.getRS()).toString(),
// 2 * leftBound, 33 * topBound);
//
// if (rft.isUnconditionallyStable()) {
// System.out.println("The transistor is unconditionally stable.");
// g.drawString("The transistor is unconditionally stable.",
// 2 * leftBound, 35 * topBound);
// }
// drawSmithChart(g, rft);
// }


