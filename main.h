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

# define ERROR1 "check number of arguments passed\n"
# define VAR "variable does not exist\n"
#define CL_CHAR_NUM 10

int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_memcpy(char *dest, char *src, size_t n);
char *_strchr(char *s, char c);
char *_realloc(char *ptr, size_t old_size, size_t new_size);
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
int builtin(char **argv, char **en);
int is_space(char *str);
void cd(char **argv, char **en);
int set_var(char *argv, char *value, char **e);
int set_pwd(char **e, char *current);
ssize_t fetchline(char **lineptr, size_t *n, FILE *stream);
ssize_t fetchline1(char **p, char *q, char *r, char *ending_buf, size_t *n);
char *_strtok(char *str, const char *delim);
void interact(char *input);
void envs(void);
#endif
