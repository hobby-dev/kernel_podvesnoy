#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define LEN 10

int main()
{
    const int socket_fd = socket(AF_INET, SOCK_STREAM, 0); 

    struct sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_port = htons(5001);
    if (inet_aton("192.168.1.108", &address.sin_addr) == 0)
    {
        perror("inet_aton");
        exit(1);
    }

    
    if (connect(socket_fd, (struct sockaddr*) &address, sizeof(address)) != 0)
    {
        perror("connect");
        exit(1);
    }
    
    while(1)
    {
        const char buf[LEN] = "hello  11 ";
        if (write(socket_fd, &buf, LEN) != LEN)
        {
            perror("write");
            exit(1);
        }
    }

    return 0;
}
