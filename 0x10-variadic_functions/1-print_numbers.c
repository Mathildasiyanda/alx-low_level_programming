#include "variadic_functions.h"

/**
 * print_numbers - Output numbers.
 * @separator: content to be printed between nums
 * @n: The number of integers to be used.
 * @...: unspecified number of numbers to be passed
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int count = 0;
	va_list arguments;

	va_start(arguments, n);

	if (separator == NULL)
		separator = "";


	while (count < n)
	{
		printf("%d", va_arg(arguments, int));

		if (separator && count < n - 1)
			printf("%s", separator);
		count++;
	}

	printf("\n");
	va_end(arguments);
}
