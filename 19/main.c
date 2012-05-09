#include <stdlib.h>
#include <stdio.h>

#define MONTHS 12
#define WEEK 7

int days_in_months[MONTHS] =
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int days_in_months_leap[MONTHS] =
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char day_names[WEEK][10] =
	{ "sun", "mon", "tues", "wed", "thurs", "fri", "sat" };
char month_names[MONTHS][10] =
	{ "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };

// predicate for whether a given year number is a leap year or not
bool is_leap_year(int year)
{
	if (0 == year % 400)
		return true;
	if (0 == year % 100)
		return false;
	return (0 == year % 4);
}

// next day of week. sunday = 0, monday = 1, etc.
void incr_day_of_week(int &day)
{
	day = (6 == day ? 0 : ++day);
}

// iterate days in a year, keeping track of sundays on 1st day of month
// start [in,out]: week day of 1st jan 
void process_one_year(int year, int &start, int &sundays)
	{
	bool leap = is_leap_year(year);
	const int *months = leap ? days_in_months_leap : days_in_months;

	for (int month = 0; month < MONTHS; month++)
		{
		for (int day = 0; day < months[month]; day++, incr_day_of_week(start))
			{
			if (0 == day && 0 == start)
				sundays++;
			}
		}
	}


int main(int argc, char *argv[])
{
	// get the first week day of 1901
	int week_day = 1;
	int unused = 0;
	process_one_year(1900, week_day, unused);

	// count sundays being 1st of the month
	int sundays = 0;
	for (int year = 1901; year <= 2000; year++)
		process_one_year(year, week_day, sundays);

	printf("%d\n", sundays);
	return 0;
}
