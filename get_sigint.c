#include "main.h"

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
<<<<<<< HEAD
}
=======
}
>>>>>>> 0bac20069f2c0500e2024ed4948377f752b00b63
