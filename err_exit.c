#include "fuji.h"
/**
* err_exit - prints out an error and exits
* @status: exits with this status
*/

void err_exit(int status)
{
	perror("./shell: ");
	exit(status);
}
