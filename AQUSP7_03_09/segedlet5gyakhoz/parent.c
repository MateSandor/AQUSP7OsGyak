#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void) {
        pid_t pid;

        if ((pid = fork()) < 0){
                perror("process error");
        }else if (pid == 0){
                if(execl("./child", "child", (char *) NULL) < 0){
                        perror("execl error");
                }
        }
        if (waitpid(pid, NULL, 0) < 0){
                perror("wait error");
        }
        return 0;
}
