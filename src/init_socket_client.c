#include "httpd.h"

void init_client(short port, char *ip_client)
{
	/*create a socket*/
	int	clientfd = socket(AF_INET, SOCK_STREAM, 0);
	if (clientfd < 0)
		print_error("create client socket failed\n");

	struct sockaddr_in clientaddr;
	memset(&clientaddr, 0, sizeof(clientaddr));
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(port);
	inet_pton(AF_INET, (const char*)&ip_client, &clientaddr.sin_addr.s_addr);
	socklen_t len = sizeof(clientaddr);
	
	/*connect to server*/
	if (connect(clientfd, (struct sockaddr*)&clientaddr, len) < 0)
		print_error("connect to server failed.\n");

#if 0	
  /*read file*/
	char buffer[1024];
	memset (buffer, 0, sizeof(buffer));
	ssize_t n;
	if((n = read(sockfd, buffer, 1024)) < 0)
		print_error("read file from server failed");
#endif
}
