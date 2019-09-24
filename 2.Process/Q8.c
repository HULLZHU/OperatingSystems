//pipe() system call 
// (1) pipe is a connection between 2 processes, such that
// the standard output from one process becomes the standard
// input of the other process.
// (2) Can be used for communication between processes (IPC)
// -----------------------Concepts---------------------------
// (1) When openning a piple, an area of MM is treated as Virtual File
// (2) One process writes to a virtual file and another process reads
// (3) If something is written to a pipe, reading process will be suspended
//  Pipes behave like Queues (FIFO).
//-----------------------prototype------------------------
// int pipe(int fds[2]);
// fd[0]: the fd(file descriptor) for the read end of pipe
// fd[1]: the fd for the write end of pipe
//  Returns: 0 -> success; -1 -> error
//  single process Inner IPC
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int pipefd[2];//file descriptor array for pipe
    char buf;

    if(pipe(pipefd) == -1)
    {
        //perror is a posix error function to print an error message to stderr
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t rc[2];
    rc[0] = fork();

    if(rc[0] < 0 )
    {
        /*Falied Fork 1st child process*/
        fprintf(stderr,"fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if(rc[0] == 0)
    {
        /*Child Process (1)*/
        close(pipefd[0]);//close the used read end
        char str[] = "Child Process (1) write\n";
        write(pipefd[1],str,strlen(str));//write to the write end
        close(pipefd[1]); // close the write end
        waitpid(rc[1],NULL,0); /*wait for the second child*/
    }
    else
    {   /*Parent Process*/
        rc[1] = fork();

        /*Failed fork 2nd child process*/
        if(rc[1] < 0 )
        {
            fprintf(stderr,"fork failed\n");
            exit(EXIT_FAILURE);
        }
        else if(rc[1] == 0)
        {
            /* Child Process (2) */
            while(read(pipefd[0],&buf,1)>0)//read the content of the pipe into the char array buf a byte at a time
            {
                write(STDOUT_FILENO, &buf,1); // echo it on standard output
            }
            write(STDOUT_FILENO,"\n",1);
            close(pipefd[0]); // close the read end
        }
        return 0;
        
    }
    

}