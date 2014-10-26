/*
 * Created on Apr 24, 2005
 */

import java.io.*;
import java.net.*;

/**
 * @author xara
 */

public class RelayServerThread extends Thread {
    Socket sverb;

    int nverb;

    RelayServerThread(Socket s, int n) {
        this.sverb = s;
        this.nverb = n;
    }

    public void run() {

        try {

            BufferedReader in = new BufferedReader(new InputStreamReader(sverb
                    .getInputStream()));

            PrintStream out = new PrintStream(sverb.getOutputStream());
            out.println("Hallo - Willkommen beim Simple-Echo-Server!\r\n");

            boolean weiter = true;
            while (weiter) {
                String str = in.readLine();
                if (str == null)
                    weiter = false;
                else {
                    out.println("Enter ciao " + nverb + " : " + str);
                    if (str.trim().equals("ciao"))
                        weiter = false;
                }
            }
            sverb.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}