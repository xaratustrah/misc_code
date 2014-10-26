/*
 * Created on Apr 15, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

/**
 * @author xara
 * 
 * TODO To change the template for this generated type comment go to Window -
 * Preferences - Java - Code Style - Code Templates
 */
public class intArray {

    public static byte[] concatByteArray(byte[] first, byte[] second) {

        byte temp[] = new byte[first.length + second.length];
        for (int i = 0; i <= first.length - 1; i++) {
            temp[i] = first[i];
        }
        for (int i = 0; i <= second.length - 1; i++) {
            temp[first.length + i] = second[i];
        }

        return temp;
    }

    public static byte[] getSubArray(byte[] input, int offset, int length) {
        byte temp[] = new byte[length];
        int j = 0;
        for (int i = offset; i <= offset + length - 1; i++) {
            temp[j] = input[i];
            j++;
        }
        return temp;
    }

    public static void main(String[] args) {

        byte[] e = { '1', '2', '3', '4', '5', '6' };

        //byte[] c = new byte[0];
        /*
         * byte a[] = { '1', '2', '3' }; byte b[] = { '4', '5', '6' }; byte d[] =
         * new byte[0]; System.out.println("separate " + new String(a) + new
         * String(b)); c = concatByteArray(c, b); System.out.println(new
         * String(c));
         */
        //c = concatByteArray(c, concatByteArray(a, b));
        byte [] f = getSubArray(e, 2, 2);
        System.out.println("Sub: " + new String(f));

    }

}