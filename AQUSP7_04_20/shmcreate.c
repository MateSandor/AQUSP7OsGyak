  
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMKEY 3212

void main() {
    int sharedMemoryId = shmget(SHMKEY, 256, IPC_CREAT | 0666);
    printf("Letrehoztam az osztott memoriat.\n");
}