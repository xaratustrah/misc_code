/*
 * Person.java
 *
 * Created on February 20, 2004, 10:26 AM
 */

package GUI_Test;

/**
 *
 * @author  xara
 */
public class Person extends java.lang.Object {
    
    private String person_Name = java.util.ResourceBundle.getBundle("GUI_Test/properties").getString("Helllo");
    
    /** Creates a new instance of Person */
    public Person() {
    }
    
    public String getPerson_Name() {
        return person_Name;
    }
    
    public void setPerson_Name(java.lang.String Name) {
        person_Name = Name;
    }
    
}
