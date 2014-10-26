import java.applet.*;
import java.awt.*;
public class Salam extends Applet{
 public void paint (Graphics g){
   String s0 =("Salam, ");
   String s1= ("1 ");
   String s2=("2.");
   String s3= ("3 ");
   String s4=("4.");
   g.drawString(s0, 20, 20);
   g.drawString(s1, 20, 40);
   g.drawString(s2, 20, 60);
   g.drawString(s3, 20, 80);
   g.drawString(s4, 20, 100);
   int x= (int) (Math.random()*10);
   int MojiCanAfford;
   MojiCanAfford = (x>4) ? 1
                         : 0;
   String m1=("5");
   String m2= ("6");
   switch (MojiCanAfford){
     case 0 : g.drawString(m2, 20, 120);
                  break;
     case 1 : g.drawString(m1+"7 ", 20, 120);
              g.drawString("8,", 20, 140);
              g.drawString("9 ", 20, 160);
              g.drawString("10.", 20, 180);
   }

  g.drawString("Ghorbanat.. 8. DEC", 20, 200);
 }
}

//Mikkkkkkkkkksssssssss! :)
