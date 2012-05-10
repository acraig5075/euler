#include <stdio.h>


int main()
{
	int test;
	for (test = 2;; test += 2)
	{
		int f[10] = {20,19,18,17,16,15,14,13,12,11};
		
		int i;
		for (i = 0; i < 10; i++)
		{
			if (0 != test % f[i])
				break;			
		}
		
		if (10 == i)
		{
			printf("%d\n", test);
			return 0;
		}
	}
	
	return 1;
}
