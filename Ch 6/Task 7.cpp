/*
Хорошо, настало время для серьезной игры! Давайте напишем упрощенную версию
известной карточной игры Blackjack (русский аналог «Очко» или «21 очко»).

Правила нашей версии Blackjack следующие:
* вначале дилер получает одну карту (в реальной жизни, дилер получает две карты, но одна лицевой стороной вниз, поэтому на данном этапе это не имеет значения);
* затем игрок получает две карты;
* игрок начинает;  игрок может либо "взять" (hit), либо "удержаться" (stand);
* если игрок "удержался", то его ход завершен, и его результат подсчитывается
на основе карт, которые у него есть;
* если игрок "берет", то он получает вторую карту, и значение этой карты
добавляется к его уже имеющемуся результату;
* туз обычно считается как 1 или как 11. Чтобы было проще, мы будем считать
его как 11;
* если у игрока в результате получается больше 21, то он проиграл;
* ход дилера выполняется после хода игрока;
* дилер берет карты до тех пор, пока его общий результат не достигнет 17
или более очков. Как только этот предел достигнут — дилер карт уже не берет;
* если у дилера больше 21-го, то дилер проиграл, а игрок победил;
* если же у дилера и у игрока до 21 очка, то выигрывает тот, у кого
результат больше.

В нашей упрощенной версии Blackjack мы не будем отслеживать, какие
конкретно карты были у игрока, а какие у дилера. Мы будем отслеживать
только сумму значений карт, которые они получили. Так будет проще.
Начнем с кода, который у нас получился в задании №6. Создайте функцию
playBlackjack(), которая возвращает true, если игрок побеждает, и false —
если он проигрывает. Эта функция должна:
* Принимать перетасованную колоду карт (deck) в качестве параметра.
* Инициализировать указатель на первую карту (имя указателя — cardPtr).
Это будет использоваться для раздачи карт из колоды.
* Иметь две целочисленные переменные для хранения результата игрока и дилера.
* Соответствовать правилам, приведенным выше.

Протестируйте выполнение одиночной игры «Блэкджек» в функции main().
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

std::string hitOrStand()
{
    std::string askPlayer;
    do {
        std::cout << "Do you want hit or stand?\n";
        std::cin >> askPlayer;
    } while (askPlayer != "hit" && askPlayer != "stand");
    return askPlayer;
}

bool playBlackjack(std::array<Card, 52>& deck)
{
    Card* cardPtr = &deck[0];

    static int player = 0;
    static int dealer = 0;
    dealer += getCardValue(*cardPtr++);
    player += getCardValue(*cardPtr++);
    player += getCardValue(*cardPtr++);

    std::cout << "You have: " << player << " points and dealer have: " << dealer << " points\n";

    if (player == 21)
        return true;

    std::string askPlayer;
    do {
        askPlayer = hitOrStand();
        if (askPlayer == "hit")
            player += getCardValue(*cardPtr++);
        std::cout << "You have: " << player << " points\n";
        if (player > 21)
            return false;
    } while (askPlayer == "hit");


    while (dealer <= 17)
    {
        dealer += getCardValue(*cardPtr++);
        std::cout << "Dealer have: " << dealer << " points\n";
    }

    if (dealer > 21)
        return true;
    
    return (player > dealer);
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

    shuffleDeck(deck);

    if (playBlackjack(deck))
        std::cout << "You win the game!";
    else
        std::cout << "You lose the game.";
    return 0;
}