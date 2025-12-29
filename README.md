# **Simple Shell**
A minimal UNIX command-line interpreter implemented in C as part of the low-level programming curriculum at Holberton School.
This shell supports interactive and non-interactive modes, built-in commands, environment variable access, and external command execution — all using system calls like `fork`, `execve`, and `wait`.
---
## :file_folder: Project Structure
| File                 | Description                      |
| -------------------- | -------------------------------- |
| `main.c`             | Program entry point              |
| `shell.c`            | Main execution loop              |
| `getline.c`          | Custom input reading (`_getline`)|
| `parse.c`            | Command parsing and tokenization |
| `path.c`             | `PATH` resolution logic          |
| `execute.c`          | External command execution       |
| `builtins.c`         | Built-in command handling        |
| `utils_string.c`     | Custom string utility functions  |
| `hsh.h`              | Header file with prototypes      |
| `man_1_simple_shell` | Manual page (`man ./man_1_simple_shell`) |
| `AUTHORS`            | List of contributors             |
---
## :sparkles: Features
- Supports **interactive mode** (with `$ ` prompt) and **non-interactive mode** (via pipe or script).
- Implements built-in commands: `exit` and `env`.
- Resolves commands using the `PATH` environment variable.
- Uses only **system calls** (`write`, `fork`, `execve`, `wait`, `access`, etc.) — **no standard I/O**.
- Handles **exit status** correctly (including modulo 256 for out-of-range values).
- Validates `exit` arguments: rejects non-numeric inputs with proper error messages.
- Fully compliant with **ISO C90** and compiles with strict GCC flags.
---
## :wrench: Built-in Commands
| Command         | Description                                |
| --------------- | ------------------------------------------ |
| `exit [status]` | Terminates the shell.                      |
| `env`           | Prints all environment variables.          |
> **`exit` behavior**:
> - No argument → exits with last command’s status.
> - Valid number → exits with that status (mod 256).
> - Invalid (e.g., `exit abc` or `exit -5`) → prints error:
>   `./hsh: 1: exit: Illegal number: <arg>` and continues.
---
## :rocket: Compilation
Compile the shell using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
----
:computer: Usage Examples
Interactive Mode
$ ./hsh
$ ls
$ pwd
$ env
$ exit
Non-Interactive Mode
$ echo "ls -l" | ./hsh
$ cat script.sh | ./hsh
Manual Page
man ./man_1_simple_shell
:warning: Error Handling
Invalid exit arguments → clear error on stderr with exit status 2.
Command not found → ./hsh: 1: <cmd>: not found\n with status 127.
Memory allocation failures → handled gracefully (shell exits safely).
All output uses write() — no reliance on printf, puts, or putchar.
:memo: AUTHORS
Abdullah Manahi Almouraibd
Rabea Younis Thabit
