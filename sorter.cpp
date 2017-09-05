#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "common.hpp"

using namespace std;

void wait_for_token()
{
	while (true)
	{
		if (access(TOKEN_FILENAME, F_OK) != -1)
			break;
		if (access(EXIT_FILENAME, F_OK) != -1)
			break;
	}
}

void do_sort()
{
	wait_for_token();
	if (access(EXIT_FILENAME, F_OK) != -1)
		return;

	numbers_t numbers;
	read_numbers(DATE_EXCHANGE_FILENAME, numbers);

	std::sort(numbers.begin(), numbers.end());

	output_numbers(DATE_EXCHANGE_FILENAME, numbers);

	std::remove(TOKEN_FILENAME);
}

int main()
{
	std::remove(EXIT_FILENAME);
	while (true)
	{
		if (access(EXIT_FILENAME, F_OK) != -1)
		{
			std::remove(EXIT_FILENAME);
			break;
		}
		do_sort();
	}
	return 0;
}
