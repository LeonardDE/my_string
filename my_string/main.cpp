#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include "String.h"

// Функция для сравнения строк без учета регистра
bool compareStringsIgnoreCase(const String& a, const String& b) {
    std::string str1 = a.c_str();
    std::string str2 = b.c_str();
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 > str2;
}

int main(int argc, char* argv[]) {
    
    std::vector<String> strings;

    // Чтение строк из аргументов командной строки
    for (int i = 1; i < argc; ++i) {
        strings.push_back(String(argv[i]));
    }

    // Сортировка строк в обратном лексикографическом порядке без учета регистра
    std::sort(strings.begin(), strings.end(), compareStringsIgnoreCase);

    // Вывод отсортированных строк
    for (const auto& str : strings) {
        std::cout << str.c_str() << std::endl;
    }

    return 0;
}

