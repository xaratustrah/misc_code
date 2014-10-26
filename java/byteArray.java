import java.util.Random;
 
public class byteArray {

/*
 * Created on 12.12.2004
 *
 * 
 */

     /**
      * Converts byte[] to a readable Hex-string-representation
      * @param byte-array
      * @return hexadecimal strings
      * @author Ulf Blanke
      */

     public static String byteArrayToHexString(byte in[]) {
	  byte ch = 0x00;
	  int i = 0; 
	  if (in == null || in.length <= 0)
	       return null;
	  String pseudo[] = {"0", "1", "2",
			     "3", "4", "5", "6", "7", "8",
			     "9", "A", "B", "C", "D", "E",
			     "F"};
	  StringBuffer out = new StringBuffer(in.length * 2);
	  out.append("0x");
	  while (i < in.length) {
	       ch = (byte) (in[i] & 0xF0);   // Strip off high nibble
	       ch = (byte) (ch >>> 4);       // shift the bits down
	       ch = (byte) (ch & 0x0F);      //	 must do this is high order bit is on!
	       out.append(pseudo[ (int) ch]); // convert the	nibble to a String Character
	       ch = (byte) (in[i] & 0x0F); // Strip off	low nibble 
	       out.append(pseudo[ (int) ch]); // convert the	nibble to a String Character
	       i++;
	  }
	  String result = new String(out);
	  return result;
     }    
     /**
      * Converts a hex-String ("A5F2") into a byte[]-array
      * @param hex the hexcode in string representation
      * @return the corresponding byte[] array
      */

     public static byte[] hexStringToByteArray(String hex) {
	  byte bytKey[] = new byte[(hex.length() / 2)];
	  int y= 0;
	  String strbyte;

	  for (int x=0; x < bytKey.length; x++) {
	       strbyte = hex.substring(y, (y + 2));
	       if (strbyte.equals("FF")) {
		    bytKey[x] = (byte) 0xFF;
	       }
	       else {
		    try {
			 bytKey[x] = (byte) Integer.parseInt(strbyte, 16);
		    }
		    catch (NumberFormatException e){
			 System.out.println("HexStringToByteArray Failed ");
		    }
	        
	       }

	       y = y + 2;
	  }
	  return bytKey;
     }
	
     public static void main (String args[]){

	  byte c = (byte) 'V';
	  byte b = (byte) 255;
	  byte [] dummy = new byte [2];

	  dummy[0] = c;
	  dummy[1] = b;

	  System.out.println(dummy);

	  System.out.println(byteArrayToHexString(dummy));

	  return;
     }

}
