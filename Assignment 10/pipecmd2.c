#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXLINE 4096
void err_exit(char* msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
int main(int argc, char* argv[])
{
    int pipefd[2];
    int pipefd2[2];
    pid_t cpid1, cpid2, cpid3;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1)
        err_exit("pipe");

    cpid1 = fork();
    if (cpid1 == -1)
        err_exit("fork");

    if (cpid1 == 0)
    {                     /* child 1 */
        close(pipefd[0]); /* close read end */
        if (dup2(pipefd[1], STDOUT_FILENO) != STDOUT_FILENO)
            err_exit("dup2 error to stdin");
        close(pipefd[1]); /* don't need this after dup2 */
                          /* call exec with appropriate arguments*/
        char* myargs[] = {"cat", argv[1], 0};
        execvp(myargs[0], myargs);
        err_exit("execvp failed");
    }

    close(pipefd[1]);
// Here begins where the majority of the modifications
// to the original code are

    if (pipe(pipefd2) == -1)
        err_exit("pipe 2");

    cpid3 = fork();
    if(cpid3 == -1)
        err_exit("fork3");

    if (cpid3 == 0)
    {
        close(pipefd2[0]);
                if (dup2(pipefd[0], STDIN_FILENO) != STDIN_FILENO)
            err_exit("dup2 error to stdin");
        close(pipefd[0]); 

                if (dup2(pipefd2[1], STDOUT_FILENO) != STDOUT_FILENO)
            err_exit("dup2 error to stdin");
        close(pipefd2[1]); 

                      
        char* myargs[] = {"cat",  0};
        execvp(myargs[0], myargs);
        err_exit("execvp failed");
        
    }
    close(pipefd[0]);
    close(pipefd2[1]);


    cpid2 = fork();
    if (cpid2 == -1)
        err_exit("fork2");

    if (cpid2 == 0)
    {                    
        if (dup2(pipefd2[0], STDIN_FILENO) != STDIN_FILENO)
            err_exit("dup2 error to stdin");
        close(pipefd2[0]); 

        /* call exec with appropriate arguments*/
        char* myargs[] = {"wc", 0};
        execvp(myargs[0], myargs);
        err_exit("execvp failed");
    }

    close(pipefd2[0]);

    /* wait for both the children */
    if (waitpid(cpid1, NULL, 0) < 0)
        err_exit("waitpid error");
    if (waitpid(cpid2, NULL, 0) < 0)
        err_exit("waitpid error");
    if (waitpid(cpid3, NULL, 0) < 0)
        err_exit("waitpid error");

    exit(EXIT_SUCCESS);
}

//In this assignment you will extend pipecmd1.c to execute 'cat <filename> | cat | wc'.
