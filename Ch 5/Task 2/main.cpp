/*
Напишите программу-игру типа Hi-Lo:
    Во-первых, ваша программа должна выбрать случайное целое число в диапазоне
от 1 до 100.
    Пользователю дается 7 попыток, чтобы угадать это число.
    Если пользователь не угадал число, то программа должна подсказывать,
была ли его догадка слишком большой или слишком маленькой.
    Если пользователь угадал число, то программа должна сообщить, что всё
верно — вы выиграли.
    Если же у пользователя кончились попытки, и он не угадал число, то
программа должна сообщить ему, что он проиграл и показать правильный результат.
    В конце игры программа должна спросить у пользователя, не хочет ли он
сыграть еще раз. Если пользователь не введет ни y, ни n (а что-то другое),
то программа должна спросить его еще раз.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

char repeat()
{
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? " << std::endl;
        char repeat;
        std::cin >> repeat;

        if (repeat == 'y' || repeat == 'n')
            return repeat;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    int tries = 1;
    int userNumber = 0;
    char ask;

    do
    {
        std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what is it." << std::endl;
        int prizeNumber = getRandomNumber(1, 100);

        while (tries <= 7 && userNumber != prizeNumber)
        {
            std::cout << "Guess #" << tries << ": ";
            std::cin >> userNumber;

            if (userNumber == prizeNumber)
            {
                std::cout << "Correct! You win!" << std::endl;
            }
            else if (userNumber > prizeNumber)
            {
                std::cout << "Your guess is too high" << std::endl;
                if (tries == 7)
                    std::cout << "Sorry, you lose. The correct number was " << prizeNumber << "." << std::endl;
                ++tries;
            }
            else if (userNumber < prizeNumber)
            {
                std::cout << "Yout guess is too low" << std::endl;
                if (tries == 7)
                    std::cout << "Sorry, you lose. The correct number was " << prizeNumber << "." << std::endl;
                ++tries;
            }
        }
        ask = repeat();
        tries = 1;
    } while (ask == 'y');
    
    return 0;
}