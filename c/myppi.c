#include <ctype.h>
#include <dev/ppbus/ppbconf.h>
#include <dev/ppbus/ppi.h>

int main()
{

     int fd;
     u_int8_t val;
     val = 0x5a;
     ioctl(fd, PPISDATA, &val);
     ioctl(fd, PPIGCTRL, &val);
     val |= STROBE;
     ioctl(fd, PPISCTRL, &val);
     val &= ~STROBE;
     ioctl(fd, PPISCTRL, &val);

}



