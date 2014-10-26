
import java.util.Vector;
import java.util.Iterator;

public class Vector2ByteArray {
     public byte[] getByteArray(Vector vectorOfByteObjects) {

	  Iterator it = vectorOfByteObjects.iterator();
	  byte[] array = new byte[vectorOfByteObjects.size()];
	  int index = 0;
	  while (it.hasNext()) {
	       Byte b = (Byte) it.next();
	       array[index] = b.byteValue();
	       index++;
	  }
	  vectorOfByteObjects.removeAllElements();
	  return array;
     }
}

