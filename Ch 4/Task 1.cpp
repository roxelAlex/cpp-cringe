/*
При разработке игры мы решили, что в ней должны быть монстры,
потому что всем нравится сражаться с монстрами. Объявите структуру,
которая представляет вашего монстра. Монстр может быть разным:
ogre, goblin, skeleton, orc и troll.
Если ваш компилятор поддерживает C++11, то используйте классы enum,
если нет — обычные перечисления.
Каждый монстр также должен иметь имя (используйте std::string) и количество
здоровья, которое отображает, сколько урона он может получить,
прежде чем умрет. Напишите функцию printMonster(),
которая выведет все члены структуры. Объявите монстров типа goblin и orc,
инициализируйте их, используя список инициализаторов, и передайте в
функцию printMonster().
*/

#include <iostream>

enum class MonstersType
{
    OGRE,
    GOBLIN,
    SKELETON,
    ORC,
    TROLL,
};

struct Monster
{
    std::string monsterName;
    int monsterHP;
    MonstersType monsterType;
};

std::string printTypeMonster(MonstersType monster)
{
    std::string monsterType;
    if (monster == MonstersType::OGRE)
    {
        return monsterType = "Ogre";
    }
    else if (monster == MonstersType::GOBLIN)
    {
        return monsterType = "Goblin";
    }
    else if (monster == MonstersType::SKELETON)
    {
        return monsterType = "Skeleton";
    }
    else if (monster == MonstersType::ORC)
    {
        return monsterType = "Orc";
    }
    else if (monster == MonstersType::TROLL)
    {
        return monsterType = "Troll";
    }
}

void printMonster(Monster monster)
{
    std::cout << "This " << printTypeMonster(monster.monsterType) << " is named " << monster.monsterName << " and has " << monster.monsterHP << " health." << std::endl;
}

int main()
{
    Monster goblin{ "John", 170, MonstersType::GOBLIN };
    Monster orc{ "James", 35, MonstersType::ORC };

    printMonster(goblin);
    printMonster(orc);
    
    return 0;
}