#include <stdio.h>
#include <arpa/inet.h>

/**
 * inet_addr
 * 成功返回32位大端序整数型值，失败返回INADDR_NONE
 * inet_addr不仅可以把IP地址转成32位整数型，而且可以检测无效的IP地址
*/
int main(int argc, char *argv[])
{
    char *addr1 = "1.2.3.4";
    char *addr2 = "1.2.3.256";

    unsigned long conv_addr = inet_addr(addr1);
    if (conv_addr == INADDR_NONE)
        printf("Error occured! \n");
    else
        printf("Network ordered integer addr: %#lx \n", conv_addr);

    conv_addr = inet_addr(addr2);
    if (conv_addr == INADDR_NONE)
        printf("Error occureded \n");
    else
        printf("Network ordered integer addr: %#lx \n\n", conv_addr);
    return 0;
}