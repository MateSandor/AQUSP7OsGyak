#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 832712L

typedef struct msgbuf1 {
    long mtype;
    char mtext[512];
} messageBuffer;

void main() {
	messageBuffer recieveBuffer;
    	messageBuffer *messagePointer = &recieveBuffer;

    	struct msqid_ds descriptor;
    	struct msqid_ds *buffer = &descriptor;
    	
	int msgid;
	int msgsz;
	int ret;
	int msglgnt = 50;
	int msgtype = 0;
	int msgflag = 0;
	
	key_t key = MSGKEY;
	
	msgid = msgget(key, 0);
	if (msgid == -1) {
        perror("Nem sikerult megnyitni a messaget!\n");
        exit(-1);
    	}
    	
    	while (buffer->msg_qnum) {
		ret = msgrcv(msgid , (messageBuffer*)messagePointer, msglgnt, msgtype , msgflag );
		printf("A kikuldott uzenet: %s\n", messagePointer->mtext);
		ret = msgctl(msgid , IPC_STAT, buffer);
    	}	
}