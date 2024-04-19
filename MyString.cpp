/*
Разработать класс String, который в дальнейшем будем использовать
для работы со строками. Класс должен содержать:
■ Конструктор по умолчанию, который позволяет создать
строку длиной 80 символов;
■Конструктор, который позволяет создавать строку произвольного размера;
■Конструктор, который создает строку и инициализирует ее
строкой, полученной от пользователя.
■Необходимо создать деструктор, а также использовать механизмы делегирования конструкторов, если это
возможно.
■Класс должен содержать методы для ввода строк с клавиатуры
клавиатуры и вывода строк на экран. Также нужно
реализовать статическую функцию-член, которая будет возвращать
количество созданных объектов строк.
*/

#include "MyString.h"
#include <cstring>
#include <iostream>

using namespace std;

int MyString::count = 0;  // Инициализация статической переменной

// Конструктор по умолчанию
MyString::MyString() : line(nullptr), size(80) {
    count++;
}

// Конструктор с размером
MyString::MyString(int size) : size(size) {
    line = new char[size + 1](); // Выделение памяти и инициализация нулями
    count++;
}

// Конструктор с C-строкой
MyString::MyString(const char* inputWord) : MyString(inputWord, strlen(inputWord)) {}

MyString::MyString(const char* inputWord, int size) : size(size) {
    if (inputWord != nullptr) {
        line = new char[size + 1]; // Выделение памяти
        strcpy_s(line, size + 1, inputWord); // Копирование строки с учётом нуль-терминатора
    }
    else {
        line = new char[1](); // Выделение памяти для пустой строки
        *line = '\0';
    }
    count++;
}

// Деструктор
MyString::~MyString() {
    delete[] line;
    count--;
}

// Вывод строки
void MyString::Print() const {
    if (line) {
        cout << line << endl;
    }
    else {
        cout << size << endl;
    }
}

// Ввод строки с клавиатуры
void MyString::Input() {
    if (line != nullptr) {
        cout << "Enter string: ";
        cin.getline(line, size);
    }
    else if (line == nullptr) {
        line = new char[size];
        cout << "Enter string: ";
        cin.getline(line, size);
    }
}

int MyString::GetCount() {
    return count;
}
