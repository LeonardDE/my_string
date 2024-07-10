#pragma once
class String {
public:
    // ����������� �� ���������
    String() : data(nullptr), length(0) {}

    // ����������� � ����������
    String(const char* str);

    // ����������� �����������
    String(const String& other);

    // �������� ������������
    String& operator=(const String& other);

    // Move-�����������
    String(String&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // Move-�������� ������������
    String& operator=(String&& other) noexcept;

    // ����������
    ~String();

    // �������� +=
    String& operator+=(const String& other);

    // ������� �������� �������� ���� �����
    friend String operator+(String lhs, const String& rhs);

    // ������� �������� �������� ������ � C-������
    friend String operator+(String lhs, const char* rhs);

    // ������� �������� �������� C-������ � ������
    friend String operator+(const char* lhs, const String& rhs);

    // ������� ��� ��������� C-������
    const char* c_str() const;

private:
    char* data;
    size_t length;

};

