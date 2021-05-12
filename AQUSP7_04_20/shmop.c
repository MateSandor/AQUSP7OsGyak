#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMKEY 3212

void main() {
    int sharedMemoryId = shmget(SHMKEY, 0, 0);
    
    char *segm = shmat(sharedMemoryId, NULL, SHM_RND);
    strcpy(segm, "uzenet");

    printf("A kozos memoria tartalma : %s\n", segm);

    shmdt(segm);
}