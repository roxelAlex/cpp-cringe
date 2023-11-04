/*
Давайте создадим генератор случайных монстров.
a) Сначала создайте перечисление MonsterType со следующими типами монстров:
Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire и Zombie + добавьте
MAX_MONSTER_TYPES, чтобы иметь возможность подсчитать общее количество
всех перечислителей.
b) Теперь создайте класс Monster со следующими тремя атрибутами
(переменными-членами):
тип (MonsterType), имя (std::string) и количество здоровья (int).
c) Перечисление MonsterType является специфичным для Monster, поэтому
переместите его внутрь класса под спецификатор доступа public.
d) Создайте конструктор, который позволит инициализировать все
переменные-члены класса.
e) Теперь нам нужно вывести информацию про нашего монстра. Для этого нужно
конвертировать MonsterType в std::string. Добавьте функцию getTypeString(),
которая будет выполнять конвертацию, и функцию вывода print().
f) Теперь мы уже можем создать сам генератор монстров. Для этого создайте
статический класс MonsterGenerator и статический метод с именем
generateMonster(), который будет возвращать случайного монстра.
Пока что возвратом метода пускай будет анонимный объект:
(Monster::Orc, "Jack", 90).
g) Теперь MonsterGenerator должен генерировать некоторые случайные атрибуты.
Для этого нам понадобится генератор случайного числа. Поскольку
MonsterGenerator будет полагаться непосредственно на эту функцию,
то поместите её внутрь класса в качестве статического метода.
h) Теперь измените функцию generateMonster() для генерации случайного
MonsterType (между 0 и Monster::MAX_MONSTER_TYPES-1) и случайного количества
здоровья (от 1 до 100). Это должно быть просто. После того, как вы это
сделаете, определите один статический фиксированный массив s_names размером
6 элементов внутри функции generateMonster() и инициализируйте его 6-ю
любыми именами на ваш выбор. Добавьте возможность выбора случайного имени
из этого массива.
*/

#include <iostream>
#include <array>
#include <string>
#include <ctime>
#include <cstdlib>

// Класс Monster
class Monster
{
public:
    // Перечисление с типами монстров.
    enum MonsterType
    {
        MONSTER_DRAGON,
        MONSTER_GOBLIN,
        MONSTER_OGRE,
        MONSTER_ORC,
        MONSTER_SKELETON,
        MONSTER_TROLL,
        MONSTER_VAMPIRE,
        MONSTER_ZOMBIE,
        MAX_MONSTER_TYPES
    };

private:
    MonsterType m_type; // Тип монстра (перечислитель)
    std::string m_name; // Имя монстра
    int m_health; // Здоровье монстра

public:

    // Конструктор класса Monster со списком инициализации
    Monster(MonsterType type, std::string name, int hp)
        : m_type(type), m_name(name), m_health(hp)
    {

    }

    // Метод getTypeString() возвращает тип монстра в виде строки.
    std::string getTypeString() const
    {
        switch (m_type)
        {
        case 0: return "dragon"; break;
        case 1: return "goblin"; break;
        case 2: return "ogre"; break;
        case 3: return "orc"; break;
        case 4: return "skeleton"; break;
        case 5: return "troll"; break;
        case 6: return "vampire"; break;
        case 7: return "zombie"; break;
        }
        return "Error!";
    }

    // Метод print() выводит информацию о монстре на экран в следующем
    // формате: 
    // <Monster_name> is the <Monster_type> that has <Monster_HP> health points.
    void print() const
    {
        std::cout << m_name << " is the " << getTypeString() <<
            " that has " << m_health << " health points.";
    }
};

// Статический класс MonsterGenerator
class MonsterGenerator
{
private:

    // Статический массив с именами
    static std::array<std::string, 6> s_name;

public:

    // Статеческий метод который возвращает монстра.
    // static Monster generateMonster()
    // {
    //     return Monster(Monster::MONSTER_ORC, "Jack", 90);
    // }

    // Статический метод generateMonster() генерирует случайного монстра
    static Monster generateMonster()
    {   // Генерация случайного типа монстра
        int monsterType = getRandomNumber(0, (Monster::MAX_MONSTER_TYPES - 1));
        // Генерация количества здоровья у монстра
        int monsterHP = getRandomNumber(1, 100);
        // Случайный выбор имени из массива с именами
        int monsterName = getRandomNumber(0, 5);

        return Monster(static_cast<Monster::MonsterType>(monsterType), s_name[monsterName], monsterHP);
    }

    // Статический метод генерации случайного числа в определенном диапозоне.
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
};

// Так как наш массив статический, его необходимо иницализировать в глобальном
// пространстве
std::array<std::string, 6> MonsterGenerator::s_name = 
{
    "Alex", "Igor", "John", "Tusk", "Slardar", "Axe"
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    Monster m = MonsterGenerator::generateMonster();
    m.print();

    return 0;
}