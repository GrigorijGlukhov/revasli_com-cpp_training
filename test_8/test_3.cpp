#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>

class Monster
{
public: // Public for acess outside class
    enum MonsterType
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MONSTERTYPEMAX
    };
private:
    MonsterType m_type;
    std::string m_name;
    int         m_health;
    std::string getTypeSting( MonsterType type ) {
        switch ( type )
        {
            default:
            case 0 : return "Dragon";
            case 1 : return "Goblin";
            case 2 : return "Ogre";
            case 3 : return "Orc";
            case 4 : return "Skeleton";
            case 5 : return "Troll";
            case 6 : return "Vampire";
            case 7 : return "Zombie";
        }
    }
public:
    Monster( MonsterType type = MonsterType::Dragon, std::string name = "noname", int health = 100 )
        : m_type(type), m_name(name), m_health(health) {}
    void print()
    {
        std::cout << m_name << " is the " << getTypeSting(m_type) << " and has " << m_health << " points of health.\n";
    }
};

// static class that generate monsters
class MonsterGenerator
{
    typedef Monster::MonsterType MMT
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0/(static_cast<double>(RAND_MAX) + 1.0); // use static because this one time aveluated value
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
public:
    static Monster generateMonster()
    {
        const std::string m_sNames[7] {"Jack", "Alex", "Bob", "Clive", "Sue", "David", "Ruppert"};
        MMT type = static_cast<MMT>(getRandomNumber(0, static_cast<int>(MMT::MONSTERTYPEMAX-1)));
        std::string name = m_sNames[getRandomNumber(0, 7)];
        int health = getRandomNumber(0, 100);
        return Monster(type, name, health);
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Monster m = MonsterGenerator::generateMonster();
    m.print();

    return 0;
}
