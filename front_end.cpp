#include <iostream>
#include <fstream>

#include "common.hpp"

using namespace std;

typedef vector<int> numbers_t;

int main()
{
	std::fstream input_file("data.txt", std::ios_base::in);
	int number;
	numbers_t numbers;
	while (input_file >> number)
	{
		numbers.push_back(number);
	}
	input_file.close();

	std::fstream output_file(DATE_EXCHANGE_FILENAME, std::ios_base::out);
	for (int number : numbers)
	{
		output_file << number;
	}
	output_file.close();

	std::fstream token_file(TOKEN_FILENAME, std::ios_base::out);
	token_file << "done\n";

	while (access(TOKEN_FILENAME, F_OK) != -1)
	{
	}

	std::fstream soorted_file(DATE_EXCHANGE_FILENAME, std::ios_base::in);
	while (soorted_file >> number)
	{
		cout << number;
	}

}
