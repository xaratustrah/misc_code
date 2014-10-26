/*
 * HardwarePort.java
 *
 * Created on November 22, 2004, 3:25 PM
 */

import javax.comm.*;
import java.io.*;

/**
 * @author xaratustra
 */

public class HardwarePort {

    private static CommPortIdentifier portId;

    private SerialPort serialPort;

    /** Creates a new instance of ReaderPort */

    public HardwarePort(HardwarePortListener listener) {

        boolean failed = false;

        System.out.print("*** DEBUG-INFO *** Trying to open port " + listener.getHardwarePort()
                + "...");

        try {
            portId = CommPortIdentifier.getPortIdentifier(listener.getHardwarePort());
        } catch (NoSuchPortException e) {
            System.err.println("*** ERROR-INFO *** " + e);
            failed = true;
        }

        if (!failed) {
            try {
                serialPort = (SerialPort) portId.open(listener.getManufacturerName(), 2000);
            } catch (PortInUseException e) {
                System.err.println("*** ERROR-INFO *** " + e);
                failed = true;
            }
        }

        if (!failed) {
            try {
                listener.setInputStream(serialPort.getInputStream());
                listener.setOutputStream(serialPort.getOutputStream());
            } catch (IOException e) {
                System.err.println("*** ERROR-INFO *** " + e);
                failed = true;
            }
        }

        if (!failed) {
            try {
                serialPort.addEventListener(listener);
                serialPort.notifyOnDataAvailable(true);
            } catch (Exception e) { // too many listeners exception??
                System.err.println("*** ERROR-INFO *** " + e);
                failed = true;
            }
        }

        if (!failed) {
            try {

                serialPort.setSerialPortParams(9600, SerialPort.DATABITS_8,
                        SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);

            } catch (UnsupportedCommOperationException e) {
                System.err.println("*** ERROR-INFO *** " + e);
                failed = true;
            }
        }

        if (!failed) {
            System.out.println("*** DEBUG-INFO *** Port oppened successfully!");
        } else {
            System.out.println("*** ERROR-INFO *** Failed to open communication port.");
        }
    }

    public void removeReader() {

        serialPort.close();
    }

}
