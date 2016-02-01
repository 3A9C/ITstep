#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char **argv)
{
    char hexDig[16]="0123456789ABCDEF";
    int fdRandom = open ("/dev/random",O_RDONLY);

    if(O_RDONLY < 0)
    {
        write(2,"can`t open\n",11);
        return 1;
    }

    unsigned char oneByte;
    read(fdRandom,&oneByte,1);

    char buf[3];

    buf[0]= hexDig[(oneByte & 0xF0)>> 4];
    buf[1]= hexDig[oneByte & 0xF];
    buf[2]= '\n';

    write(1,buf,3);

    if(close(fdRandom))
    {
        write(2,"can`t close\n",13);
        return 1;
    }
    return 0;

}
