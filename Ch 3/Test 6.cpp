/*
Напишите программу, которая просит пользователя ввести число от 0 до 255. 
Выведите его как 8-битное двоичное число (в парах по 4 цифры). 
Не используйте побитовые операторы.
Предполагается, что наименьшим числом для сравнения является 128.
Напишите функцию для проверки входных чисел: являются ли они больше чисел, 
умноженных на 2 (т.е. чисел 1, 2, 4, 8, 16, 32, 64 и 128). 
Если это так, то выводится 1, если нет — выводится 0.

Рассмотрим десятичное число 148.
Какое наибольшее число, умноженное на 2 (из ряда 1, 2, 4, 8, 16, 32, 64, 128, 256 и т.д.), меньше 148? 
Ответ: 128. 148 >= 128? Да, поэтому 128-й бит равен 1. 148 − 128 = 20 
20 >= 64? Нет, поэтому 64-й бит равен 0. 
20 >= 32? Нет, поэтому 32-й бит равен 0. 
20 >= 16? Да, поэтому 16-й бит равен 1. 20 − 16 = 4 
4 >= 8? Нет, поэтому 8-й бит равен 0. 
4 >= 4? Да, поэтому 4-й бит равен 1. 
4 − 4 = 0, что означает, что все остальные биты равны 0.
*/

#include <iostream>
using namespace std;

// Эта функция возрващает единицу, если введеное число
// больше проверочного (128, 64, 32, 16, 8, 4, 2, 1), в ином случае 0.
// Да, в условии указано не использовать побитовые операторы, но обратил внимание
// уже когда код написал. Когда-нибудь переделаю.
bool bitConv(uint16_t userNumber, uint16_t checkNumber)
{
    if(userNumber >= checkNumber)
    {
        return true;
    }
    if(userNumber == 0)
    {
        return false;
    }
    else
    {
        return false;
    }
}

// Эта функция проверяет пользователькоское число.
// Если оно больше проверочного, то из польз. вычитаем проверочное.
// В ином случае возвращаем либо само число или ноль (если число уже равно нулю.)
uint16_t userSub(uint16_t userNumber, uint16_t checkNumber)
{
    if(userNumber >= checkNumber)
    {
        return userNumber - checkNumber;
    }
    if(userNumber == 0)
    {
        return 0;
    }
    else
    {
        return userNumber;
    }
}

// Эта функция уменьшает проверочное число в 2 раза, после каждой итерации.
uint16_t checkSub(uint16_t checkNumber)
{
    return checkNumber -= (checkNumber / 2);
}

uint16_t main()
{
    cout << "Enter a number from 0 to 255): ";
    uint16_t userNumber, checkNumber = 128;
    cin >> userNumber;

    // Следующий код можно было сократить используя циклы.
    // Но на момент изучения главы, я еще "не знаю" как их использовать.
    cout << bitConv(userNumber, checkNumber);
    userNumber = userSub(userNumber, checkNumber);
    checkNumber = checkSub(checkNumber);

    cout << bitConv(userNumber, checkNumber);
    userNumber = userSub(userNumber, checkNumber);
    checkNumber = checkSub(checkNumber);

    cout << bitConv(userNumber, checkNumber);
    userNumber = userSub(userNumber, checkNumber);
    checkNumber = checkSub(checkNumber);

    cout << bitConv(userNumber, checkNumber) << " ";
    userNumber = userSub(userNumber, checkNumber);
    checkNumber = checkSub(checkNumber);

    cout << bitConv(userNumber, checkNumber);
    userNumber = userSub(userNumber, checkNumber);
    checkNumber = checkSub(checkNumber);

    cout << bitConv(userNumber, checkNumber);
    userNumber = userSub(userNumber, checkNumber);
    checkNumber = checkSub(checkNumber);

    cout << bitConv(userNumber, checkNumber);
    userNumber = userSub(userNumber, checkNumber);
    checkNumber = checkSub(checkNumber);

    cout << bitConv(userNumber, checkNumber);
    userNumber = userSub(userNumber, checkNumber);
    checkNumber = checkSub(checkNumber);
    
    return 0;
}