#include <stdio.h>

/**
 * pre_main - function that runs before main
 *
 * Return: void
 */
void __attribute__ ((constructor)) pre_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
