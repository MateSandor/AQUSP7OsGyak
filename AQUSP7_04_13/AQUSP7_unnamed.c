#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MSIZE 128
int main(){
char inBuffer[MSIZE];
int pid, fileDesc;
char input[] = "Sandor Mate";
char * fifo = "/tmp/AQUSP7";
mkfifo(fifo, 0666);
pid = fork();
if (pid < 0)
    exit(2);
//Child Beleír
if (pid == 0){
    printf("Child: Most fogok beirni a fifo pipe-ba!\n");
    fileDesc = open(fifo, O_WRONLY);
    write(fileDesc, input, strlen(input)+1);
    printf("Child: Sikeresen irtam a pipe-ba!\n");
}
//Parent Kiolvassa
else if (pid > 0 ){
    fileDesc = open(fifo, O_RDONLY);
    read(fileDesc, inBuffer, strlen(input)+1);
    printf("Parent jelenti: Ezt kaptam: %s\n", inBuffer);
    close(fileDesc);
}

return 0;
}
