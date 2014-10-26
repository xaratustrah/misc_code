/*
 * Record.java
 *
 * Created on Петък, 2004, Февруари 27, 21:14
 */

package BidiBook;

import java.io.Serializable;

/**
 *
 * @author  xara
 */
public class Record implements Serializable {
    
    /** Creates a new instance of FaxNoRecord */
    public Record() {
    }
    
    
    
    private String Name;
    public String getName(){ return Name;}
    public void setName(String Name){this.Name = Name;}
    
    private String SurName;
    public String getSurName(){ return SurName;}
    public void setSurName(String SurName){this.SurName = SurName;}
    
    private String OtherName;
    public String getOtherName(){ return OtherName;}
    public void setOtherName(String OtherName){this.OtherName = OtherName;}
    
    private String Address;
    public String getAddress(){ return Name;}
    public void setAddress(String Address){this.Address = Address;}
    
    private String EmailAddress;
    public String getEmailAddress(){ return EmailAddress;}
    public void setEmailAddress(String EmailAddress){this.EmailAddress = EmailAddress;}
    
    private String TelephoneNo;
    public String getTelephoneNo(){ return TelephoneNo;}
    public void setTelephoneNo(String TelephoneNo){this.TelephoneNo = TelephoneNo;}
    
    private String FaxNo;
    public String getFaxNo(){ return FaxNo;}
    public void setFaxNo(String FaxNo){this.FaxNo = FaxNo;}
    
}
