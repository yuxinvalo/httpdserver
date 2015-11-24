CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra
OBJS = src/httpd.c src/my_parse.c src/init_socket.c src/configuration.c \
			 src/accept_request.c src/my_getline.c src/init_socket_client.c
BIN = test

all: httpd

clean:
	rm -f $ myHTTPd
	rm -rf *.o

httpd:
	$(CC) $(CFLAGS) -o myHTTPd  $(OBJS)

check:
	$(CC) $(CFLAGS) -o test tests/main.c
	./$(BIN)

doc :


.PHONY: all clean httpd 
