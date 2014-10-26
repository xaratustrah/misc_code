// *****************************
// Metric to Imperial converter.
// written by xaratustra
// Apr.2003
// *****************************

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;

public class mil2mmSwing extends JApplet {

     JPanel topPan = new JPanel ();
     JPanel midPan = new JPanel ();
     JPanel botPan = new JPanel ();

     JLabel  lab1 = new JLabel("convert mil <-> mm:");
     JLabel  lab2 = new JLabel("mil");
     JLabel  lab3 = new JLabel("mm");
     JTextField tf1 = new JTextField("0");
     JTextField tf2 = new JTextField("0");
     JButton but1 = new JButton("dn");
     JButton but2 = new JButton("up");
     JLabel laberr= new JLabel("");

     public static void main (String [] args)
	  {
	       JFrame f = new JFrame();
	       mil2mmSwing af = new mil2mmSwing();
	       af.init();
	       af.start();
	       f.add(af);
	       f.setSize(300,300);
	       f.setVisible(true);
	       f.addWindowListener(new WindowAdapter()
		    {
			 public void windowClosing (WindowEvent e){
			      System.exit(0);
			 }
		    });
	  }
     public void init()
	  {
	       setLayout(new GridLayout (3,1));
	       topPan.setLayout (new GridLayout (1,1));
	       midPan.setLayout (new GridLayout (3,2));
	       botPan.setLayout (new GridLayout (1,1));

	       add (topPan);
	       add (midPan);
	       add (botPan);

	       topPan.add(lab1);
	       midPan.add(tf1);
	       midPan.add(lab2);
	       midPan.add(tf2);
	       midPan.add(lab3);
	       midPan.add(but1);
	       midPan.add(but2);
	       botPan.add(laberr);

	       but1.addMouseListener(
		    new MouseInputAdapter(){
			 public void mouseClicked(MouseEvent e){
			      try{
				   tf2.setText(Double.parseDouble(tf1.getText())*0.0254+"");
				   laberr.setText("");
			      }
			      catch(Exception ext)
			      {
				   laberr.setText("Use numbers only!");

			      }
			 }

		    });

	       but2.addMouseListener(
		    new MouseInputAdapter(){
			 public void mouseClicked(MouseEvent e){
			      try{
				   tf1.setText(Double.parseDouble(tf2.getText())/0.0254+"");
				   laberr.setText("");

			      }
			      catch(Exception ext)
			      {
				   laberr.setText("Use numbers only!");

			      }
			 }
		    });
	  }
}
