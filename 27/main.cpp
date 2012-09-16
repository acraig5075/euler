#include <math.h>
#include <iostream>
#include <map>

bool isPrime(int x)
{
	int root = (int)ceil(sqrt((double)x) + 0.1);
	for (int i = 3; i < root; i += 2)
	{
		if (0 == x % i)
			return false;
	}
	return true;
}

bool isPrime(std::map<int, bool> &primes, int x)
{
	if (x < 1 || x % 2 == 0)
		return false;

	std::map<int, bool>::iterator itr = primes.find(x);
	if (itr == primes.end())
	{
		// determine for the first time and cache result
		bool p = isPrime(x);
		primes.insert(std::pair<int, bool>(x, p));
		return p;
	}
	else
	{
		// it's been calculated before, so return cached result
		return (*itr).second;
	}
}

inline int func(int a, int b, int n)
{
	return (n * n) + (a * n) + b;
}

int main(int /*argc*/, char ** /*argv[]*/)
{
	std::map<int, bool> primes; // lookup table of cached results
	int consec = 0; // count of consecutive primes
	int result = 0;

	for (int a = -999; a < 1000; a++)
	{
		for (int b = -999; b < 1000; b++)
		{
			int n = 0;
			while (true)
			{
				bool p = isPrime(primes, func(a, b, n));
				n++;
				if (p)
				{
					if (n > consec)
					{
						consec = n;
						result = a * b;
					}
				}
				else
					break;
			}
		}
	}

	std::cout << result << std::endl;
	return 0;
}
