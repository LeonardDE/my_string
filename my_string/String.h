#pragma once
class String {
public:
    // Конструктор по умолчанию
    String() : data(nullptr), length(0) {}

    // Конструктор с параметром
    String(const char* str);

    // Конструктор копирования
    String(const String& other);

    // Оператор присваивания
    String& operator=(const String& other);

    // Move-конструктор
    String(String&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // Move-оператор присваивания
    String& operator=(String&& other) noexcept;

    // Деструктор
    ~String();

    // Оператор +=
    String& operator+=(const String& other);

    // Внешний оператор сложения двух строк
    friend String operator+(String lhs, const String& rhs);

    // Внешний оператор сложения строки и C-строки
    friend String operator+(String lhs, const char* rhs);

    // Внешний оператор сложения C-строки и строки
    friend String operator+(const char* lhs, const String& rhs);

    // Функция для получения C-строки
    const char* c_str() const;

private:
    char* data;
    size_t length;

};

