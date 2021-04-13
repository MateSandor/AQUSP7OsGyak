#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void TerminationHandler(int sig);

int main(void)
{
    if (signal(SIGTERM, TerminationHandler) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) \"SIGTERM\" jelre!\n");
        return 0;
    }

    while(1)
    {
        sleep(3);
	printf("\nWaiting...\n");
    }

    return 0;
}

void TerminationHandler(int sig)
{
    signal(sig, SIG_IGN);
    printf("SIGTERM signal: %d\n", sig);
}
