/*
 * Created on Feb 28, 2005
 */
package io;

/**
 *  
 */

import java.io.*;
import javax.comm.*;
import java.util.*;
import core.Parser;

public class HardwarePortListener implements SerialPortEventListener {

    public InputStream inputStream;

    public static OutputStream outputStream;

    private StringBuffer inputBuffer;

    private ArrayList pendingLines;

    private Parser parser;

    private HardwarePort hardwarePort;

    /** Creates a new instance of ISOReader */

    public HardwarePortListener(String portName, String applicationName) {

        System.out.println("*** DEBUG-INFO *** An object of "
                + this.getClass().getName() + " was instantiated...");

        hardwarePort = new HardwarePort(this, portName, applicationName);
        inputBuffer = new StringBuffer();
        pendingLines = new ArrayList();

    }

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

            while (newData != -1) {

                try {

                    newData = inputStream.read();

                    if (newData == -1) {
                        break;
                    }

                    if ('\r' == (char) newData || '\n' == (char) newData) {

                        pendingLines.add(new String(inputBuffer.toString()));
                        /*
                         * hier wird der Parser benachrichtigt.
                         */

                        parser.parseMessage(new String(inputBuffer.toString()));
                        inputBuffer = new StringBuffer();

                    } else {
                        inputBuffer.append((char) newData);
                        parser.charAvailable((char)newData);
                    }

                } catch (IOException e) {
                    System.err.println("Error: " + e);
                    return;
                }
            }
        }

    }

    public void writeStringToPort(String msg) {

        try {
            outputStream.write(msg.getBytes());
        } catch (java.io.IOException e) {
            System.err.println("Error: " + e);
        }
    }
public void writeCharToPort(char msg){
    try{
        outputStream.write(msg);
    }
    catch (IOException e) {
        System.err.println("Error: " + e);
    }
}
    public String readNextLine() {
        while (pendingLines.size() == 0) {
        }
        String line = (String) pendingLines.remove(0);
        return line;
    }

    public void resetLineBuffer() {
        pendingLines = new ArrayList();
    }

    public void removeListener() {

        try {

            inputStream.close();
            outputStream.close();

        } catch (Exception e) {
            System.err.println("Error: " + e);
        }

        hardwarePort.removeHardwarePort();
    }

    // hier sind die Operationen (get und set mehtoden)

    public InputStream getInputStream() {
        return inputStream;
    }

    public OutputStream getOutputStream() {
        return outputStream;
    }

    public void setInputStream(InputStream inputStream) {
        this.inputStream = inputStream;
    }

    public void setOutputStream(OutputStream outputStream) {
        HardwarePortListener.outputStream = outputStream;
    }

    public HardwarePort getHardwarePort() {
        return hardwarePort;
    }

    public void setParser(Parser parser) {
        this.parser = parser;
    }

}