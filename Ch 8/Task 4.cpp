/*
Настало время для нашего и вашего любимого задания «Blackjack».
На этот раз мы перепишем игру «Blackjack», которую написали ранее в итоговом
тесте главы №6, но уже с использованием классов!

Нехило, правда? С чего же начинать? Для начала нам нужна стратегия.
Программа «Blackjack» состоит из 4 частей:
* Логика работы с картами.
* Логика работы с колодами карт.
* Логика раздачи карт из колоды.
* Логика игры.
Наша стратегия заключается в том, чтобы работать над каждой из этих частей
индивидуально. Таким образом, вместо конвертации целой программы за один
присест, мы сделаем это спокойно за 4 шага.
Скопируйте вышеприведенный код в вашу IDE, а затем закомментируйте всё, кроме
строк, содержащих #include.

a) Начнем с того, что переделаем Card из структуры в класс. Хорошей новостью
является то, что класс Card очень похож на класс Monster из предыдущего
задания. Алгоритм действий следующий:
* Во-первых, переместите перечисления CardSuit и CardRank внутрь класса Card
под спецификатор доступа public (они неотъемлемо связаны с Card, поэтому
должны находиться внутри класса).
* Во-вторых, создайте закрытые переменные-члены m_rank и m_suit для хранения
значений CardRank и CardSuit.
* В-третьих, создайте открытый конструктор класса Card с инициализацией карт
(переменных-членов класса). Укажите параметры по умолчанию для конструктора
(используйте MAX_RANKS и MAX_SUITS).
* Наконец, переместите функции printCard() и getCardValue() внутрь класса под
спецификатор доступа public (не забудьте сделать их const!).

b) Хорошо, теперь давайте работать над классом Deck:
* Во-первых, в Deck должно быть 52 карты, поэтому создайте private-член
m_deck, который будет фиксированным массивом с 52-мя элементами
(используйте std::array).
*Во-вторых, создайте конструктор, который не принимает никаких параметров и
инициализирует каждый элемент массива m_deck случайной картой
(используйте код из функции main() с циклами for из вышеприведенного примера,
где присутствует полный код). Внутри циклов создайте анонимный объект
Card и присваивайте его каждому элементу массива m_deck.
* В-третьих, переместите функцию printDeck() в класс Deck под спецификатор
доступа public (не забудьте о const).
* В-четвертых, переместите функции getRandomNumber() и swapCard() в класс Deck
в качестве закрытых статических членов.
* В-пятых, переместите функцию shuffleDeck() в класс в качестве открытого члена.

c) Теперь нам нужен способ отследить то, какая карта будет раздаваться
следующей (в исходной программе для этого используется cardptr):
* Во-первых, добавьте в класс Deck целочисленный член m_cardIndex и
инициализируйте его значение 0.
* Во-вторых, создайте открытый метод dealCard(), который будет возвращать
константную ссылку на текущую карту и увеличивать m_cardIndex.
* В-третьих, метод shuffleDeck() также должен быть обновлен для сброса
m_cardIndex (так как после перетасовки колоды, раздается карта, которая
является верхней).

d) Почти готово! Теперь немного самостоятельности:
* Добавьте в программу функции getPlayerChoice() и playBlackjack().
* Измените функцию playBlackjack() в соответствие с уже имеющимся классом и
методами.
* Удалите лишнее и добавьте нужное в функцию main() (см. полный код выше).
*/

#include <iostream>
#include <cassert>
#include <array>
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
 
class Card
{
    public:
        // Перечислитель для мастей карт
        enum CardSuit
        {
        	SUIT_CLUB,
        	SUIT_DIAMOND,
        	SUIT_HEART,
        	SUIT_SPADE,
        	MAX_SUITS
        };
       // Перечислитель для доистоинства карты
        enum CardRank
        {
        	RANK_2,
        	RANK_3,
        	RANK_4,
        	RANK_5,
        	RANK_6,
        	RANK_7,
        	RANK_8,
        	RANK_9,
        	RANK_10,
        	RANK_JACK,
        	RANK_QUEEN,
        	RANK_KING,
        	RANK_ACE,
        	MAX_RANKS
        };

    private:
        CardSuit m_suit; // Масть карты
        CardRank m_rank; // Достоинство карты

    public:
        // Конструктор класса Card
        Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS) :
        m_rank(rank), m_suit(suit)
        {

        }

        // Метод, который выводит масть и достоинство карты
        void printCard() const
        {
        	switch (m_rank)
        	{
        		case RANK_2:		std::cout << '2'; break;
        		case RANK_3:		std::cout << '3'; break;
        		case RANK_4:		std::cout << '4'; break;
        		case RANK_5:		std::cout << '5'; break;
        		case RANK_6:		std::cout << '6'; break;
        		case RANK_7:		std::cout << '7'; break;
        		case RANK_8:		std::cout << '8'; break;
        		case RANK_9:		std::cout << '9'; break;
        		case RANK_10:		std::cout << 'T'; break;
        		case RANK_JACK:		std::cout << 'J'; break;
        		case RANK_QUEEN:	std::cout << 'Q'; break;
        		case RANK_KING:		std::cout << 'K'; break;
        		case RANK_ACE:		std::cout << 'A'; break;
        	}
            
            switch (m_suit)
	        {
	        	case SUIT_CLUB:		std::cout << 'C'; break;
	        	case SUIT_DIAMOND:	std::cout << 'D'; break;
	        	case SUIT_HEART:	std::cout << 'H'; break;
	        	case SUIT_SPADE:	std::cout << 'S'; break;
	        }
        }

        // Метод, который возвращает стоимость карты
        int getCardValue() const
        {
           	switch (m_rank)
           	{
               	case RANK_2:		return 2;
            	case RANK_3:		return 3;
            	case RANK_4:		return 4;
            	case RANK_5:		return 5;
            	case RANK_6:		return 6;
            	case RANK_7:		return 7;
            	case RANK_8:		return 8;
            	case RANK_9:		return 9;
            	case RANK_10:		return 10;
            	case RANK_JACK:		return 10;
            	case RANK_QUEEN:	return 10;
            	case RANK_KING:		return 10;
            	case RANK_ACE:		return 11;
            }

            	return 0;
        }
};

class Deck
{
    private:
        std::array<Card, 52> m_deck; // Массив (колода) с картами
        int m_cardIndex = 0; // Значение, для отселиживания какую карту из колоды
                             // мы раздаем

    public:
        // Конструктор, который инициализирует все 52 карты колоды
        Deck()
        {
            int card = 0;
	        for (int suit = 0; suit < Card::CardSuit::MAX_SUITS; ++suit)
	            for (int rank = 0; rank < Card::CardRank::MAX_RANKS; ++rank)
	            {
                    m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
	            	++card;
	            }
        }

        // Метод для раздачи карт игрокам
        const Card& dealCard()
        {
            assert (m_cardIndex < 52); // Если выходим за пределы колоды, то
                                       // заканчиваем игру
            return m_deck[m_cardIndex++]; // возвращаем ссылку на текущую карту
        }

        // Метод, который выводит всю колоду на экран
        void printDeck() const
        {
        	for (const auto card : m_deck)
        	{
        		card.printCard();
        		std::cout << ' ';
        	}
 
        	std::cout << '\n';
        }

        // Метод перетасовки колоды
        void shuffleDeck()
        {
        	// Перебираем каждую карту в колоде
        	for (int index = 0; index < 52; ++index)
        	{
        		// Выбираем любую случайную карту
        		int swapIndex = getRandomNumber(0, 51);
        		// Меняем местами с нашей текущей картой
        		swapCard(m_deck[index], m_deck[swapIndex]);
        	}
            m_cardIndex = 0;
        }

    private:
        // Статичный метод перетасовки двух карт
        static void swapCard(Card &a, Card &b)
        {
        	Card temp = a;
        	a = b;
        	b = temp;
        }
 
        // Генерируем случайное число между min и max (включительно).
        // Предполагается, что srand() уже был вызван
        static int getRandomNumber(int min, int max)
        {
        	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
         	// Равномерно распределяем вычисление значения из нашего диапазона
        	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
        }
};

char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');
	
	return choice;
}
 
bool playBlackjack(Deck deck)
{
 
	int playerTotal = 0;
	int dealerTotal = 0;
 
	// Дилер получает одну карту
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';
 
	// Игрок получает две карты
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();
 
	// Игрок начинает
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;
 
		playerTotal += deck.dealCard().getCardValue();
		
		// Смотрим, не проиграл ли игрок
		if (playerTotal > 21)
			return false;
	}
 
	// Если игрок не проиграл (у него не больше 21 очка), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17 очков
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}
 
	// Если у дилера больше 21, то он проиграл, а игрок выиграл
	if (dealerTotal > 21)
		return true;
 
	return (playerTotal > dealerTotal);
}
 
int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа
 
    Deck deck;
    deck.shuffleDeck();

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";
 
	return 0;
}