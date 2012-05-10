#include <stdio.h>
#include <string.h>


#define MINI 100
#define MAXI 999
#define MINPROD (MINI*MINI)
#define MAXPROD (MAXI*MAXI)


int isPalindrome(int x)
{
	char val[32];
	sprintf(val, "%d", x);
	size_t len = strlen(val);
	size_t comparisons = len/2;
	size_t i;
	for (i = 0; i < comparisons; i++)
	{
		if (val[i] != val[len-i-1])
			return 0;
	}
	return 1;
}


int hasFactors(int test, int *f1, int *f2)
{
	int g1;
	for (g1 = MAXI; g1 >= MINI; g1--)
	{
		if (0 == test % g1)
		{
			int g2 = test / g1;
			if (g2 >= MINI && g2 <= MAXI)
			{
				*f1 = g1;
				*f2 = g2;
				return 1;
			}
		}
	}
	return 0;
}


int main()
{
	int f1 = 0;
	int f2 = 0;
	
	int test;
	for (test = MAXPROD; test >= MINPROD; test--)
	{
		if (isPalindrome(test))
		{
			if (hasFactors(test, &f1, &f2))
			{
				printf("%d\n", test);
				return 0;
			}
		}
	}
	
	printf("nothing found :(\n");
	return 1;
}
