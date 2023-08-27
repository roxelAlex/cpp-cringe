/*
Что такое простое число? Правильно! Это целое положительное число больше единицы, которое делится без остатка либо на себя, либо на единицу. 
Напишите программу, которая просит пользователя ввести простое целое число, меньшее 10. Если пользователь ввел одно из следующих чисел:
2, 3, 5 или 7 — программа должна вывести The digit is prime, в противном случае — The digit is not prime.
*/

#include <iostream>
using namespace std;

bool isPrime(int x)
{
    return (x == 2 || x == 3 || x == 5 || x == 7);
}

int main()
{
    cout << "Enter your number: ";
    int x;
    cin >> x;

    if (isPrime(x))
        cout << "The digit is prime";
    else
        cout << "The digit is not prime";
    return 0;
}