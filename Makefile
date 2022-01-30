CC= 		gcc
CFLAGS= 	-g -Wall -std=gnu99
TARGETS= 	bin/proj1server bin/proj1client

all: 		$(TARGETS)

src/Server/server.o: src/Server/server.c
	$(CC) $(CFLAFS) -c -o $@ $^

src/Client/client.o: src/Client/client.c
	$(CC) $(CFLAGS) -c -o $@ $^

bin/proj1client: src/Client/client.o
	$(CC) $(CFLAGS) -o $@ $^

bin/proj1server: src/Server/server.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm src/*/*.o $(TARGETS)
