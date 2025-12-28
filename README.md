# Simple Shell (hsh)

A simple UNIX command-line interpreter written in C that replicates the basic functionality of `/bin/sh`.
---
## File Structure
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

The shell reads user input, parses it into commands and arguments, searches for executables using the `PATH` environment variable, and executes them using system calls

## Compilation  
Compile the shell using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

--
## Usage Examples
Interactive Mode
$ ./hsh
$ ls
$ pwd
$ exitNon-Interactive Mode
--

## Features
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

---
# AUTHORS

Abdullah Manahi Almouraibd
Rabea Younis Thabit



