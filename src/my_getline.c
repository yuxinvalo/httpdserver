#include "parseheader.h"
#include "httpd.h"

ssize_t my_getline(int fd, char *buf, int size)
{
	char c[1];
	int i = 0;
	if (fd < 0)
	{
	//	print_error("open file to getline error.\n");
	} 
	else
	{
		while(i < size && read(fd, c, 1))
		{
			
			if (*c == '\n' || (*c == '\n' && *(c + 1) == '\r'))
			{
				*(buf + i) = '\0';
				break;
				/*--------a modifier ---------*/
			}
		  *(buf + i) = *c;
			i++;
		}
	}
return i;
}

