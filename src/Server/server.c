#include "server_socket.h"

int main(int argc, char *argv[]) {
	char *port = argv[1];
	int server_fd = socket_listen(port);
	if (server_fd < 0)
		return EXIT_FAILURE;

	printf("Listening on port %s\n", port);

	while (1) {

		puts("\nwaiting for client");
		int fd = socket_accept(server_fd);

		puts("accepted connection");

 		char buffer[BUFSIZ];
		size_t bytes = recv(fd, buffer, BUFSIZ-1, 0);
		buffer[bytes] = '\0';

		printf("fetching file: %s\n", buffer);

		// send header
		FILE *fp = fopen(buffer, "r");
		if (fp == NULL) {
			fprintf(stderr, "ERROR: Requested file not found\n");
			send(fd, "ERROR: Requested file not found", 31, 0);
			continue;
		}
		send(fd, "FOUND", 5, 0);

		// send file
		size_t byte_total = 0;
		do {
			bytes = fread(buffer, 1, BUFSIZ, fp);
			send(fd, buffer, bytes, 0);
			byte_total += bytes;
		} while (bytes > 0);

		printf("SUCCESS: %zu bytes sent\n", byte_total);

		close(fd);

	}


}
