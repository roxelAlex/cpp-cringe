/*
Это уже немного сложнее. Напишите программу, которая просит пользователя
ввести целое число, а затем использует рекурсивную функцию для вывода
бинарного представления этого числа. Предполагается, что число, которое
введет пользователь, является положительным.
*/

#include <iostream>

void conversionToBinary(int n)
{
    if (n > 0)
    {
        int r = 0;
        if (n % 2 == 0)
            r = 0;
        else
            r = 1;
        conversionToBinary(n / 2);
        std::cout << r;
    }
}

//Ниже функция из ответов к задачам. Как видно мой код выше - хуйня :)
/*
void conversionToBinary(int n)
{
    if (n == 0)
        return;

    conversionToBinary(n / 2);

    std::cout << n % 2;
}
*/

int main()
{
    std::cout << "Enter number to convert to binary: ";
    int number;
    std::cin >> number;

    conversionToBinary(number);

    return 0;
}