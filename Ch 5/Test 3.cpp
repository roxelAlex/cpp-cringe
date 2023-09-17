/*
Напишите программу, которая выводит буквы английского алфавита от a до z
вместе с кодами из ASCII-таблицы.
*/

#include <iostream>

int main()
{
    char sign = 'a';
    while(sign <= 'z')
    {
        std::cout << sign << " " << static_cast<int>(sign) << std::endl;
        ++sign;
    }
    return 0;
}