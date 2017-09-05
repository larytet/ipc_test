#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "common.hpp"

using namespace std;

bool shall_exit()
{
	return access(EXIT_FILENAME, F_OK) != -1;
}

void wait_for_token()
{
	while (true)
	{
		if (access(TOKEN_FILENAME, F_OK) != -1)
			break;
		if (shall_exit())
			break;
	}
}

void do_sort()
{
	wait_for_token();
	if (shall_exit())
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
		if (shall_exit())
		{
			break;
		}
		do_sort();
	}
	return 0;
}
