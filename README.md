# exam_rank4

This repository contains files created to prepare myself for exam rank 4 in the 42School system. The subjects were obtained from [terminal-42s](https://github.com/terminal-42s/42_examshell).

*Please note that these files are strictly for training purposes. I do not take responsibility for their correctness, as they serve as my personal study guide **leading up** to the exam.*

## Quizlet
Quizlet flashcards that are connecting functions with their corresponding libraries can be found [here](https://quizlet.com/de/1189390875/functions-their-libraries-flash-cards/?i=1nvzgl&x=1qqt).

## Subjects
level 1 (use of pipes):
- [ft_popen](#ft_popen)
- [picoshell](#picoshell)
- [sandbox](#sandbox)

level 2 (AST creation):
- [argo](#argo)
- [vbc](#vbc)

## ft_popen
**Description**: Opens a pipe to a process and executes the given command, like libc's [popen()](https://man7.org/linux/man-pages/man3/popen.3.html).
```
int ft_popen(const char *file, char *const argv[], char type);
```
**Allowed functions**:
- [pipe](#pipe),
- [fork](#fork),
- [dup2](#dup2),
- [execvp](#execvp),
- [close](#close),
- [exit](#exit).



## picoshell
**Description**: The goal of this function is to execute a pipeline.
```
int    picoshell(char **cmds[]);
```
**Allowed functions**:
- [close](#close),
- [fork](#fork),
- [wait](#wait),
- [exit](#exit),
- [execvp](#execvp),
- [dup2](#dup2),
- [pipe](#pipe).

## sandbox
**Description**: Create a safe environment to test functions.
```
int sandbox(void (*f)(void), unsigned int timeout, bool verbose);
```
**Allowed functions**:
- [fork](#fork),
- [waitpid](#waitpid),
- [exit](#exit),
- [alarm](#alarm),
- [sigaction](#sigaction),
- [kill](#kill),
- [printf](#printf),
- [strsignal](#strsignal),
- [errno](#errno),
- [sigaddset](#sigaddset),
- [sigemptyset](#sigemptyset),
- [sigfillset](#sigfillset),
- [sigdelset](#sigdelset),
- [sigismember](#sigismember).

## argo
**Description**: Create an Abstract Syntax Tree (AST) from a command line.
```
int	argo(json *dst, FILE *stream);
```
**Allowed functions**:
- [getc](#getc),
- [ungetc](#ungetc),
- [printf](#printf),
- [malloc](#malloc),
- [calloc](#calloc),
- [realloc](#realloc),
- [free](#free),
- [isdigit](#isdigit),
- [fscanf](#fscanf),
- [write](#write).

## vbc
**Description**: Create an Abstract Syntax Tree (AST) from a command line. That will be used to calculate the value of a mathematical expression.

**Allowed functions**:
- [malloc](#malloc),
- [calloc](#calloc),
- [realloc](#realloc),
- [free](#free),
- [printf](#printf),
- [isdigit](#isdigit),
- [write](#write).

## Allowed functions

### [alarm](https://man7.org/linux/man-pages/man2/alarm.2.html)
```bash
man 2 alarm
```
```c
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
```
Sets an alarm that sends SIGALRM to the process after the given number of seconds.

### [calloc](https://man7.org/linux/man-pages/man3/malloc.3.html)
```bash
man 3 calloc
```
```c
#include <stdlib.h>
void *calloc(size_t nmemb, size_t size);
```
Allocates memory for an array of elements and zeroes the entire allocated block.

### [close](https://man7.org/linux/man-pages/man2/close.2.html)
```bash
man 2 close
```
```c
#include <unistd.h>
int close(int fd);
```
Closes an open file descriptor.

### [dup2](https://man7.org/linux/man-pages/man2/dup2.2.html)
```bash
man 2 dup2
```
```c
#include <unistd.h>
int dup2(int oldfd, int newfd);
```
Duplicates a file descriptor onto the specified descriptor number.

### [errno](https://man7.org/linux/man-pages/man3/errno.3.html)
```bash
man 3 errno
```
```c
#include <errno.h>
extern int errno;
```
A global variable holding the last system error number, not a function.

### [execvp](https://man7.org/linux/man-pages/man3/execvp.3.html)
```bash
man 3 execvp
```
```c
#include <unistd.h>
int execvp(const char *file, char *const argv[]);
```
Executes the program named by file using the argument vector.

### [exit](https://man7.org/linux/man-pages/man3/exit.3.html)
```bash
man 3 exit
```
```c
#include <stdlib.h>
void exit(int status);
```
Terminates the process and returns an exit status.

### [fork](https://man7.org/linux/man-pages/man2/fork.2.html)
```bash
man 2 fork
```
```c
#include <unistd.h>
pid_t fork(void);
```
Creates a child process as a copy of the parent.

### [free](https://man7.org/linux/man-pages/man3/malloc.3.html)
```bash
man 3 free
```
```c
#include <stdlib.h>
void free(void *ptr);
```
Frees memory previously allocated by the malloc family.

### [fscanf](https://man7.org/linux/man-pages/man3/fscanf.3.html)
```bash
man 3 fscanf
```
```c
#include <stdio.h>
int fscanf(FILE *stream, const char *format, ...);
```
Reads formatted input from a stream.

### [getc](https://man7.org/linux/man-pages/man3/fgetc.3.html)
```bash
man 3 getc
```
```c
#include <stdio.h>
int getc(FILE *stream);
```
Gets one character from a stream.

### [isdigit](https://man7.org/linux/man-pages/man3/isdigit.3.html)
```bash
man 3 isdigit
```
```c
#include <ctype.h>
int isdigit(int c);
```
Checks whether a character is a decimal digit.

### [kill](https://man7.org/linux/man-pages/man2/kill.2.html)
```bash
man 2 kill
```
```c
#include <signal.h>
int kill(pid_t pid, int sig);
```
Sends a signal to a process or process group.

### [malloc](https://man7.org/linux/man-pages/man3/malloc.3.html)
```bash
man 3 malloc
```
```c
#include <stdlib.h>
void *malloc(size_t size);
```
Allocates uninitialized dynamic memory.

### [pipe](https://man7.org/linux/man-pages/man2/pipe.2.html)
```bash
man 2 pipe
```
```c
#include <unistd.h>
int pipe(int pipefd[2]);
```
Creates a one-way communication channel between processes.

### [printf](https://man7.org/linux/man-pages/man3/printf.3.html)
```bash
man 3 printf
```
```c
#include <stdio.h>
int printf(const char *format, ...);
```
Prints formatted text to standard output.

### [realloc](https://man7.org/linux/man-pages/man3/malloc.3.html)
```bash
man 3 realloc
```
```c
#include <stdlib.h>
void *realloc(void *ptr, size_t size);
```
Changes the size of a previously allocated memory block.

### [sigaction](https://man7.org/linux/man-pages/man2/sigaction.2.html)
```bash
man 2 sigaction
```
```c
#include <signal.h>
int sigaction(int signum, const struct sigaction *restrict act, struct sigaction *restrict oldact);
```
Reads or sets the action for handling a signal.

### [sigaddset](https://man7.org/linux/man-pages/man3/sigaddset.3.html)
```bash
man 3 sigaddset
```
```c
#include <signal.h>
int sigaddset(sigset_t *set, int signum);
```
Adds a signal to a signal set.

### [sigdelset](https://man7.org/linux/man-pages/man3/sigdelset.3.html)
```bash
man 3 sigdelset
```
```c
#include <signal.h>
int sigdelset(sigset_t *set, int signum);
```
Removes a signal from a signal set.

### [sigemptyset](https://man7.org/linux/man-pages/man3/sigemptyset.3.html)
```bash
man 3 sigemptyset
```
```c
#include <signal.h>
int sigemptyset(sigset_t *set);
```
Initializes an empty signal set.

### [sigfillset](https://man7.org/linux/man-pages/man3/sigfillset.3.html)
```bash
man 3 sigfillset
```
```c
#include <signal.h>
int sigfillset(sigset_t *set);
```
Fills the set with all supported signals.

### [sigismember](https://man7.org/linux/man-pages/man3/sigismember.3.html)
```bash
man 3 sigismember
```
```c
#include <signal.h>
int sigismember(const sigset_t *set, int signum);
```
Checks whether a signal is a member of the set.

### [strsignal](https://man7.org/linux/man-pages/man3/strsignal.3.html)
```bash
man 3 strsignal
```
```c
#include <string.h>
char *strsignal(int sig);
```
Returns a textual description of a signal.

### [ungetc](https://man7.org/linux/man-pages/man3/ungetc.3.html)
```bash
man 3 ungetc
```
```c
#include <stdio.h>
int ungetc(int c, FILE *stream);
```
Pushes a character back into the input stream.

### [wait](https://man7.org/linux/man-pages/man2/wait.2.html)
```bash
man 2 wait
```
```c
#include <sys/wait.h>
pid_t wait(int *wstatus);
```
Waits for a child process to terminate or change state.

### [waitpid](https://man7.org/linux/man-pages/man2/waitpid.2.html)
```bash
man 2 waitpid
```
```c
#include <sys/wait.h>
pid_t waitpid(pid_t pid, int *wstatus, int options);
```
Waits for a specific child process or process group.

### [write](https://man7.org/linux/man-pages/man2/write.2.html)
```bash
man 2 write
```
```c
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count);
```
Writes bytes from a buffer to a file descriptor.

