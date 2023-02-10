#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void handler_signal(int signum)
{
    wait(NULL);
}

int main(int argc, char const *argv[]) 
{
    pid_t child_pid; 
    //int status, r_wait;              

    child_pid = fork();         
    if (child_pid >= 0) 
    {
        if (child_pid == 0) 
        {   
            for(int i = 0; i < 5; i++)
            {   
              printf("Children PID is: %d\n", getpid());
            }
            //sleep(3);
            //while(1);
        } 

        else 
        {
            signal(SIGCHLD, handler_signal);
            printf("Parent PID is: %d\n", getpid());
            while(1);
        }
    } 

    else 
    {
        printf("fork() fail\n"); 
    }

    return 0;
}
