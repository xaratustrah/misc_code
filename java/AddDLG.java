/*
 * AddDLG.java
 *
 * Created on February 20, 2004, 10:48 AM
 */

package GUI_Test;

/**
 *
 * @author  xara
 */
public class AddDLG extends javax.swing.JDialog {
    
    private Person lnkPerson = new Person();
    private MainFrame lnkFrame  = new MainFrame();
    
    /** Creates new form AddDLG */
    public AddDLG(java.awt.Frame parent, boolean modal) {
        super(parent, modal);
        initComponents();
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    private void initComponents() {//GEN-BEGIN:initComponents
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jTextField1 = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();

        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                closeDialog(evt);
            }
        });

        jLabel1.setText("And then press OK.");
        getContentPane().add(jLabel1, java.awt.BorderLayout.SOUTH);

        jLabel2.setText("Please enter somthing...");
        getContentPane().add(jLabel2, java.awt.BorderLayout.NORTH);

        jTextField1.setText("jTextField1");
        getContentPane().add(jTextField1, java.awt.BorderLayout.CENTER);

        jButton1.setText(java.util.ResourceBundle.getBundle("GUI_Test/properties").getString("Helllo"));
        jButton1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                okButtonPressed(evt);
            }
        });

        getContentPane().add(jButton1, java.awt.BorderLayout.EAST);

        pack();
    }//GEN-END:initComponents

    private void okButtonPressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_okButtonPressed
        lnkPerson.setPerson_Name(jTextField1.getText());
        lnkFrame.acceptPerson(lnkPerson);
        setVisible(false);
        dispose();
        
        // Add your handling code here:
    }//GEN-LAST:event_okButtonPressed
    
    /** Closes the dialog */
    private void closeDialog(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_closeDialog
        setVisible(false);
        dispose();
    }//GEN-LAST:event_closeDialog
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        new AddDLG(new javax.swing.JFrame(), true).show();
    }
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JTextField jTextField1;
    // End of variables declaration//GEN-END:variables
    
}
