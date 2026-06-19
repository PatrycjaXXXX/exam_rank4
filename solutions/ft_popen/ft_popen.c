#include <unistd.h> //pipe, fork, dup2, execvp, close
#include <stdlib.h> //exit
#include <sys/types.h> //pid_t

// In case of error or invalid parameter the function must return -1.
# define ERR -1

int ft_popen(const char *file, char *const argv[], char type)
{
	int pipefd[2];
	pid_t pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return ERR;
	if (pipe(pipefd) == -1)
		return ERR;
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return ERR;
	}
	if (pid == 0) // Child process
	{
		if (type == 'r')
		{
			if (dup2(pipefd[1], STDOUT_FILENO) == -1)
				exit(1);
		}
		else
		{
			if (dup2(pipefd[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(pipefd[0]);
		close(pipefd[1]); //not needed after dup2
		execvp(file, argv); //execute the command
		exit(1); // If execvp fails
	}
	else
	{
		//else is here for readability
		//you are a parent, so return write pipe for w and read pipe for r
		if (type == 'r')
		{
			close(pipefd[1]);
			return pipefd[0];
		}
		else
		{
			close(pipefd[0]);
			return pipefd[1];
		}
	}
}