#include "parseheader.h"
#include "httpd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

/*implemetation the HTTP header
 *fd is a file content the header info
 */
void parse_header(int fd)
{
	char buf[512];
	/*---------a modifier-------getline is not pratice to use*/
	ssize_t headernum = my_getline(fd, buf, sizeof(buf));
	printf("getline: %s\n", buf);
	char *method; char *delim = " ";
  method = strtok(buf, delim);
	/*store the method into p*/
	while (method != NULL)
	{
		printf( " %s\n", method);
		break;
	}
	
	if (strcasecmp(method, "POST") == 0)
		printf("post message\n");
		;/*recieve a post message*/

	if (strcasecmp(method, "GET") == 0)
	{
		method = strtok(NULL, delim);
		while (method != NULL)
		{
			printf("uri is %s\n", method);
			break;
		}

		/*recieve a get message*/
	}

	if (strcasecmp(method, "POST") && strcasecmp(method, "GET"))
		no_service(fd);

	/*get URI web info*/
	method = strtok(NULL, delim);
	while (method != NULL)
	{
		printf("%s\n", method);
		break;
	}
	/*get version info*/
	method = strtok(NULL, delim);
	while (method != NULL)
	{
		printf("%s\n", method);
		break;
	}
}

int main(void)
{
	int fdtest = open("test", O_RDONLY | O_CREAT);
	parse_header(fdtest);
	close (fdtest);
}
