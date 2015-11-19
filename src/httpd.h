#ifdef HTTPD_H
# define HTTPD_H
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <getopt.h>

# define PORT 80 //web port
# define 	BACKLOG 5 //how many pending connections queue will hold
int init_socket(u_short *);
void usage();
void my_parse(int opt, char* cmd[]);


/*my function*/
char *my_strcpy(char *dst, const char* src);
int my_strcmp(const char* dst, const char* src);

#endif /*HTTPD_H*/
