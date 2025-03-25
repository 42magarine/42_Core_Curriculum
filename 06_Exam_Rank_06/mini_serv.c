#include <stdio.h>      // sprintf
#include <unistd.h>     // write, close
#include <stdlib.h>     // malloc, realloc, free, calloc, atoi, exit
#include <string.h>     // strstr, bzero, strlen, strcpy, strcat, memset
#include <sys/select.h> // select
#include <sys/socket.h> // socket, accept, listen, send, recv, bind, struct sockaddr
#include <netinet/in.h> // struct sockaddr_in
#include <arpa/inet.h>  // htonl, htons
#include <stdbool.h>    // true

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

typedef struct s_client {
    int id;
    int fd;
    char *buffer;
    struct s_client *next;
} t_client;

t_client* g_client_list = NULL;
fd_set g_read_fds, g_write_fds, g_aktive_fds;

void print_error(char* error_message) {
    write(STDERR_FILENO, error_message, strlen(error_message));
}

void my_exit(void) {
    t_client *temp;

    while (g_client_list != NULL) {
        temp = g_client_list;
        g_client_list = g_client_list->next;
        close(temp->fd);
        free(temp->buffer);
        free(temp);
    }
    exit(1);
}

void broadcast_message(int sender_fd, char *message) {
    t_client *temp = g_client_list;

    while (temp) {
        if (temp->fd != sender_fd && FD_ISSET(temp->fd, &g_write_fds)) {
            // ssize_t send(int sockfd, const void buf[.size], size_t size, int flags);
            send(temp->fd, message, strlen(message), 0);
        }
        temp = temp->next;
    }
}

void add_client(int fd) {
    static int id_counter = 0;

    t_client *client = malloc(sizeof(t_client));
    if (client == NULL) {
        print_error("Fatal error\n");
        my_exit();
    }

    client->id = id_counter++;
    client->fd = fd;
    client->buffer = NULL;
    client->next = g_client_list;
    g_client_list = client;

    FD_SET(fd, &g_aktive_fds);

    char message[50];
    sprintf(message, "server: client %d just arrived\n", client->id);
    broadcast_message(fd, message);
}

void remove_client(int fd) {
    t_client* previous = NULL;
    t_client* temp = g_client_list;

    while (temp != NULL) {
        if (temp->fd == fd) {
            char message[50];
            sprintf(message, "server: client %d just left\n", temp->id);
            broadcast_message(fd, message);

            if (previous != NULL) {
                previous->next = temp->next;
            }
            else {
                g_client_list = temp->next;
            }

            close(temp->fd);
            free(temp->buffer);
            free(temp);
            FD_CLR(fd, &g_aktive_fds);
            return;
        }
        previous = temp;
        temp = temp->next;
    }
}

void handle_client_message(t_client *client, char *buffer) {
    client->buffer = str_join(client->buffer, buffer);

    char *message = NULL;
    while (extract_message(&client->buffer, &message)) {
        char* extract_message;
        extract_message = malloc(strlen(message) + 15 + 1);
        if (extract_message == NULL) {
            print_error("Fatal error\n");
            my_exit();
        }
        sprintf(extract_message, "client %d: %s", client->id, message);
        broadcast_message(client->fd, extract_message);
        free(extract_message);
        free(message);
    }
}

int main(int argc, char** argv) {
    int server_fd, client_fd, port, nfds;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    if (argc != 2) {
        print_error("Wrong number of arguments\n");
        my_exit();
    }

    port = atoi(argv[1]);
    if (port == 0) {
        print_error("Fatal error\n");
        my_exit();
    }

    // int socket(int domain, int type, int protocol);
    // AF_INET      IPv4 Internet protocols
    // SOCK_STREAM  Provides sequenced, reliable, two-way, connection-based byte streams
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        print_error("Fatal error\n");
        my_exit();
    }

    // struct sockaddr_in {
    //     sa_family_t     sin_family;     /* AF_INET */
    //     in_port_t       sin_port;       /* Port number */
    //     struct in_addr  sin_addr;       /* IPv4 address */
    // };
    // sockaddr_in
    // Describes an IPv4 Internet domain socket address.
    // The sin_port and sin_addr members are stored in network byte order.
    // 127.0.0.1 =
    //  127 * (256^3) +
    //    0 * (256^2) +
    //    0 * (256^1) +
    //    1 * (256^0) = 2130706433 (decimal) = 0x7F000001 (hex)
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);   // host to network long
    server_addr.sin_port = htons(port);                     // host to network short

    // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    if (bind(server_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("Fatal error\n");
        my_exit();
    }

    // int listen(int sockfd, int backlog);
    if (listen(server_fd, 10) == -1) {
        print_error("Fatal error\n");
        my_exit();
    }

    FD_ZERO(&g_aktive_fds);
    FD_SET(server_fd, &g_aktive_fds);

    while (true) {
        nfds = server_fd;
        for (t_client *temp = g_client_list; temp != NULL; temp = temp->next) {
            if (temp->fd > nfds) {
                nfds = temp->fd;
            }
        }

        g_read_fds = g_aktive_fds;
        g_write_fds = g_aktive_fds;

        // int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
        if (select(nfds + 1, &g_read_fds, &g_write_fds, NULL, NULL) == -1) {
            continue;
        }

        if (FD_ISSET(server_fd, &g_read_fds) != 0) {
            memset(&client_addr, 0, sizeof(client_addr));
            // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
            client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_size);
            if (client_fd == -1) {
                print_error("Fatal error\n");
                my_exit();
            }
            add_client(client_fd);
        }

        t_client *temp = g_client_list;
        t_client *next;

        while (temp != NULL) {
            next = temp->next;
            if (FD_ISSET(temp->fd, &g_read_fds) != 0) {
                char buffer[1024] = {0};
                int nbytes = recv(temp->fd, buffer, 1023, 0);
                if (nbytes == 0) {
                    remove_client(temp->fd);
                }
                else {
                    buffer[nbytes] = '\0';
                    handle_client_message(temp, buffer);
                }
            }
            temp = next;
        }
    }
    return 0;
}
