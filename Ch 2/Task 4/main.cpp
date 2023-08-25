#include "io.h"

int main()
{
    double heightBall = getHeight();

    isGround(0, (height(0, heightBall)));
    isGround(1, (height(1, heightBall)));
    isGround(2, (height(2, heightBall)));
    isGround(3, (height(3, heightBall)));
    isGround(4, (height(4, heightBall)));
    isGround(5, (height(5, heightBall)));

    return 0;
}