#pragma once

#include <fstream>
#include <vector>

extern const char *TOKEN_FILENAME;
extern const char *DATE_EXCHANGE_FILENAME;
extern const char *DATE_INPUT_FILENAME;

typedef std::vector<int> numbers_t;


void output_numbers(const char* filename, const numbers_t &numbers);

void read_numbers(const char* filename, numbers_t &numbers);
