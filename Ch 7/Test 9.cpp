/*
Мы собираемся написать небольшую игру с квадратами чисел.
Суть игры:
* Попросите пользователя ввести 2 числа: первое — стартовое число, которое
нужно возвести в квадрат, второе — количество чисел, которые нужно возвести в
квадрат. 
* Сгенерируйте случайное целое число от 2 до 4 и возведите в квадрат указанное
пользователем количество чисел, начиная со стартового.
* Умножьте каждое возведенное в квадрат число на сгенерированное ранее число
(от 2 до 4).
* Пользователь должен вычислить, какие числа были сгенерированы — он указывает
свои предположения.
* Программа проверяет, угадал ли пользователь число, и, если угадал — удаляет
угаданное число из списка.
* Если пользователь не угадал число, то игра заканчивается, и программа
выводит число, которое было ближе всего к окончательному предположению
пользователя, но только если последнее предположение не отличалось больше 
чем на 4 единицы от числа из списка.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int maximumWrongAnswer = 4;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

auto searchNumber(std::vector<int> &array, int number)
{
    return std::find(array.begin(), array.end(), number);
}

int findClosestNumber(std::vector<int> &array, int number)
{
    return *std::min_element(array.begin(), array.end(), [=](int a, int b)
    {
        return (std::abs(a - number) < std::abs(b - number));
    });
}
void printFailure(std::vector<int> &array, int number)
{
    int closest = findClosestNumber(array, number);
    if (std::abs(number - closest) <= maximumWrongAnswer)
        std::cout << number << " is wrong. Try " << closest << " next time.\n";
    else
        std::cout << '\n';
}
void printSucces(std::vector<int> &array)
{
    if(array.size() > 0)
        std::cout << "Nice! " << array.size() << " numbers left\n";
    else
        std::cout << "Nice! You found all numbers, good job!";
}

int askUserGuess()
{
    int askNumber;
    std::cout << "\n> ";
    std::cin >> askNumber;
    return askNumber;
}

void playGame(std::vector<int> &array)
{
    do {
        int guess = askUserGuess();
        auto found = searchNumber(array, guess);
        if (found == array.end())
        {
            printFailure(array, guess);
            break;
        }
        else
        {
            array.erase(found);
            printSucces(array);           
        }
    } while (array.begin() != array.end());
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    int startNumber;
    int amountOfNumbers;
    int multiplier = getRandomNumber(2, 4);

    std::cout << "Start where? ";
    std::cin >> startNumber;

    std::cout << "How many? ";
    std::cin >> amountOfNumbers;

    std::vector<int> array(amountOfNumbers);

    for (int i = 0; i < amountOfNumbers; i++)
    {
        array[i] = (startNumber * startNumber) * multiplier;
        startNumber++;
    }

    std::cout << "\nI generated " << amountOfNumbers << " square numbers. Do you know what each number is after multiplying it by " << multiplier;

    playGame(array);
    return 0;
}