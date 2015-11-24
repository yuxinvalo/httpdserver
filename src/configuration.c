#include "configuration.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"


void parse_line(struct config *config, char *buf)
{
  printf("parsingline\n");
  char *val = strtok(buf," ");
  if (strcmp(val, "port") == 0)
    {
      printf("found port \n");

      if(strcmp(strtok(NULL, " "), "=") == 0)
        config->port = atoi(strtok(NULL," "));
    }
  else if (strcmp(val, "root-dir") == 0)
    {
      if(strcmp(strtok(NULL, " "), "=") == 0)
        config->root_dir = strtok(NULL," ");
    }
  else if (strcmp(val, "pid-file") == 0)
    {
      if(strcmp(strtok(NULL, " "), "=") == 0)
        config->pid_file = strtok(NULL," ");
    }
  else if (strcmp(val, "log-file") == 0)
    {
      if(strcmp(strtok(NULL, " "), "=") == 0)
        config->log_file = strtok(NULL," ");
    }
}

struct config *configuration(char *path)
{
  char buffer[500];
  FILE *file;
  struct config *config = malloc(sizeof (config));
  file = fopen(path, "r");
  if (file)
    {
      while(fgets(buffer, sizeof buffer, file))
        {
          parse_line(config, buffer);
        }
    }
    

  return config;
}
