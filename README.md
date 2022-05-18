# **Shellex** - Simple Shell :shell:

A simple UNIX command interpreter written as part of the low-level programming and algorithm track at ALX.

## Description :speech_balloon:

**Shellex** is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

### Invocation :rocket:

Usage: **shellex** [filename]

To invoke **shellex**, compile all `.c` files in the repository and run the resulting executable:

```
gcc *.c -o shellex
./shellex
```

**Shellex** can be invoked both interactively and non-interactively. If **shellex** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'hello'" | ./shellex
'hello'
$
```

If **shellex** is invoked with standard input connected to a terminal (determined by [isatty](https://linux.die.net/man/3/isatty)(3)), an *interactive* shell is opened. When executing interactively, **shellex** displays the prompt `$ ` when it is ready to read a command.

Example:
```
$./shellex
$
```

Alternatively, if command line arguments are supplied upon invocation, **shellex** treats the first argument as a file from which to read commands. The supplied file should contain one command per line. **Shellex** runs each of the commands contained in the file in order before exiting.

Example:
```
$ cat test
echo 'hello'
$ ./shellex test
'hello'
$
```

### Environment :deciduous_tree:

Upon invocation, **shellex** receives and copies the environment of the parent process in which it was executed. This environment is an array of *name-value* strings describing variables in the format *NAME=VALUE*. A few key environmental variables are:

#### HOME
The home directory of the current user and the default directory argument for the **cd** builtin command.

```
$ echo "echo $HOME" | ./shellex
/home/vagrant
```

#### PWD
The current working directory as set by the **cd** command.

```
$ echo "echo $PWD" | ./shellex
/home/vagrant/ALX/simple_shell
```

#### OLDPWD
The previous working directory as set by the **cd** command.

```
$ echo "echo $OLDPWD" | ./shellex
/home/vagrant/ALX/printf
```
