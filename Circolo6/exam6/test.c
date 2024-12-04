#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client {
    int id;
    char msg[400000];
} t_client;

t_client clients[1024];
fd_set current, read_set, write_set;
int max_fd = 0, next_id = 0;

void fatal_error(const char *msg) {
    write(2, msg, strlen(msg));
    exit(1);
}

void send_to_all(int sender_fd, const char *msg) {
    for (int fd = 0; fd <= max_fd; fd++) {
        if (FD_ISSET(fd, &write_set) && fd != sender_fd)
            send(fd, msg, strlen(msg), 0);
    }
}

void handle_client_message(int client_fd) {
    char recv_buffer[400000];
    int bytes_received = recv(client_fd, recv_buffer, sizeof(recv_buffer) - 1, 0);

    if (bytes_received <= 0) {
        sprintf(recv_buffer, "server: client %d just left\n", clients[client_fd].id);
        send_to_all(client_fd, recv_buffer);
        FD_CLR(client_fd, &current);
        close(client_fd);
    } else {
        recv_buffer[bytes_received] = '\0';
        char *start = recv_buffer, *newline;
        while ((newline = strchr(start, '\n'))) {
            *newline = '\0';
            char send_buffer[400000];
            sprintf(send_buffer, "client %d: %s\n", clients[client_fd].id, start);
            send_to_all(client_fd, send_buffer);
            start = newline + 1;
        }
        strcpy(clients[client_fd].msg, start);
    }
}


int main(int argc, char **argv) {
    if (argc != 2)
        fatal_error("Wrong number of arguments\n");

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        fatal_error("Fatal error\n");

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 || listen(server_fd, 100) < 0)
        fatal_error("Fatal error\n");

    FD_ZERO(&current);
    FD_SET(server_fd, &current);
    max_fd = server_fd;

    while (1) {
        read_set = current;
        write_set = current;
        if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) < 0) continue;

        for (int fd = 0; fd <= max_fd; fd++) {
            if (!FD_ISSET(fd, &read_set)) continue;

            if (fd == server_fd) {
                int client_fd = accept(server_fd, NULL, NULL);
                if (client_fd < 0) continue;
                clients[client_fd].id = next_id++;
                FD_SET(client_fd, &current);
                max_fd = (client_fd > max_fd) ? client_fd : max_fd;

                char msg[100];
                sprintf(msg, "server: client %d just arrived\n", clients[client_fd].id);
                send_to_all(client_fd, msg);
            } else {
                handle_client_message(fd);
            }
        }
    }

    return 0;
}
