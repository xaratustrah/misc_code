/*
 * Created on Apr 24, 2005
 */

/**
 * @author xara
 */

public class HardwareParser implements HardwarePortInterface {

    HardwarePortListener pl;

    public HardwareParser(RelayServer mainApplication) {
        pl = new HardwarePortListener(this, "name", "man");
    }

    public void newByteArrayIsAvailable(HardwarePortListener pl) {

    }

    public void writeByteArray(byte[] content) throws HardwarePortException {

    }
    
    public byte[] readByteArray(){
        return null;
    }
}