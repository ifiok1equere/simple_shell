#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void prompt(void);
char *read_input(void);
char *_strdup(char *source);
char **tokenize(char *command, char *delim);
void frees(char **argv, char **envp);
char *_getenv(const char *name);
char **new_env(void);
char *path_finder(char **argv);
void execute(char **argv);
void frees1(char **argv);
void errors(char *argv);
int set_env(char **argv, char **e);
int unset_env(char **argv, char **e);
#endif
