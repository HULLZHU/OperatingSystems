#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    printf("Hello World (PID: %d) \n",(int)getpid());
    int rc = fork();//rc is assigned with the PID of the Parent Process
    if(rc < 0)
    {
        fprintf(stderr,"Fork Failed\n");
        exit(1);
    }
    else if(rc == 0 )//child(new process)
    {
        printf("I am child(PID: %d)\n",(int)getpid());
        char *myargs[3];
        //char *strdup(const char*s);
        //This function returns a pointer to a null-terminated
        //byte string, which is a duplicate of the string pointed to
        // by s
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p3.c");
        myargs[2] = NULL;
        //int execvp(const char *file, char *const argv[])
        //using this command, the created process does not have to run the same program as
        //the parent process does.
        //1st arg: a character string containing the name of a file to be executed
        //2nd arg: a pointer to an array of character strings.
        execvp(myargs[0], myargs);//runs word count
        printf("This should not print out");
    }
    else//parent 
    { 
        int wc = wait(NULL);
        //rc == wc == PID of the child process
        printf("Hello, I am parent of %d (wc: %d) (PID: %d)\n",rc,wc,(int)getpid());
    }
    return 0;
}