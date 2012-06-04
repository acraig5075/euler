#include <iostream>
#include <set>

#define LIMIT 28123
//#define LIMIT 100

int count_divisors(int x)
	{
	//std::cout << x << ": ";
	int count = 1;
	int b = x;
	for (int i = 2; i < b; i++)
		{
		if (0 == x % i)
			{
			b = x / i;
			count += i;
			//std::cout << i << " ";

			if (i != b)
				{
				count += b;
				//std::cout << b << " ";
				}
			}
		}
	//std::cout << "(" << count << ")" << std::endl;
	return count;
	}

int main()
{
	std::set<int> aset;
	std::set<int> bset;

	// insert all abundant numbers into a list (unique)
	long total = 0;
	for (int i = 1; i <= LIMIT; i++)
	{
		int a = count_divisors(i);
		bool abundant = (a > i);
		if (abundant)
			aset.insert(i);
		total += i;
	}

	// make another list of all possible additions
	while (aset.size() > 0)
	{
		std::set<int>::iterator itr1, itr2;
		itr1 = aset.begin();
		for (itr2 = aset.begin(); itr2 != aset.end(); itr2++)
		{
			int x = *itr1 + *itr2;
			if (x <= LIMIT)
				bset.insert(x);
		}
		aset.erase(itr1);
	}

	// sum positive integers not in this list
	long sum = 0;
	for (int j = 1; j <= LIMIT; j++)
		{
		if (bset.find(j) == bset.end())
			sum += j;
		}

	long count = 0;
	std::set<int>::iterator itr;
	for (itr = bset.begin(); itr != bset.end(); itr++)
		count += *itr;

	std::cout << total << "\n";
	std::cout << count << "\n";
	std::cout << sum << "\n";
	return 0;	
}
