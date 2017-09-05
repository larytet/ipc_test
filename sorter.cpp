#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "common.hpp"

using namespace std;

bool shall_exit()
{
	return file_exists(EXIT_FILENAME);
}

void wait_for_token()
{
	while (true)
	{
		if (token_exists())
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

	remove_token();
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
