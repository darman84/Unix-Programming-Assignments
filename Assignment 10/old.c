#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 4096
void
err_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
int
main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t cpid1, cpid2;

    if (argc != 2) {
     fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
     exit(EXIT_FAILURE);
    }


    if (pipe(pipefd) == -1) 
        err_exit("pipe");

    cpid1 = fork();
    if (cpid1 == -1) 
        err_exit("fork");

	if (cpid1 == 0) {    /* child 1 */
        close(pipefd[0]); /* close read end */
        if (dup2(pipefd[1], STDOUT_FILENO) != STDOUT_FILENO)
             err_exit("dup2 error to stdin");
         close(pipefd[1]);   /* don't need this after dup2 */
		/* call exec with appropriate arguments*/
        char *myargs[] = {"cat", argv[1], 0};
        execvp(myargs[0], myargs);
		err_exit("execvp failed");
	}

    cpid2 = fork();
    if (cpid2 == -1) 
        err_exit("fork2");

	if (cpid2 == 0) {    /* child 2 */
		close(pipefd[1]);   /* close write end */
        if (dup2(pipefd[0], STDIN_FILENO) != STDIN_FILENO)
        	err_exit("dup2 error to stdin");
        close(pipefd[0]);   /* don't need this after dup2 */

		/* call exec with appropriate arguments*/
        char *myargs[] = {"wc", 0};
        execvp(myargs[0], myargs);
			err_exit("execvp failed");
	}
	/* parent should close both ends of the pipe */
	close(pipefd[0]); /* close read end */
	close(pipefd[1]);   /* close write end */

	/* wait for both the children */
	 if (waitpid(cpid1, NULL, 0) < 0)
            err_exit("waitpid error");
	 if (waitpid(cpid2, NULL, 0) < 0)
            err_exit("waitpid error");
        exit(EXIT_SUCCESS);
}

