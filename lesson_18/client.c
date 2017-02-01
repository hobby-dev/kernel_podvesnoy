#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <strings.h>
#include <unistd.h> // write()

int main()
{
    int client_socket = socket( AF_UNIX, SOCK_STREAM, 0);

    if (client_socket < 0)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_un server_address = {AF_UNIX, "/tmp/my_socket"};
    
    int ret = connect(client_socket, (struct sockaddr*)&server_address, SUN_LEN(&server_address));

    if (ret < 0)
    {
        perror("connect");
        exit(1);
    }

    char message_to_server[10] = "hello";
    printf("Enter message to server: \n");
    scanf("%s", message_to_server);

    int written_bytes = write(client_socket, message_to_server, strlen(message_to_server));
    if (written_bytes <= 0)
    {
        perror("write");
        exit(1);
    }
    printf("Message sent\n");

    close(client_socket);


    return 0;
}
