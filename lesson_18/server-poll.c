#include <stdio.h>
#include <stdlib.h> // exit();
#include <sys/socket.h>
#include <sys/un.h> // sockaddr_un
#include <unistd.h> // read?

#include <poll.h>
#include <sys/time.h>


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
    if (client_fd < 0)
    {
        perror("accept");
        exit(1);
    }

    char message[10] = {0};

    int ready_descriptor, ready_count;

    struct pollfd poll_descriptors[2] = { 0 };
    poll_descriptors[0].fd = 0;
    poll_descriptors[0].events = POLLIN;


    poll_descriptors[1].fd = client_fd;
    poll_descriptors[1].events = POLLIN;

    while(1)
    {
        ready_count = poll(poll_descriptors, 2, 10000);

        if (ready_count < 0)
        {
            perror("poll");
            exit(1);
        }

        if (ready_count > 0)
        {
            if (poll_descriptors[0].revents > 0) 
            {
                ret = read(poll_descriptors[0].fd, message, 10);
                if (ret < 0)
                {
                    perror("read");
                    exit(1);
                }
                printf("Read from stdin: %s\n", message);
            }

            if (poll_descriptors[1].revents > 0) 
            {
                ret = read(poll_descriptors[1].fd, message, 10);
                if (ret < 0)
                {
                    perror("read");
                    exit(1);
                }
                printf("Read from socket: %s\n", message);
            }
        }
        else // ready_count == 0
        {

            printf("Timeout!\n");
            break;
        }
    }


    close(client_fd);
    close(sock_fd);

    return 0;
}
