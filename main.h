#ifndef MAIN_H
#define MAIN_H

/* libraries we used */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

/* some definitions */

#define READ 1024
#define WRITE 1024
#define FLUSH -1
#define NORMAL 0 /*command*/
#define OR 1 /*command*/
#define AND 2 /* command*/
#define CHAINING 3
#define UNSIGNED 2 /* convert numbers we'll usCHAINING 3e this*/
#define LOWER 1
#define GETLINE_SYS 0
#define STRTOK_SYS 0

/* the structures */

/**
 * struct StringNode - a singly linked list
 * @number: number
 * @string: a string
 * @next: pointer to the next node
 */

typedef struct StringNode
{
	int number;
	char *string;
	struct StringNode *next;
} string_list;

/**
 * struct function_args - structue that contains arguments for the function
 * @arg_string: a string we can get from getline
 * @arg_vector: an array of strings
 * @command_path: the string path for cmd
 * @arg_count: count arguments
 * @line_error_count: to count error
 * @exit_error_code: The error code for exit() calls
 * @line_count_flag: A flag to count output lines
 * @program_filename: The name of the current program file
 * @environment_list: A linked list holding local copies
 * of environment variables
 * @modified_environment: A custom modified copy of
 * environment variables from env
 * @alias_node: A node representing aliases
 * @environment_changed: A flag indicating whether
 * environment variables were changed
 * @return_status: The return status of the last executed command
 * @command_buffer: Address of the pointer to the command buffer
 * @command_buffer_type: Specifies the type of command
 * chaining (COMMAND_OR, COMMAND_AND, COMMAND_CHAINING)
 * @read_file_descriptor: The file descriptor used for reading input lines
 */

typedef struct function_args
{
	char *arg_string;
	char **arg_vector;
	int arg_count;
	char *command_path;
	unsigned int line_error_count;
	int line_count_flag;
	int exit_error_code;
	string_list *environment_list;
	string_list *alias_node;
	char *program_filename;
	int environment_changed;
	char **modified_environment;
	char **command_buffer;
	int return_status;
	int read_file_descriptor;
	int command_buffer_type;
} function_args;

#define FUNCTION_ARGS_INIT \
{NULL, NULL, 0, NULL, 0, 0, 0, NULL, NULL, NULL, 0, NULL, \
	NULL, 0, 0, 0}

/**
 * struct BuiltinCommand - Represents a builtin command
 * and its corresponding function
 * @command_type: The type of builtin command
 * @command_function: The function pointer to the
 * corresponding builtin function
 */

typedef struct BuiltinCommand
{
	char *command_type;
	int (*command_function)(function_args *);
} BuiltinCommandTable;

int set_env(function_args *args);
int fill_env(function_args *args);
int unset_env(function_args *args);

void _fork(function_args *function_args);
void _find(function_args *function_args);
int prompt(function_args *function_args, char **av);
int find_builtin(function_args *function_args);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *sw(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);

char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);


char **_strtk(char *str, char d);
char **strtk(char *str, char *d);

void chk_chain(function_args *function_args, char *buf,
		size_t *p, size_t i, size_t len);
int is_chain_del(function_args *function_args, char *buf, size_t *p);
int replace_strs(char **old, char *new);
int replace_vars(function_args *function_args);
int replace_alias(function_args *function_args);

ssize_t gni(string_list *head, string_list *node);
string_list *nsw(string_list *node, char *prefix, char c);
size_t p_ls(const string_list *head);
char **list_to_strs(string_list *head);
size_t list_len(const string_list *head);

int is_cmd(function_args *function_args, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(function_args *function_args, char *pathstr, char *cmd);

int exit_shell(function_args *);
int change_directory(function_args *);
int shelp(function_args *);
int _alias(function_args *);
int _mysetenv(function_args *);
int _myunsetenv(function_args *);
int print_environment(function_args *);

void erputs(char *str);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);
int erputchar(char c);

int _erratoi(char *s);
void perr(function_args *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);

char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);

char **get_environ(function_args *function_args);
int _unsetenv(function_args *function_args, char *var);
int _setenv(function_args *function_args, char *var, char *value);

void clear_function_args(function_args *function_args);
void set_function_args(function_args *function_args, char **av);
void free_function_args(function_args *function_args, int all);

ssize_t input_buf(function_args *function_args, char **buf, size_t *len);
ssize_t get_input(function_args *function_args);
ssize_t read_buf(function_args *function_args, char *buf, size_t *i);
int _getline(function_args *function_args, char **ptr, size_t *length);
void sigintHandler(int sig_num);

string_list *add_node(string_list **head, const char *str, int num);
string_list *ane(string_list **head, const char *str, int num);
size_t ps_ls(const string_list *h);
int dni(string_list **head, unsigned int index);
void free_list(string_list **head_ptr);

int is_inter(function_args *function_args);
int is_del(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

int unalias(function_args *function_args, char *str);
int salias(function_args *function_args, char *str);
int palias(string_list *node);
int _alias(function_args *function_args);

int _mysetenv(function_args *info);
int _myunsetenv(function_args *info);
int populate_env_list(function_args *info);
char *_getenv(function_args *info, const char *name);

char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
int bfree(void **ptr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
