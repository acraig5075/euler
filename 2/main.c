#include <stdio.h>

int main()
{
	int sum = 0;
	int fib = 0;
	int f1 = 0;
	int f2 = 1;

	for (; f1 < 4000000; f1=f2,f2=fib) 
	{
		fib = f1+f2;
		if (0 == fib%2)
			sum += fib;
	}
	
	printf("%d\n", sum);
}
