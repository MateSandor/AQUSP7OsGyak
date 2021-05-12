#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 12345L

union semun {
    	int val;
    	struct semid_ds *buf;
   	unsigned short *array;
   	struct seminfo *__buf;
};


void main(){
	union semun arg;
	
    	int semID = semget(SEMKEY, 1, IPC_CREAT | 0666);
	arg.val = 15;
	semctl(semID, 0, SETVAL, arg);
   	if (semID == -1) {
     	  	perror("Nem sikerult semaforokat letrehozni");
   	 	exit(-1);
    	}
   
	
   	printf("%d\n", arg);

}
