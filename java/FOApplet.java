import java.applet.*;
import java.awt.BorderLayout;
import java.awt.Canvas;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.ScrollPane;
import java.awt.event.*;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.KeyStroke;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

public class FOApplet extends Applet implements KeyListener, ActionListener {

	/**
	 * 
	 */
	private static final long serialVersionUID = -6740521709584212789L;

	static final String newline = System.getProperty("line.separator");

	private JTextArea jTextArea = null;

	private JScrollPane scrollPane = null;

	private JPanel inputFieldPanel = null;

	private JPanel contentPanel = null;

	private JPanel statusPanel = null;

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

	private JTextField s22PhaseTextField = null;

	private JMenuBar menuBar = null;

	private JMenu menu = null;

	private JMenuItem menuItemAbout = null, menuItemExit = null;

	private JLabel statusMessage = null;

	Complex defaultS11;

	Complex defaultS12;

	Complex defaultS21;

	Complex defaultS22;

	RFTransistor rft;

	private JLabel poten1Label;

	private JLabel paran1Label;

	private JLabel poten2Label;

	private JLabel poten3Label;

	private JLabel poten4Label;

	private JLabel paran2Label;

	private JLabel paran3Label;

	private JLabel paran4Label;

	public void init() {
		ymax = getHeight();
		xmax = getWidth();
		setLayout(new BorderLayout());

		menu = new JMenu("File");
		menu.setMnemonic(KeyEvent.VK_F);
		menu.getAccessibleContext().setAccessibleDescription(
				"The only menu in this program that has menu items");

		menuItemAbout = new JMenuItem("About", KeyEvent.VK_A);
		menuItemAbout.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_A,
				ActionEvent.ALT_MASK));
		menuItemAbout.getAccessibleContext().setAccessibleDescription(
				"This doesn't really do anything");
		menu.add(menuItemAbout);

		menu.addSeparator();
//		menuItemExit = new JMenuItem("Exit", KeyEvent.VK_X);
//		menuItemExit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_X,
//				ActionEvent.ALT_MASK));
//		menuItemExit.getAccessibleContext().setAccessibleDescription(
//				"This doesn't really do anything");
//		menuItemExit.setAction(actionMap.get("quit")); // NOI18N
//		menuItemExit.setName("exitMenuItem"); // NOI18N
		menu.add(menuItemExit);

		menuBar = new JMenuBar();
		menuBar.add(menu);
		add(menuBar, BorderLayout.NORTH);

		contentPanel = new JPanel();
		contentPanel.setLayout(new BorderLayout());
		contentPanel.add(this.getInputFieldPanel(), BorderLayout.NORTH);

		contentPanel.add(this.getJTextArea(), BorderLayout.SOUTH);
		scrollPane = new JScrollPane(jTextArea);
		scrollPane.setPreferredSize(new Dimension(375, 125));
		contentPanel.add(scrollPane, null);
		add(contentPanel, BorderLayout.CENTER);

		statusPanel = new JPanel();
		statusPanel.setLayout(new GridLayout(1, 1));
		statusMessage = new JLabel("Modify the S parameters and press Enter.");
		statusPanel.add(statusMessage, null);
		add(statusPanel, BorderLayout.SOUTH);

		s11MagTextField.addKeyListener(this);
		s12MagTextField.addKeyListener(this);
		s21MagTextField.addKeyListener(this);
		s22MagTextField.addKeyListener(this);

		s11PhaseTextField.addKeyListener(this);
		s12PhaseTextField.addKeyListener(this);
		s21PhaseTextField.addKeyListener(this);
		s22PhaseTextField.addKeyListener(this);

		menuItemAbout.addActionListener(this);
		menuItemExit.addActionListener(this);

	}

	private JPanel getInputFieldPanel() {
		if (inputFieldPanel == null) {
			s11Label = new JLabel();
			s11Label.setText("S11 =");
			s11Label.setHorizontalAlignment(SwingConstants.CENTER);

			s12Label = new JLabel();
			s12Label.setText("S12 =");
			s12Label.setHorizontalAlignment(SwingConstants.CENTER);

			s21Label = new JLabel();
			s21Label.setText("S21 =");
			s21Label.setHorizontalAlignment(SwingConstants.CENTER);

			s22Label = new JLabel();
			s22Label.setText("S22 =");
			s22Label.setHorizontalAlignment(SwingConstants.CENTER);

			poten1Label = new JLabel();
			poten1Label.setText(" * exp ( ");
			poten1Label.setHorizontalAlignment(SwingConstants.CENTER);

			poten2Label = new JLabel();
			poten2Label.setText(" * exp ( ");
			poten2Label.setHorizontalAlignment(SwingConstants.CENTER);

			poten3Label = new JLabel();
			poten3Label.setText(" * exp ( ");
			poten3Label.setHorizontalAlignment(SwingConstants.CENTER);

			poten4Label = new JLabel();
			poten4Label.setText(" * exp ( ");
			poten4Label.setHorizontalAlignment(SwingConstants.CENTER);

			paran1Label = new JLabel();
			paran1Label.setText(" ) in Degrees");
			paran1Label.setHorizontalAlignment(SwingConstants.CENTER);

			paran2Label = new JLabel();
			paran2Label.setText(" ) in Degrees");
			paran2Label.setHorizontalAlignment(SwingConstants.CENTER);

			paran3Label = new JLabel();
			paran3Label.setText(" ) in Degrees");
			paran3Label.setHorizontalAlignment(SwingConstants.CENTER);

			paran4Label = new JLabel();
			paran4Label.setText(" ) in Degrees");
			paran4Label.setHorizontalAlignment(SwingConstants.CENTER);

			inputFieldPanel = new JPanel();
			inputFieldPanel.setLayout(new GridLayout(4, 5, 5, 5));

			inputFieldPanel.add(s11Label, null);
			inputFieldPanel.add(getS11MagTextField(), null);
			inputFieldPanel.add(poten1Label, null);
			inputFieldPanel.add(getS11PhaseTextField(), null);
			inputFieldPanel.add(paran1Label, null);

			inputFieldPanel.add(s12Label, null);
			inputFieldPanel.add(getS12MagTextField(), null);
			inputFieldPanel.add(poten2Label, null);
			inputFieldPanel.add(getS12PhaseTextField(), null);
			inputFieldPanel.add(paran2Label, null);

			inputFieldPanel.add(s21Label, null);
			inputFieldPanel.add(getS21MagTextField(), null);
			inputFieldPanel.add(poten3Label, null);
			inputFieldPanel.add(getS21PhaseTextField(), null);
			inputFieldPanel.add(paran3Label, null);

			inputFieldPanel.add(s22Label, null);
			inputFieldPanel.add(getS22MagTextField(), null);
			inputFieldPanel.add(poten4Label, null);
			inputFieldPanel.add(getS22PhaseTextField(), null);
			inputFieldPanel.add(paran4Label, null);
		}
		return inputFieldPanel;
	}

	public void updateTextArea() {
		String jTextAreaContent;
		try {
			defaultS11 = new Complex(Double.parseDouble(s11MagTextField
					.getText()), Double
					.parseDouble(s11PhaseTextField.getText()), Boolean.FALSE);
			defaultS12 = new Complex(Double.parseDouble(s12MagTextField
					.getText()), Double
					.parseDouble(s12PhaseTextField.getText()), Boolean.FALSE);
			defaultS21 = new Complex(Double.parseDouble(s21MagTextField
					.getText()), Double
					.parseDouble(s21PhaseTextField.getText()), Boolean.FALSE);
			defaultS22 = new Complex(Double.parseDouble(s22MagTextField
					.getText()), Double
					.parseDouble(s22PhaseTextField.getText()), Boolean.FALSE);

			rft = new RFTransistor(defaultS11, defaultS12, defaultS21,
					defaultS22);

			jTextAreaContent = FOModel.makeString("S11", defaultS11) + newline
					+ FOModel.makeString("S12", defaultS12) + newline
					+ FOModel.makeString("S21", defaultS21) + newline
					+ FOModel.makeString("S22", defaultS22) + newline + "B1= "
					+ new Double(rft.getB1()).toString() + newline + "B2= "
					+ new Double(rft.getB2()).toString() + newline
					+ FOModel.makeString("C1", rft.getC1()) + newline
					+ FOModel.makeString("C2", rft.getC1()) + newline + "K= "
					+ new Double(rft.getK()).toString() + newline
					+ FOModel.makeString("Delta", rft.getDelta()) + newline
					+ FOModel.makeString("GammaMS", rft.getGammaMS()) + newline
					+ FOModel.makeString("GammaML", rft.getGammaML()) + newline
					+ "GTMax= " + new Double(rft.getGTMax()).toString() + "or"
					+ new Double(rft.getGTMaxDB()).toString() + "dB" + newline +

					"MSG= " + new Double(rft.getMSG()).toString() + newline
					+ FOModel.makeString("Cs", rft.getCS()) + newline + "Rs= "
					+ new Double(rft.getRS()).toString() + newline;

			if (rft.isUnconditionallyStable()) {
				jTextAreaContent += "The transistor is unconditionally stable."
						+ newline;
			}
			jTextArea.setText(jTextAreaContent);

		} catch (Exception e) {
			JOptionPane.showMessageDialog(this, "Please use numbers only!",
					"FiftyOhm", JOptionPane.ERROR_MESSAGE);
		}
	}

	// public void drawSmithChart(Graphics g) {
	// g.drawOval(400, 300, 100, 100);
	// }

	public void convertCoordinartes() {
	}

	public static void startAppletInFrame() {
		JFrame f = new JFrame();
		FOApplet af = new FOApplet();
		af.init();
		af.start();
		f.add(af);
		f.setSize(500, 400);
		f.setTitle("FiftyOhm");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
	}

	public static void main(String args[]) {
		/* Use an appropriate Look and Feel */
		try {
			// Set System L&F
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (UnsupportedLookAndFeelException e) {
			// handle exception
		} catch (ClassNotFoundException e) {
			// handle exception
		} catch (InstantiationException e) {
			// handle exception
		} catch (IllegalAccessException e) {
			// handle exception
		}

		// creating and showing this application's GUI.

		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				startAppletInFrame();
			}
		});
	}

	/**
	 * This method initializes jTextArea
	 * 
	 * @return javax.swing.JTextArea
	 */
	private JTextArea getJTextArea() {
		if (jTextArea == null) {
			jTextArea = new JTextArea("Welcome to FiftyOhm" + newline
					+ "RF Transistor Calculator");
			jTextArea.setSize(new Dimension(200, 300));
			jTextArea.setEditable(Boolean.FALSE);
		}
		return jTextArea;
	}

	/**
	 * This method initializes jTextField
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS11MagTextField() {
		if (s11MagTextField == null) {
			s11MagTextField = new JTextField(new Double(0.4).toString());
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
			s12MagTextField = new JTextField(new Double(0.07).toString());
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
			s21MagTextField = new JTextField(new Double(4.0).toString());
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
			s22MagTextField = new JTextField(new Double(0.5).toString());
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
			s11PhaseTextField = new JTextField(new Double(170.0).toString());
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
			s12PhaseTextField = new JTextField(new Double(70.0).toString());
		}
		return s12PhaseTextField;
	}

	/**
	 * This method initializes jTextField6 updateTextArea();
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getS21PhaseTextField() {
		if (s21PhaseTextField == null) {
			s21PhaseTextField = new JTextField(new Double(50.0).toString());
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
			s22PhaseTextField = new JTextField(new Double(-40.0).toString());
		}
		return s22PhaseTextField;
	}

	public void keyPressed(KeyEvent e) {
		int id = e.getKeyCode();
		if (id == KeyEvent.VK_ENTER) {
			updateTextArea();
		}
	}

	public void keyReleased(KeyEvent e) {
	}

	public void keyTyped(KeyEvent e) {
	}

	public void actionPerformed(ActionEvent arg0) {
		s11MagTextField.requestFocusInWindow();
	}
}
