#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "common.hpp"

using namespace std;

void do_sort()
{
	while (true)
	{
		if (access(TOKEN_FILENAME, F_OK) != -1)
			break;
	}

	std::fstream sorted_file(DATE_EXCHANGE_FILENAME, std::fstream::in);
	numbers_t numbers;
	int number;
	while (sorted_file >> number)
	{
		numbers.push_back(number);
	}
	sorted_file.close();


	std::sort(numbers.begin(), numbers.end());

	std::fstream output_file(DATE_EXCHANGE_FILENAME, std::fstream::out);
	for (int number : numbers)
	{
		output_file << number << " ";
	}
	output_file.close();

	std::remove(TOKEN_FILENAME);
}

int main()
{
	while (true)
	{
		do_sort();
	}
}
