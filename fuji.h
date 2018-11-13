#ifndef FUJI_HEADER
#define FUJI_HEADER

#define _GNU_SOURCE
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

void ls_path(void);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(const char *name);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
int _which(int argc, char *argv[]);
char **strtow(char *str);
void get_word(char **array, char *str);
int word_count(char *str);
void cpy_str(int end, char *s, char **word_box);
#endif
