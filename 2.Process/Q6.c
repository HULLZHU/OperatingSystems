#define _GNU_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
/*This practice uses the waitpid() rather than wait*/
int main(int argc, char *argv[])
{   int wstatus;
    int rc = fork();
    if(rc < 0)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if(rc == 0)
    {   
        //Because child process cannot call any more child process, so -1 is returned
        pid_t pid = waitpid(-1,NULL,WUNTRACED|WCONTINUED);
        printf("Child Process; Wait PID: %d\n", (int)pid);
    }
    else
    {   //the PID of the child process is returned
        //pid_t waitpid(pid_t pid, int *status, int options)
        //(1) By default, waitpid() waits only for terminated children, but this behavior is modifiable via option argument such as 
        //WIFEXITED, WEXITSTATUS
        //(2) pid < -1: wait for any children pricess whose process ID is equal to the absolute value of the pid
        //    pid = -1: wait for ang child process
        //    pid = 0 : wait for child process whose PID is equal to the calling process
        //    pid >0 : wait for the child whose process ID is equal to the value of PID 
        pid_t pid = waitpid(rc,&wstatus,WUNTRACED|WCONTINUED);//WUNRACED: STOPPED CHILDREN; WCONTINUED: CONTINUED CHILDREN
        printf("Parent Process; Wait PID: %d\n ",(int)pid);
        //WIFEXITED, WEXITSTATUS can be used within the wait() or waitpid() to learn about the status of its stopped child
        printf("If the child terminated normally: %s\n", WIFEXITED(wstatus)?"true":"false");
        //WIFEXITED(status): returns true if the child terminated normally
        //WEXITSTATUS(status): returns the exit status of the child. This macro should be employed only if WIFEXIED returned true
        //WEXITSTATUS(status): (1) return 1: Miscellaneous error: divided by 0 and other impermissible error
        //(2) return 2: keyword or command, or permission problem
        //(3) return 126: permission problem or command is not an executable
        //(4) return 128: invalid argument to exit
        //(5) return 0: normally

    }

    return 0;
}