#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_COUNT 5163
#define MAX_LENGTH 32

bool read_file(const char *filename, char **names)
	{
	FILE *fp = fopen(filename, "rt");
	if (NULL == fp)
		return false;

	if (fp)
		{
		int ni = 0; // row count
		int ci = 0; // column count
		int open = false; // parenthesis open

		while (!feof(fp))
			{
			int c = getc(fp);
			if (c == '\"')
				{
				open = !open;
				if (!open)
					names[ni++][ci] = '\0';
				ci = 0;
				}
			else if (c != ',' && c != EOF)
				{
				names[ni][ci++] = c;
				}
			}

		fclose(fp);
		}
	return true;
	}

int sort_fn(const void *a, const void *b)
	{
	const char *aa = *(const char **)a;
	const char *bb = *(const char **)b;
	return strcmp(aa, bb);
	}

void sort_names(char **names)
	{
	qsort(names, NAME_COUNT, sizeof(names), &sort_fn);
	}

long word_score(int row, const char *name)
	{
	int score = 0;
	const char *c = &name[0];
	while (*c != '\0')
		{
		score += (int)(*c) - 64;
		c++;
		}
	return (long)(row * score);
	}

long total_score(char **names)
	{
	long score = 0L;
	for (int i = 0; i < NAME_COUNT; i++)
		score += word_score(i + 1, names[i]);
	return score;
	}

int main(int argc, char *argv[])
	{
	char **names = (char **)malloc(sizeof(char *) * NAME_COUNT);
	for (int j = 0; j < NAME_COUNT; j++)
		names[j] = (char *)malloc(sizeof(char) * MAX_LENGTH);

	const char *filename = "names.txt";
	if (!read_file(filename, names))
		return 1;

	sort_names(names);

	long score = total_score(names);
	printf("%ld\n", score);

	return 0;
	}
