#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client
{
	int id;
	char msg[290000];
} t_client;

int max_fd = 0, next_id = 0;
char send_buffer[300000], recv_buffer[300000];
t_client clients[1024];
fd_set read_set, write_set, current_set;

int err(const char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error\n", 12);
	exit(1);
}

void send_to_all(int send_fd)
{
	for (int fd = 0; fd <= max_fd; fd ++)
	{
		if (FD_ISSET(fd, &write_set) && fd != send_fd)
		{
			if (send(fd, send_buffer, strlen(send_buffer), 0) < 0)
				err(NULL);
		}		
	}
}


void handle_new_connection(int server_fd)
{
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);
	int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);

	if (client_fd < 0)
		return;

	FD_SET(client_fd, &current_set);
	if(client_fd > max_fd)
		max_fd = client_fd;

	clients[client_fd].id = next_id++;
	sprintf(send_buffer, "server: client %d just arrived\n", clients[client_fd].id);
	send_to_all(client_fd);
}	


void handle_client_message(int client_fd)
{
	int bytes_received = recv(client_fd, recv_buffer, sizeof(recv_buffer) - 1, 0);

	if (bytes_received <= 0)
	{
		sprintf(send_buffer, "server: client %d just left\n", clients[client_fd].id);
		send_to_all(client_fd);
		FD_CLR(client_fd, &current_set);
		close(client_fd);
		memset(clients[client_fd].msg, 0, sizeof(clients[client_fd].msg));
		return;
	}
	recv_buffer[bytes_received] = '\0';
	
	char *start = recv_buffer, *newline;
	while ((newline = strchr(start, '\n')))
	{
		*newline = '\0';
		sprintf(send_buffer, "client %d: %s\n", clients[client_fd].id, start);
		send_to_all(client_fd);
		start = newline + 1;
	}
	strcpy(clients[client_fd].msg, start);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		err("Wrong number of arguments\n");

	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
		err(NULL);

	struct sockaddr_in server_addr = {0};
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	server_addr.sin_port = htons(atoi(argv[1]));

	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 || listen(server_fd, 100) < 0)
		err(NULL);

	FD_ZERO(&current_set);
	FD_SET(server_fd, &current_set);
	max_fd = server_fd;

	while (1)
	{
		read_set = current_set;
		write_set = current_set;

		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if(FD_ISSET(fd, &read_set))
			{
				if (fd == server_fd)
					handle_new_connection(server_fd);
				else
					handle_client_message(fd);
			}
		}
	}
	return 0;
}









