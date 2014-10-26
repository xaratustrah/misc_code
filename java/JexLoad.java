/*
 * Created on Feb 28, 2005
 */
package ui;

/**
 * @author xaratustra
 *  
 */

import core.Parser;
import io.HardwarePortListener;

public class JexLoad {

    Parser parser;

    public JexLoad() {

        parser = new Parser((new HardwarePortListener("/dev/ttyS0", this
                .getClass().getName())));

        System.out.println("*** DEBUG-INFO *** An object of "
                + this.getClass().getName() + " was instantiated...");
        parser.startCommunication();
    }

    public static void main(String[] args) {

        JexLoad dummy = new JexLoad();
        System.out.println("Hello!");

    }
}