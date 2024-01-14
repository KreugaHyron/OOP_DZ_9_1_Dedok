#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
//класс MyString
class MyString {
private:
    char* str;
    int size;
public:
    MyString() : size(80) {
        str = new char[size + 1];
        for (int i = 0; i <= size; ++i) {
            str[i] = '\0';
        }
    }
    MyString(int customSize) : size(customSize) {
        str = new char[size + 1];
        for (int i = 0; i <= size; ++i) {
            str[i] = '\0';
        }
    }
    MyString(const char* initialStr) : size(strlen(initialStr)) {
        str = new char[size + 1];
        strcpy(str, initialStr);
    }
    MyString(const MyString& other) : size(other.size) {
        str = new char[size + 1];
        strcpy(str, other.str);
    }
    ~MyString() {
        delete[] str;
    }
    void inputString() {
        cout << "Введите строку: ";
        cin >> str;
    }
    void outputString() const {
        cout << "String: " << str << "\n";
    }
    static int getCount() {
        static int count = 0;
        return count;
    }
    MyString& operator++() {
        char* temp = new char[size + 2];
        strcpy(temp, str);
        temp[size] = 'x';
        temp[size + 1] = '\0';
        delete[] str;
        str = temp;
        size++;
        return *this;
    }
    MyString& operator--() {
        if (size > 0) {
            str[size - 1] = '\0';
            size--;
        }
        return *this;
    }
    MyString operator+(int count) const {
        MyString result(*this);
        char* temp = new char[result.size + count + 1];
        strcpy(temp, result.str);
        for (int i = 0; i < count; ++i) {
            temp[result.size + i] = 'x';
        }
        temp[result.size + count] = '\0';
        delete[] result.str;
        result.str = temp;
        result.size += count;
        return result;
    }
    MyString operator-(int count) const {
        MyString result(*this);
        if (count >= result.size) {
            delete[] result.str;
            result.str = new char[1];
            result.str[0] = '\0';
            result.size = 0;
        }
        else {
            result.size -= count;
            result.str[result.size] = '\0';
        }
        return result;
    }
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            size = other.size;
            str = new char[size + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    MyString operator++(int) {
        MyString temp(*this);
        ++(*this);
        return temp;
    }
    MyString operator--(int) {
        MyString temp(*this);
        --(*this);
        return temp;
    }
    friend MyString operator+(int count, const MyString& myString) {
        MyString result(count + myString.size);
        for (int i = 0; i < count; ++i) {
            result.str[i] = 'x';
        }
        strcpy(result.str + count, myString.str);
        return result;
    }
};
int main()
{
    MyString s1("hello");
    MyString s2("world");
    s1 = s2;
    s1.outputString();
    MyString s3 = s2++;
    s3.outputString();
    MyString s4 = s2--;
    s4.outputString();
    s2.outputString();
    MyString s("world");

    MyString result = 5 + s;
    result.outputString();
}

