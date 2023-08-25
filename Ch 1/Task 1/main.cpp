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