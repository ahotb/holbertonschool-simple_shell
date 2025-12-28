# Simple Shell (hsh)

A simple UNIX command-line interpreter written in C that replicates the basic functionality of `/bin/sh`.

---

## Table of Contents
- [Description](#description)
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Usage Examples](#usage-examples)
- [Features](#features)
- [Built-in Commands](#built-in-commands)
- [Error Handling](#error-handling)
- [File Structure](#file-structure)
- [AUTHORS](#authors)

---

## Description  
This project is a simple UNIX command-line interpreter (shell) written in C. It mimics the basic behavior of `/bin/sh` and supports executing commands in both **interactive** and **non-interactive** modes.

The shell reads user input, parses it into commands and arguments, searches for executables using the `PATH` environment variable, and executes them using system calls.

---

## Learning Objectives  
By completing this project, we are able to explain:

- Who designed and implemented the original Unix operating system  
- Who wrote the first version of the UNIX shell  
- Who invented the B programming language  
- Who Ken Thompson is  
- How a shell works  
- What a PID and a PPID are  
- How to manipulate the environment of the current process  
- The difference between a function and a system call  
- How to create processes using `fork`  
- The three prototypes of `main`  
- How the shell uses the `PATH` variable  
- How to execute a program with `execve`  
- How to wait for child processes  
- What EOF (End Of File) means  

---

## Requirements  
- **Allowed editors**: `vi`, `vim`, `emacs`  
- **Compiled on**: Ubuntu 20.04 LTS  
- **Compiler**: `gcc`  
- **Compilation flags**:  
  `-Wall -Werror -Wextra -pedantic -std=gnu89`  
- **Betty style compliance**  
- **No memory leaks**  
- **No more than 5 functions per file**  
- **Header files must be include-guarded**  
- **Only allowed system calls and standard functions are used**

---

## Compilation  
Compile the shell using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage Examples
Interactive Mode
$ ./hsh
$ ls
$ pwd
$ exitNon-Interactive Mode

Features
Displays a $ prompt in interactive mode
Executes external commands
Handles the PATH environment variable to locate executables
Built-in commands:
exit (with optional numeric status code)
env
Error messages match /bin/sh behavior
Avoids unnecessary fork() calls when a command is not found
Built-in Commands
exit [status]
Exits the shell
Supports optional numeric exit status (e.g., exit 98)
Handles invalid numeric arguments gracefully (prints error but does not exit)
env
Prints all environment variables, one per line, in NAME=value format
Error Handling
All errors are printed to stderr
Error messages match the format used by /bin/sh
The program name in error messages reflects argv[0]
In non-interactive mode, errors include the command line number
Example:

./hsh: 1: qwerty: not found

File Structure
.
├── AUTHORS
├── README.md
├── hsh.h
├── main.c
├── shell.c
├── getline.c
├── parse.c
├── path.c
├── execute.c
├── builtins.c
└── utils_string.c

AUTHORS
Abdullah Manahi Almouraibd
Rabea Younis Thabit



