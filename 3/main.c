#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPrime(int x)
{
	if (0 == x%2)
		return false;
	int root = (int)ceil(sqrt((double)x));
	for (int i = 3; i < root; i += 2)
	{
		if (0 == x%i)
			return false;
	} 
	return true;
}

int main(int argc, char *argv[])
{
	long long int target = (2 == argc ? atoll(argv[1]) : 600851475143LL);
	int divisor = 3;
	while (divisor <= target)
	{
		if (isPrime(divisor) && (0 == target%divisor))
		{
			target /= divisor;
			printf("%d\n", divisor);
		}
		divisor += 2;
	}
	return 0;
}

