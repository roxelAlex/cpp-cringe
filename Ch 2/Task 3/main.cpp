/*
Напишите следующую программу. Сначала пользователю предлагается ввести 2 числа типа с плавающей точкой (используйте тип double). 
Затем предлагается ввести один из следующих математических символов: +, -, * или /. 
Программа выполняет выбранную пользователем математическую операцию между двумя числами, а затем выводит результат на экран. 
Если пользователь ввел некорректный символ, то программа ничего не должна выводить.
*/

#include <iostream>
using namespace std;

void calc(double x, double y, char ch)
{
    if (ch == '+')
    {
        cout << x << ch << y << " = " << x + y;
    }
    if (ch == '-')
    {
        cout << x << ch << y << " = " << x - y;
    }
    if (ch == '*')
    {
        cout << x << ch << y << " = " << x * y;
    }
    if (ch == '/')
    {
        cout << x << ch << y << " = " << x / y;
    }
}

int main()
{
    cout << "Enter first number: ";
    double x;
    cin >> x;

    cout << "Enter second number: ";
    double y;
    cin >> y;

    cout << "Enter one of the following: +, -, *, /: ";
    char ch;
    cin >> ch;

    calc(x, y, ch);
    return 0;
}