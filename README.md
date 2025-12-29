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
$ env
AWS_EXECUTION_ENV=AWS_ECS_FARGATE
AWS_CONTAINER_CREDENTIALS_RELATIVE_URI=/v2/credentials/0920ece8-1fbc-43b5-86bd-75ad69a7a33a
HOSTNAME=d2c24ae70a6c4950a4192c86106af9f1-2377118072
AWS_DEFAULT_REGION=me-central-1
AWS_REGION=me-central-1
PWD=/root/holbertonschool-simple_shell
ECS_CONTAINER_METADATA_URI_V4=http://169.254.170.2/v4/d2c24ae70a6c4950a4192c86106af9f1-2377118072
HOME=/root
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
PROMPT_COMMAND=history -a
ECS_AGENT_URI=http://169.254.170.2/api/d2c24ae70a6c4950a4192c86106af9f1-2377118072
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
ECS_CONTAINER_METADATA_URI=http://169.254.170.2/v3/d2c24ae70a6c4950a4192c86106af9f1-2377118072
SHLVL=1
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/root
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
