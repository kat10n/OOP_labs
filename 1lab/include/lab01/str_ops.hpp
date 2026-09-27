#pragma once
#include <cstddef>
#include <iostream>
#include <cstring>
#include <limits>

namespace lab01 {
char* str_alloc(const char* src);
std::size_t str_len(const char* s);
void str_copy(char* dst, const char* src);
void str_delete(char*& s);
void str_print(const char* s);
void str_to_upper(char* str);
std::size_t str_count_char(const char* s, char ch);
char* str_read_line();
}