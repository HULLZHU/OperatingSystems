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
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#define MSGSIZE 16
char *msg1 = "Hello, world #1";
char *msg2 = "Hello, world #2";
char *msg3 = "Hello, world #3";

int main()
{
    char inbuf[MSGSIZE];//This memory space is used as buffer for IPC
    int p[2], pid, nbytes;

    if(pipe(p) < 0)
    {
        exit(1);
    }

    int rc = fork();
    if( rc > 0 )//write end: parent
    {   printf("Parent Process: %d \n", (int)getpid());
        write(p[1],msg1,MSGSIZE);//wirte the message to the write end.The write end can be also seen as a file descriptor
        write(p[1],msg2,MSGSIZE);
        write(p[1],msg3,MSGSIZE);
        //Following code is needed if you want to hang the program
        close(p[1]);
        wait(NULL);
    }
    else//read end: child
    {   printf("Child Process: %d \n", (int)getpid());
        //Following code is needed if you want to hang the program
        close(p[1]);
        while((nbytes = read(p[0],inbuf,MSGSIZE))>0)
        {
            printf("%s\n",inbuf);
        }
        if(nbytes !=0)
            exit(2);
        printf("Reading Finished\n");
    }

    return 0; 
}
