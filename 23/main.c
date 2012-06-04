#include <iostream>
#include <set>

#define LIMIT 28123

// return summation of divisors - Abundant numbers are less than this summation
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

			if (i != b)
				count += b;
			}
		}
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

	// sum all elements in the list
	long sum = 0;
	std::set<int>::iterator itr;
	for (itr = bset.begin(); itr != bset.end(); itr++)
		sum += *itr;

	// summation of values not in this list is the difference between
	// the total and the summation of what is in the list.
	std::cout << total - sum << "\n";
	return 0;	
}
