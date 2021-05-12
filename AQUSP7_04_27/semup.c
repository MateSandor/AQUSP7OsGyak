#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 12345L

void main(){
	int semID = semget(SEMKEY , 0, 0);
   	if (semID == -1){
   	    	perror("Nem sikerult semaforokat lekerdezni\n");
     		exit(-1);
   	}

   	struct sembuf buffer;

  	buffer.sem_num = 3;
  	buffer.sem_op = 1; 
  	buffer.sem_flg = 0666; 

   	if (semop(semID, &buffer, 1)){
       	perror("Sikertelen\n");
       	exit(-1);
    	}
}