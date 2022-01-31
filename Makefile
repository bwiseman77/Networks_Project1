CC= 		gcc
CFLAGS= 	-g -Wall -std=gnu99
TARGETS= 	proj1server proj1client

all: 		$(TARGETS)

src/Server/%.o: src/Server/%.c
	$(CC) $(CFLAFS) -c -o $@ $^

src/Client/%.o: src/Client/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

proj1client: src/Client/client.o src/Client/socket.o
	$(CC) $(CFLAGS) -o $@ $^

proj1server: src/Server/server.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm src/*/*.o $(TARGETS)
