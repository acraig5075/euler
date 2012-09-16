#include <stdio.h>

int main()
{
	int sum; // summation of diagonals
	int value; // running index
	int dimension; // dimension of square
	int cnr_interval; // interval of items between corners
	int num_on_edge; // number of items on an edge of a square
	int i;

	sum = 1;
	value = 1;

	for (dimension = 3; dimension <= 1001; dimension += 2)
	{
		cnr_interval = dimension - 1;
		num_on_edge = 1 + cnr_interval * 4;

		for (i = 1; i < num_on_edge; i++)
		{
			value++;

			if (i % cnr_interval == 0)
				sum += value;
		}
	}

	printf("%d\n", sum);
	return 0;
}
