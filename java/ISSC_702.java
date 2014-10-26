/*
 * Appli.java
 *
 * Created on December 10, 2003, 3:46 PM
 */

package ISSC_702;

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

public class ISSC_702 extends javax.swing.JFrame {
    
    /** Creates new form ISSC_702 */
    public ISSC_702() {
        initComponents();
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    private void initComponents() {//GEN-BEGIN:initComponents
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jTree1 = new javax.swing.JTree();
        PortButton = new javax.swing.JToggleButton();
        O_C_Button = new javax.swing.JToggleButton();
        jLabel1 = new javax.swing.JLabel();
        menuBar = new javax.swing.JMenuBar();
        fileMenu = new javax.swing.JMenu();
        openMenuItem = new javax.swing.JMenuItem();
        saveMenuItem = new javax.swing.JMenuItem();
        saveAsMenuItem = new javax.swing.JMenuItem();
        exitMenuItem = new javax.swing.JMenuItem();
        editMenu = new javax.swing.JMenu();
        cutMenuItem = new javax.swing.JMenuItem();
        copyMenuItem = new javax.swing.JMenuItem();
        pasteMenuItem = new javax.swing.JMenuItem();
        deleteMenuItem = new javax.swing.JMenuItem();
        helpMenu = new javax.swing.JMenu();
        contentsMenuItem = new javax.swing.JMenuItem();
        aboutMenuItem = new javax.swing.JMenuItem();

        jMenu1.setText("Menu");
        jMenuBar1.add(jMenu1);

        getContentPane().setLayout(null);

        setResizable(false);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                exitForm(evt);
            }
        });

        getContentPane().add(jTree1);
        jTree1.setBounds(10, 10, 250, 130);

        PortButton.setText("\u062f\u0631\u06af\u0627\u0647");
        PortButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                PortButtonMousePressed(evt);
            }
        });

        getContentPane().add(PortButton);
        PortButton.setBounds(270, 70, 130, 25);

        O_C_Button.setText("\u0642\u0637\u0639 \u0648 \u0648\u0633\u0644");
        O_C_Button.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                O_C_ButtonMousePressed(evt);
            }
        });

        getContentPane().add(O_C_Button);
        O_C_Button.setBounds(270, 110, 130, 25);

        jLabel1.setFont(new java.awt.Font("SansSerif", 1, 14));
        jLabel1.setForeground(new java.awt.Color(255, 0, 0));
        jLabel1.setText("\u067e\u0627\u064a\u0627\u0646\u0647\u064f \u0633\u0631\u064a\u0627\u0644 ");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(280, 20, 102, 30);

        fileMenu.setText("\u067e\u0631\u0648\u0646\u062f\u0647");
        openMenuItem.setText("Open");
        fileMenu.add(openMenuItem);

        saveMenuItem.setText("Save");
        fileMenu.add(saveMenuItem);

        saveAsMenuItem.setText("Save As ...");
        fileMenu.add(saveAsMenuItem);

        exitMenuItem.setText("Exit");
        exitMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                exitMenuItemActionPerformed(evt);
            }
        });

        fileMenu.add(exitMenuItem);

        menuBar.add(fileMenu);

        editMenu.setText("\u062a\u0646\u0638\u064a\u0645\u0627\u062a");
        cutMenuItem.setText("Cut");
        editMenu.add(cutMenuItem);

        copyMenuItem.setText("Copy");
        editMenu.add(copyMenuItem);

        pasteMenuItem.setText("Paste");
        editMenu.add(pasteMenuItem);

        deleteMenuItem.setText("Delete");
        editMenu.add(deleteMenuItem);

        menuBar.add(editMenu);

        helpMenu.setText("\u062a\u0648\u0636\u064a\u062d\u0627\u062a");
        contentsMenuItem.setText("Contents");
        helpMenu.add(contentsMenuItem);

        aboutMenuItem.setText("About");
        helpMenu.add(aboutMenuItem);

        menuBar.add(helpMenu);

        setJMenuBar(menuBar);

        pack();
    }//GEN-END:initComponents
    
    private void O_C_ButtonMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_O_C_ButtonMousePressed
        // Add your handling code here:
        //        cnt.SerialWrite("q");
        System.out.println("sending \"q\"");
    }//GEN-LAST:event_O_C_ButtonMousePressed
    
    private void PortButtonMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_PortButtonMousePressed
        // Add your handling code here:
        
        if (!localToggle) {
            System.out.println("port on");
            cnt.SerialOpen();
            localToggle = true;
        }
        else {
            System.out.println("port off");
            //cnt.SerialClose();
            localToggle = false;
        }
    }//GEN-LAST:event_PortButtonMousePressed
    
    private void exitMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_exitMenuItemActionPerformed
        System.exit(0);
    }//GEN-LAST:event_exitMenuItemActionPerformed
    
    /** Exit the Application */
    private void exitForm(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_exitForm
        System.exit(0);
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
        //        new Appli().show();
        ISSC_702 NewFrame = new ISSC_702();
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension frameSize = NewFrame.getSize();
        frameSize.height = ((frameSize.height > screenSize.height) ? screenSize.height : frameSize.height);
        frameSize.width = ((frameSize.width > screenSize.width) ? screenSize.width : frameSize.width);
        NewFrame.setLocation((screenSize.width - frameSize.width) / 2, (screenSize.height - frameSize.height) / 2);
        NewFrame.setVisible(true);
        
        NewFrame.show();
        
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToggleButton O_C_Button;
    private javax.swing.JToggleButton PortButton;
    private javax.swing.JMenuItem aboutMenuItem;
    private javax.swing.JMenuItem contentsMenuItem;
    private javax.swing.JMenuItem copyMenuItem;
    private javax.swing.JMenuItem cutMenuItem;
    private javax.swing.JMenuItem deleteMenuItem;
    private javax.swing.JMenu editMenu;
    private javax.swing.JMenuItem exitMenuItem;
    private javax.swing.JMenu fileMenu;
    private javax.swing.JMenu helpMenu;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JTree jTree1;
    private javax.swing.JMenuBar menuBar;
    private javax.swing.JMenuItem openMenuItem;
    private javax.swing.JMenuItem pasteMenuItem;
    private javax.swing.JMenuItem saveAsMenuItem;
    private javax.swing.JMenuItem saveMenuItem;
    // End of variables declaration//GEN-END:variables
    
    private static Enumeration	      portList;
    static CommPortIdentifier portId;
    static String	      messageString = "q";
    static SerialPort	      serialPort;
    static OutputStream       outputStream;
    static boolean	      outputBufferEmptyFlag = false;
    
}
