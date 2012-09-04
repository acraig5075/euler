#include <stdlib.h>
#include <stdio.h>

// does search exist inside array
int exists(const int *done, int size, int search)
{
	while (size > 0)
	{
		--size;
		if (done[size] == search)
			return 1;
	}
	return 0;
}

// count of recurring subsequence in decimal part of reciprocal(denominator)
int recurring(int denominator)
{
	int done[1000] = {0};
	int done_size = 0;

	int a;
	if (denominator < 10)
		a = 10;
	else if (denominator < 100)
		a = 100;
	else
		a = 1000;

	int count = 0;

	while (a != 0)
	{
		int b = a / denominator;

		a -= b * denominator;

		if (exists(done, done_size, a))
			return count;
		else
			done[done_size++] = a;

		++count;
		a *= 10;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int limit = argc == 2 ? atoi(argv[1]) : 1000;

	int r = 0; // length of recurring cycle
	int d = 0; // test value d < 1000

	for (int i = 2; i < limit; i++)
	{
		int r0 = recurring(i);
		if (r0 > r)
		{
			r = r0;
			d = i;
		}
	}

	printf("%d\n", d);
	return 0;
}
