/*
 * MainFrame.java
 *
 * Created on ??????????, 2004, ???????????????? 27, 21:12
 */

package BidiBook;

import java.awt.Dimension;
import java.util.Vector;
import javax.swing.*;
import javax.swing.UIManager;
import java.awt.Dimension;
import java.awt.Toolkit;

/**
 *
 * @author  xara
 */
public class MainFrame extends javax.swing.JFrame {
    
    /** Creates new form MainFrame */
    public MainFrame() {
        setSize(400, 300);
        initComponents();
        
        
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    private void initComponents() {//GEN-BEGIN:initComponents
        mainToolBar = new javax.swing.JToolBar();
        mainToolBarAddButton = new javax.swing.JButton();
        mainToolBarDelButton = new javax.swing.JButton();
        mainScrollPane = new javax.swing.JScrollPane();
        mainTable = new javax.swing.JTable();
        mainMenuBar = new javax.swing.JMenuBar();
        mainMenuFile = new javax.swing.JMenu();
        mainMenuFileExit = new javax.swing.JMenuItem();
        mainMenuHelp = new javax.swing.JMenu();
        mainMenuHelpAbout = new javax.swing.JMenuItem();

        setTitle("BidiBook");
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                exitForm(evt);
            }
        });

        mainToolBarAddButton.setText("ADD");
        mainToolBarAddButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                mainToolBarAddButtonMousePressed(evt);
            }
        });

        mainToolBar.add(mainToolBarAddButton);

        mainToolBarDelButton.setText("Delete");
        mainToolBar.add(mainToolBarDelButton);

        getContentPane().add(mainToolBar, java.awt.BorderLayout.NORTH);

        mainTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null}
            },
            new String [] {
                "Name", "Surname", "Other Name", "Address", "Title 5"
            }
        ));
        mainScrollPane.setViewportView(mainTable);

        getContentPane().add(mainScrollPane, java.awt.BorderLayout.CENTER);

        mainMenuFile.setText("File");
        mainMenuFileExit.setText("Exit");
        mainMenuFile.add(mainMenuFileExit);

        mainMenuBar.add(mainMenuFile);

        mainMenuHelp.setText("Help");
        mainMenuHelpAbout.setText("About...");
        mainMenuHelp.add(mainMenuHelpAbout);

        mainMenuBar.add(mainMenuHelp);

        setJMenuBar(mainMenuBar);

        pack();
    }//GEN-END:initComponents
    
    private void mainToolBarAddButtonMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_mainToolBarAddButtonMousePressed
        // Add your handling code here:
        AddDialog add_dlg = new AddDialog(MainFrame.this, true);
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension frameSize = add_dlg.getSize();
        frameSize.height = ((frameSize.height > screenSize.height) ? screenSize.height : frameSize.height);
        frameSize.width = ((frameSize.width > screenSize.width) ? screenSize.width : frameSize.width);
        add_dlg.setLocation((screenSize.width - frameSize.width) / 2, (screenSize.height - frameSize.height) / 2);
        add_dlg.setVisible(true);
    }//GEN-LAST:event_mainToolBarAddButtonMousePressed
    
    /** Exit the Application */
    private void exitForm(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_exitForm
        System.exit(0);
    }//GEN-LAST:event_exitForm
    public void showInTable(Record lnkRecord){
        System.out.println(lnkRecord.getName());
        mainTable.setValueAt(
        lnkRecord.getName(),1, 1);
        mainTable.doLayout();
        
    }
    
    /**
     * @param args the command line arguments
     */
/*    public static void main(String args[]) {
        new MainFrame().show();
    }
 */
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuBar mainMenuBar;
    private javax.swing.JMenu mainMenuFile;
    private javax.swing.JMenuItem mainMenuFileExit;
    private javax.swing.JMenu mainMenuHelp;
    private javax.swing.JMenuItem mainMenuHelpAbout;
    private javax.swing.JScrollPane mainScrollPane;
    private javax.swing.JTable mainTable;
    private javax.swing.JToolBar mainToolBar;
    private javax.swing.JButton mainToolBarAddButton;
    private javax.swing.JButton mainToolBarDelButton;
    // End of variables declaration//GEN-END:variables
    
}