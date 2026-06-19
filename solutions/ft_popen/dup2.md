# Why `dup2` Can Fail and Return `-1`

`dup2(oldfd, newfd)` duplicates the file descriptor `oldfd` onto `newfd`. It can fail under several conditions:

| Error code | Cause                                              |
|------------|-----------------------------------------------------|
| `EBADF`    | invalid `oldfd` or `newfd` out of range             |
| `EINTR`    | call interrupted by a signal                        |
| `EBUSY`    | race condition was detected between `dup2()` and **opening a file** in some implementations (rare, system-dependent) |
| `EMFILE`   | too many open file descriptors                      |
| `EIO`      | **I/O error** occurred while closing the old `newfd` (if it was already open) before the duplication |

**Always check the return value of `dup2()`** - if it returns `-1`, the duplication failed and `errno` is set to indicate the reason.

## Should You Close Other FDs Before Exiting on Failure?

Short answer: **it's good practice**, but not strictly necessary if you exit immediately.

When a process terminates via `exit()` (or `_exit()`), **the operating system automatically closes all of its file descriptors**. So if `dup2()` fails and you call `exit(1)` right away, the OS cleans up for you - nothing leaks.

### When manual cleanup actually matters
- **You don't exit immediately** - e.g. you try a fallback path and keep the process running. In that case you must close the fd yourself, since the leak persists for the lifetime of the process.
- **You're writing a library/function** that may be called repeatedly in a long-lived process - fd hygiene matters here, otherwise you'll eventually hit the open file descriptor limit (`EMFILE`).
- **Readability and good practice** - even though the OS will clean up anyway, explicitly closing fds makes your intent clear and eases debugging.

### Summary

| Situation                                  | Need to close fds manually? |
|---------------------------------------------|:------------------------------:|
| Exiting the process right after the error   | No (OS cleans up)             |
| Continuing execution (fallback path)        | Yes                            |
| Long-lived process / reusable function      | Yes                            |