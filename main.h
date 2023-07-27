#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

/* some definitions */

/**
 * struct DirNode - stores directory names
 * @dir: string to store the dirctory name
 * @next: pointer to the next node in the linked list
 */

typedef struct DirNode
{
	char *dir;
	struct DirNode *next;
} DirNode;

extern DirNode *path_list;
extern char **environ;

#define MAX_INPUT_LEN 1024
#define READ_BUF_SIZE 1024

/* our functions */

int _exec(char **args);
char *find_command_in_path(const char *command);
char *get_full_path(const char *dir, const char *command);
char *read_input(void);
char **parse_input(char *input);
void search_and_execute(const char *command, char **args);
void parse_path(void);
ssize_t _getline(char **ptr, size_t *line_len, int fd);
ssize_t read_buff(char *buff, size_t *len);
char *_realloc(char *ptr, size_t old_size, size_t new_size);
char *_getenv(const char *a);
/*function that prints current environment*/
void p_env(void);
int find_env(const char *var);
int set_env(const char *var, const char *n);
int unset_env(const char *var);

void free_path_list(void);

/* helpful functions we used */
size_t _strlen(const char *s);
size_t _strcspn(const char *str, const char *reject);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *dest, const char *src);
char *_strchr(const char *str, int c);
char *_strdup(const char *str);
char *_strncat(char *dest, char *src, size_t n);
char *_strncpy(char *dest, char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);
int _atoi(const char *a);

#endif

