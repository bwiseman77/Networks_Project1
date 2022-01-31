#include "socket.h"
#include <stdio.h>



int main(int argc, char *argv[]) {
	puts("hello client");
	char *host = argv[1];
	char *port;
	if (argc == 3) {
		port = argv[2];
	} else {
		port = NULL;
	}
	int socket_fd = socket_dial(host, port);
	if (socket_fd != -1)
		close(socket_fd);
}

