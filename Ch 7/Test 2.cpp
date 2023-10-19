/*
В этот раз мы попытаемся написать версию базового калькулятора с помощью
указателей на функции.
a) Напишите короткую программу, которая просит пользователя ввести два
целых числа и выбрать математическую операцию: +, -, * или /. Убедитесь,
что пользователь ввел корректный символ математической операции (используйте
проверку).
b) Напишите функции add(), subtract(), multiply() и divide(). Они должны
принимать два целочисленных параметра и возвращать целочисленное значение. 
c) Создайте typedef с именем arithmeticFcn для указателя на функцию, которая
принимает два целочисленных параметра и возвращает целочисленное значение.
d) Напишите функцию с именем getArithmeticFcn(), которая принимает символ
выбранного математического оператора и возвращает соответствующую функцию в
качестве указателя на функцию.
e) Добавьте в функцию main() вызов функции getArithmeticFcn().
f) Соедините все части вместе.
*/

#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

typedef int (*arithmeticFcn)(int, int);

arithmeticFcn getArithmeticFcn(char operation)
{
    switch(operation)
    {
        default:
        case '+': return add;
        case '-': return substract;
        case '*': return multiply;
        case '/': return divide;
    }
}

int main()
{
    int a, b;
    char operation;

    std::cout << "Enter first int: ";
    std::cin >> a;

    std::cout << "Enter second int: ";
    std::cin >> b;

    std::cout << "Enter operation sign: ";
    do
    {
        std::cin >> operation;
    } while (operation != '+' && operation != '-' && operation != '*' && operation != '/');
    
    arithmeticFcn fcn = getArithmeticFcn(operation);

    std::cout << "Your result is: " << fcn(a, b);
    return 0;
}