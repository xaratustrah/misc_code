
public class intArray{

     public intArray(){}

     public static byte [] concatByteArray (byte [] first, byte [] second){
	  byte temp[] = new byte[first.length + second.length];
	  for (int i =0; i<= first.length - 1; i++){
	       temp[i] = first [i];
	  }
	  for (int i =0; i<= second.length - 1; i++){
	       temp[first.length + i] = first [i];
	  }

	  return temp;
     }

     public static void main (String args []){

	  byte a[] = {'1','2','3'};
	  byte b[] = {'4','5','6'};
	  System.out.println("separate " + new String (a) + new String (b) );
	  byte c[] = concatByteArray (a , b);
	  System.out.println("together " + new String (c));

     }
}
