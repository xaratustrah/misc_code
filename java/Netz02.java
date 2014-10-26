/*
 * Netz02.java
 *
 * Created on March 30, 2004, 10:52 PM
 */

/**
 *
 * @author  xara
 */
import java.io.*;
import java.net.*;

public class Netz02 {
    public static void main(String ip[]) {
        if (ip[0] == null){
            System.out.println(" ");
            System.exit(1);
        }
        try{
            Socket s = new Socket("127.0.0.1", 13);
            BufferedReader is = new BufferedReader(new InputStreamReader(s.getInputStream()));
            boolean weiter = true;
            String str;
            while ((str = is.readLine())!= null){
                System.out.println(str);
            }
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }
}
