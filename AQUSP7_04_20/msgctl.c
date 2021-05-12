#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 832712L

void main() {
    key_t key = MSGKEY;
    int msgid= msgget(key, 0);
    int ret = msgctl(msgid, IPC_RMID, NULL);
    if (msgid == -1) {
        perror("Nem sikerult kitorolni!\n");
        exit(-1);
    }

    printf("Sikerult kitorolni!\n");

}