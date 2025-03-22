#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Hello, world (pid:%d)!\n",(int)getpid());
    int rc = fork();
    if (rc<0) //fork failed exit
    {
       exit(1);
    }else if (rc==0)
    {
        /* code */
    }else{

    }
    return 0;
}