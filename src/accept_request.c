#include "httpd.h"

void accept_request(int httpdfd)
{
  /*accept a request*/
  while (1)
  {
    struct sockaddr_in addrclient;
    socklen_t len_client = sizeof(addrclient);
    int fd = accept(httpdfd, (struct sockaddr *)&addrclient, &len_client);
    if (fd < 0)
    {
      print_error("Error:accept request failed.");
      continue; 
      //must not exit the prog, should continue to deal next request
    }
		/*----a completer--what does it do when recieve a request-----*/
    close(fd);
  } 
}
