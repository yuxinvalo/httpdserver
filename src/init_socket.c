#include "httpd.h"

/*output an error info in stderr*/
void print_error (const char *err_info)
{
  perror(err_info);
  exit(1);
}

int init_socket(short *port)
{
	int httpdfd = 0;
	struct sockaddr_in addrserver;
	
	/*create a socket*/
	httpdfd = socket(PF_INET, SOCK_STREAM, 0);
	if (httpdfd == -1)
	{
		print_error("create socket failed.");
	}
	/*set ip addr and port*/
	memset(&addrserver, 0, sizeof(addrserver));
	addrserver.sin_family = AF_INET;
	addrserver.sin_port = htons(*port);
	addrserver.sin_addr.s_addr = INADDR_ANY;
	printf("set ip\n");
	/*bind ip and port*/
	int len = sizeof(addrserver);
	if (bind(httpdfd, (struct sockaddr*)&addrserver,len) < 0)
	{
		print_error("Error:bind socket failed.");
	}
	/*start to listen*/
	if (listen(httpdfd, BACKLOG) < 0)
	{
		print_error("Error:listen requests failed.");
	}
	return httpdfd;
}

