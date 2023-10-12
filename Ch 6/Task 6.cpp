/*
В колоде карт находятся 52 уникальные карты: 13 достоинств
(2, 3, 4, 5, 6, 7, 8, 9, 10, Валет, Дама, Король, Туз) и 4 масти
(трефы, бубны, червы, пики). Создайте два перечисления: первое для масти,
второе для достоинств карт.

Каждая карта должна быть представлена структурой Card, в которой хранится
информация о достоинстве и масти карты (например, 4 бубны, король трефы). 
Создайте эту структуру.

Создайте функцию printCard(), параметром которой будет константная ссылка
типа структуры Card, которая будет выводить значения достоинства и масти
определенной карты в виде 2-буквенного кода (например, валет пики будет
выводиться как VP).

Для представления целой колоды карт (52 карты) создайте массив deck
(используя std::array) и инициализируйте каждый элемент определенной картой.

Напишите функцию printDeck(), которая в качестве параметра принимает
константную ссылку на массив deck и выводит все значения (карты).
Используйте цикл foreach.

Напишите функцию swapCard(), которая принимает две карты и меняет
местами их значения.

Напишите функцию shuffleDeck() для перетасовки колоды карт. Для этого
используйте цикл for с итерацией по массиву. Перетасовка карт должна
произойти 52 раза. В цикле for выберите случайное число от 1 до 52 и
вызовите swapCard(), параметрами которой будут текущая карта и карта,
выбранная случайным образом. Добавьте в функцию main() возможность перетасовки
и вывода уже обновленной (перетасованной) колоды карт.

Напишите функцию getCardValue(), которая возвращает значение карты
(например, 2 значит 2, 3 значит 3 и т.д., 10, валет, королева или король —
это 10, туз — это 11).
*/

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

// Так как перечисление начинается с нуля, а ценность карты с 2ух, введена
// эта константа, чтобы уровнять одно с другим для фукнции getValueCard.
const int enumAlignment = 2;

enum Suit
{
    SUIT_CLUBS,
    SUIT_DIAMONDS,
    SUIT_HEARTS,
    SUIT_SPADES,
    SUIT_MAX
};

enum Dignity
{
    DIGNITY_2,
    DIGNITY_3,
    DIGNITY_4,
    DIGNITY_5,
    DIGNITY_6,
    DIGNITY_7,
    DIGNITY_8,
    DIGNITY_9,
    DIGNITY_10,
    DIGNITY_JACK,
    DIGNITY_QUEEN,
    DIGNITY_KING,
    DIGNITY_ACE,
    DIGNITY_MAX
};

struct Card
{
    Dignity dignity;
    Suit suit;
};

void printCard(Card const& card)
{
    switch (card.dignity)
    {
    case DIGNITY_2:
        std::cout << "2";
        break;
    case DIGNITY_3:
        std::cout << "3";
        break;
    case DIGNITY_4:
        std::cout << "4";
        break;
    case DIGNITY_5:
        std::cout << "5";
        break;
    case DIGNITY_6:
        std::cout << "6";
        break;
    case DIGNITY_7:
        std::cout << "7";
        break;
    case DIGNITY_8:
        std::cout << "8";
        break;
    case DIGNITY_9:
        std::cout << "9";
        break;
    case DIGNITY_10:
        std::cout << "10";
        break;
    case DIGNITY_JACK:
        std::cout << "J";
        break;
    case DIGNITY_QUEEN:
        std::cout << "Q";
        break;
    case DIGNITY_KING:
        std::cout << "K";
        break;
    case DIGNITY_ACE:
        std::cout << "A";
        break;
    }

    switch (card.suit)
    {
    case SUIT_CLUBS:
        std::cout << "C";
        break;
    case SUIT_DIAMONDS:
        std::cout << "D";
        break;
    case SUIT_HEARTS:
        std::cout << "H";
        break;
    case SUIT_SPADES:
        std::cout << "S";
        break;
    }
}

void printDeck(const std::array<Card, 52>& deck)
{
    int count = 1;
    for (const auto& card : deck)
    {
        std::cout << "Card #" << count << ": ";
        printCard(card);
        std::cout << "\n";
        count++;
    }
}

void swapCard(Card& a, Card& b)
{
    Card temp = a;
    a = b;
    b = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52>& deck)
{
    for (int index = 0; index < 52; index++)
    {
        int randomCard = getRandomNumber(0, 51);

        swapCard(deck[index], deck[randomCard]);
    }
}

int getCardValue(const Card& card)
{
    for (int value = 0; value <= DIGNITY_10; value++)
    {
        if (value == card.dignity)
            return value + enumAlignment;
    }
    if (card.dignity == 9 || card.dignity == 10 || card.dignity == 11)
        return 10;
    else
        return 11;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    std::array<Card, 52> deck;

    int card = 0;
    for (int suit = 0; suit < SUIT_MAX; suit++)
        for (int dignity = 0; dignity < DIGNITY_MAX; dignity++)
        {
            deck[card].suit = static_cast<Suit>(suit);
            deck[card].dignity = static_cast<Dignity>(dignity);
            card++;
        }

    printDeck(deck);

    shuffleDeck(deck);

    printDeck(deck);

    return 0;
}