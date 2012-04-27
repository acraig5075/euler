#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define	even(x) (!(x&1))

bool isPrime(long x)
{
	if (even(x))
		return false;

	long root = (long)ceil(sqrt((double)x)) + 1;
	for (long i = 3; i < root; i += 2)
	{
		if (0 == x%i)
			return false;
	} 

	return true;
}

int main(int argc, char *argv[])
{
	argc--;
	argv++;

	long max = (argc > 0 ? atoi(argv[0]) : 2000000);

	long sum = 2;
	for (long i = 3; i < max; i += 2)
	{
		if (isPrime(i))
		{
			sum += i;
		}
	}
	printf ("%ld\n", sum);
	return 0;
}

