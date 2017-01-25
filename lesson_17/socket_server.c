#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{

    struct sockaddr_in incoming_socket_addr = {0};
    incoming_socket_addr.sin_family = AF_INET;
    incoming_socket_addr.sin_port = htons(5001);
    if (inet_aton("127.0.0.1", &incoming_socket_addr.sin_addr) == 0)
    {
        perror("inet_aton");
        exit(1);
    }

    const int incoming_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    const int rc = bind(incoming_socket_fd, (struct sockaddr *) &incoming_socket_addr, sizeof(incoming_socket_addr));
    if (rc == -1)
    {
        perror("bind");
        close(incoming_socket_fd);
        exit(1);
    }

    if (listen(incoming_socket_fd, 1024) != 0)
    {
        perror("listen");
        exit(1);
    }

    char buf[1024];
    while(1)
    {
        struct sockaddr_in client_socket_addr;
        socklen_t addrlen = sizeof(client_socket_addr);
        int acceptrc = accept(incoming_socket_fd, (struct sockaddr *) &client_socket_addr, &addrlen);
        if (acceptrc == -1)
        {
            perror("accept");
            close(incoming_socket_fd);
            exit(1);
        }
        printf("Connected client: %s\n", inet_ntoa(client_socket_addr.sin_addr));
        read(acceptrc, buf, sizeof(buf));
        printf("Data: %s\n", buf);
        close(acceptrc);
    }

    close(incoming_socket_fd);

    return 0;
}
