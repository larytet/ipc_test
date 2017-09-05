#include <iostream>
#include <fstream>

#include "common.hpp"

using namespace std;

typedef vector<int> numbers_t;

void do_sort()
{
	while (!(access(TOKEN_FILENAME, F_OK) != -1))
	{
	}

	std::fstream sorted_file(DATE_EXCHANGE_FILENAME, std::ios_base::in);
	numbers_t numbers;
	int number;
	while (sorted_file >> number)
	{
		numbers.push_back(number);
	}
	sorted_file.close();

	std::sort(numbers.begin(), numbers.end());

	std::fstream output_file(DATE_EXCHANGE_FILENAME, std::ios_base::out);
	for (int number : numbers)
	{
		output_file << number;
	}
	output_file.close();
}

int main()
{
	while (true)
	{
		do_sort();
	}
}
