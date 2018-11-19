#ifndef FUJI_HEADER
#define FUJI_HEADER

#define _GNU_SOURCE
#include <stdarg.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <signal.h>

/**
 * struct linked_PATH - singly linked list of PATH directories
 * @dir: directories
 * @next: pointer to the next node
 *
 * Description: singly linked list node structure for PATH directories
 */
typedef struct linked_PATH
{
	char *dir;
	struct linked_PATH *next;
} lp_t;
/**
 * struct builtins - builtin command and functions for shell
 * @cmd: cmd name
 * @f: pointer to builtin functions
 *
 * Description: struct for builtin functions
 */
typedef struct builtins
{
	char *cmd;
	void (*f)(char **args);
} built_t;
/* Function Declarations for builtin shell commands */
void fuji_env(char **args, char **env);
void fuji_exit(char **args, char **env);
void fuji_built(char **args, char **env);

void inline_mode(int argc, char **argv);
void free_array(char **array);
void free_cptrn(int, const unsigned int n, ...);
lp_t *linked_PATH(void);
lp_t *add_node_end(lp_t **head, char *str);
void ls_path(void);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(const char *name);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
int _strcmp2(const char *s1, const char *s2);
int _which(int argc, char *argv[]);
char **strtow(char *str);
void get_word(char **array, char *str);
int word_count(char *str);
void cpy_str(int end, char *s, char **word_box);
char *str_concat(char *s1, char *s2);
void check_path(char **string);
void free_lp(char *str1, lp_t *head);
void signal_handler(int signo);
#endif
