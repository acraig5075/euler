#include <stdio.h>

#define	even(x) (!(x&1))

inline long callatz(long x)
{
	//return even(x) ? x / 2 : 3 * x + 1;
	return even(x) ? x >> 1 : x + (x << 1) + 1;
}

long sequence(long x)
{
	long count = 1;
	while (x != 1)
	{
		x = callatz(x);
		count++;
	}
	return count;
}

int main(int argc, char *argv[])
{
	argc--;
	argv++;

	long longest = 0;
	long answer = 0;
	for (long start = 999999; start > 0; start -= 2)
	{
		long chain = sequence(start);
		if (chain > longest)
		{
			longest = chain;
			answer = start;
		}
	}		
	printf("%ld\n", answer);

	return 0;
}
