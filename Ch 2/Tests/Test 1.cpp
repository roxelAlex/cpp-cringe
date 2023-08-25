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