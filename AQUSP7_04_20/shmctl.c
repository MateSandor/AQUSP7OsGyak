#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMKEY 3212

void main() {
    int sharedMemoryId = shmget(SHMKEY, IPC_RMID, 0);
    struct shmid_ds buffer;
    if (shmctl(sharedMemoryId, IPC_STAT, &buffer) == -1) {
        perror("Nem sikerult az adatokat lekerdezni");
        exit(-1);
    }
}
