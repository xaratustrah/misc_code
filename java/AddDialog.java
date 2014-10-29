/*
 * AddDialog.java
 *
 * Created on ??????????, 2004, ???????????????? 27, 21:12
 */

package BidiBook;

/**
 *
 * @author  xara
 */
public class AddDialog extends javax.swing.JDialog {
    
    /** Creates new form AddDialog */
    public AddDialog(java.awt.Frame parent, boolean modal) {
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
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        AddDlgNameField = new javax.swing.JTextField();
        AddDlgSurNameField = new javax.swing.JTextField();
        AddDlgOtherNameField = new javax.swing.JTextField();
        AddDlgAddressField = new javax.swing.JTextField();
        AddDlgEmailField = new javax.swing.JTextField();
        AddDlgTelField = new javax.swing.JTextField();
        AddDlgFaxField = new javax.swing.JTextField();
        AddDlgURLField = new javax.swing.JTextField();
        jSeparator1 = new javax.swing.JSeparator();
        jLabel9 = new javax.swing.JLabel();
        AddDlgOKButton = new javax.swing.JButton();
        AddDlgCancelButton = new javax.swing.JButton();

        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        setResizable(false);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                closeDialog(evt);
            }
        });

        jLabel1.setText("Name");
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 40, -1, -1));

        jLabel2.setText("Surname");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 70, -1, -1));

        jLabel3.setText("Email");
        getContentPane().add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 160, -1, -1));

        jLabel4.setText("Address");
        getContentPane().add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 130, -1, -1));

        jLabel5.setText("Tel.");
        getContentPane().add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 190, -1, -1));

        jLabel6.setText("Fax.");
        getContentPane().add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 220, 30, -1));

        jLabel7.setText("Other");
        getContentPane().add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 100, -1, -1));

        jLabel8.setText("URL");
        getContentPane().add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 250, -1, -1));

        getContentPane().add(AddDlgNameField, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 40, 270, -1));

        getContentPane().add(AddDlgSurNameField, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 70, 270, -1));

        getContentPane().add(AddDlgOtherNameField, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 100, 270, -1));

        getContentPane().add(AddDlgAddressField, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 130, 270, -1));

        getContentPane().add(AddDlgEmailField, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 160, 270, -1));

        getContentPane().add(AddDlgTelField, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 190, 270, -1));

        getContentPane().add(AddDlgFaxField, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 220, 270, -1));

        getContentPane().add(AddDlgURLField, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 250, 270, -1));

        getContentPane().add(jSeparator1, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 280, 400, -1));

        jLabel9.setText("Enter new record");
        getContentPane().add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(280, 10, -1, -1));

        AddDlgOKButton.setText("ADD");
        AddDlgOKButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                AddDlgOKButtonMousePressed(evt);
            }
        });

        getContentPane().add(AddDlgOKButton, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 290, -1, -1));

        AddDlgCancelButton.setText("Cancel");
        AddDlgCancelButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                AddDlgCancelButtonMousePressed(evt);
            }
        });

        getContentPane().add(AddDlgCancelButton, new org.netbeans.lib.awtextra.AbsoluteConstraints(230, 290, -1, -1));

        pack();
    }//GEN-END:initComponents

    private void AddDlgCancelButtonMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_AddDlgCancelButtonMousePressed
        // Add your handling code here:
        setVisible(false);
        dispose();
    }//GEN-LAST:event_AddDlgCancelButtonMousePressed

    private void AddDlgOKButtonMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_AddDlgOKButtonMousePressed
        // Add your handling code here:
        lnkRecord.setName(AddDlgNameField.getText());
        lnkMainFrame.showInTable(lnkRecord);
        setVisible(false);
        dispose();
    }//GEN-LAST:event_AddDlgOKButtonMousePressed
    
    /** Closes the dialog */
    private void closeDialog(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_closeDialog
        setVisible(false);
        dispose();
    }//GEN-LAST:event_closeDialog
    
    /**
     * @param args the command line arguments
     */
/*
    public static void main(String args[]) {
        new AddDialog(new javax.swing.JFrame(), true).show();
    }
 */
    private Record lnkRecord = new Record();
    private MainFrame lnkMainFrame = new MainFrame();
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField AddDlgAddressField;
    private javax.swing.JButton AddDlgCancelButton;
    private javax.swing.JTextField AddDlgEmailField;
    private javax.swing.JTextField AddDlgFaxField;
    private javax.swing.JTextField AddDlgNameField;
    private javax.swing.JButton AddDlgOKButton;
    private javax.swing.JTextField AddDlgOtherNameField;
    private javax.swing.JTextField AddDlgSurNameField;
    private javax.swing.JTextField AddDlgTelField;
    private javax.swing.JTextField AddDlgURLField;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JSeparator jSeparator1;
    // End of variables declaration//GEN-END:variables
    
}