/*
Напишите функцию calculate(), которая принимает две переменные типа int и
одну переменную типа char, которая, в свою очередь, представляет одну из
следующих математических операций: +, -, *, / или % (остаток от числа).
Используйте switch для выполнения соответствующей математической операции
над целыми числами, а результат возвращайте обратно в main().
Если в функцию передается недействительный математический оператор,
то функция должна выводить ошибку. С оператором деления выполняйте
целочисленное деление.
*/

#include <iostream>

int calculate(int first, int second, char operation)
{
    switch (operation)
    {
    case '+':
        return first + second;
        break;
    case '-':
        return first - second;
        break;
    case '*':
        return first * second;
        break;
    case '/':
        return first / second;
        break;
    case '%':
        return first % second;
        break;
    default:
        std::cout << "You entered wrong operation sign." << std::endl;
        return 0;
        break;
    }
}

int main()
{
    std::cout << "Enter first digit: ";
    int first;
    std::cin >> first;

    std::cout << "Enter second digit: ";
    int second;
    std::cin >> second;

    std::cout << "Enter operation sign: ";
    char operation;
    std::cin >> operation;

    int result = calculate(first, second, operation);
    std::cout << "Your result is: " << result;
    return 0;
}