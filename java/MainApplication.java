/*
 * MainApplication.java
 *
 * Created on Петък, 2004, Февруари 27, 21:13
 */

package BidiBook;

import javax.swing.UIManager;
import java.awt.Dimension;
import java.awt.Toolkit;

/**
 *
 * @author  xara
 */
public class MainApplication {
    
    /** Creates a new instance of MainApplication */
    public MainApplication() {
        
        MainFrame frame = new MainFrame();
        //Center the frame on screen
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension frameSize = frame.getSize();
        frameSize.height = ((frameSize.height > screenSize.height) ? screenSize.height : frameSize.height);
        frameSize.width = ((frameSize.width > screenSize.width) ? screenSize.width : frameSize.width);
        frame.setLocation((screenSize.width - frameSize.width) / 2, (screenSize.height - frameSize.height) / 2);
        frame.setVisible(true);
    }
        public static void main(String[] argv) {
        // set up system Look&Feel
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        new MainApplication();
    }
}
