#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    
    if(pid == 0)
    {
        execl("/bin/ls","bin/ls","-a",NULL);
    }

    int status;

    waitpid(pid, &status, 0);

    if(WIFEXITED(status))
    {
        int exit_status = WEXITSTATUS(status);
        printf("The exit status of the child process was %d\n",exit_status);
    }
    return 0;
}