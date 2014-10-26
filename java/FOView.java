import javax.swing.JPanel;
import javax.swing.JApplet;
import java.awt.GridLayout;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Dimension;
import javax.swing.JTextPane;
import javax.swing.JEditorPane;

public class FOView extends JApplet {

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

	private JButton calculateButton = null;  //  @jve:decl-index=0:visual-constraint="741,-6"

	private JTextPane jTextPane = null;  //  @jve:decl-index=0:visual-constraint="274,116"

	private JEditorPane jEditorPane = null;

	/**
	 * This is the xxx default constructor
	 */
	public FOView() {
		super();
		this.horizGridGap = 15;
		this.vertGridGap = 15;
	}

	public void setHorizGridGap(int horizGridGap) {
		this.horizGridGap = horizGridGap;
	}

	public int getHorizGridGap() {
		return horizGridGap;
	}

	public void setVertGridGap(int vertGridGap) {
		this.vertGridGap = vertGridGap;
	}

	public int getVertGridGap() {
		return vertGridGap;
	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	public void init() {
		this.setSize(687, 119);
		this.setContentPane(getJContentPane());
	}

	/**
	 * This method initializes jContentPane
	 * 
	 * @return javax.swing.JPanel
	 */
	private JPanel getJContentPane() {
		if (jContentPane == null) {
			jContentPane = new JPanel();
			jContentPane.setLayout(new GridLayout(3, 1));
			jContentPane.add(getJEditorPane(), null);
			jContentPane.add(getMiddlePanel());
		}
		return jContentPane;
	}

	/**
	 * This method initializes jPanel
	 * 
	 * @return javax.swing.JPanel
	 */
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
			middlePanel.add(s21Label, null);
			middlePanel.add(getS21MagTextField(), null);
			middlePanel.add(getS21PhaseTextField(), null);

			middlePanel.add(s22Label, null);
			middlePanel.add(getS22MagTextField(), null);
			middlePanel.add(getS22PhaseTextField(), null);

			middlePanel.add(getS12PhaseTextField(), null);
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

	/**
	 * This method initializes jEditorPane	
	 * 	
	 * @return javax.swing.JEditorPane	
	 */
	private JEditorPane getJEditorPane() {
		if (jEditorPane == null) {
			jEditorPane = new JEditorPane();
		}
		return jEditorPane;
	}


}  //  @jve:decl-index=0:visual-constraint="26,-20"
