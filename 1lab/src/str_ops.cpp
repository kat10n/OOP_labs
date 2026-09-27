
#include "str_ops.h"

namespace lab01 {
std::size_t str_len(const char* s)
{
    if(s == nullptr) {
        return 0; // если указатель на строку равен nullptr, возвращаем 0
    }
    std::size_t len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}

void str_copy(char* dst, const char* src) {
    if(dst == nullptr || src == nullptr) {
        return; // если указатели на строки равны nullptr, ничего не делаем
    }
    std::size_t i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        ++i;
    }
    dst[i] = '\0';
}

char* str_alloc(const char* src) {
    if(src == nullptr) {
        return nullptr; // если указатель на строку равен nullptr, возвращаем nullptr
    }
    std::size_t len = str_len(src);
    char* new_str = new char[len + 1]; // +1 для '\0'
    str_copy(new_str, src);
    return new_str;
}


void str_delete(char*& s){
    if(s == nullptr) {
        return; // если указатель на строку равен nullptr, ничего не делаем
    }
    delete[] s; // память освобождена, но указатель не обнулен
    s = nullptr; // указатель обнулен чтобы не упало при повторном вызове
}

void str_print(const char* s){
    if(s == nullptr) {
        std::cout << "Строка не введена" << std::endl; 
        return;
    }
    std::size_t i = 0;
    while (s[i] != '\0') {
        std::cout << s[i]; // посимвольно печатаем строку
        ++i;
    }
    std::cout << std::endl;
}

void str_to_upper(char* str){
    if(str == nullptr) {
        return; // если указатель на строку равен nullptr, ничего не делаем
    }
    std::size_t i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';
        }
        ++i;
    }
}

std::size_t str_count_char(const char* s, char ch) {
    if (s == nullptr) {
        return 0;
    }
    std::size_t count = 0;
    std::size_t i = 0;
    while (s[i] != '\0') {
        if (s[i] == ch) {
            ++count;
        }
        ++i;
    }
    return count;
}

char* str_read_line() {
    std::size_t capacity = 16;   // с чего начинаем
    std::size_t size = 0;        // сколько символов уже записано
    char* buffer = new char[capacity];
    while (true) {
        char ch;
        if (!std::cin.get(ch) || ch == '\n') {
            break;
        }
        if (size + 1 >= capacity) { // +1 для '\0'
            capacity *= 2;            // увеличиваем емкость вдвое
            char* new_buffer = new char[capacity];
            for (std::size_t i = 0; i < size; ++i) {
                new_buffer[i] = buffer[i];
            }
            delete[] buffer;
            buffer = new_buffer;
        }
        buffer[size] = ch;
        ++size;
        }
    buffer[size] = '\0'; // завершаем строку нулевым символ
    char* result = str_alloc(buffer);   // копия ровно по размеру
    delete[] buffer;                     // временный буфер больше не нужен
    return result;
}
}
