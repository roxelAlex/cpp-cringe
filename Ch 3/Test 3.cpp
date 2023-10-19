/*
Напишите программу, которая просит пользователя ввести целое число, а затем сообщает, 
является ли его число чётным или нечётным. 
Напишите функцию isEven(), которая возвращает true, если целое число является чётным. 
Используйте оператор деления с остатком, чтобы определить чётность числа.
*/


#include <iostream>
using namespace std;

int userNumber()
{
    cout << "Enter yout number: ";
    int x;
    cin >> x;
    return x;
}

bool isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    int x = userNumber();
    if (isEven(x) == 1)
    {
        cout << "Your number is Even";
    }
    else
    {
        cout << "Your number is not Even";
    }
    return 0;
}