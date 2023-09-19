/*
Напишите цикл for, который выводит каждое четное число в диапазоне от 0 до 20.
*/

#include <iostream>

int main()
{
    for(int count = 0; count <= 20; count ++)
    {
        if (count % 2 == 0)
        std::cout << count << " ";
    }
    return 0;
}