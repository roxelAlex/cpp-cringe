/*
В итоговом тесте главы №2 мы написали программу имитации мячика,
падающего с башни. Так как тогда мы еще ничего не знали о циклах и не
умели их использовать, то время полета мячика составляло всего лишь 5 секунд.
Измените программу, таким образом, чтобы мячик падал
ровно то количество секунд, которое необходимо ему для достижения земли.
*/

// Я для своего удобства удалил все функции, кроме функции, которая
// запрашивает у юзера высоту. Сначала пытался сохранить все функции, 
// но у меня не получалось. По не опытности, пытался вписать циклы в сами
// функции, но возникла проблема как же мне их взаимосвязать. И ничего не смог
// придумать. Решил просто весь функционал перенести в main(). Только потом, до
// меня дошло, что можно же все эти функции вызывать уже в
// самом main() внутри цикла. Но в принципе мой вариант тоже справляется
// отлично с поставленной задачей.

#include <iostream>
#include "constants.h"

double getInitialHeight()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;
    return initialHeight;
}

int main()
{
    double const height = getInitialHeight(); // Запрашиваем высоту и делаем из нее
    // константу, чтобы случайно число не изменилось.
    int seconds = 0;
    double currentHeight = height;

    while (currentHeight > 0)
    {
        double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
        currentHeight = height - distanceFallen;

        if (currentHeight > 0)
        {
            std::cout << "At " << seconds << " seconds, the ball is at height:\t" << currentHeight << " meters\n";
            ++seconds;
        }
        else
            std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
    }
    return 0;
}