#include <stdio.h>
#include <iostream>
#include <fstream>

#include "common.hpp"

using namespace std;


int main()
{
	std::remove(TOKEN_FILENAME);
	std::remove(DATE_EXCHANGE_FILENAME);

	std::fstream input_file(DATE_INPUT_FILENAME, std::fstream::in);

	int number;
	numbers_t numbers;
	while (input_file >> number)
	{
		numbers.push_back(number);
	}
	input_file.close();


	printf("Got %lu numbers\n", numbers.size());

	std::fstream output_file(DATE_EXCHANGE_FILENAME, std::fstream::out);
	for (int number : numbers)
	{
		output_file << number << " ";
	}
	output_file.close();

	std::fstream token_file(TOKEN_FILENAME, std::fstream::out);
	token_file << "done\n";

	while (true)
	{
		if (access(TOKEN_FILENAME, F_OK) == -1)
			break;
	}
	printf("Token removed\n");

	std::fstream soorted_file(DATE_EXCHANGE_FILENAME, std::fstream::in);
	while (soorted_file >> number)
	{
		cout << number << " ";
	}

}
