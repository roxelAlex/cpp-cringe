/*
Напишите однофайловую программу (с именем main.cpp),
которая запрашивает у пользователя два целых числа, складывает их, а затем выводит результат.
В программе должно быть 3 функции:
Функция readNumber(), которая запрашивает у пользователя целое число, а затем возвращает его в main();
Функция writeAnswer(), которая выводит результат на экран. Функция должна быть без возвращаемого значения и иметь только один параметр;
Функция main(), которая соединяет всё и вся.
*/


#include <iostream>
using namespace std;

int readNumber()
{
    int x;
    cout << "Enter your int: ";
    cin >> x;
    return x;
}

void writeAnswer(int x, int y)
{
    cout << "Your answer is: " << x + y << endl;
}

int main()
{
    int x = readNumber();
    int y = readNumber();
    writeAnswer(x, y);
    return 0;
}