/*
 * Created on Apr 24, 2005
 */

/**
 * @author xara
 *  
 */

public interface HardwarePortInterface {

    public byte[] readByteArray();

    public void writeByteArray(byte[] content) throws HardwarePortException;
}