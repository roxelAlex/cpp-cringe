/*
Факториал целого числа N определяется как умножение всех чисел между 1 и N
(0! = 1). Напишите рекурсивную функцию factorial(), которая возвращает
факториал ввода. Протестируйте её с помощью первых 8 чисел.
*/

#include <iostream>

int factorial(int number)
{
    if(number < 1)
    return 1;
    else 
        return factorial(number - 1) * number;
}

int main()
{
    for(int number = 0; number < 8; number++)
    {
        std::cout << "Factorial of " << number << " is " << factorial(number) << std::endl;
    }

    return 0;
}