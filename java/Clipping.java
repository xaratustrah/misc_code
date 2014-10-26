import java.applet.*;
import java.awt.*;

public class Clipping extends Applet
{
	public void paint (Graphics gr)
	{
		int maxWidth=gr.getClipBounds().width;
		int maxHeight=gr.getClipBounds().height;
		gr.setColor(Color.blue);
		gr.drawString("The Boundry size is: "+ maxWidth+" X "+maxHeight, 50,50);
	}
}
