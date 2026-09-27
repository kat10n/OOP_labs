#include "str_ops.hpp"


int main()
{
  char* str = nullptr;
  int command;

  while (true) {
    std::cout << "Выберите команду:" << '\n'
               << "1. Ввести строку" << '\n'
               << "2. Напечатать" << '\n'
               << "3. Длина" << '\n'
               << "4. Скопировать в буфер и напечатать" << '\n'
               << "5. Регистр ASCII" << '\n'
               << "6. Счетчик символов" << '\n'
               << "0. Выход" << std::endl;
    if (!(std::cin >> command)) {
      if (std::cin.eof()) {          // поток закончился, читать больше нечего
          lab01::str_delete(str);
          break;
      }
      std::cin.clear();              // иначе это просто мусор вроде буквы
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Некорректный ввод." << std::endl;
      continue;
    }

    if (command == 1) {
      std::cout << "Введите строку: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
      lab01::str_delete(str);
      str = lab01::str_read_line();
    } else if (command == 2) {
      if (str != nullptr) {
        lab01::str_print(str);
      } else {
        std::cout << "Строка не введена." << std::endl;
      }
    } else if (command == 3) {
      if (str != nullptr) {
        std::size_t length = lab01::str_len(str);
        std::cout << "Длина строки: " << length << std::endl;
      } else {
        std::cout << "Строка не введена." << std::endl;
      }
    } else if (command == 4) {
      if (str != nullptr) {
        char* buffer = new char[lab01::str_len(str) + 1]; // пустой буфер нужного размера
        lab01::str_copy(buffer, str);                     // копируем строку в буфер
        std::cout << "Буфер: " << buffer << std::endl;
        lab01::str_delete(buffer);
    } else {
        std::cout << "Строка не введена." << std::endl;
    }
    } else if (command == 5) {
      if (str != nullptr) {
        lab01::str_to_upper(str);
        std::cout << "Строка в верхнем регистре: " << str << std::endl;
      } else {
        std::cout << "Строка не введена." << std::endl;
      }
    } else if (command == 6) {
      if (str != nullptr) {
        std::cout << "Какой символ считать: ";
        char ch;
        if (!(std::cin >> ch)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод." << std::endl;
            continue;
        }
        std::size_t count = lab01::str_count_char(str, ch);
        std::cout << "Количество вхождений: " << count << std::endl;
      } else {
        std::cout << "Строка не введена." << std::endl;
      }
    } else if (command == 0) {
      std::cout << "Выход из программы." << std::endl;
      lab01::str_delete(str);
      break;
    } else {
      std::cout << "Неверная команда." << std::endl;
    }
  }
  return 0;
}