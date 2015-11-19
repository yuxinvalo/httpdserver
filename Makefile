CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra
OBJS = src/httpd.c src/my_parse.c 
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
