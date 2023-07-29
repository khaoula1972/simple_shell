# Simple Shell Team Project

Cooperation plays a crucial role in various aspects of life, including education, technology, and personal relationships. Although we recognize its significance, we sometimes succumb to the temptation of prioritizing our individual productivity instead of actively engaging with others.

With the intention of ensuring our responsibility and active involvement, this group project will emphasize a significant requirement for equal contribution.

<p align=center>
	<img src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg">
</p>

## Table of Contents

- [Team Members](#team-members)
- [Project Duration](#project-duration)
- [Project Description](#project-description)
- [Resources](#resources)
- [Compilation](#compilation)
- [Tasks Details](#tasks-details)

## Team members :
    Khaoula Nakkach and Aziz Nagwaka

**Cohort** : 15 SE ALX program

**Project Duration:**
- Start date : 12 July 2023
- End date : 27 July 2023

## Project description :

When utilizing any major operating system, our interaction with the shell occurs indirectly. For instance, when working with Ubuntu, Linux Mint, or any Linux
distribution, we engage with the shell through the terminal.

Shell is a special user program that provides an interface for the user to use operating system services. it accepts human-readable commands from users and converts them into something which the [kernel](https://www.geeksforgeeks.org/kernel-in-operating-system/) can understand.

<p align=center>
	<img src="https://media.geeksforgeeks.org/wp-content/uploads/18834419_1198504446945937_35839918_n-300x291.png">
</p>

Shell scripting involves writing a set of commands that can be executed in the shell, either interactively or automatically. A shell script comprises the following elements :

	- Shell Keywords – if, else, break etc.
	- Shell commands – cd, ls, echo, pwd, touch etc.
	- Functions
	- Control flow – if..then..else, case and shell loops etc.

Our objective for this project is to develop a simple UNIX interpreter and systematically complete all the assigned tasks in accordance with the specified requirements. The primary aim is to build a Shell that will support a range basic functionalities, including command execution, command-line parsing, input/output redirection, and basic shell scripting capabilities.

By building this simple shell, we will gain a deeper understanding of operating system concepts, command-line interfaces, and the inner workings of UNIX-like systems.

## Resources

- [Introduction to Linux Shell and Shell Scripting](https://www.geeksforgeeks.org/introduction-linux-shell-shell-scripting/)
- [Building a simple shell in C](https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-1)
- [Everything you need to know to start coding your own shell](https://intranet.alxswe.com/concepts/64)

## Compilation

Our code is compiled this way :
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Tasks details:

### Tasks Details

The number of tasks:
- 6 Mandatory tasks
- 11 Advanced tasks

Each task has specific requirements that need to be implemented. Here is a detailed overview of the tasks:

---

### Task 0

**Description:** Betty would be proud

**Requirements:**
- Write a beautiful code that passes the Betty checks

---
---

### Task 1

**Description:** Simple shell `0.1`

**Requirements:**
- Display a `prompt` and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- “end of file” condition should be handled (`Ctrl+D`)

---
---

### Task 2

**Description:** Simple shell `0.2`

**Requirements:**
- The new version of shell has to handle command lines with arguments.

---
---

### Task 3

**Description:** Simple shell `0.3`

**Requirements:**
- It has to handle the `PATH`.
- `fork` must not be called if the command doesn’t exist.

---
---

### Task 4

**Description:** Simple shell `0.4`

**Requirements:**
- The new version has to implement the exit built-in, that exits the shell
- No need to handle any argument to the built-in exit.

---
---

### Task 5

**Description:** Simple shell `1.0`

**Requirements:**
- It has to implement the env built-in, that prints the current environment.

---
---

### Task 6

**Description:** Simple shell `0.1.1`

**Requirements:**
- Writing our own `getline` function
- Using a buffer to read many chars at once and call the least possible the read system call

---

---

### Task 7

**Description:** Simple shell `0.2.1`

**Requirements:**
- Using `strtok` is not allowed.

---

---

### Task 8

**Description:** Simple shell `0.4.1`

**Requirements:**
- It has to handle arguments for the built-in exit.

---

---

### Task 9

**Description:** setenv, unsetenv

**Requirements:**
- Implementing the `setenv` and `unsetenv` builtin commands.

---

---

### Task 10

**Description:** cd

**Requirements:**
- Implementing the builtin command `cd` (command syntax cd [DIRECTORY])

---

---

### Task 11

**Description:** ;

**Requirements:**
- Handle the commands seperator `;`.

---

---

### Task 12

**Description:** && and ||

**Requirements:**
- Handle the `&&` and `||` shell logical operators.

---

---

### Task 13

**Description:** alias

**Requirements:**
- Implement the `alias` builtin command.

---

---

### Task 14

**Description:** Variables

**Requirements:**
- Handle variable replacement
- Handle the `$?` variable.
- Handle the `$$` variable.

---

---

### Task 15

**Description:** Comments

**Requirements:**
- Handle comments `#`.

---

---

### Task 16

**Description:** File as input

**Requirements:**
- The shell can take a file as a command line argument.
- The file contains all the commands that shell should run before exiting
- The file should contain one command per line.
- In this mode, the shell should not print a prompt and should not read from `stdin`.
