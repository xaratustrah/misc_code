/*
 * relay.java
 *
 * Created on December 12, 2003, 11:00 PM
 */

import javax.swing.UIManager;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.io.*;
import java.util.*;
import javax.comm.*;

/**
 *
 * @author  xara
 */
public class relay extends javax.swing.JFrame {
    
    /** Creates new form tet */
    public relay() {
        initComponents();
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    private void initComponents() {//GEN-BEGIN:initComponents
        jToggleButton1 = new javax.swing.JToggleButton();
        jLabel1 = new javax.swing.JLabel();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenuFile = new javax.swing.JMenu();
        jMenuExit = new javax.swing.JMenuItem();

        getContentPane().setLayout(null);

        setTitle("Relay");
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                exitForm(evt);
            }
        });

        jToggleButton1.setText("Relay  -  \u0631\u0644\u0647");
        jToggleButton1.setBorder(new javax.swing.border.EtchedBorder());
        jToggleButton1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                jToggleButton1MousePressed(evt);
            }
        });

        getContentPane().add(jToggleButton1);
        jToggleButton1.setBounds(60, 50, 131, 30);

        jLabel1.setFont(new java.awt.Font("SansSerif", 1, 14));
        jLabel1.setForeground(new java.awt.Color(255, 0, 0));
        jLabel1.setText("Relay Actuator -  \u0631\u0627\u0647 \u0627\u0646\u062f\u0627\u0632 \u0631\u0644\u0647 ");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(20, 10, 230, 30);

        jMenuFile.setText("File  -  \u0641\u0627\u064a\u0644");
        jMenuExit.setText("Exit  -  \u062e\u0631\u0648\u062c");
        jMenuExit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuExitActionPerformed(evt);
            }
        });

        jMenuFile.add(jMenuExit);

        jMenuBar1.add(jMenuFile);

        setJMenuBar(jMenuBar1);

        pack();
    }//GEN-END:initComponents
    
    private void jMenuExitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuExitActionPerformed
        // Add your handling code here:
        try {
            Thread.sleep(100);  // Be sure data is xferred before closing
        } catch (Exception e) {}
        serialPort.close();
        System.exit(1);
        
        
    }//GEN-LAST:event_jMenuExitActionPerformed
    
    private void jToggleButton1MousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jToggleButton1MousePressed
        // Add your handling code here:
        System.out.println(
        "Writing \""+messageString+"\" to "
        +serialPort.getName());
        
        try {
            outputStream.write(messageString.getBytes());
        } catch (IOException e) {}
        
    }//GEN-LAST:event_jToggleButton1MousePressed
    
    /** Exit the Application */
    private void exitForm(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_exitForm
        try {
            Thread.sleep(100);  // Be sure data is xferred before closing
        } catch (Exception e) {}
        serialPort.close();
        System.exit(1);
    }//GEN-LAST:event_exitForm
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        relay NewFrame = new relay();
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension frameSize = NewFrame.getSize();
        frameSize.height = ((frameSize.height > screenSize.height) ? screenSize.height : frameSize.height);
        frameSize.width = ((frameSize.width > screenSize.width) ? screenSize.width : frameSize.width);
        NewFrame.setLocation((screenSize.width - frameSize.width) / 2, (screenSize.height - frameSize.height) / 2);
        NewFrame.setVisible(true);
        NewFrame.setSize(250, 120);
        NewFrame.show();
        
        
        boolean portFound = false;
        String  defaultPort = "/dev/ttyS0";
        
        if (args.length > 0) {
            defaultPort = args[0];
        }
        
        portList = CommPortIdentifier.getPortIdentifiers();
        
        while (portList.hasMoreElements()) {
            portId = (CommPortIdentifier) portList.nextElement();
            
            if (portId.getPortType() == CommPortIdentifier.PORT_SERIAL) {
                
                if (portId.getName().equals(defaultPort)) {
                    System.out.println("Found port " + defaultPort);
                    
                    portFound = true;
                    
                    try {
                        serialPort =
                        (SerialPort) portId.open("SimpleWrite", 2000);
                    } catch (PortInUseException e) {
                        System.out.println("Port in use.");
                        
                        continue;
                    }
                    
                    try {
                        outputStream = serialPort.getOutputStream();
                    } catch (IOException e) {}
                    
                    try {
                        serialPort.setSerialPortParams(4800,
                        SerialPort.DATABITS_8,
                        SerialPort.STOPBITS_1,
                        SerialPort.PARITY_NONE);
                    } catch (UnsupportedCommOperationException e) {}
                    
                    
                    try {
                        serialPort.notifyOnOutputEmpty(true);
                    } catch (Exception e) {
                        System.out.println("Error setting event notification");
                        System.out.println(e.toString());
                        System.exit(-1);
                    }
                }
            }
        }
        
        if (!portFound) {
            System.out.println("port " + defaultPort + " not found.");
        }
    }
    
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuExit;
    private javax.swing.JMenu jMenuFile;
    private javax.swing.JToggleButton jToggleButton1;
    // End of variables declaration//GEN-END:variables
    
    private static Enumeration	      portList;
    static CommPortIdentifier portId;
    static String	      messageString = "qwe\n";
    static SerialPort	      serialPort;
    static OutputStream       outputStream;
    static boolean	      outputBufferEmptyFlag = false;
    
}