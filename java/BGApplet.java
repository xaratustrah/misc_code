import java.awt.*;
import java.applet.*;

public class BGApplet extends Applet {
   String bgColor, bgColor2, language;

   	public void init() {
          language = getParameter("Language");
          if(language.equals("english") ) {

      	   bgColor = getParameter("Background");   
           if(bgColor.equals("red"))
	      setBackground(Color.red);
           else if(bgColor.equals("green"))
	      setBackground(Color.green);
           else if(bgColor.equals("blue"))
	      setBackground(Color.blue);
           else if(bgColor.equals("black"))
	      setBackground(Color.black);
           else if(bgColor.equals("white"))
	      setBackground(Color.white);
           else if(bgColor.equals("yellow"))
	      setBackground(Color.yellow);

          bgColor2 = getParameter("Foreground");   
          if(bgColor2.equals("red"))
	     setForeground(Color.red);
          else if(bgColor2.equals("green"))
	     setForeground(Color.green);
          else if(bgColor2.equals("blue"))
	     setForeground(Color.blue);
          else if(bgColor2.equals("black"))
	     setForeground(Color.black);
          else if(bgColor2.equals("white"))
	     setForeground(Color.white);
          else if(bgColor2.equals("yellow"))
	     setForeground(Color.yellow);
	
   }


   else if(language.equals("deutsch"))   {
      bgColor = getParameter("Background");   
      if(bgColor.equals("rot"))
	 setBackground(Color.red);
      else if(bgColor.equals("gruen"))
	 setBackground(Color.green);
      else if(bgColor.equals("blau"))
	 setBackground(Color.blue);
      else if(bgColor.equals("schwarz"))
	 setBackground(Color.black);
      else if(bgColor.equals("weiss"))
	 setBackground(Color.white);
      else if(bgColor.equals("gelb"))
	 setBackground(Color.yellow);

      bgColor2 = getParameter("Foreground");   
      if(bgColor2.equals("rot"))
	 setForeground(Color.red);
      else if(bgColor2.equals("gruen"))
	 setForeground(Color.green);
      else if(bgColor2.equals("blau"))
	 setForeground(Color.blue);
      else if(bgColor2.equals("schwarz"))
	 setForeground(Color.black);
      else if(bgColor2.equals("weiss"))
	 setForeground(Color.white);
      else if(bgColor2.equals("gelb"))
	 setForeground(Color.yellow);
   }
}
   public void paint(Graphics g) {
      g.drawString("Der Hintergrund ist " + bgColor2, 7, 40);
   }

};