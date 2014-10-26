/*
 * Netz01.java
 *
 * Created on March 30, 2004, 10:41 PM
 */

/**
 *
 * @author  xara
 */
import java.net.*;
public class Netz01 {
    public static void main(String[] ip) {
        if (ip[0] == null){
            System.out.println(" ");
            System.exit(1);
        }
        try {
            InetAddress host = InetAddress.getByName(ip[0]);
            System.out.println(host.getHostName());
            System.out.println(host.getHostAddress());
        }
        catch(UnknownHostException e) {
            System.out.println(e.toString());
        }
    }
    
}
