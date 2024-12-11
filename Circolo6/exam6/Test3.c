#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Client structure to hold ID and message buffer
typedef struct s_client {
    int id;
    char msg[300000];
} t_client;

// Global variables
t_client clients[1024];
fd_set current_set, read_set, write_set;
int max_fd = 0, next_id = 0;
char send_buffer[300000], recv_buffer[300000];

// Error handling function
void err(const char *msg) {
    if (msg)
        write(2, msg, strlen(msg));
    else
        write(2, "Fatal error\n", 12);
    exit(1);
}

// Broadcast message to all clients except the sender
void send_to_all(int sender_fd) {
    for (int fd = 0; fd <= max_fd; fd++) {
        if (FD_ISSET(fd, &write_set) && fd != sender_fd) {
            if (send(fd, send_buffer, strlen(send_buffer), 0) < 0)
                err(NULL);
        }
    }
}

// Handle new client connection
void handle_new_connection(int server_fd) {
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);

    if (client_fd < 0)
        return;

    // Add client to the set and assign an ID
    FD_SET(client_fd, &current_set);
    if (client_fd > max_fd) max_fd = client_fd;

    clients[client_fd].id = next_id++;
    sprintf(send_buffer, "server: client %d just arrived\n", clients[client_fd].id);
    send_to_all(client_fd);
}

// Handle client messages
void handle_client_message(int client_fd) {
    int bytes_received = recv(client_fd, recv_buffer, sizeof(recv_buffer) - 1, 0);

    // Client disconnect
    if (bytes_received <= 0) {
        sprintf(send_buffer, "server: client %d just left\n", clients[client_fd].id);
        send_to_all(client_fd);
        FD_CLR(client_fd, &current_set);
        close(client_fd);
        memset(clients[client_fd].msg, 0, sizeof(clients[client_fd].msg));
        return;
    }

    // Null-terminate received data
    recv_buffer[bytes_received] = '\0';

    // Process each line in the message
    char *start = recv_buffer, *newline;
    while ((newline = strchr(start, '\n'))) {
        *newline = '\0';
        sprintf(send_buffer, "client %d: %s\n", clients[client_fd].id, start);
        send_to_all(client_fd);
        start = newline + 1;
    }

    // Save remaining partial message
    strcpy(clients[client_fd].msg, start);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2)
        err("Wrong number of arguments\n");

    // Server setup
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        err(NULL);

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 ||
        listen(server_fd, 100) < 0)
        err(NULL);

    // Initialize sets
    FD_ZERO(&current_set);
    FD_SET(server_fd, &current_set);
    max_fd = server_fd;

    while (1) {
        read_set = write_set = current_set;

        if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) < 0)
            continue;

        for (int fd = 0; fd <= max_fd; fd++) {
            if (FD_ISSET(fd, &read_set)) {
                if (fd == server_fd) {
                    handle_new_connection(server_fd);
                } else {
                    handle_client_message(fd);
                }
            }
        }
    }
    return 0;
}