# Simple Shell
## Description

Simple Shell is a UNIX command line interpreter implemented in the C programming language.
It provides a minimal implementation of basic shell functionalities, allowing users to execute commands and interact with the operating system.
---

## File

| File                 | Description                      |
| -------------------- | -------------------------------- |
| `main.c`             | Program entry point              |
| `shell.c`            | Main execution loop              |
| `getline.c`          | Custom input reading function    |
| `parse.c`            | Command parsing and tokenization |
| `path.c`             | PATH resolution logic            |
| `execute.c`          | External command execution       |
| `builtins.c`         | Built-in command handling        |
| `utils_string.c`     | Utility string functions         |
| `hsh.h`              | Header file                      |
| `man_1_simple_shell` | Manual page                      |
| `AUTHORS`            | List of contributors             |

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
## Compilation  
Compile the shell using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh``

--
## Usage Examples
Interactive Mode
$ ./hsh
$ ls
$ pwd
$ exitNon-Interactive Mode
--
## Non-Interactive Mode
$ echo "/bin/ls" | ./hsh
--
## Built-in Commands
| Command         | Description                                |
| --------------- | ------------------------------------------ |
| `exit [status]` | Terminates the shell process               |
| `env`           | Displays the current environment variables |

## exit Command
-If no argument is provided, the shell exits with the status of the last executed command

-If a numeric argument is provided, it is used as the exit status

-If a non-numeric argument is provided, an error message is printed and the shell continues execution

--
## Implementation Overview

1- Displays a prompt when running in interactive mode.

2- Reads input from standard input using a custom _getline implementation.

3- Parses and tokenizes the input line.

4- Identifies and executes built-in commands.

5- Searches for executable files in the PATH environment variable.

6- Creates a child process using fork.

7- Executes external commands using execve.

8- Waits for the child process to terminate.
--

## Manual

man ./man_1_simple_shell
--
## License

This project is intended for educational purposes only.
--

# AUTHORS

Abdullah Manahi Almouraibd
Rabea Younis Thabit



