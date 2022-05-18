# HSH Simple Shell
This project consists of a basic command interpreter (Shell) created in C language with several features; its development was part of an intensive coding program in ALX School.

## Overview
The HSH simple_shell is a program that reads commands provided by a user through Standard Input Stream and attempts to execute them by means of low level system procedures. This is by using built in functions, or searching for executable programs in the operating system.

The shell has two operating modes:

**Interactive** and **Non-interactive**.

In **Interactive mode**, the shell will display a prompt ($) indicating that the user can write and execute a command. After the command is run, the prompt will appear again a wait for a new command. This can go indefinitely as long as the user does not exit the shell.


    test@ubuntu:~/simple_shell$ ./hsh
    $ ls
    file1 file2 dira dirb
    $ 

In **Non-interactive mode**, the shell will need to be run with a command input piped into its execution so that the command is run as soon as the Shell starts. In this mode no prompt will appear, and no further input will be expected from the user.

    test@ubuntu:~/simple_shell$ echo "ls" | ./hsh
    file1 file2 dira dirb
    test@ubuntu:~/simple_shell$
    
## Testing

You can check the manual page of the project by running the _man_1_simple_shell_ file as

    test@ubuntu:~/simple_shell$ man ./man_1_simple_shell

**Compilation:**

In order to test the HSH simple shell, you will need to open a terminal in a Linux distribution and go to the folder you just cloned from GitHub. In there, you will need to compile the program, which was tested in GNU GCC 5.5.0 with different error flags such as:

> **-Wall:**  Enables all the warnings about constructions.
> 
> **-Wextra :**  Enables some extra warning flags that are not enabled by  **-Wall**.
> 
> **-Werror:**  Make all warnings into hard errors.
> 
> **-pedantic:**  Issue all the mandatory diagnostics listed in the C standard.

The compilation code goes as follows:

    test@ubuntu:~/simple_shell$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

By default, the name of the executable will be **hsh**, but you can change it if you desire to do so.

## Example:

$ echo "echo 'Alx school'" | ./hsh
'holberton'
$
When hsh is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened. sodash Will be using the following prompt ^-^ .

## Example:

$./hsh
^-^
If a command line argument is invoked, hsh will take that first argument as a file from which to read commands.

## Example:

$ cat text
echo 'ALX'
$ ./hsh text
'ALX'
$
## Environment
Upon invocation, hsh receives and copies the environment of the parent process in which it was executed. This environment is an array of name-value strings describing variables in the format NAME=VALUE. A few key environmental variables are:

## HOME
The home directory of the current user and the default directory argument for the cd builtin command.

$ echo "echo $HOME" | ./hsh
/home/vagrant
## PWD
The current working directory as set by the cd command.

$ echo "echo $PWD" | ./hsh
/home/vagrant/alx/simple_shell
## OLDPWD
The previous working directory as set by the cd command.

$ echo "echo $OLDPWD" | ./hsh
/home/vagrant/alx/bog-062019-test_suite
## PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

$ echo "echo $PATH" | ./hsh
/home/vagrant/.cargo/bin:/home/vagrant/.local/bin:/home/vagrant/.rbenv/plugins/ruby-build/bin:/home/vagrant/.rbenv/shims:/home/vagrant/.rbenv/bin:/home/vagrant/.nvm/versions/node/v10.15.3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/vagrant/.cargo/bin:/home/vagrant/workflow:/home/vagrant/.local/bin
## Command Execution
After receiving a command, hsh tokenizes it into words using " " as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. hsh then proceeds with the following actions:

If the first character of the command is neither a slash (\) nor dot (.), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
If the first character of the command is none of a slash (\), dot (.), nor builtin, hsh searches each element of the PATH environmental variable for a directory containing an executable file by that name.
If the first character of the command is a slash (\) or dot (.) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.
## Exit Status
hsh returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure. If a command is not found, the return status is 127; if a command is found but is not executable, the return status is 126. All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

## Signals
While running in interactive mode, the shell ignores the keyboard input ctrl+c. Alternatively, an input of End-Of-File ctrl+d will exit the program.

User hits ctrl+d in the fourth command.

$ ./hsh
^-^ ^C
^-^ ^C
^-^ ^C
^-^
## Variable Replacement
The shell interprets the $ character for variable replacement.

## $ENV_VARIABLE
ENV_VARIABLE is substituted with its value.

Example:

$ echo "echo $PWD" | ./hsh
/home/vagrant/alx/simple_shell
## $?
? is substitued with the return value of the last program executed.

Example:

$ echo "echo $?" | ./sodash
0
$$
The second $ is substitued with the current process ID.

Example:

$ echo "echo $$" | ./sodash
3855
## Comments
The shell ignores all words and characters preceeded by a # character on a line.

Example:

$ echo "echo 'alx' #this will be ignored!" | ./hsh
'alx'
## Operators
The shell specially interprets the following operator characters:

; - Command separator
Commands separated by a ; are executed sequentially.

Example:

$ echo "echo 'hello' ; echo 'world'" | ./hsh
'hello'
'world'
## && - AND logical operator
command1 && command2: command2 is executed if, and only if, command1 returns an exit status of zero.

Example:

$ echo "error! && echo 'alx'" | ./hsh
$ echo "echo 'my name is' && echo 'alx'" | ./hsh
'my name is'
'alx'
## || - OR logical operator
command1 || command2: command2 is executed if, and only if, command1 returns a non-zero exit status.

Example:

$ echo "error! || echo 'wait for it'" | ./sodash
./hsh: 1: error!: not found
'wait for it'
The operators && and || have equal precedence, followed by ;.

## Builtin Commands
### cd
Usage: cd [DIRECTORY]
Changes the current directory of the process to DIRECTORY.
If no argument is given, the command is interpreted as cd $HOME.
If the argument - is given, the command is interpreted as cd $OLDPWD and the pathname of the new working directory is printed to standad output.
If the argument, -- is given, the command is interpreted as cd $OLDPWD but the pathname of the new working directory is not printed.
The environment variables PWD and OLDPWD are updated after a change of directory.
Example:

$ ./hsh
^-^ pwd
/home/vagrant/alx/simple_shell
$ cd ../
^-^ pwd
/home/vagrant/alx
^-^ cd -
^-^ pwd
/home/vagrant/alx/simple_shell
## exit
Usage: exit [STATUS]
Exits the shell.
The STATUS argument is the integer used to exit the shell.
If no argument is given, the command is interpreted as exit 0.
Example:

$ ./hsh
$ exit
## env
Usage: env
Prints the current environment.
Example:

$ ./hsh
$ env
NVM_DIR=/home/vagrant/.nvm
...
## setenv
Usage: setenv [VARIABLE] [VALUE]
Initializes a new environment variable, or modifies an existing one.
Upon failure, prints a message to stderr.
Example:

$ ./hsh
$ setenv NAME Alx
$ echo $NAME
Alx
## unsetenv
Usage: unsetenv [VARIABLE]
Removes an environmental variable.
Upon failure, prints a message to stderr.
Example:

$ ./hsh
$ setenv NAME Holberton
$ unsetenv NAME
$ echo $NAME

$

## Built with

Ubuntu 20.04, Emacs, Vim, and C language.


## Authors 
David Luke <lucadavid075>
Mercy Kalu <belrah>