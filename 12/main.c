#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long countFactors(long x)
{
	long count = 2; // known factors are 1 and itself
	long root = (long)ceil(sqrt((double)x)) + 1;

	for (long i = 2; i < root; i++)
	{
		if (0 == x%i)
			count += 2; // mirror image
	}
	return count;
}

int main(int argc, char *argv[])
{
	argc--;
	argv++;

	long divisors = (argc > 0 ? atol(argv[0]) : 500);
	long previous = 0;
	long i = 1;

	while (true)
	{
		long triangle = previous + i;
		long factors = countFactors(triangle);
		if (factors > divisors)
		{
			printf("%ld\n", triangle);
			return 0;
		}
		previous = triangle;
		i++;
	}
	return 1;
}

