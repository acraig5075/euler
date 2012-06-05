#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#if !defined(__linux__)
#define __strrev strrev
#endif

char* strrev(char* szT)
{
	if ( !szT ) // handle null passed strings.
		return NULL;
	int i = strlen(szT);
	int t = !(i%2)? 1 : 0; // check the length of the string .
	for(int j = i-1 , k = 0 ; j > (i/2 -t) ; j-- )
		{
		char ch = szT[j];
		szT[j] = szT[k];
		szT[k++] = ch;
		}
	return szT;
}

// http://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
bool next(const int *count, char *a)
{
	int k, l;
	// Find the largest index k such that a[k] < a[k + 1]
	for (k = 8; k >= 0; k--)
		{
		if (a[k] < a[k + 1])
			break;
		}
	if (k < 0)
		return false;

	// Find the largest index l such that a[k] < a[l]
	for (l = 9; l >= 0; l--)
		{
		if (a[k] < a[l])
			break;
		}
	if (l < 0)
		return false;

	// Swap a[k] with a[l] and Reverse the sequence from a[k + 1]
	int temp = a[k];
	a[k] = a[l];
	a[l] = temp;
	if (k < 9)
		strrev(&a[k + 1]);

	//printf("%7d, %d, %d, %s\n", *count, k, l, a);
	return true;
}

int main(int argc, char *argv[])
{
	argc--;
	argv++;
	int maximum = argc > 0 ? atoi(argv[0]) : 1000000;

	char a[] = "0123456789";
	// printf("%7d, 0, 0, %s\n", 0, a);
	
	for (int count = 1; count < maximum; count++)
		{
		if (!next(&count, a))
			{
			printf("premature fail\n");
			break;
			}
		}
	printf("%s\n", a);

	return 0;
}
