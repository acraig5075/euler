#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define width 500

int main(int argc, char *argv[])
{
	int a[2][width];
	memset(&a[0], 0, 2 * width * sizeof(int));
	a[0][width - 1] = 1;
	
	int limit = 2 == argc ? atoi(argv[1]) : 1000;
	for (int i = 0; i < limit; i++)
	{
		int this_idx = i % 2;
		int next_idx = (i + 1) % 2;

		int carry = 0;
		for (int j = width - 1; j >= 0; j--)
		{
			int v = a[this_idx][j];
			int w = (v << 1) + carry;
			a[next_idx][j] = w % 10;
			carry = w / 10;
		}
	}
		
	int final_idx = limit % 2;
	int solution = 0;
	for (int k = 0; k < width; k++)
		solution += a[final_idx][k];
	printf("%d\n", solution);	
	return 0;
}
