#include "client_socket.h"

int main(int argc, char *argv[]) {
	puts("Welcome client.");
	char *host = argv[1];
	char *port = argv[2];
	char *msg = strdup(argv[3]);

	// connect to server
	int fd = socket_dial(host, port);

	// send name of file
	printf("fetching %s\n", msg);
	size_t bytes = send(fd, msg, strlen(msg), 0);

	// Parse incoming header
	char buffer[BUFSIZ];
	recv(fd, buffer, 5, 0);
	buffer[5] = '\0';
	if (strcmp("FOUND", buffer)) {
		puts("ERROR: something went wrong"); // we cant tell the difference b/w the file not existing and the server crashing
		close(fd);
		free(msg);
		exit(EXIT_FAILURE);
	}

	FILE *fp = fopen(msg, "w");
	size_t byte_total = 0;
	do {
		bytes = recv(fd, buffer, BUFSIZ, 0);
		fwrite(buffer, 1, bytes, fp);
		byte_total += bytes;
	} while (bytes > 0);

	printf("SUCCESS: %zu bytes recieved\n", byte_total);

	free(msg);
	close(fd);


	return 0;
}
