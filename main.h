#ifndef MAIN_H
#define MAIN_H

#define CL_CHAR_NUM 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_realloc(char *ptr, size_t old_size, size_t new_size);
char *_memcpy(char *dest, char *src, size_t n);
ssize_t fetchline(char **lineptr, size_t *n, FILE *stream);
ssize_t fetchline1(char **p, char *q, char *r, char *ending_buf, size_t *n);
char *_strtok(char *str, const char *delim);
#endif
