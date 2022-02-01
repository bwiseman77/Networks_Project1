#include "client_socket.h"

int main(int argc, char *argv[]) {
	puts("hello client");
	char *host = argv[1];
	char *port;
	if (argc == 3) {
		port = argv[2];
	} else {
		port = NULL;
	}
	int fd = socket_dial(host, port);

	char *msg = "Hello there! how are you \0";
	int bytes = send(fd, msg, strlen(msg), 0);
	printf("%d bytes sent\n", bytes);
	char buff[BUFSIZ];
	bytes = recv(fd, buff, BUFSIZ, 0);
	printf("%d revc: %s\n", bytes, buff);
	
	
	return 0;
}

