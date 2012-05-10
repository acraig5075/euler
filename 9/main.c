#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// integer sqrt
int isqrt(int x)
{
	for (int i = x/2; i > 0; i--)
	{
		if (x == i * i)
			return i;
	}
	return -1;
}


int main()
{
	for (int a = 2; a < 500; a++)
		{
		for (int b = a-1; b > 2; b--)
			{
			int c = isqrt(a * a + b * b);
			if (-1 == c)
				continue;
			
			if (1000 == a + b + c)
				{
				printf("%d\n", a * b * c);
				return 0;
				}
			}
		}
	return 1;
}
