/************************************************************
 * Project: Szoftverrendszerek, signal kezeles
 * File name: $HOME/cs/alarm.c
 * Abstract: Pelda signal kezelesre.
 *           ctrl/break signal hatasara a do_int handler mukodik
 *           eloszor, majd ignoralodik ez a signal.
 *           A ciklusban masodpercenkent alarm generalodik,
 *           az alarm signal handler-e a do_nothing.
 *           A pause felfuggeszti a process-t, amig kap egy signalt.
 * Usage:    cc -o alarm alarm.c -lc_s
 *
 *           alarm
 * Athor: Dr. Vadasz Denes
 * Internals: signal (), alarm(), pause()
 *         
 * Bugs, problems: none
 * History: 
 *   Created: 1993. oct. 7
 *   Modified:
*************************************************************/

#include <unistd.h>
#include <signal.h>
#define SECOND 1

void do_nothing();
void do_int();

main ()
{
	int i;
	unsigned sec=1;

	signal(SIGINT, do_int);

for (i=1;i<8;i++) {
	alarm(sec);
	signal(SIGALRM, do_nothing);
	printf("  %d varok de meddig?\n",i);
	pause();
    }
}	
void do_nothing(){ ;}

void do_int() {
	printf(" int jott ");
	signal(SIGINT,SIG_IGN);
}