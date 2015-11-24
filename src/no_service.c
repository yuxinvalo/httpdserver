#include "httpd.h"

/*recieve a request but the method has not been implemented*/
void no_service(int fd_client)
{
	char buf[1024];

	sprintf(buf, "%s%s dosen't support such a method\r\n", VERSION, SERVER);
	send(fd_client, buf, strlen(buf), 0);

	sprintf(buf, "<HTML><HEAD><TITLE>\
	%s error </TITLE></HEAD><BODY>we didn't implement this method \
	</BODY></HTML>", SERVER);
	send(fd_client, buf, strlen(buf), 0);
}
