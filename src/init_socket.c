#include "httpd.h"
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
#include <arpa/inet.h>
# define BACKLOG 5

int init_socket(u_short *port)
{
	int httpdfd = 0;
	struct sockaddr_in addrserver;
	
	/*creat a socket*/
	httpdfd = socket(PF_INET, SOCK_STREAM, 0);
	if (httpdfd == -1)
	{
		/*----error handled---------*/
	}
	
	/*set ip addr and port*/
	memset(&addrserver, 0, size(addrserver));
	addrserver.sin_family = AF_INET;
	addrserver.sin_port = htons(*port);
	addrserver.sin_addr.s_addr = INADDR_ANY;

	/*bind ip and port*/
	int len = sizeof(addrserver);
	if (bind(httpdfd, (struct sockaddr*)&addrserver,len) < 0)
	{
		;/*------error handle---------*/
		exit(-1);
	}

	/*start to listen*/
	if (listen(httpdfd, BACKLOG) < 0)
	{
		;/*------error handle---------*/
		exit(-1);
	}
 
	/*accept a request*/
	while (1)
	{
		struct sockaddr_in addrclient;
		int len_client = sizeof(addrclient);
		int fd = accept(httpdfd, (struct sockaddr*)&addrclient, &len);
		if (fd < 0)
		{
			;/*-----error handle---------*/
			continue; 
			//must not exit the prog, should continue to deal next request
		}
		close(fd);
	}	
	return httpdfd;
}

