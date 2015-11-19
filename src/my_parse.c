#include "httpd.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

void print_usage()
{
	printf("Usage: myHTTPd {-h | -f file [-a start|stop|restart|reload]}\n");
	exit (-1);
}

void my_parse(int opt, char* cmd[])
{
	if (opt < 2)
	{
		print_usage();
		exit (-1);
	}

	int c;
	c = getopt(opt, cmd, "f:a:h" );
	while (c != -1)
	{
		switch (c)
		{
			case 'h' : 
				print_usage();
				break;

			case 'f' :
				/*the file should be configured*/ 
				printf("f=> file is %s\n", optarg);
				break;

			case 'a' :
				if (strcmp(optarg, "start") == 0)
				{
					;/*start service http*/
				}
				if (strcmp(optarg, "stop") == 0)
				{
					;/*stop service http*/
				}
				if (strcmp(optarg, "restart") == 0)
				{
					;/*restart service http*/
				}
				if (strcmp(optarg, "reload") == 0)
				{
					;/*reload service http*/
				}
				break;

			default :
				print_usage();
				exit(0);
				break;
		}
		break;
	}
}


