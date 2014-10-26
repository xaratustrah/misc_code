/*
 * Created on May 24, 2003
 *
 * To change the template for this generated file go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
package dbgui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import java.util.Vector;

//import java.sql.DriverManager;
import java.sql.SQLException;
import com.mysql.jdbc.*;
/**
 * @author shr1k3
 *
 * To change the template for this generated type comment go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
public class ExampleDBGUI {
	private Vector colNames = new Vector();
	private Vector rowData = new Vector();

	public void prepareInputData() {
		colNames.add("ID");
		colNames.add("Stamp");
		colNames.add("Blog");

		com.mysql.jdbc.Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;

		try {
			Class driver = Class.forName("com.mysql.jdbc.Driver");

			driver.newInstance();
			con =
				(
					com
						.mysql
						.jdbc
						.Connection) java
						.sql
						.DriverManager
						.getConnection(
					"jdbc:mysql://localhost/blog?user=shr1k3&password=gr0ddZ");
			stmt = (com.mysql.jdbc.Statement) con.createStatement();
			rs =
				(com.mysql.jdbc.ResultSet) stmt.executeQuery(
					"SELECT * FROM blog");

			while (rs.next()) {
				Vector tmp = new Vector();
				tmp.add(new Integer(rs.getInt("ID")));
				tmp.add(rs.getString("stamp").toString());
				tmp.add(rs.getString("blog"));
				rowData.add(tmp);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (con != null)
					con.close();
			} catch (SQLException ignored) {
			}
		}
	}

	public Component createComponents() {
		JScrollPane scroller = null;
		JTabbedPane tabs = new JTabbedPane(JTabbedPane.LEFT);
		JTable table1 = new JTable(rowData, colNames);
		table1.setPreferredScrollableViewportSize(new Dimension(600, 300));
		
		scroller = new JScrollPane(table1);
//		scroller.setBorder(BorderFactory.createEmptyBorder(5, 5, 100, 100));
		tabs.addTab("table1", scroller);
		tabs.addTab("table2", null);

		return tabs;
	}

	public static void main(String[] args) {
		try {
			UIManager.setLookAndFeel(
				UIManager.getCrossPlatformLookAndFeelClassName());
		} catch (Exception e) {
		}

		//Create the top-level container and add contents to it.
		JFrame frame = new JFrame("DBGUI");
		ExampleDBGUI app = new ExampleDBGUI();
		app.prepareInputData();
		Component contents = app.createComponents();
		frame.getContentPane().add(contents, BorderLayout.CENTER);

		//Finish setting up the frame, and show it.
		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		frame.pack();
		frame.setVisible(true);
	}

}
