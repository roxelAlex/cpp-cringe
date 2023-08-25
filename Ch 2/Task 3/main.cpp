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