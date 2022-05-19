# HSH Simple Shell
This project consists of a basic command interpreter (Shell) created in C language with several features; its development was part of an intensive coding program in Alx School.

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

## **Built Ins**

The simple shell has a set of commands that work like internal functions and don't require the search for any executable program.  

|Built In|Description|
|--|--|
|**exit**|This command is used for exiting the Shell, its syntax is **exit status** , where status is an integer number. If no status is given, exit will use the value set by the last error encountered.|
|**env**|This command is used for displaying the system's current environment in the format **variable=value**. Its syntax is simply **env** with no options.|
|**setenv**| This command will overwrite the value of an environmental variable if it already exists, or create a new one in case it does not. Its syntax is **setenv VARIABLE VALUE**. If no arguments are given, then setenv will print the current environment as if **env** had been used.  |
|**unsetenv**| This command will remove an environmental variable from the system if it exists, or leave the environment untouched if it does not. Its syntax is **unsetenv VARIABLE**. If no argument is given, the environment will remain the same. |
|**cd**|This command is used for changing the current working directory. Its syntax is **cd DIRECTORY**. If no directory is specified, cd will change directory to the value set in the environmental variable **HOME**. If instead of directory, a symbol **-** is used, then cd will change to the previous working directory, which by default is initially **HOME**.  |
|**help**|This command will show a text explaining the usage of a built in. Its syntax is **help BUILTIN**. If this command is run without argument, then a list of all built ins and their syntax will be displayed. This command can be used on itself. |

## Environment
Upon invocation, the shell receives and copies the environment of the parent process in which it was executed. This environment is an array of name-value strings describing variables in the format NAME=VALUE. A few key environmental variables are:

## HOME
The home directory of the current user and the default directory argument for the cd builtin command.

$ echo "echo $HOME" | ./hsh
/home/vagrant
## PWD
The current working directory as set by the cd command.

$ echo "echo $PWD" | ./hsh
/home/vagrant/holberton/simple_shell
## OLDPWD
The previous working directory as set by the cd command.

$ echo "echo $OLDPWD" | ./hsh
/home/vagrant/holberton/bog-062019-test_suite
## PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

$ echo "echo $PATH" | ./hsh
/home/vagrant/.cargo/bin:/home/vagrant/.local/bin:/home/vagrant/.rbenv/plugins/ruby-build/bin:/home/vagrant/.rbenv/shims:/home/vagrant/.rbenv/bin:/home/vagrant/.nvm/versions/node/v10.15.3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/vagrant/.cargo/bin:/home/vagrant/workflow:/home/vagrant/.local/bin
## Command Execution
After receiving a command, the shell tokenizes it into words using " " as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. sodash then proceeds with the following actions:

If the first character of the command is neither a slash (\) nor dot (.), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
If the first character of the command is none of a slash (\), dot (.), nor builtin, the shell searches each element of the PATH environmental variable for a directory containing an executable file by that name.
If the first character of the command is a slash (\) or dot (.) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.
## Exit Status
the shell returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure. If a command is not found, the return status is 127; if a command is found but is not executable, the return status is 126. All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

## Signals
While running in interactive mode, the shell ignores the keyboard input ctrl+c. Alternatively, an input of End-Of-File ctrl+d will exit the program.

User hits ctrl+d in the foutrh command.

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
/home/vagrant/holberton/simple_shell
## $?
? is substitued with the return value of the last program executed.

Example:

$ echo "echo $?" | ./hsh
0
$$
The second $ is substitued with the current process ID.

Example:

$ echo "echo $$" | ./hsh
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

$ echo "error! && echo 'ALX'" | ./hsh
./shellby: 1: error!: not found
$ echo "echo 'my name is' && echo 'ALX'" | ./hsh
'my name is'
'ALX'
## || - OR logical operator
command1 || command2: command2 is executed if, and only if, command1 returns a non-zero exit status.

Example:

$ echo "error! || echo 'wait for it'" | ./hsh
./hsh: 1: error!: not found
'wait for it'
The operators && and || have equal precedence, followed by ;.


## Authors & Copyrights
Mercy Kalu <belrah>                                                               
David Luke <lucadavid075>