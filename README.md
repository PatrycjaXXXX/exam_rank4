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
**Description**: simple function recreating libc's `popen()`.
```
int ft_popen(const char *file, char *const argv[], char type);
```
**Allowed functions**:
- pipe,
- fork,
- dup2,
- execvp,
- close,
- exit.

## picoshell
**Description**: The goal of this function is to execute a pipeline.
```
int    picoshell(char **cmds[]);
```
**Allowed functions**:
- close,
- fork,
- wait,
- exit,
- execvp,
- dup2,
- pipe.

## sandbox
**Description**: Create a safe environment to test functions.
```
int sandbox(void (*f)(void), unsigned int timeout, bool verbose);
```
**Allowed functions**:
- fork,
- waitpid,
- exit,
- [alarm](#alarm),
- sigaction,
- kill,
- printf,
- strsignal,
- errno,
- sigaddset,
- sigemptyset,
- sigfillset,
- sigdelset,
- sigismember.

## argo
**Description**: Create an Abstract Syntax Tree (AST) from a command line.
```
int	argo(json *dst, FILE *stream);
```
**Allowed functions**:
- getc,
- ungetc,
- printf,
- malloc,
- calloc,
- realloc,
- free,
- isdigit,
- fscanf,
- write.

## vbc
**Description**: Create an Abstract Syntax Tree (AST) from a command line. That will be used to calculate the value of a mathematical expression.

**Allowed functions**:
- malloc,
- calloc,
- realloc,
- free,
- printf,
- isdigit,
- write.

## Allowed functions

### alarm
```
man alarm
```
```
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
```


### calloc


### close


### dup2


### errno


### execvp


### exit


### fork


### free


### fscanf


### getc


### isdigit


### kill


### malloc


### pipe


### printf


### realloc


### sigaction


### sigaddset


### sigdelset


### sigemptyset


### sigfillset


### sigismember


### strsignal


### ungetc


### wait


### waitpid


### write

