#include <stdio.h>

int main()
{
	const int square_sum = 5050 * 5050;
	
	int sum_squares = 0;
	
	int i;
	for (i = 1; i <= 100; i++)
		sum_squares += i * i;

	printf("%d\n", square_sum - sum_squares);
	
	return 0;
}
