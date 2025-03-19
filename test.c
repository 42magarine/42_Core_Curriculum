#include <stdio.h>      // sprintf
#include <unistd.h>     // write, close
#include <stdlib.h>     // malloc, realloc, free, calloc, atoi, exit
#include <string.h>     // strstr, bzero, strlen, strcpy, strcat, memset
#include <sys/select.h> // select
#include <sys/socket.h> // socket, accept, listen, send, recv, bind, struct sockaddr
#include <netinet/in.h> // struct sockaddr_in
#include <arpa/inet.h>  // htonl, htons
#include <stdbool.h>    // true

void putstr_error(char* message) {
    while (*message != '\0') {
        write(STDERR_FILENO, message, 1);
        message++;
    }
    exit(1);
}

int main(int argc, char** argv) {
    int server_fd, client_fd, max_fd;
    short port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    fd_set read_fds, write_fds, except_fds;

    if (argc != 2) {
        putstr_error("Wrong number of arguments\n");
    }

    else {
        port = atoi(argv[1]);
        if (port == 0) {
            putstr_error("Fatal error - atoi\n");
            exit (1);
        }
    }

    // int socket(int domain, int type, int protocol);
    // AF_INET      IPv4 Internet protocols
    // SOCK_STREAM  Provides sequenced, reliable, two-way, connection-based byte streams
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        putstr_error("Fatal error - socket\n");
        exit (1);
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
    server_addr.sin_port = htons(port);                     // host to network short
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);   // host to network long

    // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    if (bind(server_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        putstr_error("Fatal error - bind\n");
        exit (1);
    }
    // int listen(int sockfd, int backlog);
    if (listen(server_fd, 10) == -1) {
        putstr_error("Fatal error - listen\n");
        exit (1);
    }

    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);
    FD_ZERO(&except_fds);

    FD_SET(server_fd, &read_fds);
    max_fd = server_fd;

    while (true) {
        // int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
        if (select(max_fd + 1, &read_fds, &write_fds, &except_fds, NULL) == -1) {
            putstr_error("Fatal error - select\n");
            exit (1);
        }

        if (FD_ISSET(server_fd, &read_fds) != 0){
            // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
            client_addr_size = sizeof(client_addr);
            client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_size);
            if (client_fd == -1) {
                putstr_error("Fatal error - accept\n");
                exit (1);
            }

            FD_SET(client_fd, &read_fds);
            FD_SET(client_fd, &write_fds);
            FD_SET(client_fd, &except_fds);

            if (client_fd > max_fd) {
                max_fd = client_fd;
            }

            char buffer[1024];
            recv(client_fd, buffer, sizeof(buffer), 0);
            printf("recv: %s",buffer);

            // ssize_t send(int sockfd, const void buf[.size], size_t size, int flags);
            const char* msg = "Hello Client\n";
            send(client_fd, msg, sizeof(msg), 0);
            // close (client_fd);
        }
    }

    close (server_fd);

    return 0;
}
