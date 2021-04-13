#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MSIZE 10
int main(){
char inBuffer[MSIZE];
int p[2], nbytes, pid;
if (pipe(p) < 0){
    perror("Pipe hiba");
    exit(1);
}
pid = fork();
if (pid < 0)
    exit(2);
//Child beleír
if (pid == 0){
    printf("Child: Most irok a pipe-ba!\n");
    write(p[1], "SM AQUSP7", MSIZE);
    printf("Child: Sikeresen irtam pipe-ba, olvasható!\n");
}
//Parent Kiolvassa
else if (pid > 0 ){
    wait(NULL);
    printf("Parent: Vettem! Most fogok kiolvasni a pipe-bol!\n");
    read(p[0], inBuffer, MSIZE);
    printf("Ezt olvastam ki: %s\n", inBuffer);
    printf("Parent jelzi: elkeszult!\n");
}

return 0;
}

