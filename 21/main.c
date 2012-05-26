#include <stdio.h>

int count_divisors(int x)
{
	int count = 1;
	int b = x;
	for (int i = 2; i < b; i++)
	{
		if (0 == x % i)
			{
			b = x / i;
			count += i;
			count += b;
			}
		}
	return count;
	}

int main()
{
	int sum = 0;
	for (int i = 1; i < 10000; i++)
	{
		int a = count_divisors(i);
		int b = count_divisors(a);
		bool amicable = (i == b && a != b);
		if (amicable)
			sum += a;
	}
	printf("%d\n", sum);
	return 0;	
}