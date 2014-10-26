/*
 * HardwarePortListener.java
 *
 * Created on January 10, 2005, 3:51 PM
 */

import java.io.*;
import javax.comm.*;
import java.util.ArrayList;
import java.util.Vector;
import java.lang.Exception;

/**
 * This is the Port listener class which is associated with the 
 * physical hardware port class.
 * 
 * @author Xaratustra
 */
public class HardwarePortListener implements SerialPortEventListener {

    //private final static int INPUT_BUFFER_SIZE = 1024;

    private String manufacturerName;

    private String hardwarePort;

    public InputStream inputStream;

    public static OutputStream outputStream;

    private ArrayList pendingLines;

    private HardwareParser parser;

    private HardwarePort readerPort;

    private Vector buffer;

    /**
     * This is the constructor. 
     * Creates a new instance of ISOReader 
     * */

    public HardwarePortListener(HardwareParser parser, String hardwarePort,
            String manufacturerName) {

        this.manufacturerName = manufacturerName;
        this.hardwarePort = hardwarePort;
        System.out.println("*** DEBUG-INFO *** An object of "
                + this.getClass().getName() + " was instantiated...");

        readerPort = new HardwarePort(this);

        this.parser = parser;

        pendingLines = new ArrayList();
        buffer = new Vector();
    }

    /**
     * This is the catcher of the serial events.
     *  
     */
    public void serialEvent(javax.comm.SerialPortEvent serialPortEvent) {
        switch (serialPortEvent.getEventType()) {

        case SerialPortEvent.BI:
        case SerialPortEvent.OE:
        case SerialPortEvent.FE:
        case SerialPortEvent.PE:
        case SerialPortEvent.CD:
        case SerialPortEvent.CTS:
        case SerialPortEvent.DSR:
        case SerialPortEvent.RI:
        case SerialPortEvent.OUTPUT_BUFFER_EMPTY:

            break;

        case SerialPortEvent.DATA_AVAILABLE:

            int newData = 0;
            int cnt = 0;

            while (newData != -1) {

                try {

                    newData = inputStream.read();

                    if (newData == -1) {
                        break;
                    }

                    if ('\r' == (char) newData || '\n' == (char) newData) {

                        pendingLines.add(byteHelper.getByteArray(buffer));

                        /*
                         * hier wird der Parser benachrichtigt.
                         */
                        
                        parser.newByteArrayIsAvailable(this);

                    } else {
                        buffer.add(new Byte((byte) newData));
                    }

                } catch (IOException e) {
                    System.err.println("*** ERROR-INFO *** " + e.toString());
                    return;
                }

                cnt++;
            }
        }

    }

    /**
     * This method writes the given byte array to the ports output stream.
     * 
     * @param msg the message to be sent.
     */
    
    public void writeToHardwarePort(byte[] msg) {

        try {
            outputStream.write(msg);
        } catch (java.io.IOException e) {
            System.err.println("*** ERROR-INFO *** " + e);
        }
    }

    /**
     * This method reads the next available byteArray from the 
     * queue.
     * @return The readbyte array.
     */
    
    public byte[] readNextLine() {
        while (pendingLines.size() == 0) {
        }
        byte[] line = (byte[]) pendingLines.remove(0);
        return line;
    }

    /**
     * This method flushes the input queue.
     */
    
    public void resetLineBuffer() {
        pendingLines = new ArrayList();
    }

    /**
     * This method removes the io streams and virtually turns off
     * the associated reader ports.
     * 
     */
    public void removeListener() {

        try {

            inputStream.close();
            outputStream.close();

        } catch (Exception e) {
            System.err.println("*** ERROR-INFO *** " + e);
        }

        readerPort.removeReader();
    }

    // hier sind die Operationen (get und set mehtoden)

    /**
     * Returns the primitive input stream related to this 
     * ISOPortlistener object, in conjugation with the 
     * hardware port. 
     * @return The input stream.
     */
    
    public InputStream getInputStream() {
        return inputStream;
    }
   
    /**
     * Returns the primitive output stream related to this 
     * ISOPortlistener object, in conjugation with the 
     * hardware port. 
     * @return The output stream.
     */

    public OutputStream getOutputStream() {
        return outputStream;
    }

    /**
     * Sets the primitive input stream related to this 
     * ISOPortlistener object, in conjugation with the 
     * hardware port. 
     * @return The input stream.
     */

    public void setInputStream(InputStream inputStream) {
        this.inputStream = inputStream;
    }

    /**
     * Sets the primitive output stream related to this 
     * ISOPortlistener object, in conjugation with the 
     * hardware port. 
     * @return The output stream.
     */

    public void setOutputStream(OutputStream outputStream) {
        HardwarePortListener.outputStream = outputStream;
    }

    /**
     * Returns the primitive port reader related to this 
     * ISOPortlistener object, in conjugation with the 
     * hardware port. 
     * @return The reader port.
     */

    public HardwarePort getReaderPort() {
        return readerPort;
    }

     /**
     * @param ManufacturerID The name of the manufacturer of the 
     * reader device.
     */
    
    public void setManufacturerName(String ManufacturerID) {

        this.manufacturerName = ManufacturerID;
    }

    /**
     * @return returns the ame of the manufacturer of the 
     * reader device.
     */
    
    public String getManufacturerName() {

        return manufacturerName;
    }

    /**
     * @param hardwarePort sets the string representing the hardware port name
     * on the operating system.
     */
    
    public void setHardwarePort(String hardwarePort) {

        this.hardwarePort = hardwarePort;
    }

    /**
     * @param hardwarePort gets the string representing the hardware port name
     * on the operating system.
     */
    
    public String getHardwarePort() {

        return hardwarePort;
    }

}