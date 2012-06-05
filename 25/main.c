#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(long term, int *s)
{
	printf("Term %6ld: ", term);
	for (int i = 990; i < 1000; i++)
		printf("%d", s[i]);
	printf("\n");
}

int num_digits(int *s)
{
	int i = 0;
	while (0 == s[i])
		++i;
	return 1000 - i;
}

long fibonacci(int digits)
{
	int a[1000] = {0};
	int b[1000] = {0};
	int c[1000] = {0};
	a[999] = 1;
	b[999] = 1;
	long term = 3L;

	// print(1L, a);
	// print(2L, b);

	while (true)
		{
		int carry = 0;
		for (int i = 999; i >= 0; i--)
			{
			int sum = carry + a[i] + b[i];
			c[i] = sum % 10;
			carry = sum / 10;
			}
		// print(term, c);
	
		if (digits == num_digits(c))
			break;

		memcpy(a, b, 1000 * sizeof(int));
		memcpy(b, c, 1000 * sizeof(int));
		memset(c, 0, 1000 * sizeof(int));
		term++;
		}

	return term;
}

int main(int argc, char *argv[])
{
	argc--;
	argv++;
	int digits = argc > 0 ? atoi(argv[0]) : 1000;

	long term = fibonacci(digits);
	printf("%ld\n", term);
	return 0;
}
