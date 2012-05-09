#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<int> numbers; // global storage of triangle data
map<int,int> row_map; // map of row numbers to corresponding index into `numbers'

// Read contents of file into one array of integers (global `numbers')
int read_numbers(const char *filename)
	{
	fstream fin;
	fin.open(filename, ios_base::in);
	if (fin.fail())
		{
		cerr << "file opening failed\n";
		return 0;
		}

	string s;
	stringstream ss(stringstream::in | stringstream::out);
	int expect = 1;
	int val;

	// get each null-terminated line
	while (getline(fin, s, '\n'))
		{
		ss.clear();
		ss << s;
		// get each space-delimited integer value
		for (int i = 0; i < expect; i++)
			{
			ss >> val;
			numbers.push_back(val);
			}
		expect++;
		}

	fin.close();
	int rows = expect - 1;
	return rows;
	}

// Return the index of a triangle row stored in `numbers' array
inline int row_index(int row)
	{
	int sum = row;
	while (row > 0)
		sum += --row;
	return sum;
	}

// Map row numbers to the corresponding index of the first column in `numbers'
void map_row_indices(int rows)
	{
	for (int r = 0; r < rows; r++)
		row_map[r] = row_index(r);
	}

// Get data stored at given row/col
int get_at(int row, int col)
	{
	int idx = row_map.find(row)->second + col;
	return numbers.at(idx);
	}

// Set data stored at given row/col
void set_at(int row, int col, int val)
	{
	int idx = row_map.find(row)->second + col;
	numbers.at(idx) = val;
	}

int main(int argc, char *argv[])
	{
	const char *filename = 2 == argc ? argv[1] : "triangle.txt";

	int rows = read_numbers(filename);

	map_row_indices(rows);

	for (int row = rows - 2; row >= 0; row--)
		{
		int numcols = row + 1;
		for (int col = 0; col < numcols; col++)
			{
			int a = get_at(row, col);
			int b = get_at(row + 1, col + 0);
			int c = get_at(row + 1, col + 1);

			a += max<int>(b, c);
			set_at(row, col, a);
			}
		}

	int answer = get_at(0, 0);
	cout << answer << endl;
	return 0;
	}
