#include <stdio.h>
#include <iostream>

#include "common.hpp"

using namespace std;

void wait_for_token_disapper()
{
	while (true)
	{
		if (access(TOKEN_FILENAME, F_OK) == -1)
			break;
	}
}

void create_token()
{
	std::fstream token_file(TOKEN_FILENAME, std::fstream::out);
	token_file << "done\n";
	token_file.close();
}

int main()
{
	std::remove(TOKEN_FILENAME);
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

}
