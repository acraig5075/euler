#include <stdio.h>
#include <math.h>

bool isPrime(int x)
{
	//if (0 == x%2)
	//	return false;
		
	int root = (int)ceil(sqrt((double)x)+.1);
	for (int i = 3; i < root; i += 2)
	{
		if (0 == x%i)
			return false;
	} 
	return true;
}

int main(int argc, char *argv[])
{
	int primes = 1;
	int test = 1;
	while (primes < 10001)
	{
		test += 2;
		
		if (isPrime(test))
			primes++;
	}
	
	printf("%d\n", test);
	return 0;
}
