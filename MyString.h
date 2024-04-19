﻿/*
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
и вывода строк на экран. Также нужно реализовать статическую
функцию-член, которая будет возвращать количество созданных объектов строк.
*/
#pragma once

class MyString
{
private:
    int size;
    char* line;
    static int count;  // Статическая переменная для подсчета объектов

public:
    MyString();
    MyString(int size);
    MyString(const char* inputWord, int size);
    MyString(const char* inputWord);
    ~MyString();

    void Print() const;
    void Input();

    static int GetCount();
};