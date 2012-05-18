#include <string.h>
#include <iostream>
#include <stdlib.h>

#define SIZE 200

class Multiplier
{
public:
	enum
		{
		WORK = 0,
		SUMM
		};
	Multiplier()
		: m_adigits(0),
			m_bdigits(0)
	{
		memset(m_a, 0, sizeof(short) * SIZE);
		memset(m_b, 0, sizeof(short) * SIZE);
		memset(m_scratch, 0, sizeof(short) * 2 * SIZE);
	}

public:
	// Set the multiplicant (factor 1)
	void SetFactor(int multiplicant)
	{
		m_adigits = SetInputArray(m_a, multiplicant);
	}

	// Set the multiplier (factor 2) and compute multiplication
	void MultiplyBy(int multiplier)
	{
		m_bdigits = SetInputArray(m_b, multiplier);
		memset(m_scratch, 0, sizeof(short) * 2 * SIZE);

		for (int b = 0; b < m_bdigits; b++)
			{
			int carry = 0;
			int a;
			for (a = 0; a < m_adigits; a++)
				{
				short v = m_a[SIZE - a - 1] * m_b[SIZE - b - 1];
				v += carry;
				m_scratch[WORK][SIZE - a - 1 - b] = v % 10;
				carry = v / 10;
				}

			if (carry > 0)
				m_scratch[WORK][SIZE - a - 1 - b] = carry;

			Addition();
			}

		ReadyForCommutative();
	}

	// Print the multiplication result
	void PrintAnswer() const
	{
		Print(SUMM);
	}

	// Sum the digits in the answer
	int SumAnswerDigits() const
	{
		int sum = 0;
		for (int i = 0; i < SIZE; i++)
			sum += m_scratch[SUMM][i];
		return sum;
	}

private:
	// Populate either of the input arrays
	int SetInputArray(short *parray, int val)
	{
		memset(parray, 0, sizeof(short) * SIZE);
		int i = SIZE - 1;
		while (val > 0)
			{
			parray[i] = val % 10;
			val = val / 10;
			i--;
			}

		return SIZE - 1 - i;
	}

	// Do long-addtion of the two scratch arrays
	void Addition()
	{
		int carry = 0;
		for (int i = SIZE - 1; i >= 0; i--)
			{
			short sum = carry + m_scratch[SUMM][i] + m_scratch[WORK][i];
			m_scratch[SUMM][i] = sum % 10;
			carry = sum / 10;
			m_scratch[WORK][i] = 0;
			}
	}

	// Prepare for chaining-on another multiplication
	void ReadyForCommutative()
		{
		memcpy(m_a, m_scratch[SUMM], SIZE * sizeof(short));

		int i = 0;
		while (i < SIZE && 0 == m_a[i])
			++i;
		m_adigits = SIZE - i;
		m_bdigits = 0;
		}

	// Print one of the two scratch arrays
	void Print(short id) const
	{
		const short *parray = 0 == id ? m_scratch[WORK] : m_scratch[SUMM];
		int i = 0;

		while (i < SIZE && 0 == parray[i])
			++i;
		while (i < SIZE)
			std::cout << parray[i++];

		std::cout << std::endl;
	}

	short m_a[SIZE]; // multiplicant
	short m_b[SIZE]; // multiplier
	short m_scratch[2][SIZE]; // scratch arrays for working and for addition
	int m_adigits; // number of digits in multiplicant
	int m_bdigits; // number of digits in multiplier
};

int main(int argc, char *argv[])
{
	int n = (2 == argc ? atoi(argv[1]) : 100);

	Multiplier m;
	m.SetFactor(n);
	while (--n > 0)
		m.MultiplyBy(n);

	std::cout << m.SumAnswerDigits() << std::endl;
}
