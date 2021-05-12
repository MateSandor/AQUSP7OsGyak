#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 321711L

typedef struct msgbuf1 {
    long mtype;
    char mtext[512];
} messageBuffer;

void main() {
	pid_t pd;
	key_t key = MSGKEY;
	pd = fork();
	if(pd<0){
		fprintf(stderr, "fork Failed");
		exit(-1);
	}
	else if(pd>0){
		messageBuffer sendBuffer;
        	messageBuffer *messagePointer;
    	
		int msgid;
		int ret;
		int msgflag;
		int msgsz;
		
		msgflag = 0666 | IPC_CREAT;
		msgid = msgget(key, msgflag);
		if (msgid == -1) {
                perror(": msgget() nem sikerult!");
                exit(-1);
		}

		messagePointer = &sendBuffer;
       	messagePointer->mtype = 1;
        	char *messages[] = {"elso", "masodik", "harmadik"};
        
        	for (int i = 0; i < 3; i++) {
           	 strcpy(messagePointer->mtext, messages[i]);
           	 msgsz = strlen(messagePointer->mtext) + 1;

           	 ret = msgsnd(msgid, (messageBuffer*)messagePointer, msgsz, msgflag);
           	 if (ret == -1) {
            	    perror("Nem sikerult kuldeni\n");
            	    exit(-1);
           	 }
        	}
        
        	printf("Elkuldte a messageket!\n");
	}
	else{
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
		
		msgid = msgget(key, 0);
		ret = msgctl(msgid, IPC_STAT, buffer);
		printf("Az uzenetek szama: %ld\n", buffer->msg_qnum);
	}
}