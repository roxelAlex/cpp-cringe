#include <iostream>
#include "constants.h"
using namespace std;
using namespace myConstants;


double height(int sec, double heightBall)
{
    return heightBall - (gravity * ((static_cast<double> (sec) * static_cast<double> (sec)) / 2));
}

void isGround(int sec, double height)
{
    if (height > 0)
    {
        cout << "At " << sec << " seconds, the ball is at height: " << height << " meters." << endl;
    }

 /*   if (sec == 0)
    {
        cout << "At " << sec << " seconds, the ball is at height: " << height << " meters." << endl;
    }
*/
    else
    {
        cout << "At " << sec << " seconds, the ball is on the ground." << endl;
    }
}

double getHeight()
{
    cout << "Enter the initial height of the tower in meters: ";
    double heightBall;
    cin >> heightBall;
    return heightBall;
}