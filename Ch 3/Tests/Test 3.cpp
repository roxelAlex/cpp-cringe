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