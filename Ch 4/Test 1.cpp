/*
Напишите программу, которая просит пользователя ввести два целых числа:
второе должно быть больше первого. 
Если пользователь введет второе число меньше первого, то используйте
блок и временную переменную, чтобы поменять местами пользовательские числа.
Затем выведите значения этих переменных. Добавьте в свой код комментарии,
объясняющие, где и какая переменная уничтожается.
*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    int x, y;
    cout << "Введите число: ";
    cin >> x;

    cout << "Введите большее число: ";
    cin >> y;

    if (x > y)
    {
        int temp;
        temp = y;
        y = x;
        x = temp;
    } // Переменная temp уничтожается здесь.

    cout << "Меньшее число: " << x << endl;
    cout << "Большее число: " << y << endl;

    return 0;
} // Переменные x и y уничтожаются здесь.