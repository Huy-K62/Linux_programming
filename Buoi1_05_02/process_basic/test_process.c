#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) 
{
    pid_t child_pid; 
    int status, r_wait;              

    child_pid = fork();         
    if (child_pid >= 0) 
    {
        if (child_pid == 0) 
        {      
            printf("Children PID is: %d, my parent PID is: %d\n", getpid(), getppid());
            //sleep(3);
            while(1);
        } 

        else 
        {
            printf("Parent PID is: %d\n", getpid());
            
            r_wait = waitpid(child_pid, &status, 0);
            if (r_wait == -1) 
            {
                printf("wait() fail\n");
            }
            //while(1);
            
            if (WIFEXITED(status)) 
            {
                printf("Normally termination, status=%d\n", WEXITSTATUS(status));
            } 
            
            else if (WIFSIGNALED(status))
            {
                printf("killed by signal, value = %d\n", WTERMSIG(status));
            }
        }
    } 

    else 
    {
        printf("fork() fail\n"); 
    }

    return 0;
}
