#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
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
arg: excutable's arguments, arg[0]: executable name, arg[last]: NULL
*/

int main(int argc, char *argv[])
{
    int rc = fork();
    if(rc < 0)
    {
        fprintf(stderr,"Fork Failed\n");
        exit(0);
    }
    else if(rc == 0)//
    {
        /* child  process*/
        char *myargs[2];
        myargs[0] = "ls";
        myargs[1] = NULL;
        execvp(myargs[0], myargs);
        printf("This should not be printed out");
    }
    else
    {
        printf("Parent Process \n");
    }

    return 0;

}
