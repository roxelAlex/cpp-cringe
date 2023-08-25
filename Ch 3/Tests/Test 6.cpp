#include <iostream>
using namespace std;

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

uint16_t checkSub(uint16_t checkNumber)
{
    return checkNumber -= (checkNumber / 2);
}

uint16_t main()
{
    cout << "Enter a number from 0 to 255): ";
    uint16_t userNumber, checkNumber = 128;
    cin >> userNumber;

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