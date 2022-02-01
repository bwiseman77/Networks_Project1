#include "server_socket.h"

int main(int argc, char *argv[]) {
	char *port = argv[1];
	int server_fd = socket_listen(port);
	if (server_fd < 0)
		return EXIT_FAILURE;

	printf("Listening on port %s\n", port);

	while (1) {
		puts("accepting");
		int fd = socket_accept(server_fd);

		puts("handling");
		char buff[BUFSIZ];		
		int bytes = recv(fd, buff, BUFSIZ, 0);
		printf("%d bytes recv\n", bytes);
		printf("%s \n", buff);
		send(fd, "200 OK\n", 7, 0);
		close(fd);
	}
	
		
}
