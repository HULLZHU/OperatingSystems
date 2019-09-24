#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{   
    //args: A null terminated array of character pointers
    char *args[] = {"./EXEC",NULL};
    execvp(args[0],args);

    printf("ENDING---");
    return 0;
}