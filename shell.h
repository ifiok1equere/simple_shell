#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
extern char ** environ;
char **tokenize(char *command, char *delim);
void execute(char **argv);
char *prompt(void);
void frees(char **argv);
char *_strtok(char *str, char *delim);
char *_strchr(char *str, char c);
char **new_env(void);
char *_getenv(const char *name);
#endif
