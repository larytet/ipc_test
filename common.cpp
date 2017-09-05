#include <cstdio>

#include "common.hpp"


static const char *TOKEN_FILENAME = "token.txt";
const char *DATE_EXCHANGE_FILENAME = "data_exchange.txt";
const char *DATE_INPUT_FILENAME = "data.txt";
const char *EXIT_FILENAME = "exit.txt";

void output_numbers(const char* filename, const numbers_t &numbers)
{
	std::fstream output_file(filename, std::fstream::out);
	for (int number : numbers)
	{
		output_file << number << " ";
	}
	output_file.close();

}

void read_numbers(const char* filename, numbers_t &numbers)
{
	std::fstream input_file(filename, std::fstream::in);
	int number;
	while (input_file >> number)
	{
		numbers.push_back(number);
	}
	input_file.close();
}


void remove_token()
{
	std::remove(TOKEN_FILENAME);
}

void create_token()
{
	std::fstream token_file(TOKEN_FILENAME, std::fstream::out);
	token_file.close();
}

bool token_exists()
{
	return file_exists(TOKEN_FILENAME);
}

bool file_exists(const char *filename)
{
	return (access(filename, F_OK) != -1);
}
