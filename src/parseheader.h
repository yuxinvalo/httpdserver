#ifndef _PARSEHEADER_
# define _PARSEHEADER_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>

ssize_t my_getline(int fd, char *buf, int size);
void parse_header(int fd);

#endif /*_PARSE_HEADER_*/
