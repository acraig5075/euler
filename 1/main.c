#include <stdio.h>

int main()
{
	int sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (0 == i%3 || 0 == i%5)
			sum += i;		
	}
	printf("%d\n", sum);
}
