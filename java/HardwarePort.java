/*
 * Created on Feb 28, 2005
 * 
 * Window - Preferences - Java - Code Style - Code Templates
 */
package io;

/**
 */

import javax.comm.*;
import java.io.*;

public class HardwarePort {

    private String applicationName;

    private String hardwarePort;

    private static CommPortIdentifier portId;

    private SerialPort serialPort;

    /** Creates a new instance of ReaderPort */

    public HardwarePort(HardwarePortListener listener, String hardwarePort,
            String applicationName) {

        boolean failed = false;
        this.hardwarePort = hardwarePort;

        System.out.print("Trying to open port " + hardwarePort + "...");

        try {
            portId = CommPortIdentifier.getPortIdentifier(hardwarePort);
        } catch (NoSuchPortException e) {
            System.err.println("Error: " + e);
            failed = true;
        }

        if (!failed) {
            try {
                serialPort = (SerialPort) portId.open(applicationName, 2000);
            } catch (PortInUseException e) {
                System.err.println("Error: " + e);
                failed = true;
            }
        }

        if (!failed) {
            try {
                listener.setInputStream(serialPort.getInputStream());
                listener.setOutputStream(serialPort.getOutputStream());
            } catch (IOException e) {
                System.err.println("Error: " + e);
                failed = true;
            }
        }

        if (!failed) {
            try {
                serialPort.addEventListener(listener);
                serialPort.notifyOnDataAvailable(true);
            } catch (Exception e) { // too many listeners exception??
                System.err.println("Error: " + e);
                failed = true;
            }
        }

        if (!failed) {
            try {

                serialPort.setSerialPortParams(19200, SerialPort.DATABITS_8,
                        SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);

            } catch (UnsupportedCommOperationException e) {
                System.err.println("Error: " + e);
                failed = true;
            }
        }

        if (!failed) {
            System.out.println("ok!");
        } else {
            System.out.println("failed");
        }
    }

    /**
     * @return closes the used serialport in the system.
     */
    public void removeHardwarePort() {

        serialPort.close();
    }

    /** Get and set methods for the private variables */

    /**
     * @param hardwarePort Sets the hardware port on the system to be used.
     */
    
    public void setHardwarePort(String hardwarePort) {

        this.hardwarePort = hardwarePort;
    }

    /**
     * @return Returns the a string containing the name of the used hardware serial Port on the system.
     */
    public String getHardwarePort() {

        return hardwarePort;
    }
}
