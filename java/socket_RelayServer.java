/*
 * Created on Apr 24, 2005
 */

import java.net.*;

/**
 * @author xara
 *  
 */

public class RelayServer {
    HardwareParser hp;

    public RelayServer() {
        hp = new HardwareParser(this);
    }

    public static void main(String args[]) {

        RelayServer rs = new RelayServer();

        int anz = 1;
        try {
            ServerSocket ss = new ServerSocket(7788);
            while (true) {
                Socket sverb = ss.accept();
                System.out.println(" Verbindung " + anz);
                new RelayServerThread(sverb, anz).start();
                anz++;
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}