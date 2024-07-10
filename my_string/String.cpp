#include "String.h"
#include <cstring>
#include <vector>

String::String(const char* str) {
    if (str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }
    else {
        data = nullptr;
        length = 0;
    }
}

String::String(const String& other) : length(other.length) {
    if (other.data) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }
    else {
        data = nullptr;
    }
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}





String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}

String::~String() {
    delete[] data;
}

String& String::operator+=(const String& other) {
    if (other.data) {
        size_t new_length = length + other.length;
        char* new_data = new char[new_length + 1];
        std::strcpy(new_data, data ? data : "");
        std::strcat(new_data, other.data);
        delete[] data;
        data = new_data;
        length = new_length;
    }
    return *this;
}

String operator+(String lhs, const String& rhs) {
    lhs += rhs;
    return lhs;
}

String operator+(String lhs, const char* rhs) {
    lhs += String(rhs);
    return lhs;
}

String operator+(const char* lhs, const String& rhs) {
    return String(lhs) + rhs;
}

const char* String::c_str() const {
    return data;
}
