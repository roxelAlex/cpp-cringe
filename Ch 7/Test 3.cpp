/*
Теперь давайте изменим программу, которую мы написали в первом задании,
чтобы переместить логику из getArithmeticFcn в массив.
a) Создайте структуру с именем arithmeticStruct, которая имеет два
члена: математический оператор типа char и указатель на функцию arithmeticFcn.
b) Создайте статический глобальный массив arithmeticArray, используя структуру
arithmeticStruct, который будет инициализирован каждой из 4 математических
операций.
c) Измените getArithmeticFcn для выполнения цикла по массиву и возврата
соответствующего указателя на функцию. Подсказка: Используйте цикл foreach.
d) Соедините все части вместе.
*/

#include <iostream>

typedef int (*arithmeticFcn)(int, int);

struct arithmeticStruct
{
    char operation;
    arithmeticFcn fcn;
};

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

static arithmeticStruct arithmeticArray[] = {
    {'+', add},
    {'-', substract},
    {'*', multiply},
    {'/', divide} 
};

arithmeticFcn getArithmeticFcn(char operation)
{
    for (auto element : arithmeticArray)
    {
        if (element.operation == operation)
            return element.fcn;
    }
}

int getInt()
{
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;
    return a;
}

char getOperation()
{
    std::cout << "Enter operation sign: ";
    char operation;
    do
    {
        std::cin >> operation;
    } while (operation != '+' && operation != '-' && operation != '*' && operation != '/');
    return operation;
}

int main()
{
    int a, b;
    char operation;

    a = getInt();
    b = getInt();

    operation = getOperation();    
    
    arithmeticFcn fcn = getArithmeticFcn(operation);

    std::cout << "Your result is: " << fcn(a, b);
    return 0;
}