/*
 * Created on Feb 28, 2005
 *
 * Window - Preferences - Java - Code Style - Code Templates
 */
package core;

/**
 * @author Window - Preferences - Java - Code Style - Code
 *         Templates
 */

import io.HardwarePortListener;

public class Parser {

    //	private ReaderManager manager;

    public static final char CMD_NULL = 0x00;

    public static final char CMD_WRITE_PAGE = 0xFF;

    public static final char MSG_ACK = 0xE5;

    private HardwarePortListener hardwarePortListener;

    /** Creates a new instance of ISOParser */

    public Parser(HardwarePortListener hardwarePortListener) {

        this.hardwarePortListener = hardwarePortListener;
        this.hardwarePortListener.setParser(this);

        System.out.println("*** DEBUG-INFO *** An object of "
                + this.getClass().getName() + " was instantiated...");

    }

    public void parseMessage(String message) {

        System.out.println("This comes from the Controller :" + message + ".");
    }

    public void charAvailable(char incomming) {
        if (incomming == 0x00) {
            System.out.println("No answer from Controller.");
            return;
        }
         System.out.println("Controller answered with : "
                + String.valueOf(incomming));
        if (incomming == MSG_ACK)
            System.out.println("Ja! erlebt noch!");
    }

    public void startCommunication() {

        hardwarePortListener.writeCharToPort(CMD_NULL);
        //   hardwarePortListener.resetLineBuffer();
    }

    public void writeChar(char toBeWritten) {

        hardwarePortListener.writeCharToPort(toBeWritten);

    }

    public String writePage(String pageNo, String page) {

        hardwarePortListener.writeStringToPort(CMD_WRITE_PAGE + pageNo + page);
        String response = hardwarePortListener.readNextLine();

        if (response == null)
            response = hardwarePortListener.readNextLine();
        else if (response.equals(""))
            response = hardwarePortListener.readNextLine();

        return response;
    }

}