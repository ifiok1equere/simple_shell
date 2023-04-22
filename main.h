#ifndef MAIN_H
#define MAIN_H

#define CL_CHAR_NUM 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int exec_func(char *argv[]);
ssize_t fetchline(char **lineptr, size_t *n, FILE *stream);
ssize_t fetchline1(char **p, char *q, char *r, char *ending_buf, size_t *n);
char *_realloc(char *ptr, size_t old_size, size_t new_size);
char *_memcpy(char *dest, char *src, size_t n);
#endif
