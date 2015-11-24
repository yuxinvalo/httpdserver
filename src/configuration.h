#ifndef CONFIGURATION_H
#define CONFIGURATION_H

struct config
{
  int port;
  char *root_dir;
  char *pid_file;
  char *log_file;
};

struct config *configuration(char *path);

#endif /* !CONFIGURATION_H */
