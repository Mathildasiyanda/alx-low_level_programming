#include "main.h"

/**
 * print_chessboard - prints the chessboard.
 * @a: array of size 8
 * Return:
 */
void print_chessboard(char (*a)[8])
{
	int c;
	int d;

	c = 0;
	while (c < 8)
	{
		d = 0;
		while (d < 8)
		{
			_putchar(a[c][d]);
			d++;
		}
		_putchar('\n');
		c++;
	}
}
