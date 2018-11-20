#include "fuji.h"

/**
 * signal_handler - reprints prompt when signal ctrl+C is captured
 * @signo: signal number
 */
void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(2, "\n", 1);
		write(2, "Fuji$ ", 6);
	}
	
	if (signo == SIGCHLD)
		exit(0);
}
