#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char units[10][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char tens[10][20] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char teens[10][20] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

char scratch[256];

char *val_name(int val)
{
	scratch[0] = '\0';

	// handle outside case of 1000, and invalid number
	if (val > 1000 || val < 1)
		return scratch;
	else if (1000 == val)
		strcpy(scratch, "onethousand");

	// remove the thousands part
	while (val >= 1000)
		val -= 1000; 

	// handle the hundreds part
	if (val / 100 > 0)
		sprintf(scratch, "%shundred", units[val / 100]);
	if (val / 100 > 0 && 0 != val % 100)
		strcat(scratch, "and");

	// remove the hundreds part
	while (val > 100)
		val -= 100; 

	// handle the tens part, and more awkwardly the teens
	bool the_teens = 1 == val / 10;
	if (the_teens)
		strcat(scratch, teens[val % 10]);
	else if (val / 10 > 1)
		strcat(scratch, tens[val / 10]);

	// remove the tens part
	if (!the_teens)
	while (val > 10)
		val -= 10; 

	// finished
	if (0 != val)
		strcat(scratch, units[val]);
	return &scratch[0];
}

void test(int val)
{
	printf("%4d: %s\n", val, val_name(val));
}

size_t val_length(int val)
{
	return strlen(val_name(val));
}

int main(int argc, char *argv[])
{
/*
	test(1);
	test(10);
	test(15);
	test(20);
	test(35);
	test(99);
	test(100);
	test(111);
	test(145);
	test(160);
	test(200);
	test(310);
	test(457);
	test(717);
	test(999);
	test(1000);
*/
	size_t total = 0;
	for (int i = 1; i <= 1000; i++)
		total += val_length(i);
	
	printf("%lu\n", total);
	return 0;
}

