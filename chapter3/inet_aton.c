#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void error_handling(char *message);

/**
 * inet_aton函数与inet_addr函数在功能上完全相同
 * 将字符串形式的IP地址转换为32位网络字节序整数并返回
 * 成功返回1， 失败返回0
 * 
 * struct sockaddr_in
 * {
 *      sa_family_t sin_family; // 地址族
 *      uint16_t    sin_port; // 16位TCP/IP端口号
 *      struct in_addr  sin_addr; // 32位IP地址
 *      char sin_zero[8];   // 不使用
 * }
 * 
 * struct in_addr
 * {
 *      in_addr_t   s_addr;     // 32位IPv4地址
 * }
*/
int main(int argc, char *argv[])
{
    char *addr="127.232.124.79";

    struct sockaddr_in addr_inet;
    if (!inet_aton(addr, &addr_inet.sin_addr))
        error_handling("Conversion error");
    else
        printf("Network ordered integer addr:  %#x \n", addr_inet.sin_addr.s_addr);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}