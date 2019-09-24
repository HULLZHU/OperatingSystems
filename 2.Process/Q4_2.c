#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


/*
int excel(const char* path, const char *arg, ...)
int excelp(const char *file, const char *arg, ...)
int excele(const char *path, const char *arg, ...)
int execle(const char *path, const char *argm .., char )
int execv(const char* path, char *const argv[])
int execvp(const char *file, char *const argv[])
int execvpe(const char *file, char *const argv[], char *const envp[])

path: executable file's path
arg: excutable's arguments, arg[0]: executable name without path, arg[last]: NULL
file: with /, seen as path name; otherwise seen as environment PATH Variable
*/

int main(int argc, char *argv[])
{
    int rc = fork();
    if(rc < 0 )
    {
        fprintf(stderr,"Fork Failed\n");
        exit(1);
    }
    else if(rc == 0)
    {
        char * argv[] = {"ls","-l","-a","-h", NULL};
        char * envp[] = {NULL};

        execl("/bin/ls","ls","-l","-a","-h",NULL);
        execlp("ls","ls","-l","-a","-h",NULL);
        execle("/bin/ls","ls","-l","-a","-h",NULL,envp);

        execv("/bin/ls",argv);
        execvp("ls", argv);
        //execvpe("ls",argv,envp); //may not work
    }
    else
    {
        printf("Parent Process\n");
    }
    
    return 0;
}