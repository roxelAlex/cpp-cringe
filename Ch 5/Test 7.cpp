/*
Напишите функцию sumTo(), которая принимает целочисленный параметр с именем
value и возвращает сумму всех чисел от 1 до значения value.
*/

#include <iostream>

int sumTo(int value)
{
    int temp = 0;
    for (int count = 1; count <= value; count++)
        temp += count;
    return temp;
}

int main()
{
    std::cout << "Sum of all numbers from 1 to 5 is: " << sumTo(5) << std::endl;
    std::cout << "Sum of all numbers from 1 to 6 is: " << sumTo(6) << std::endl;
    std::cout << "Sum of all numbers from 1 to 8 is: " << sumTo(8) << std::endl;
    return 0;
}