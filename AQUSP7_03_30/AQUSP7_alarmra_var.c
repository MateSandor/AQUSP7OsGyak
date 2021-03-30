/************************************************************
 * Project: Szoftverrendszerek, signal kezeles
 * File name: $HOME/cs/alarmra_var.c
 * Abstract: Pelda signal kezelesre.
 *           Az alarm signal handler-e a do_nothing.
 * Usage:    >cc -o alarmra_var alarmra_var.c-lc_s
 *
 *           >alarmra_var & 
 *            # es jegyezd meg a pid-jet
 * Athor: Dr. Vadasz Denes
 * Internals: signal (), pause()
 *         
 * Bugs, problems: none
 * History: 
 *   Created: 1993. oct. 11
 *   Modified:
*************************************************************/

#include <unistd.h>
#include <signal.h>


void do_nothing();


main ()
{


	signal(SIGALRM, do_nothing);
	printf("  %d varok de meddig?\n");
	pause();
    	printf("  Vegre, itt az alarm \n");
}	
void do_nothing(){ ;}
