# Simple Shell

A simple UNIX command interpreter written as part of the Holberton School curriculum.

## Features
- Interactive and non-interactive mode
- Built-in commands: `exit`, `env`
- Executes external programs using `execve`
- Mimics `/bin/sh` error messages

## Usage
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
