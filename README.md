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
🚀 Compilation

Compile the shell using:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```

---
💻 Usage Examples
🔹 Interactive Mode
```
$ ./shell
$ ls
$ pwd
$ env
$ exit
```
```
root@d2c24ae70a6c4950a4192c86106af9f1-2377118072:~/holbertonschool-simple_shell# ./shell
$ ls
README.md  builtins.c  execute.c  getline.c  hsh.h  main.c  parse.c  path.c  shell  shell.c  utils_string.c
$ pwd
/root/holbertonschool-simple_shell
$ exit
```
---
🔹 Non-Interactive Mode
```
$ echo "ls -l" | ./shell
"ls -l" | ./shell
$ 
```
---
📖 Manual Page
```man ./man_1_simple_shell```

---
⚠️ Error Handling

Invalid exit arguments
→ Displays a clear error message on stderr
→ Exits with status code 2

---
Command not found
→ Error message:
```
./shell: 1: <cmd>: not found
```

---
✍️ AUTHORS

Abdullah Manahi Almouraibd

Rabea Younis Thabit
