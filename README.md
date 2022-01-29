# Simple Shell [Licence: MIT](https://github.com/kwamboka1/simple_shell/blob/main/LICENSE)

This is a simple UNIX command interpreter based on bash and Sh.
## Overview
**m_sh** is a sh-compatible command language interpreter that executes commands read from the standard input or from a file.
### Invocation
Usage: **m_sh** 
m_sh is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command: 
```
gcc -Wall -Werror -Wextra -pedantic *.c -o m_sh
./m_sh
```
**m_sh** is allowed to be invoked interactively and non-interactively. If **m_sh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.



