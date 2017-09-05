#pragma once

#include <fstream>
#include <vector>

extern const char *DATE_EXCHANGE_FILENAME;
extern const char *DATE_INPUT_FILENAME;
extern const char *EXIT_FILENAME;

typedef std::vector<int> numbers_t;


void output_numbers(const char* filename, const numbers_t &numbers);
void read_numbers(const char* filename, numbers_t &numbers);
void remove_token();
void create_token();
bool token_exists();
bool file_exists(const char *filename);
void wait_for_token(bool exists);

