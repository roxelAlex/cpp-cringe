/*
Напишите свою функцию, которая меняет местами значения двух целочисленных
переменных. Проверку осуществляйте в функции main().
*/

#include <iostream>

void intSwap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 5, b = 10;

    intSwap(a, b);

    std::cout << a << "    " << b;
    return 0;
}