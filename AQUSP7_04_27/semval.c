#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 12345L

union semun{
   	int val;
   	struct semid_ds *buf;
   	unsigned short *array;
   	struct seminfo *__buf;
};

void main(){
    
   	int semID = semget(SEMKEY, 0, 0);
    	int n = 5;
   	if (semID == -1) {
     		perror("Nem sikerult semaforokat lekerdezni\n");
     		exit(-1);
    	}

    	union semun arg;

    	printf("Semaforok tartalma: \n");
    	arg.array = (short *)calloc(n, sizeof(int));

    	semctl(semID, 0, GETALL, arg);

   	 for (int i = 0; i < n; i++) 
       	 printf("%d ", arg.array[i]);   
}