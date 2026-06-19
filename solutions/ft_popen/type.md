# type

- STDIN_FILENO == 0
- STDOUT_FILENO == 1
- STDERR_FILENO == 2

```c
int pipe(int pipefd[2]);
```

`pipefd[0]` is the **read end** of the pipe,
`pipefd[1]` is the **write end** of the pipe.

Just like `stdin` is `0`, `pipefd[0]` is also for **reading** - i.e. fetching input.
 
Just like `stdout` is `1`, `pipefd[1]` is also for **writing** - i.e. sending output.

process A write/fd[1] -> pipe -> process B read/fd[0]


```bash
ls | grep c
```
stdout(ls) -> pipe -> stdin(grep)

If `type == r`, it means **read the output** of the launched file.

If `type == w`, it means **write the input** to the launched file.

### that means that if type == 'r':

child will change stdout into fd[1]

parent will return read pipe fd[0]

### and that means that if type == 'w':

child will change stdin into fd[0]

parent will return write pipe fd[1]