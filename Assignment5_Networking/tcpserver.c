// Compile with: gcc tcpserver.c -o tcpserver
//
// Implement tcp server below.

// Our standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some types and unix operations
#include <sys/types.h>
#include <unistd.h>

// A sockets library and internet protocol library
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>

//Calling sub-file

int command(char *cmmd);

int main() {

    // Create the server socket
    int server_socket;
    //            domain, type         ,protocol
    // domain = AF_INET(IPv4) or AF_INET6
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address format
    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(3003); // 9002 is choosen arbitrarily. Try other ports if this does not work
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    printf("Server bind()\n");

    //Step 5 – Listening
    listen(server_socket, 27);

    // Integer to hold a potential client socket
    int client_socket;
    while (1) {
        client_socket = accept(server_socket, NULL, NULL);

        // send a message from the server
        char server_message[256] = "You have reached the server";

        send(client_socket, server_message, sizeof(server_message), 0);
        printf("Client joined: ", server_message);

        //Allocating memory – malloc
        char *client_username = malloc(sizeof(char) * 128);
        recv(client_socket, client_username, sizeof(client_username), 0);
        printf(">%s\n", client_username);

        //Another loop
        while (1) {

            char *client_command = malloc(sizeof(char) * 128);
            recv(client_socket, client_command, sizeof(client_command), 0);
            printf("%s\n", client_command);
            if (strcmp("exit", client_command) == 0) {
                free(client_command);
                break;
            }
            system(client_command);
            free(client_command);
        }
        free(client_username);
    }


    // Close the socket
    close(server_socket);

    return 0;

}

//Sub-file

int command(char *cmmd) {

    if (fork() == 0) {
        system(cmmd);
        exit(1);
    } else {
        wait(NULL);
        return 1;
    }
}
