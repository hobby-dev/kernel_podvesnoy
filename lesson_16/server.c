#include <stdio.h>
#include <stdlib.h> // exit();
#include <sys/socket.h>
#include <sys/un.h> // sockaddr_un
#include <unistd.h> // read?
// #include <sys/types.h> // sockaddr?

#define MAX_CLIENTS 100500

int main()
{
    unlink("/tmp/my_socket");
    int sock_fd = 0;

    sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un our_addr = {AF_UNIX, "/tmp/my_socket"};
    
    int ret = bind( sock_fd, (struct sockaddr*)&our_addr, SUN_LEN(&our_addr)); 
    if (ret < 0)
    {
        perror("bind");
    };

    ret = listen(sock_fd, MAX_CLIENTS);

    struct sockaddr_un client_info;
    int client_info_len = sizeof(client_info);

    int client_fd = accept(sock_fd, (struct sockaddr *)&client_info, &client_info_len);

    char message[10] = {0};
    ret = read(client_fd, message, 10);

    if (ret < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Message received: %s\n", message);

    close(client_fd);
    close(sock_fd);

    return 0;
}
