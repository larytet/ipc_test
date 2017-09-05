#include <stdio.h>
#include <iostream>

#include "common.hpp"

using namespace std;

void wait_for_token_disapper()
{
	while (true)
	{
		if (!token_exists())
			break;
	}
}


int main()
{
	remove_token();
	std::remove(DATE_EXCHANGE_FILENAME);

	numbers_t numbers;
	read_numbers(DATE_INPUT_FILENAME, numbers);

	output_numbers(DATE_EXCHANGE_FILENAME, numbers);

	create_token();

	wait_for_token_disapper();

	std::fstream sorted_file(DATE_EXCHANGE_FILENAME, std::fstream::in);
	int number;
	while (sorted_file >> number)
	{
		cout << number << " ";
	}
	cout << std::endl;

}
