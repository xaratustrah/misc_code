/*
 * Connection.java
 *
 * Created on Петък, 2003, Декември 12, 20:08
 */

package ISSC_702;

import javax.comm.*;
import java.util.*;
import java.io.*;


/**
 *
 * @author  xara
 */
public class Connection {
    
    private CommPortIdentifier portID;
    private Enumeration portList;
    private SerialPort serialPort;
    private OutputStream outputStream;
    private String defaultPort;
    
    /** Creates a new instance of Connection */
    
    public Connection(String defaultPort) {
        this.defaultPort = defaultPort;
    }
    
    /** get and set for the default Port */
    
    public void setPort(String defaultPort) {
        this.defaultPort = defaultPort;
    }
    public String getPort(){
        
        return defaultPort;
    }
    
    public void SerialOpen(){
        boolean foundPort = false;
        portID = (CommPortIdentifier) portList.nextElement();
        
        while (portList.hasMoreElements()) {
            portID = (CommPortIdentifier) portList.nextElement();
            
            if (portID.getPortType() == CommPortIdentifier.PORT_SERIAL) {
                
                if (portID.getName().equals(defaultPort)) {
                    
                    System.out.println("Found port " + defaultPort);
                    
                    foundPort = true;
                    
                    try {
                        serialPort = (SerialPort) portID.open("Wtiting", 2000);
                    }
                    
                    catch (PortInUseException e) {
                        System.out.println("Port in use.");
                        continue;
                    }
                    
                    try {
                        outputStream = serialPort.getOutputStream();
                    }
                    
                    catch (IOException e) {}
                    
                    try {
                        serialPort.setSerialPortParams(9600,
                        SerialPort.DATABITS_8,
                        SerialPort.STOPBITS_1,
                        SerialPort.PARITY_NONE);
                    }
                    
                    catch (UnsupportedCommOperationException e) {}
                    
                    
                    try {
                        serialPort.notifyOnOutputEmpty(true);
                    }
                    
                    catch (Exception e) {
                        System.out.println("Error setting event notification");
                        System.out.println(e.toString());
                        //                        System.exit(-1);
                    }
                }
            }
        }
    }
    
    public void SerialWrite(String str){
        try {
            outputStream.write(str.getBytes());
        } catch (IOException e){}
    }
    public void SerialClose(){
//        try {
//            Thread.sleep(2000);  // wait a little bit!
//        } catch (Exception e) {}
        serialPort.close();
    }
    
}
