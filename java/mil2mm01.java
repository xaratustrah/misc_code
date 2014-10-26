// *****************************
// Metric to Imperial converter.
// written by Xaratustra.
// Darmstadt Apr.2003
// *****************************

import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class mil2mm extends Applet {
 
 
     Label  lab1 = new Label("convert mil <-> mm:");
     Label  lab2 = new Label("mil");
     Label  lab3 = new Label("mm");
     TextField tf1 = new TextField("0");
     TextField tf2 = new TextField("0");
     Button but1 = new Button("dn");
     Button but2 = new Button("up");
     Label laberr= new Label("");
  
     public void init()
	  {
	  setLayout(null);
	  lab1.setBounds(10,10,200,20);
	  tf1.setBounds(10,35,80,30);
	  lab2.setBounds(100,40,30,20);
	  but1.setBounds(10,70,40,20);
	  but2.setBounds(50,70,40,20);
	  tf2.setBounds(10,95,80,30);
	  lab3.setBounds(100,100,30,20);
	  laberr.setBounds(10,125,150,20);
	  add(lab1);
	  add(tf1);
	  add(lab2);
	  add(tf2);
	  add(lab3);
	  add(but1);
	  add(but2);
	  add(laberr);

	  but1.addMouseListener(
	       new MouseAdapter(){
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
	       new MouseAdapter(){
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
