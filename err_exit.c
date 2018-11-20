#include "fuji.h"
/**
* err_exit - prints out an error and exits
* @status: exits with this status
*/

void err_exit(char *argv, int status)
{
	perror(argv);
	exit(status);
}
